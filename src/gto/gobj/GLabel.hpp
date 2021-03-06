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

#ifndef GLabel_hpp
#define GLabel_hpp

#include <stdexcept>
#include <cstdint>
#include <string>

#include "GComponent.hpp"
#include "GGraphicControl.hpp"
#include "GTypes.hpp"
#include "GfxFontInfo.hpp"

namespace gto
{

namespace gobj
{

class GLabel : public GGraphicControl
{
public:
    GLabel() = delete;

    GLabel(const GLabel& other) = delete;
    GLabel(GLabel&& other) = delete;

    GLabel& operator=(const GLabel& other) = delete;
    GLabel& operator=(GLabel&& other) = delete;

    explicit GLabel(const std::string& vname, GComponent* owner, const uint16_t width, const uint16_t height,
                    const std::string& text, const uint8_t textsize);

    const std::string getText(void) const noexcept;
    void setText(const std::string& text) noexcept;

    gfx::xtra::GfxFontInfo& getFontInfo(void) noexcept;
    void setFontInfo(const gfx::xtra::GfxFontInfo& fontinfo) noexcept;

    GTextRenderMode getTextRenderMode(void) const noexcept;
    void setTextRenderMode(const GTextRenderMode& textrendermode) noexcept;

    virtual void draw(void);
protected:
    GTextRenderMode textRenderMode_;

    static const GTextRenderMode kDefaultTextRenderMode = GTextRenderMode::solidText;
private:
    std::string text_;
    gfx::xtra::GfxFontInfo fontInfo_;
};

}  // namespace gobj

}  // namespace gto

#endif /* GLabel_hpp */
