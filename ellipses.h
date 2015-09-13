/* ellipses.h */

#ifndef _Ellipses_H_
#define _Ellipses_H_

#include "shape.h"

class Ellipses : public Shape
{
    private: 
        float xRadius, yRadius;
        ColorType c;

    public:
        Ellipses( float x = 0.0, float y = 0.0, ColorType c = ColorType( 0 ); float xRaius = 1.0; float yRadius = 1.0 );
        ~Ellipses();
        void moveTo( float x, float y );
        void changeColor( ColorType c );
        void changeDimensions( float xRadius, float yRadius );
        void draw() const;
        void erase() const;
        void print( ostream& out ) const;
};
