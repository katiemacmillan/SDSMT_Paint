/* shape.cpp */

#include "shape.h"

// consntructor
Shape :: Shape( float x, float y, const float* bC, const float* fC ) : locX( x ), locY( y ),bColor( bC ), fColor( fC )
{}

// destructor
Shape :: ~Shape()
{}

// change the border color
void Shape :: setBorderColor( const float* bC )
{
    bColor = bC;
}

// change the fill color
void Shape :: setFillColor( const float* fC )
{
    fColor = fC;
}

// move shape
///move the center point??
void Shape :: moveTo( float x, float y )
{}

///something with the linked list here
void Shape :: erase()
{}
