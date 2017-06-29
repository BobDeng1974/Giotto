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
#include <cstring>

#include "GfxBitmapFont.hpp"
#include "GfxBasicLogger.hpp"

namespace gfx
{

namespace bgi
{

namespace fnt
{

const char GfxBitmapFont::ClassName[] = "GfxBitmapFont";

GfxBitmapFont::GfxBitmapFont() noexcept : GfxObject(ClassName), fontData_(nullptr),
        fontDataSize_(0), fontWidth_(0), fontHeight_(0)
{
    TRACE_P0();
}

GfxBitmapFont::GfxBitmapFont(const uint8_t * fontData, const uint8_t fontWidth, const uint8_t fontHeight)
        noexcept : GfxObject(ClassName)
{
    TRACE_P0();
    assert(fontData != nullptr);
    assert(fontWidth > 0);
    assert(fontHeight > 0);

    fontWidth_ = 0;
    fontHeight_ = 0;
    fontDataSize_ = 0;
    fontData_ = nullptr;

    if (((fontWidth % 8) == 0) && ((fontHeight % 8) == 0))
    {
        fontWidth_ = fontWidth;
        fontHeight_ = fontHeight;
        fontDataSize_ = fontWidth / 8 * fontHeight * 256;
        fontData_ = new uint8_t[fontDataSize_];
        std::memcpy(fontData_, fontData, fontDataSize_);
    }
}

GfxBitmapFont::GfxBitmapFont(GfxBitmapFont const& other) noexcept : GfxObject(ClassName)
{
    TRACE_P0();
    fontWidth_ = other.fontWidth_;
    fontHeight_ = other.fontHeight_;
    fontDataSize_ = other.fontDataSize_;
    fontData_ = new uint8_t[fontDataSize_];
    std::memcpy(fontData_, other.fontData_, fontDataSize_);
}

GfxBitmapFont::GfxBitmapFont(GfxBitmapFont&& other) noexcept : GfxObject(ClassName)
{
    TRACE_P0();
    fontWidth_ = other.fontWidth_;
    fontHeight_ = other.fontHeight_;
    fontDataSize_ = other.fontDataSize_;
    fontData_ = other.fontData_;
    // Delete other's data
    other.fontWidth_ = 0;
    other.fontHeight_ = 0;
    other.fontDataSize_ = 0;
    other.fontData_ = nullptr;
}

GfxBitmapFont::~GfxBitmapFont() noexcept
{
    TRACE_P0();
    if (fontData_ != nullptr)
    {
        delete[] fontData_;
    }
}

GfxBitmapFont& GfxBitmapFont::operator=(GfxBitmapFont const& other) noexcept
{
    TRACE_P0();
    if (this != &other)
    {
        fontWidth_ = other.fontWidth_;
        fontHeight_ = other.fontHeight_;
        if (fontData_ != nullptr)
        {
            delete[] fontData_;
        }
        fontDataSize_ = other.fontDataSize_;
        fontData_ = new uint8_t[fontDataSize_];
        std::memcpy(fontData_, other.fontData_, fontDataSize_);
    }
    return *this;
}

GfxBitmapFont& GfxBitmapFont::operator=(GfxBitmapFont&& other) noexcept
{
    TRACE_P0();
    if (this != &other)
    {
        fontWidth_ = other.fontWidth_;
        fontHeight_ = other.fontHeight_;
        fontDataSize_ = other.fontDataSize_;
        fontData_ = other.fontData_;
        // Delete other's data
        other.fontWidth_ = 0;
        other.fontHeight_ = 0;
        other.fontDataSize_ = 0;
        other.fontData_ = nullptr;
    }
    return *this;
}

GfxBitmapFont::operator bool() const noexcept
{
    TRACE_P0();
    return (fontData_ != nullptr);
}

uint8_t * GfxBitmapFont::getFontData(void) const noexcept
{
    TRACE_P0();
    return fontData_;
}

uint16_t GfxBitmapFont::getFontDataSize(void) const noexcept
{
    TRACE_P0();
    return fontDataSize_;
}

uint8_t GfxBitmapFont::getFontWidth(void) const noexcept
{
    TRACE_P0();
    return fontWidth_;
}

uint8_t GfxBitmapFont::getFontHeight(void) const noexcept
{
    TRACE_P0();
    return fontHeight_;
}

}  // namespace fnt

}  // namespace bgi

}  // namespace gfx

/* EOF */
