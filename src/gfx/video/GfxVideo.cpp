/*
 Giotto
 Copyright (C) 2017 George Oros
 
 This software is provided 'as-is', without any express or implied
 warranty.  In no event will the authors be held liable for any damages
 arising from the use of this software.
 
 Permission is granted to anyone to use this software for any purpose,
 including commercial applications, and to alter it and redistribute it
 freely, subject to the following restrictions:
 
 1. The origin of this software must not be misrepresented; you must not
 claim that you wrote the original software. If you use this software
 in a product, an acknowledgment in the product documentation would be
 appreciated but is not required.
 2. Altered source versions must be plainly marked as such, and must not be
 misrepresented as being the original software.
 3. This notice may not be removed or altered from any source distribution.
 
 See copyright notice at http://lidsdl.org/license.php
*/

#include <cassert>
#include <cstdint>
#include <map>
#include <string>
#include <utility>

#include "GfxVideo.hpp"

namespace gfx
{

namespace video
{

const char GfxVideo::ClassName[] = "GfxVideo";

GfxVideo::GfxVideo() noexcept : GfxObject(ClassName)
{
    clear();
}

GfxVideo::GfxVideo(GfxVideo&& other) noexcept : GfxObject(ClassName)
{
    numvideodrivers_ = other.numvideodrivers_;
    numvideodisplays_ = other.numvideodisplays_;
    numdisplaymodes_ = std::move(other.numdisplaymodes_);
    // Delete other's data
    other.clear();
}

GfxVideo& GfxVideo::operator=(GfxVideo&& other) noexcept
{
    if (this != &other)
    {
        numvideodrivers_ = other.numvideodrivers_;
        numvideodisplays_ = other.numvideodisplays_;
        numdisplaymodes_ = std::move(other.numdisplaymodes_);
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxVideo::operator bool() const noexcept
{
    return true;
}

void GfxVideo::videoInit(void) throw(std::runtime_error)
{
    throw std::runtime_error("Use GfxInitQuit.hpp");
}

void GfxVideo::videoQuit(void) throw(std::runtime_error)
{
    throw std::runtime_error("Use GfxInitQuit.hpp");
}

int32_t GfxVideo::getNumVideoDrivers(void) noexcept
{
    numvideodrivers_ = sdl2::SDL_GetNumVideoDrivers();
    return numvideodrivers_;
}

std::string GfxVideo::getVideoDriver(const int32_t driverindex) const noexcept
{
    assert(driverindex >= 0);

    std::string str = "";

    if ((numvideodrivers_ >= 0) && (driverindex < numvideodrivers_))
    {
        str = sdl2::SDL_GetVideoDriver(driverindex);
    }
    return str;
}

std::string GfxVideo::getCurrentVideoDriver(void) const noexcept
{
    const char * c;
    std::string str = "Not initialized";

    c = reinterpret_cast<const char *>(sdl2::SDL_GetCurrentVideoDriver());
    if (c != NULL)
    {
        str = c;
    }
    return str;
}

int32_t GfxVideo::getNumVideoDisplays(void) noexcept
{
    numvideodisplays_ = sdl2::SDL_GetNumVideoDisplays();
    return numvideodisplays_;
}

std::string GfxVideo::getDisplayName(const int32_t displayindex) const noexcept
{
    assert(displayindex >= 0);

    std::string str = "";

    if ((numvideodisplays_ >= 0) && (displayindex < numvideodisplays_))
    {
        str = sdl2::SDL_GetDisplayName(displayindex);
    }
    return str;
}

rect::GfxRect GfxVideo::getDisplayBounds(const int32_t displayindex) const noexcept
{
    assert(displayindex >= 0);

    rect::GfxRect::SdlType rt;

    if ((numvideodisplays_ >= 0) && (displayindex < numvideodisplays_))
    {
        (void)SDL_GetDisplayBounds(displayindex, &rt);
        return rect::GfxRect(rt);
    }
    return rect::GfxRect();
}

rect::GfxRect GfxVideo::getDisplayUsableBounds(const int32_t displayindex) const noexcept
{
    assert(displayindex >= 0);

    rect::GfxRect::SdlType rt;

    if ((numvideodisplays_ >= 0) && (displayindex < numvideodisplays_))
    {
        (void)SDL_GetDisplayUsableBounds(displayindex, &rt);
        return rect::GfxRect(rt);
    }
    return rect::GfxRect();
}

void GfxVideo::getDisplayDPI(const int32_t displayindex, float * ddpi, float * hdpi, float * vdpi) const noexcept
{
    assert(displayindex >= 0);
    assert(ddpi != nullptr);
    assert(hdpi != nullptr);
    assert(vdpi != nullptr);

    if ((numvideodisplays_ >= 0) && (displayindex < numvideodisplays_))
    {
        sdl2::SDL_GetDisplayDPI(displayindex, ddpi, hdpi, vdpi);
    }
}

int32_t GfxVideo::getNumDisplayModes(const int32_t displayindex) noexcept
{
    assert(displayindex >= 0);

    int32_t numdisplaymodes = -1;

    if ((numvideodisplays_ >= 0) && (displayindex < numvideodisplays_))
    {
        numdisplaymodes = sdl2::SDL_GetNumDisplayModes(displayindex);
        numdisplaymodes_[displayindex] = numdisplaymodes;
    }
    return numdisplaymodes;
}

GfxDisplayMode GfxVideo::getDisplayMode(const int32_t displayindex, const int32_t modeindex) noexcept
{
    assert(displayindex >= 0);
    assert(modeindex >= 0);

    int32_t mcount;
    GfxDisplayMode::SdlType dms;

    if ((numvideodisplays_ >= 0) && (displayindex < numvideodisplays_))
    {
        try
        {
            mcount = numdisplaymodes_.at(displayindex);
        }
        catch(std::out_of_range& e)
        {
            mcount = -1;
        }
        if ((mcount >= 0) && (modeindex < mcount))
        {
            SDL_GetDisplayMode(displayindex, modeindex, &dms);
            return GfxDisplayMode(dms);
        }
    }
    return GfxDisplayMode();
}

GfxDisplayMode GfxVideo::getDesktopDisplayMode(const int32_t displayindex) const noexcept
{
    assert(displayindex >= 0);

    GfxDisplayMode::SdlType dms;

    if ((numvideodisplays_ >= 0) && (displayindex < numvideodisplays_))
    {
        SDL_GetDesktopDisplayMode(displayindex, &dms);
        return GfxDisplayMode(dms);
    }
    return GfxDisplayMode();
}

GfxDisplayMode GfxVideo::getCurrentDisplayMode(const int32_t displayindex) const noexcept
{
    assert(displayindex >= 0);

    GfxDisplayMode::SdlType dms;

    if ((numvideodisplays_ >= 0) && (displayindex < numvideodisplays_))
    {
        SDL_GetCurrentDisplayMode(displayindex, &dms);
        return GfxDisplayMode(dms);
    }
    return GfxDisplayMode();
}

GfxDisplayMode GfxVideo::getClosestDisplayMode(const int32_t displayindex,
                                               GfxDisplayMode const& mode) const noexcept
{
    assert(displayindex >= 0);
    assert(mode);

    GfxDisplayMode::SdlType dms;
    GfxDisplayMode::SdlTypePtr dmsptr;

    if ((numvideodisplays_ >= 0) && (displayindex < numvideodisplays_))
    {
        dmsptr = SDL_GetClosestDisplayMode(displayindex, mode.getAsSdlTypePtr(), &dms);
        if (dmsptr == &dms)
        {
            return GfxDisplayMode(dms);
        }
    }
    return GfxDisplayMode();
}

// Private methods
void GfxVideo::clear(void) noexcept
{
    numvideodrivers_ = -1;
    numvideodisplays_ = -1;
    numdisplaymodes_.clear();
}

}  // namespace video

}  // namespace gfx

/* EOF */
