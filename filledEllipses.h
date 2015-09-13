/* filledEllipses.h */

#ifndef _Ellipses_H_
#define _Ellipses_H_

//#include "ellipses.h"
#include "shape.h"

// Filled ellipses class interface
// Do we need a lot of these? Or can we just use ellipses's draw and just hold the fill color in here?
class FilledEllipses : public Shape
{
    private: 
        float xRadius, yRadius;
        ColorType cBorder, cFill;

    public:
        FilledEllipses( float x = 0.0, float y = 0.0, ColorType cBorder = ColorType( 0 ), ColorType cFill = ColorType( 0 ), float xRaius = 1.0, float yRadius = 1.0 );
        ~FilledEllipses();
        void moveTo( float x, float y );
        void changeBorderColor( ColorType c );
        void changeFillColor( ColorType c );
        void changeDimensions( float xRadius, float yRadius );
        void draw() const;
        void erase() const;
        void print( ostream& out ) const;
};

#endif
