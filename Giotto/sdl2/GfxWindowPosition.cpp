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

#include "GfxWindowPosition.hpp"

GfxWindowPosition::GfxWindowPosition() : GfxRootClass("GfxWindowPosition")
{
    pos_ = GfxWindowPositionValues::positionUndefined;
    coord_ = -1;
}

GfxWindowPosition::GfxWindowPosition(GfxWindowPositionValues pos,uint32_t coord) : GfxRootClass("GfxWindowPosition")
{
    pos_ = pos;
    if (pos_ == GfxWindowPosition::GfxWindowPositionValues::positionSpecified)
    {
        if ((coord > 0) && (coord <= 16384))
        {
            coord_ = coord;
        }
        else
        {
            coord_ = 100;
        }
    }
}

GfxWindowPosition::GfxWindowPosition(GfxWindowPosition const& other) : GfxRootClass("GfxWindowPosition")
{
    pos_ = other.pos_;
    coord_ = other.coord_;
}

GfxWindowPosition::GfxWindowPosition(GfxWindowPosition&& other) : GfxRootClass("GfxWindowPosition")
{
    pos_ = other.pos_;
    coord_ = other.coord_;
    // Delete other's data
    other.pos_ = GfxWindowPositionValues::positionUndefined;
    other.coord_ = -1;
}

GfxWindowPosition& GfxWindowPosition::operator=(GfxWindowPosition const& other)
{
    if (this != &other)
    {
        pos_ = other.pos_;
        coord_ = other.coord_;
    }
    return *this;
}

GfxWindowPosition& GfxWindowPosition::operator=(GfxWindowPosition&& other)
{
    if (this != &other)
    {
        pos_ = other.pos_;
        coord_ = other.coord_;
        // Delete other's data
        other.pos_ = GfxWindowPositionValues::positionUndefined;
        other.coord_ = -1;
    }
    return *this;
}

void GfxWindowPosition::setPosition(GfxWindowPositionValues pos)
{
    pos_ = pos;
}

GfxWindowPosition::GfxWindowPositionValues GfxWindowPosition::getPosition(void) const
{
    return pos_;
}

void GfxWindowPosition::setCoordinate(uint32_t coord)
{
    coord_ = coord;
}

uint32_t GfxWindowPosition::getCoordinate(void) const
{
    uint32_t ret;
    
    switch (pos_)
    {
        case GfxWindowPositionValues::positionUndefined:
            ret = SDL_WINDOWPOS_UNDEFINED;
            break;
        case GfxWindowPositionValues::positionCentered:
            ret = SDL_WINDOWPOS_CENTERED;
            break;
        case GfxWindowPositionValues::positionSpecified:
            ret = coord_;
            break;
        default:
            ret = SDL_WINDOWPOS_UNDEFINED;
            break;
    }
    return ret;
}