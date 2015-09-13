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
        FilledRectangle( float x = 0.0, float y = 0.0, ColorType cBorder = ColorType( 0 ), ColorType cFill = ColorType( 0 ), float w = 1.0, float h = 1.0 );
        ~FilledRectangle();
        void moveTo( float x, float y );
        void changeFillColor( ColorType c );
        void changeDimensions( float w, float h );
        void draw() const;
        void erase() const;
        void print( ostream& out ) const;
};

#endif
