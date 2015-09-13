#ifndef _Rectangle_H_
#define _Rectangle_H_

#include "shape.h"

// Rectangle class interface
// If we do decide to have filled rectange inherit from this, do we need to also make some of these methods virtual?
class Rectangle : public Shape
{
    private:
        float width, height;
        ColorType c;

    public:
        Rectangle( float x = 0.0, float y = 0.0, ColorType c = ColorType( 0 ), float x = 1.0, floah h = 1.0 );
        ~Rectangle();
        void moveTo( float x, float y );
        void changeColor( ColorType c );
        void changeDimensions( float w, float h );
        void draw() const;
        void erase() const;
        void print( ostream& out ) const;
};

#endif
