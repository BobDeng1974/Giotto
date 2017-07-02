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

#include "GfxPixelFormatEnum.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxpixelformatenum::pixels::gfx");

namespace gfx
{

namespace pixels
{

const char GfxPixelFormatEnum::ClassName[] = "GfxPixelFormatEnum";

GfxPixelFormatEnum::GfxPixelFormatEnum() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxPixelFormatEnum::GfxPixelFormatEnum(const ValueType value) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    value_ = static_cast<SdlType>(value);
}

GfxPixelFormatEnum::GfxPixelFormatEnum(const SdlType value) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    value_ = value;
}

GfxPixelFormatEnum::GfxPixelFormatEnum(GfxPixelFormatEnum const& other) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    value_ = other.value_;
}

GfxPixelFormatEnum::GfxPixelFormatEnum(GfxPixelFormatEnum&& other) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    value_ = other.value_;
    // Delete other's data
    other.clear();
}

GfxPixelFormatEnum& GfxPixelFormatEnum::operator=(GfxPixelFormatEnum const& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        value_ = other.value_;
    }
    return *this;
}

GfxPixelFormatEnum& GfxPixelFormatEnum::operator=(GfxPixelFormatEnum&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        value_ = other.value_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxPixelFormatEnum::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxPixelFormatEnum::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

GfxPixelFormatEnum::ValueType GfxPixelFormatEnum::getValue(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return static_cast<ValueType>(value_);
}

void GfxPixelFormatEnum::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    value_ = static_cast<SdlType>(ValueType::pixelFormatUnknown);
}

GfxPixelFormatEnum::SdlType GfxPixelFormatEnum::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return value_;
}

}  // namespace pixels

}  // namespace gfx

/* EOF */
