/* ellipses.h */

#ifndef _Ellipses_H_
#define _Ellipses_H_

#include "shape.h"

class Ellipse : public Shape
{
    private: 
        float xRadius, yRadius;
        float[] c;

    public:
        Ellipses( float, float, float[], float, float);
        ~Ellipses();
        void moveTo( float, float );
        void changeColor( float[] );
        void changeDimensions( float, float );
        void draw() const;
};

#endif
