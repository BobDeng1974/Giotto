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

#include "GfxPackedOrder.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxpackedorder::pixels::gfx");

namespace gfx
{

namespace pixels
{

const char GfxPackedOrder::ClassName[] = "GfxPackedOrder";

GfxPackedOrder::GfxPackedOrder() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxPackedOrder::GfxPackedOrder(const ValueType value) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    value_ = static_cast<SdlType>(value);
}

GfxPackedOrder::GfxPackedOrder(const SdlType value) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    value_ = value;
}

GfxPackedOrder::GfxPackedOrder(GfxPackedOrder const& other) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    value_ = other.value_;
}

GfxPackedOrder::GfxPackedOrder(GfxPackedOrder&& other) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    value_ = other.value_;
    // Delete other's data
    other.clear();
}

GfxPackedOrder& GfxPackedOrder::operator=(GfxPackedOrder const& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        value_ = other.value_;
    }
    return *this;
}

GfxPackedOrder& GfxPackedOrder::operator=(GfxPackedOrder&& other) noexcept
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

GfxPackedOrder::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxPackedOrder::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

GfxPackedOrder::ValueType GfxPackedOrder::getValue(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return static_cast<ValueType>(value_);
}

void GfxPackedOrder::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    value_ = static_cast<SdlType>(ValueType::packedOrderNone);
}

GfxPackedOrder::SdlType GfxPackedOrder::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return value_;
}

}  // namespace pixels

}  // namespace gfx

/* EOF */
