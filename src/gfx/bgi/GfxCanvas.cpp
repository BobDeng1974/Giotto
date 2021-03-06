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
#include <cstring>
#include <string>
#include <cmath>
#include <vector>

#include "GfxCanvas.hpp"
#include "GfxBgiConstants.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxcanvas::bgi::gfx");

namespace gfx
{

namespace bgi
{

const char GfxCanvas::ClassName[] = "GfxCanvas";

GfxCanvas::GfxCanvas(const surface::GfxSurface& surf) noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    assert(surf);

    bgi_.setCanvas(static_cast<uint32_t *>(surf.getAsSdlTypePtr()->pixels), surf.getAsSdlTypePtr()->w,
                    surf.getAsSdlTypePtr()->h);
}

GfxCanvas::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxCanvas::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

void GfxCanvas::Arc(const rect::GfxPoint& pt, const GfxAngle& stangle, const GfxAngle& endangle,
                    const GfxRadius& radius) noexcept
{
    LOG_TRACE_PRIO_MED();

    assert(pt);
    assert(stangle);
    assert(endangle);
    assert(radius);

    bgi_.arc(pt.getX(), pt.getY(), stangle.getValue(), endangle.getValue(), radius.getValue());
}

void GfxCanvas::Bar(const rect::GfxPoint& pt1, const rect::GfxPoint& pt2) noexcept
{
    LOG_TRACE_PRIO_MED();

    assert(pt1);
    assert(pt2);

    bgi_.bar(pt1.getX(), pt1.getY(), pt2.getX(), pt2.getY());
}

void GfxCanvas::Bar(const rect::GfxRect& r) noexcept
{
    LOG_TRACE_PRIO_MED();

    assert(r);

    bgi_.bar(r.getX(), r.getY(), r.getWidth() + 1, r.getHeight() + 1);
}

void GfxCanvas::Bar3D(const rect::GfxPoint& pt1, const rect::GfxPoint& pt2, const int32_t depth,
                      const bool topflag) noexcept
{
    LOG_TRACE_PRIO_MED();

    assert(pt1);
    assert(pt2);
    assert(depth > 0);

    int32_t int_topflag = static_cast<int32_t>(topflag);

    bgi_.bar3d(pt1.getX(), pt1.getY(), pt2.getX(), pt2.getY(), depth, int_topflag);
}

void GfxCanvas::Bar3D(const rect::GfxRect& r, const int32_t depth, const bool topflag) noexcept
{
    LOG_TRACE_PRIO_MED();

    assert(r);
    assert(depth > 0);

    int32_t int_topflag = static_cast<int32_t>(topflag);

    bgi_.bar3d(r.getX(), r.getY(), r.getWidth() + 1, r.getHeight() + 1, depth, int_topflag);
}

void GfxCanvas::Circle(const rect::GfxPoint& pt, const GfxRadius& r) noexcept
{
    LOG_TRACE_PRIO_MED();

    assert(pt);
    assert(r);

    bgi_.circle(pt.getX(), pt.getY(), r.getValue());
}

void GfxCanvas::ClearDevice(void) noexcept
{
    LOG_TRACE_PRIO_MED();

    bgi_.cleardevice();
}

void GfxCanvas::ClearViewPort(void) noexcept
{
    LOG_TRACE_PRIO_MED();

    bgi_.clearviewport();
}

void GfxCanvas::DrawPoly(const std::vector<rect::GfxPoint>& polypoints) noexcept
{
    LOG_TRACE_PRIO_MED();

    assert(polypoints.size() > 0);

    int * points = new int[polypoints.size() * 2];  // NOLINT
    int index = 0;

    for (const auto& it : polypoints)
    {
        points[index + 0] = it.getX();
        points[index + 1] = it.getY();
        index += 2;
    }
    bgi_.drawpoly(static_cast<int>(polypoints.size()), const_cast<int *>(points));
    delete[] points;
}

void GfxCanvas::Ellipse(const rect::GfxPoint& pt, const GfxAngle& stangle, const GfxAngle& endangle,
                        const GfxRadius& xradius, const GfxRadius& yradius) noexcept
{
    LOG_TRACE_PRIO_MED();

    assert(pt);
    assert(stangle);
    assert(endangle);
    assert(xradius);
    assert(yradius);

    bgi_.ellipse(pt.getX(), pt.getY(), stangle.getValue(), endangle.getValue(), xradius.getValue(),
                 yradius.getValue());
}

void GfxCanvas::FillEllipse(const rect::GfxPoint& pt, const GfxRadius& xradius, const GfxRadius& yradius) noexcept
{
    LOG_TRACE_PRIO_MED();

    assert(pt);
    assert(xradius);
    assert(yradius);

    bgi_.fillellipse(pt.getX(), pt.getY(), xradius.getValue(), yradius.getValue());
}

void GfxCanvas::FillPoly(const std::vector<rect::GfxPoint>& polypoints) noexcept
{
    LOG_TRACE_PRIO_MED();

    assert(polypoints.size() > 0);

    int * points = new int[polypoints.size() * 2];  // NOLINT
    int index = 0;

    for (const auto& it : polypoints)
    {
        points[index + 0] = it.getX();
        points[index + 1] = it.getY();
        index += 2;
    }
    bgi_.fillpoly(static_cast<int>(polypoints.size()), const_cast<int *>(points));
    delete[] points;
}

void GfxCanvas::FloodFill(const rect::GfxPoint& pt, const GfxColors2& border) noexcept
{
    LOG_TRACE_PRIO_MED();

    assert(pt);
    assert(border);

    prv::GfxCanvasBgi::bgiColors color;

    if (border.isCustomColor() == true)
    {
        color = prv::GfxCanvasBgi::CUSTOM_FILL;
        bgi_.setCustomFillColor(border.getValue());
    }
    else
    {
        color = border.getAsBgiType();
    }
    bgi_.floodfill(pt.getX(), pt.getY(), color);
}

void GfxCanvas::FreeImage(void * bitmap) noexcept
{
    LOG_TRACE_PRIO_MED();

    assert(bitmap != nullptr);

    bgi_.freeimage(bitmap);
}

const GfxArcCoordsType GfxCanvas::GetArcCoords(void) noexcept
{
    LOG_TRACE_PRIO_MED();

    struct prv::GfxCanvasBgi::arccoordstype arccoords;

    bgi_.getarccoords(&arccoords);
    return GfxArcCoordsType(arccoords);
}

const GfxColors2& GfxCanvas::GetBkColor(void) noexcept
{
    LOG_TRACE_PRIO_MED();

    prv::GfxCanvasBgi::bgiColors clr = bgi_.getbkcolor();
    GfxColors2::ValueType retclr;

    if (clr == prv::GfxCanvasBgi::CUSTOM_BG)
    {
        retclr = bgi_.getCustomBackgroundColor();
    }
    else
    {
        retclr = clr;
    }
    prvColor_.setValue(retclr);
    return prvColor_;
}

const GfxColors2& GfxCanvas::GetColor(void) noexcept
{
    LOG_TRACE_PRIO_MED();

    prv::GfxCanvasBgi::bgiColors clr = bgi_.getcolor();
    GfxColors2::ValueType retclr;

    if (clr == prv::GfxCanvasBgi::CUSTOM_FG)
    {
        retclr = bgi_.getCustomForegroundColor();
    }
    else
    {
        retclr = clr;
    }
    prvColor_.setValue(retclr);
    return prvColor_;
}

const GfxPaletteType GfxCanvas::GetDefaultPalette(void) noexcept
{
    LOG_TRACE_PRIO_MED();

    struct prv::GfxCanvasBgi::palettetype * palette_ptr;
    struct prv::GfxCanvasBgi::palettetype palette;

    palette_ptr = bgi_.getdefaultpalette();
    palette.size = palette_ptr->size;
    std::memcpy(palette.colors, palette_ptr->colors, prv::GfxCanvasBgi::kMaxColors + 1);
    return GfxPaletteType(palette);
}

void GfxCanvas::GetFillPattern(char * pattern) noexcept
{
    LOG_TRACE_PRIO_MED();

    assert(pattern != nullptr);

    bgi_.getfillpattern(pattern);
}

const GfxFillSettingsType GfxCanvas::GetFillSettings(void) noexcept
{
    LOG_TRACE_PRIO_MED();

    struct prv::GfxCanvasBgi::fillsettingstype * fill_ptr = nullptr;
    struct prv::GfxCanvasBgi::fillsettingstype fill;

    bgi_.getfillsettings(fill_ptr);
    fill.pattern = fill_ptr->pattern;
    fill.color = fill_ptr->color;
    return GfxFillSettingsType(fill);
}

void GfxCanvas::GetImage(const rect::GfxPoint& pt1, const rect::GfxPoint& pt2, void * bitmap) noexcept
{
    LOG_TRACE_PRIO_MED();

    assert(pt1);
    assert(pt2);
    assert(bitmap != nullptr);

    bgi_.getimage(pt1.getX(), pt1.getY(), pt2.getX(), pt2.getY(), bitmap);
}

void GfxCanvas::GetImage(const rect::GfxRect& r, void * bitmap) noexcept
{
    LOG_TRACE_PRIO_MED();

    assert(r);
    assert(bitmap != nullptr);

    bgi_.getimage(r.getX(), r.getY(), r.getWidth() + 1, r.getHeight() + 1, bitmap);
}

const GfxLineSettingsType GfxCanvas::GetLineSettings(void) noexcept
{
    LOG_TRACE_PRIO_MED();

    struct prv::GfxCanvasBgi::linesettingstype linesettings;

    bgi_.getlinesettings(&linesettings);
    return GfxLineSettingsType(linesettings);
}

int32_t GfxCanvas::GetMaxColor(void) noexcept
{
    LOG_TRACE_PRIO_MED();

    return bgi_.getmaxcolor();
}

int32_t GfxCanvas::GetMaxX(void) noexcept
{
    LOG_TRACE_PRIO_MED();

    return bgi_.getmaxx();
}

int32_t GfxCanvas::GetMaxY(void) noexcept
{
    LOG_TRACE_PRIO_MED();

    return bgi_.getmaxy();
}

const GfxPaletteType GfxCanvas::GetPalette(void) noexcept
{
    LOG_TRACE_PRIO_MED();

    struct prv::GfxCanvasBgi::palettetype palette;

    bgi_.getpalette(&palette);
    return GfxPaletteType(palette);
}

int32_t GfxCanvas::GetPaletteSize(void) noexcept
{
    LOG_TRACE_PRIO_MED();

    return bgi_.getpalettesize();
}

const GfxColors2& GfxCanvas::GetPixel(const rect::GfxPoint& pt) noexcept
{
    LOG_TRACE_PRIO_MED();

    assert(pt);

    prvColor_.setValue(bgi_.getpixel(pt.getX(), pt.getY()));
    return prvColor_;
}

const GfxTextSettingsType GfxCanvas::GetTextSettings(void) noexcept
{
    LOG_TRACE_PRIO_MED();

    struct prv::GfxCanvasBgi::textsettingstype textsettings;

    bgi_.gettextsettings(&textsettings);
    return GfxTextSettingsType(textsettings);
}

const GfxViewPortType GfxCanvas::GetViewSettings(void) noexcept
{
    LOG_TRACE_PRIO_MED();

    struct prv::GfxCanvasBgi::viewporttype viewport;

    bgi_.getviewsettings(&viewport);
    return GfxViewPortType(viewport);
}

int32_t GfxCanvas::GetX(void) noexcept
{
    LOG_TRACE_PRIO_MED();

    return bgi_.getx();
}

int32_t GfxCanvas::GetY(void) noexcept
{
    LOG_TRACE_PRIO_MED();

    return bgi_.gety();
}

void GfxCanvas::GraphDefaults(void) noexcept
{
    LOG_TRACE_PRIO_MED();

    bgi_.graphdefaults();
}

uint32_t GfxCanvas::ImageSize(const rect::GfxPoint& pt1, const rect::GfxPoint& pt2) noexcept
{
    LOG_TRACE_PRIO_MED();

    assert(pt1);
    assert(pt2);

    return bgi_.imagesize(pt1.getX(), pt1.getY(), pt2.getX(), pt2.getY());
}

uint32_t GfxCanvas::ImageSize(const rect::GfxRect& r) noexcept
{
    LOG_TRACE_PRIO_MED();

    assert(r);

    return bgi_.imagesize(r.getX(), r.getY(), r.getWidth() + 1, r.getHeight() + 1);
}

void GfxCanvas::Line(const rect::GfxPoint& pt1, const rect::GfxPoint& pt2) noexcept
{
    LOG_TRACE_PRIO_MED();

    assert(pt1);
    assert(pt2);

    bgi_.line(pt1.getX(), pt1.getY(), pt2.getX(), pt2.getY());
}

void GfxCanvas::LineRel(const rect::GfxPoint& pt) noexcept
{
    LOG_TRACE_PRIO_MED();

    assert(pt);

    bgi_.linerel(pt.getX(), pt.getY());
}

void GfxCanvas::LineTo(const rect::GfxPoint& pt) noexcept
{
    LOG_TRACE_PRIO_MED();

    assert(pt);

    bgi_.lineto(pt.getX(), pt.getY());
}

void GfxCanvas::MoveRel(const rect::GfxPoint& pt) noexcept
{
    LOG_TRACE_PRIO_MED();

    assert(pt);

    bgi_.moverel(pt.getX(), pt.getY());
}

void GfxCanvas::MoveTo(const rect::GfxPoint& pt) noexcept
{
    LOG_TRACE_PRIO_MED();

    assert(pt);

    bgi_.moveto(pt.getX(), pt.getY());
}

void GfxCanvas::OutText(const GfxText& text) noexcept
{
    LOG_TRACE_PRIO_MED();

    assert(text);

    bgi_.outtext(const_cast<char *>(text.getValue().c_str()));
}

void GfxCanvas::OutText(const GfxText& text, const fnt::GfxBitmapFont& font) noexcept
{
    LOG_TRACE_PRIO_MED();

    assert(text);
    assert(font);

    bgi_.setCustomFont(font.getFontData(), font.getFontWidth(), font.getFontHeight());
    bgi_.outtext(const_cast<char *>(text.getValue().c_str()));
    bgi_.setDefaultFont();
}

void GfxCanvas::OutTextXY(const rect::GfxPoint& pt, const GfxText& text, const fnt::GfxBitmapFont& font) noexcept
{
    LOG_TRACE_PRIO_MED();

    assert(pt);
    assert(text);
    assert(font);

    bgi_.setCustomFont(font.getFontData(), font.getFontWidth(), font.getFontHeight());
    bgi_.outtextxy(pt.getX(), pt.getY(), const_cast<char *>(text.getValue().c_str()));
    bgi_.setDefaultFont();
}

void GfxCanvas::OutTextXY(const rect::GfxPoint& pt, const GfxText& text) noexcept
{
    LOG_TRACE_PRIO_MED();

    assert(pt);
    assert(text);

    bgi_.outtextxy(pt.getX(), pt.getY(), const_cast<char *>(text.getValue().c_str()));
}

void GfxCanvas::PieSlice(const rect::GfxPoint& pt, const GfxAngle& stangle, const GfxAngle& endangle,
                         const GfxRadius& radius) noexcept
{
    LOG_TRACE_PRIO_MED();

    assert(pt);
    assert(stangle);
    assert(endangle);
    assert(radius);

    bgi_.pieslice(pt.getX(), pt.getY(), stangle.getValue(), endangle.getValue(), radius.getValue());
}

void GfxCanvas::PutImage(const rect::GfxPoint& pt, void * bitmap, const GfxDrawingMode& dmode) noexcept
{
    LOG_TRACE_PRIO_MED();

    assert(pt);
    assert(bitmap != nullptr);
    assert(dmode);

    bgi_.putimage(pt.getX(), pt.getY(), bitmap, dmode.getAsBgiType());
}

void GfxCanvas::PutPixel(const rect::GfxPoint& pt, const GfxColors2& clr) noexcept
{
    LOG_TRACE_PRIO_MED();

    assert(pt);

    GfxColors2::BgiType c;

    if (clr.isCustomColor() == true)
    {
        c = prv::GfxCanvasBgi::CUSTOM_FG;
        bgi_.setCustomForegroundColor(clr.getValue());
    }
    else
    {
        c = clr.getAsBgiType();
    }
    bgi_.putpixel(pt.getX(), pt.getY(), c);
}

void GfxCanvas::Rectangle(const rect::GfxPoint& pt1, const rect::GfxPoint& pt2) noexcept
{
    LOG_TRACE_PRIO_MED();

    assert(pt1);
    assert(pt2);

    bgi_.rectangle(pt1.getX(), pt1.getY(), pt2.getX(), pt2.getY());
}

void GfxCanvas::Rectangle(const rect::GfxRect& r) noexcept
{
    LOG_TRACE_PRIO_MED();

    assert(r);

    bgi_.rectangle(r.getX(), r.getY(), r.getWidth() + 1, r.getHeight() + 1);
}

void GfxCanvas::Sector(const rect::GfxPoint& pt, const GfxAngle& stangle, const GfxAngle& endangle,
                       const GfxRadius& xradius, const GfxRadius& yradius) noexcept
{
    LOG_TRACE_PRIO_MED();

    assert(pt);
    assert(stangle);
    assert(endangle);
    assert(xradius);
    assert(yradius);

    bgi_.sector(pt.getX(), pt.getY(), stangle.getValue(), endangle.getValue(),
                xradius.getValue(), yradius.getValue());
}

void GfxCanvas::SetAllPalette(const GfxPaletteType& palette) noexcept
{
    LOG_TRACE_PRIO_MED();

    assert(palette);

    GfxPaletteType::BgiType pal;

    pal = palette.getAsBgiType();
    bgi_.setallpalette(&pal);
}

void GfxCanvas::SetBkColor(const GfxColors2& clr) noexcept
{
    LOG_TRACE_PRIO_MED();

    assert(clr);

    GfxColors2::BgiType c;

    if (clr.isCustomColor() == true)
    {
        c = prv::GfxCanvasBgi::CUSTOM_BG;
        bgi_.setCustomBackgroundColor(clr.getValue());
    }
    else
    {
        c = clr.getAsBgiType();
    }
    bgi_.setbkcolor(c);
}

void GfxCanvas::SetColor(const GfxColors2& clr) noexcept
{
    LOG_TRACE_PRIO_MED();

    assert(clr);

    GfxColors2::BgiType c;

    if (clr.isCustomColor() == true)
    {
        c = prv::GfxCanvasBgi::CUSTOM_FG;
        bgi_.setCustomForegroundColor(clr.getValue());
    }
    else
    {
        c = clr.getAsBgiType();
    }
    bgi_.setcolor(c);
}

void GfxCanvas::SetFillPattern(uint8_t * upattern, const GfxColors2& clr) noexcept
{
    LOG_TRACE_PRIO_MED();

    assert(upattern != nullptr);

    GfxColors2::BgiType c;

    if (clr.isCustomColor() == true)
    {
        c = prv::GfxCanvasBgi::CUSTOM_FILL;
        bgi_.setCustomFillColor(clr.getValue());
    }
    else
    {
        c = clr.getAsBgiType();
    }
    bgi_.setfillpattern(upattern, c);
}

void GfxCanvas::SetFillStyle(const GfxFillStyles& pattern, const GfxColors2& clr) noexcept
{
    LOG_TRACE_PRIO_MED();

    assert(pattern);
    assert(clr);

    GfxColors2::BgiType c;

    if (clr.isCustomColor() == true)
    {
        c = prv::GfxCanvasBgi::CUSTOM_FILL;
        bgi_.setCustomFillColor(clr.getValue());
    }
    else
    {
        c = clr.getAsBgiType();
    }
    bgi_.setfillstyle(pattern.getAsBgiType(), c);
}

void GfxCanvas::SetLineStyle(const GfxLineStyle& linestyle, const GfxFillStyles& upattern,
                             const GfxLineThickness& thickness) noexcept
{
    LOG_TRACE_PRIO_MED();

    assert(linestyle);
    assert(upattern);
    assert(thickness);

    bgi_.setlinestyle(linestyle.getAsBgiType(), upattern.getAsBgiType(), thickness.getAsBgiType());
}

void GfxCanvas::SetPalette(int32_t colornum, const GfxColors2& clr) noexcept
{
    LOG_TRACE_PRIO_MED();

    assert(colornum >= 0);
    assert(clr);

    bgi_.setpalette(colornum, clr.getValue());
}

void GfxCanvas::SetTextJustify(const GfxTextJustification& horiz, const GfxTextJustification& vert) noexcept
{
    LOG_TRACE_PRIO_MED();

    assert(horiz);
    assert(vert);

    bgi_.settextjustify(horiz.getAsBgiType(), vert.getAsBgiType());
}

void GfxCanvas::SetTextStyle(const GfxFonts& font, const GfxDirection& direction, int32_t charsize) noexcept
{
    LOG_TRACE_PRIO_MED();

    assert(font);
    assert(direction);
    assert(charsize);

    bgi_.settextstyle(font.getAsBgiType(), direction.getAsBgiType(), charsize);
}

void GfxCanvas::SetUserCharSize(const int32_t multx, const int32_t divx, const int32_t multy,
                                const int32_t divy) noexcept
{
    LOG_TRACE_PRIO_MED();

    assert(multx > 0);
    assert(divx > 0);
    assert(multy > 0);
    assert(multy > 0);

    bgi_.setusercharsize(multx, divx, multy, divy);
}

void GfxCanvas::SetViewPort(const rect::GfxPoint& pt1, const rect::GfxPoint& pt2, const bool clip) noexcept
{
    LOG_TRACE_PRIO_MED();

    assert(pt1);
    assert(pt2);

    int32_t int_clip = static_cast<int32_t>(clip);

    bgi_.setviewport(pt1.getX(), pt1.getY(), pt2.getX(), pt2.getY(), int_clip);
}

void GfxCanvas::SetViewPort(const rect::GfxRect& r, const bool clip) noexcept
{
    LOG_TRACE_PRIO_MED();

    assert(r);

    int32_t int_clip = static_cast<int32_t>(clip);

    bgi_.setviewport(r.getX(), r.getY(), r.getWidth() + 1, r.getHeight() + 1, int_clip);
}

void GfxCanvas::SetWriteMode(const GfxDrawingMode& dmode) noexcept
{
    LOG_TRACE_PRIO_MED();

    assert(dmode);

    bgi_.setwritemode(dmode.getAsBgiType());
}

int32_t GfxCanvas::TextHeight(const GfxText& textstring) noexcept
{
    LOG_TRACE_PRIO_MED();

    assert(textstring);

    return bgi_.textheight(const_cast<char *>(textstring.getValue().c_str()));
}

int32_t GfxCanvas::TextWidth(const GfxText& textstring) noexcept
{
    LOG_TRACE_PRIO_MED();

    assert(textstring);

    return bgi_.textwidth(const_cast<char *>(textstring.getValue().c_str()));
}

}  // namespace bgi

}  // namespace gfx

/* EOF */
