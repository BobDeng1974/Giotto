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

#ifndef GfxBitmapOrder_hpp
#define GfxBitmapOrder_hpp

#include <cstdint>

#include "GfxRootClass.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace pixels
{

class GfxBitmapOrder : public gfx::GfxRootClass
{
public:
    typedef uint32_t SdlType;

    static const char ClassName[];

    enum class ValueType : uint32_t
    {
        bitmapOrderNone = sdl2::SDL_BITMAPORDER_NONE,
        bitmapOrder4321 = sdl2::SDL_BITMAPORDER_4321,
        bitmapOrder1234 = sdl2::SDL_BITMAPORDER_1234,
    };

    GfxBitmapOrder();
    explicit GfxBitmapOrder(ValueType value);
    explicit GfxBitmapOrder(SdlType value);

    GfxBitmapOrder(GfxBitmapOrder const& other);
    GfxBitmapOrder(GfxBitmapOrder&& other);

    GfxBitmapOrder& operator=(GfxBitmapOrder const& other);
    GfxBitmapOrder& operator=(GfxBitmapOrder&& other);

    virtual explicit operator bool() const;

    ValueType getValue(void) const noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const;
private:
    SdlType value_;
};

}  // namespace pixels

}  // namespace gfx

#endif /* GfxBitmapOrder_hpp */