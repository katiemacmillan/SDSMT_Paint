/* ellipses.h */

#ifndef _Ellipses_H_
#define _Ellipses_H_

#include "shape.h"

class Ellipse : public Shape
{
    private: 
        float xRadius, yRadius;
        ColorType c;

    public:
        Ellipses( float, float, ColorType, float, float);
        ~Ellipses();
        void moveTo( float, float );
        void changeColor( ColorType );
        void changeDimensions( float, float );
        void draw() const;
        void erase() const;
        void print( ostream& ) const;
};

#endif
