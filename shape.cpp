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

// move shape
///move the center point??
void Shape :: moveTo( float x, float y )
{}

///something with the linked list here
void Shape :: erase()
{}
