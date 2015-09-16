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
        FilledEllipses( float, float, ColorType, ColorType, float, float );
        ~FilledEllipses();
        void moveTo( float, float );
        void changeBorderColor( ColorType );
        void changeFillColor( ColorType );
        void changeDimensions( float, float );
        void draw() const;
        void erase() const;
        void print( ostream& ) const;
};

#endif
