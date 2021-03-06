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

#ifndef GfxHitTest_hpp
#define GfxHitTest_hpp

#include <string>

#include "GfxObject.hpp"
#include "GfxHitTestResult.hpp"
#include "GfxPoint.hpp"

namespace gfx
{

namespace video
{

class GfxHitTest : public GfxObject
{
public:
    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    GfxHitTest() noexcept;

    virtual ~GfxHitTest() noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    virtual const GfxHitTestResult& operator()(void * win, rect::GfxPoint * area) noexcept = 0;
};

}  // namespace video

}  // namespace gfx

#endif /* GfxHitTest_hpp */
