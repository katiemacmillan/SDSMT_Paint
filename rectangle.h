/* rectangle.h */

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
        Rectangle( float, float, ColorType, float, float );
        ~Rectangle();
        void moveTo( float, float );
        void changeColor( ColorType );
        void changeDimensions( float, float );
        void draw() const;
        void erase() const;
        void print( ostream& ) const;
};

#endif
