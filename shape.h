/* shape.h */

#ifndef _Shape_H_
#define _Shape_H_

#include <iostream>
using namespace std;

// Define a color type
enum ColorType
{
    BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, LIGHTGRAY, DARKGRAY,
    LIGHTBLUE, LIGHTGREEN, LIGHTCYAN, LIGHTRED, LIGHTMAGENTA, YELLOW, WHITE    
};

// Shape class interface
class Shape
{
    protected:
        float locX, locY;
        ColorType fColor;
        ColorType bColor;
        bool filled;


    public:
        // Constructor
        Shape( float float, ColorType, ColorType, bool);

        // Destructor
        virtual ~Shape();

        // Move object
        void moveTo( float, float );
        
        // Change color of the object
        void changeColor( ColorType );

        // Print, draw, and erase methods:
        virtual void print( ostream& ) const = 0;
        virtual void draw() const = 0;
        virtual void erase() const = 0;
};

#endif
