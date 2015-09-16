/* filledRectangle.h */

#ifndef _FilledRectangle_H_
#define _FilledRectangle_H_

#include "shape.h"
//#include "rectangle.h"

// Filled Rectangle class interface
// Do we need all of these methods or do we just need to hold the fill color?
class FilledRectangle : public Shape
{
    private:
        float width, height;
        ColorType cBorder, cFill;

    public:
        FilledRectangle( float, float, ColorType, ColorType, float, float );
        ~FilledRectangle();
        void moveTo( float, float );
        void changeBorderColor (ColorType);
        void changeFillColor( ColorType );
        void changeDimensions( float, float );
        void draw() const;
        void erase() const;
        void print( ostream& ) const;
};

#endif
