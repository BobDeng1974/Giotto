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

#ifndef GfxWindowFlags_hpp
#define GfxWindowFlags_hpp

#include "GfxRootClass.hpp"
#include "GfxSdlHeader.hpp"

class GfxWindowFlags final : public GfxRootClass
{
public:
    typedef SDL_WindowFlags SdlType;
    typedef SDL_WindowFlags* SdlTypePtr;

    enum class GfxWindowFlagsValues : uint32_t
    {
        windowFlagUnknown = 0,
        windowFlagFullscreen = SDL_WINDOW_FULLSCREEN,
        windowFlagOpenGL = SDL_WINDOW_OPENGL,
        windowFlagShown = SDL_WINDOW_SHOWN,
        windowFlagHidden = SDL_WINDOW_HIDDEN,
        windowFlagBorderless = SDL_WINDOW_BORDERLESS,
        windowFlagResizable = SDL_WINDOW_RESIZABLE,
        windowFlagMinimized = SDL_WINDOW_MINIMIZED,
        windowFlagMaximized = SDL_WINDOW_MAXIMIZED,
        windowFlagInputGrabbed = SDL_WINDOW_INPUT_GRABBED,
        windowFlagInputFocus = SDL_WINDOW_INPUT_FOCUS,
        windowFlagMouseFocus = SDL_WINDOW_MOUSE_FOCUS,
        windowFlagFullscreenDesktop = SDL_WINDOW_FULLSCREEN_DESKTOP,
        windowFlagForeign = SDL_WINDOW_FOREIGN,
        windowFlagAllowHighDPI = SDL_WINDOW_ALLOW_HIGHDPI,
        windowFlagMouseCapture = SDL_WINDOW_MOUSE_CAPTURE,
        // X11 only
        windowAlwaysOnTop = SDL_WINDOW_ALWAYS_ON_TOP,
        windowSkipTaskbar = SDL_WINDOW_SKIP_TASKBAR,
        windowUtility = SDL_WINDOW_UTILITY,
        windowTooltip = SDL_WINDOW_TOOLTIP,
        windowPopupMenu = SDL_WINDOW_POPUP_MENU
    };

    GfxWindowFlags();
    explicit GfxWindowFlags(GfxWindowFlagsValues flag);
    explicit GfxWindowFlags(SdlType flag);
    explicit GfxWindowFlags(SdlTypePtr flag);
    GfxWindowFlags(GfxWindowFlags const& other);
    GfxWindowFlags(GfxWindowFlags&& other);

    GfxWindowFlags& operator=(GfxWindowFlags const& other);
    GfxWindowFlags& operator=(GfxWindowFlags&& other);

    bool isUnkown(void) const;
    bool isFullscreen(void) const;
    bool isOpenGL(void) const;
    bool isShown(void) const;
    bool isHidden(void) const;
    bool isBorderless(void) const;
    bool isResizable(void) const;
    bool isMinimized(void) const;
    bool isMaximized(void) const;
    bool isInputGrabbed(void) const;
    bool isInputFocus(void) const;
    bool isMouseFocus(void) const;
    bool isFullscreenDesktop(void) const;
    bool isForeign(void) const;
    bool allowHighDPI(void) const;
    bool mouseCapture(void) const;
    // X11 only
    bool isAlwaysOnTop(void) const;
    bool skipTaskbar(void) const;
    bool isUtility(void) const;
    bool isTooltip(void) const;
    bool isPopupMenu(void) const;

    void setFullscreen(void);
    void resetFullscreen(void);
    void setOpenGL(void);
    void resetOpenGL(void);
    void setShown(void);
    void resetShown(void);
    void setHidden(void);
    void resetHidden(void);
    void setBorderless(void);
    void resetBorderless(void);
    void setResizable(void);
    void resetResizable(void);
    void setMinimized(void);
    void resetMinimized(void);
    void setMaximized(void);
    void resetMaximized(void);
    void setInputGrabbed(void);
    void resetInputGrabbed(void);
    void setInputFocus(void);
    void resetInputFocus(void);
    void setMouseFocus(void);
    void resetMouseFocus(void);
    void setFullscreenDesktop(void);
    void resetFullscreenDesktop(void);
    void setForeign(void);
    void resetForeign(void);
    void setAllowHighDPI(void);
    void resetAllowHighDPI(void);
    void setMouseCapture(void);
    void resetMouseCapture(void);
    // X11 only
    void setAlwaysOnTop(void);
    void resetAlwaysOnTop(void);
    void setSkipTaskbar(void);
    void resetSkipTaskbar(void);
    void setUtility(void);
    void resetUtility(void);
    void setTooltip(void);
    void resetTooltip(void);
    void setPopupMenu(void);
    void resetPopupMenu(void);

    SdlType getAsSdlType(void) const;
    SdlTypePtr getAsSdlTypePtr(void) const;
private:
    SdlType flags_;
};

#endif /* GfxWindowFlags_hpp */
