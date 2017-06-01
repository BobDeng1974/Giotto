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

#include <stdexcept>
#include <cassert>
#include <string>

#include "GfxGammaRamp.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace supp
{

const char GfxGammaRamp::ClassName[] = "GfxGammaRamp";

GfxGammaRamp::GfxGammaRamp() : GfxRootClass(ClassName)
{
    clear();
}

GfxGammaRamp::GfxGammaRamp(SdlTypePtr gammaRamp)
{
    int32_t index;

    for (index = 0; index < kGammaRampNumberOfElements; index++)
    {
        gammaRamp_[index] = *gammaRamp;
        gammaRamp++;
    }
}

GfxGammaRamp::GfxGammaRamp(GfxGammaRamp const& other)
{
    int32_t index;

    for (index = 0; index < kGammaRampNumberOfElements; index++)
    {
        gammaRamp_[index] = other.gammaRamp_[index];
    }
}

GfxGammaRamp::GfxGammaRamp(GfxGammaRamp&& other)
{
    int32_t index;

    for (index = 0; index < kGammaRampNumberOfElements; index++)
    {
        gammaRamp_[index] = other.gammaRamp_[index];
    }
    other.clear();
}

GfxGammaRamp& GfxGammaRamp::operator=(GfxGammaRamp const& other)
{
    int32_t index;

    if (this != &other)
    {
        for (index = 0; index < kGammaRampNumberOfElements; index++)
        {
            gammaRamp_[index] = other.gammaRamp_[index];
        }
    }
    return *this;
}

GfxGammaRamp& GfxGammaRamp::operator=(GfxGammaRamp&& other)
{
    int32_t index;

    if (this != &other)
    {
        for (index = 0; index < kGammaRampNumberOfElements; index++)
        {
            gammaRamp_[index] = other.gammaRamp_[index];
        }
        other.clear();
    }
    return *this;
}

GfxGammaRamp::operator bool() const
{
    return true;
}

uint16_t& GfxGammaRamp::operator [](int32_t index) throw(std::runtime_error)
{
    if ((index >= 0) and (index <= kGammaRampNumberOfElements))
    {
        return gammaRamp_[index];
    }
    throw std::runtime_error("Index out of bounds");
}

void GfxGammaRamp::clear(void)
{
    int32_t index;

    for (index = 0; index < kGammaRampNumberOfElements; index++)
    {
        gammaRamp_[index] = kInvalidValue;
    }
}

GfxGammaRamp::SdlTypePtr GfxGammaRamp::getAsSdlTypePtr(void) const
{
    return const_cast<SdlTypePtr>(&gammaRamp_[0]);
}

}  // namespace supp

}  // namespace gfx

/* EOF */