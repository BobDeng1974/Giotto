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

#include <string>

#include "GfxTtfInitQuit.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxttfinitquit::ttf::gfx");

namespace gfx
{

namespace ttf
{

const char GfxTtfInitQuit::ClassName[] = "GfxTtfInitQuit";

GfxTtfInitQuit::GfxTtfInitQuit() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_TOP();

    errorCode_ = sdl2::TTF_Init();
}

GfxTtfInitQuit::~GfxTtfInitQuit(void) noexcept
{
    LOG_TRACE_PRIO_TOP();

    sdl2::TTF_Quit();
}

GfxTtfInitQuit::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return (errorCode_ == 0);
}

std::string GfxTtfInitQuit::to_string() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

int32_t GfxTtfInitQuit::wasInit(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return sdl2::TTF_WasInit();
}

int32_t GfxTtfInitQuit::getErrorCode(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return errorCode_;
}

}  // namespace ttf

}  // namespace gfx

/* EOF */
