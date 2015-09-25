/* shape.cpp */

#include "shape.h"

// consntructor
Shape :: Shape( float x, float y, const float* bC ) : locX( x ), locY( y ), bColor( bC )
{}

// destructor
Shape :: ~Shape()
{}

// set the center point of the shape
void Shape :: setCenterCoordinate( float x, float y )
{
    locX = x;
    locY = y;
}

// change the border color
void Shape :: setBorderColor( const float* bC )
{
    bColor = bC;
}

float Shape :: getCenterX(){return locX;}
float Shape :: getCenterY(){return locY;}
const float* Shape :: getBorderColor(){return bColor;}
