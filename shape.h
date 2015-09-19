/* shape.h */

#ifndef _Shape_H_
#define _Shape_H_

#include <iostream>
using namespace std;

struct ShapeNode
{
    Shape shapeObj;
    ShapeNode* next;
};

// Shape class interface
class Shape
{
    protected:

        //Draw points
        float X1, Y1, X2, Y2;
        //Center Point
        float Xc, Yc;
        //filled color
        float fColor[];
        //border color
        float bColor[];
        bool filled;


    public:
        // Constructor
        Shape( float, float,float, float, float[], float[], bool);

        // Destructor
        virtual ~Shape();

        // Move object
        void moveTo( float, float );
        
        // Change color of the object
        void changeColor( float[] );

        //Erase a selected shape
        void erase();

        // Draw, a shape object
        virtual void draw() const = 0;
        
};

#endif
