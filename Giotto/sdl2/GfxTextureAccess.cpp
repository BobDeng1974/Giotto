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

#include "GfxTextureAccess.hpp"

namespace gfx
{

const char GfxTextureAccess::ClassName[] = "GfxTextureAccess";

GfxTextureAccess::GfxTextureAccess() : GfxRootClass(ClassName)
{
    access_ = static_cast<SdlType>(GfxTextureAccessValues::accessStatic);
}

GfxTextureAccess::GfxTextureAccess(const GfxTextureAccessValues access) : GfxRootClass(ClassName)
{
    access_ = static_cast<SdlType>(access);
}

GfxTextureAccess::GfxTextureAccess(GfxTextureAccess const& other) : GfxRootClass(ClassName)
{
    access_ = other.access_;
}

GfxTextureAccess::GfxTextureAccess(GfxTextureAccess&& other) : GfxRootClass(ClassName)
{
    access_ = other.access_;
    // Delete other's data
    other.access_ = static_cast<SdlType>(GfxTextureAccessValues::accessStatic);
}

GfxTextureAccess& GfxTextureAccess::operator=(GfxTextureAccess const& other)
{
    if (this != &other)
    {
        access_ = other.access_;
    }
    return *this;
}

GfxTextureAccess& GfxTextureAccess::operator=(GfxTextureAccess&& other)
{
    if (this != &other)
    {
        access_ = other.access_;
        // Delete other's data
        other.access_ = static_cast<SdlType>(GfxTextureAccessValues::accessStatic);
    }
    return *this;
}

GfxTextureAccess::SdlType GfxTextureAccess::getAsSdlType(void) const
{
    return access_;
}

GfxTextureAccess::SdlTypePtr GfxTextureAccess::getAsSdlTypePtr(void) const
{
    return (SdlTypePtr)&access_;
}

}  // namespace gfx

/* EOF */
