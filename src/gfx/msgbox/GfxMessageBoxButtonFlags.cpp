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
#include <string>

#include "GfxMessageBoxButtonFlags.hpp"

namespace gfx
{

namespace msgbox
{

const char GfxMessageBoxButtonFlags::ClassName[] = "GfxMessageBoxButtonFlags";

GfxMessageBoxButtonFlags::GfxMessageBoxButtonFlags() noexcept : GfxObject(ClassName)
{
    clear();
}

GfxMessageBoxButtonFlags::GfxMessageBoxButtonFlags(const ValueType flags) noexcept :
        GfxObject(ClassName)
{
    flags_ = static_cast<SdlType>(flags);
}

GfxMessageBoxButtonFlags::GfxMessageBoxButtonFlags(const SdlType flags) noexcept : GfxObject(ClassName)
{
    assert(flags > 0);
    assert(flags < 3);

    flags_ = flags;
}

GfxMessageBoxButtonFlags::GfxMessageBoxButtonFlags(GfxMessageBoxButtonFlags const& other) noexcept :
        GfxObject(ClassName)
{
    flags_ = other.flags_;
}
GfxMessageBoxButtonFlags::GfxMessageBoxButtonFlags(GfxMessageBoxButtonFlags&& other) noexcept :
        GfxObject(ClassName)
{
    flags_ = other.flags_;
    // Delete other's data
    other.clear();
}

GfxMessageBoxButtonFlags& GfxMessageBoxButtonFlags::operator=(GfxMessageBoxButtonFlags const& other) noexcept
{
    if (this != &other)
    {
        flags_ = other.flags_;
    }
    return *this;
}

GfxMessageBoxButtonFlags& GfxMessageBoxButtonFlags::operator=(GfxMessageBoxButtonFlags&& other) noexcept
{
    if (this != &other)
    {
        flags_ = other.flags_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

bool GfxMessageBoxButtonFlags::operator==(GfxMessageBoxButtonFlags const& other) noexcept
{
    return (flags_ == other.flags_);
}

GfxMessageBoxButtonFlags::operator bool() const noexcept
{
    return true;
}

bool GfxMessageBoxButtonFlags::isReturnDefault(void) const noexcept
{
    return (flags_ == sdl2::SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT);
}

bool GfxMessageBoxButtonFlags::isEscDefault(void) const noexcept
{
    return (flags_ == sdl2::SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT);
}

void GfxMessageBoxButtonFlags::clear(void) noexcept
{
    flags_ = static_cast<SdlType>(ValueType::noneDefault);
}

GfxMessageBoxButtonFlags::SdlType GfxMessageBoxButtonFlags::getAsSdlType(void) const noexcept
{
    return flags_;
}

}  // namespace msgbox

}  // namespace gfx

/* EOF */
