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

#ifndef GfxTextSettingsType_hpp
#define GfxTextSettingsType_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxCanvasBgi.hpp"
#include "GfxFonts.hpp"
#include "GfxDirection.hpp"
#include "GfxTextJustification.hpp"

namespace gfx
{

namespace bgi
{

class GfxTextSettingsType final : public GfxObject
{
public:
    typedef prv::GfxCanvasBgi::textsettingstype BgiType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    GfxTextSettingsType() noexcept;

    explicit GfxTextSettingsType(const BgiType textsettings) noexcept;

    GfxTextSettingsType(const GfxTextSettingsType& other) noexcept;
    GfxTextSettingsType(GfxTextSettingsType&& other) noexcept;

    GfxTextSettingsType& operator=(const GfxTextSettingsType& other) noexcept;
    GfxTextSettingsType& operator=(GfxTextSettingsType&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    const GfxFonts getFont(void) const noexcept;
    const GfxDirection getDirection(void) const noexcept;
    int32_t getCharSize(void) const noexcept;
    const GfxTextJustification getHorizontalJustification(void) const noexcept;
    const GfxTextJustification getVerticalJustification(void) const noexcept;
    void setValue(const BgiType textsettings) noexcept;

    void clear(void) noexcept;

    BgiType getAsBgiType(void) const noexcept;
private:
    BgiType textSettings_;
};

}  // namespace bgi

}  // namespace gfx

#endif /* GfxTextSettingsType_hpp */
