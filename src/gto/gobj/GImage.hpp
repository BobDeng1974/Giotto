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

#ifndef GImage_hpp
#define GImage_hpp

#include <stdexcept>
#include <cstdint>
#include <string>

#include "GComponent.hpp"
#include "GGraphicControl.hpp"
#include "GTypes.hpp"

namespace gto
{

namespace gobj
{

class GImage : public GGraphicControl
{
public:
    GImage() = delete;

    GImage(const GImage& other) = delete;
    GImage(GImage&& other) = delete;

    GImage& operator=(const GImage& other) = delete;
    GImage& operator=(GImage&& other) = delete;

    explicit GImage(const std::string& vname, GComponent* owner, const uint16_t width, const uint16_t height);
    virtual ~GImage();

    GImageScaleMode getScaleMode(void) const noexcept;
    void setScaleMode(const GImageScaleMode& scalemode) noexcept;

    const std::string getFileName(void) const noexcept;
    void setFileName(const std::string& filename) noexcept;

    virtual void load(void) throw(std::runtime_error) = 0;
    virtual void draw(void);
protected:
    GImageScaleMode scaleMode_;
    std::string fileName_;

    static const GImageScaleMode kDefaultImageScaleMode = GImageScaleMode::centerScaled;
};

}  // namespace gobj

}  // namespace gto

#endif /* GImage_hpp */
