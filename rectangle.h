/* rectangle.h */

#ifndef _Rectangle_H_
#define _Rectangle_H_

#include "shape.h"
#include "globals.h"

class Rectangle : public Shape
{
    private:
        float width, height;
        bool filled;

    public:
        // constructor
        Rectangle( float x = 0.0, float y = 0.0, const float* bColor = Black, const float* fColor = Black, float w = 1.0, float h = 1.0, bool f = false );
        
        // destructor
        ~Rectangle();

        // change the dimensions of the rectangle
        void changeDimensions( float, float );
        
        // draw the rectangle, overridding the shape draw
        void draw() const;
};

#endif
