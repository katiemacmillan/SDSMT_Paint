/* shape.h */

#ifndef _Shape_H_
#define _Shape_H_

#include "globals.h"

class Shape
{
    /******Class Data******/
    protected:
        // center point of the shape
        float locX, locY;
        const float* bColor; 
        
    public:
        /******Constructor******/
        Shape( float x = 0.0, float y = 0.0, const float* bC = Black );
        
        /******Copy Constructor******/
        Shape( const Shape& );
      
        /******Destructor******/
        virtual ~Shape();
        
        /******Get Functions******/
        float getCenterX();
        float getCenterY();
        const float* getBorderColor();

        /******Set Functions******/
        void setCenterCoordinate( float, float );
        void setBorderColor( const float* );

        /******Display Functions******/
        virtual void draw() const = 0;
        virtual void moveTo( float, float );

};

//extern vector<Shape*> drawnShapes;
extern Shape* currentShape;
extern Shape* colorPalette;
#endif
