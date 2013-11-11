//
//  FTColor.h
//  ftgles
//
//  Created by Sergey Fedortsov on 12.11.13.
//
//

#ifndef ftgles_FTColor_h
#define ftgles_FTColor_h

#ifndef __ftgl__
#   warning This header is deprecated. Please use <FTGL/ftgl.h> from now.
#   include <FTGL/ftgl.h>
#endif

/**
 * FTColor class is a basic RGBA color.
 */
class FTGL_EXPORT FTColor
{
public:
    /**
     * Default constructor. Color is set to absolutely white.
     */
    FTColor() : r_(1.0), g_(1.0), b_(1.0), a_(1.0) {}
    
    /**
     * RGBA constructor. Alpha channel is set to 255 if unspecified.
     *
     * @param r Red channel (0 .. 255)
     * @param g Green channel (0 .. 255)
     * @param b Blue channel (0 .. 255)
     * @param a Alpha channel (0 .. 255)
     */
    FTColor(const FTGL_BYTE r, const FTGL_BYTE g, const FTGL_BYTE b, const FTGL_BYTE a = 255)
        : r_(r), g_(g), b_(b), a_(a) {}

    
    /**
     * RGBA constructor. Alpha channel is set to 1.0 if unspecified.
     *
     * @param r Red channel (0 .. 1.0)
     * @param g Green channel (0 .. 1.0)
     * @param b Blue channel (0 .. 1.0)
     * @param a Alpha channel (0 .. 1.0)
     */
    FTColor(const FTGL_FLOAT r, const FTGL_FLOAT g, const FTGL_FLOAT b, const FTGL_FLOAT a = 1.0f)
    : r_(r * 0xff), g_(g * 0xff), b_(b * 0xff), a_(a * 0xff) {}
    
    /**
     Getters
     */
    FTGL_BYTE Red() { return r_; }
    FTGL_BYTE Green() { return g_; }
    FTGL_BYTE Blue() { return b_; }
    FTGL_BYTE Alpha() { return a_; }
    
private:
    FTGL_BYTE r_, g_, b_, a_;
};

#endif
