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

#ifndef GfxBool_hpp
#define GfxBool_hpp

#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

class GfxBool final : public GfxObject
{
public:
    typedef SDL_bool SdlType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    enum class ValueType : bool
    {
        boolFalse = SDL_FALSE,
        boolTrue = SDL_TRUE
    };

    GfxBool() noexcept;

    explicit GfxBool(const ValueType value) noexcept;
    explicit GfxBool(const SdlType value) noexcept;
    explicit GfxBool(const bool value) noexcept;

    GfxBool(const GfxBool& other) noexcept;
    GfxBool(GfxBool&& other) noexcept;

    GfxBool& operator=(const GfxBool& other) noexcept;
    GfxBool& operator=(GfxBool&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    bool getValue(void) const noexcept;

    bool isFalse(void) const noexcept;
    bool isTrue(void) const noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
private:
    SdlType value_;
};

}  // namespace gfx

#endif /* GfxBool_hpp */
