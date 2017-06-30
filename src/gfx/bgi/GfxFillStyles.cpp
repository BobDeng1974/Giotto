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

#include "GfxFillStyles.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxfillstyles::bgi::gfx");

namespace gfx
{

namespace bgi
{

const char GfxFillStyles::ClassName[] = "GfxFillStyles";

GfxFillStyles::GfxFillStyles() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_LOW();
    clear();
}

GfxFillStyles::GfxFillStyles(const ValueType fill) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_LOW();
    fill_ = static_cast<BgiType>(fill);
}

GfxFillStyles::GfxFillStyles(const BgiType fill) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_LOW();
    fill_ = fill;
}

GfxFillStyles::GfxFillStyles(GfxFillStyles const& other) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_LOW();
    fill_ = other.fill_;
}

GfxFillStyles::GfxFillStyles(GfxFillStyles&& other) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_LOW();
    fill_ = other.fill_;
    // Delete other's value
    other.clear();
}

GfxFillStyles& GfxFillStyles::operator=(GfxFillStyles const& other) noexcept
{
    LOG_TRACE_PRIO_LOW();
    if (this != &other)
    {
        fill_ = other.fill_;
    }
    return *this;
}

GfxFillStyles& GfxFillStyles::operator=(GfxFillStyles&& other) noexcept
{
    LOG_TRACE_PRIO_LOW();
    if (this != &other)
    {
        fill_ = other.fill_;
        // Delete other's value
        other.clear();
    }
    return *this;
}

GfxFillStyles::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();
    return true;
}

GfxFillStyles::ValueType GfxFillStyles::getValue(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();
    return static_cast<ValueType>(fill_);
}

void GfxFillStyles::setValue(const ValueType fill) noexcept
{
    LOG_TRACE_PRIO_LOW();
    fill_ = static_cast<BgiType>(fill);
}

void GfxFillStyles::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();
    fill_ = static_cast<BgiType>(ValueType::solidFill);
}

GfxFillStyles::BgiType GfxFillStyles::getAsBgiType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();
    return fill_;
}

}  // namespace bgi

}  // namespace gfx

/* EOF */
