/* shape.h */

#ifndef _Shape_H_
#define _Shape_H_

#include "globals.h"

class Shape
{
    protected:
        // center point of the shape
        float locX, locY;
        const float* bColor; 
        
    public:
        // constructor
        Shape( float x = 0.0, float y = 0.0, const float* bC = Black );
        
        // destructor
        virtual ~Shape();
        
        // move object
        void moveTo( float, float );

        // change border color
        void setBorderColor( const float* );

        // set the center point of the shape
        void setCenterCoordinate( float, float );

        // erase shape
        void erase();

        // draw shape object, must be overridden
        virtual void draw() const = 0;
};

//extern vector<Shape*> drawnShapes;
extern Shape* currentShape;
extern Shape* colorPalette;
#endif
