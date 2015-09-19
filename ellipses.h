/* ellipses.h */

#ifndef _Ellipses_H_
#define _Ellipses_H_

#include "shape.h"

class Ellipse : public Shape
{
    private: 
        float xRadius, yRadius;

    public:
        Ellipses( float, float, float, float, float[], float[], bool, float, float );
        ~Ellipses();
        void changeDimensions( float, float );
        void draw() const;
};

#endif
