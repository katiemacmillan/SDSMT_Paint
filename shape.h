/* shape.h */

#ifndef _Shape_H_
#define _Shape_H_

#include "globals.h"

class Shape
{
    protected:
        // center point of the shape
        float locX, locY;
        const float* bColor, fColor;

    public:
        // constructor
        Shape( float x = 0.0, float y = 0.0, const float* bC = Black, const float* fC = Black );
        
        // destructor
        virtual ~Shape();
        
        // move object
        void moveTo( float, float );

        // change border color
        void setBorderColor( const float* );
        void setFillColor( const float* );

        // erase shape
        void erase();

        // draw shape object, must be overridden
        virtual void draw() const = 0;
};

//extern vector<Shape*> drawnShapes;
extern Shape* currentShape;
extern Shape* colorPalette;
#endif
