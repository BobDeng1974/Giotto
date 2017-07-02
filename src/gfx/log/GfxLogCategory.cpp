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

#include "GfxLogCategory.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxlogcategory::log::gfx");

namespace gfx
{

namespace log
{

const char GfxLogCategory::ClassName[] = "GfxLogCategory";

GfxLogCategory::GfxLogCategory() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    clear();
}

GfxLogCategory::GfxLogCategory(const ValueType value) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    value_ = static_cast<SdlType>(value);
}

GfxLogCategory::GfxLogCategory(const SdlType value) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    value_ = value;
}

GfxLogCategory::GfxLogCategory(GfxLogCategory const& other) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    value_ = other.value_;
}

GfxLogCategory::GfxLogCategory(GfxLogCategory&& other) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    value_ = other.value_;
    // Delete other's data
    other.clear();
}

GfxLogCategory& GfxLogCategory::operator=(GfxLogCategory const& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        value_ = other.value_;
    }
    return *this;
}

GfxLogCategory& GfxLogCategory::operator=(GfxLogCategory&& other) noexcept
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

GfxLogCategory::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxLogCategory::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

void GfxLogCategory::clear(void) noexcept
{
    LOG_TRACE_PRIO_LOW();

    value_ = static_cast<SdlType>(ValueType::logCategoryCustom);
}

GfxLogCategory::SdlType GfxLogCategory::getAsSdlType(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return value_;
}

}  // namespace log

}  // namespace gfx

/* EOF */
