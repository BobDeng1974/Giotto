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

#include "GfxError.hpp"

namespace gfx
{

namespace error
{

const char GfxError::ClassName[] = "GfxError";

GfxError::GfxError() noexcept : GfxObject(ClassName)
{
    clear();
}

GfxError::GfxError(std::string const& error) noexcept : GfxObject(ClassName)
{
    assert(error.length() > 0);

    error_ = error;
}

GfxError::GfxError(GfxError const& other) noexcept : GfxObject(ClassName)
{
    error_ = other.error_;
}

GfxError::GfxError(GfxError&& other) noexcept : GfxObject(ClassName)
{
    error_ = other.error_;
    // Delete other's data
    other.clear();
}

GfxError& GfxError::operator=(GfxError const& other) noexcept
{
    if (this != &other)
    {
        error_ = other.error_;
    }
    return *this;
}

GfxError& GfxError::operator=(GfxError&& other) noexcept
{
    if (this != &other)
    {
        error_ = other.error_;
        // Delete other's data
        other.clear();
    }
    return *this;
}

GfxError::operator bool() const noexcept
{
    return (error_.length() > 0);
}

std::string const& GfxError::get() const noexcept
{
    return error_;
}

void GfxError::clear(void) noexcept
{
    error_ = "";
}

}  // namespace error

}  // namespace gfx

/* EOF */
