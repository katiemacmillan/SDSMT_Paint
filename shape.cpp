/* shape.cpp */

#include "headers.h"

// consntructor
Shape :: Shape( float x, float y, const float* bC ) : locX( x ), locY( y ),bColor( bC )
{}

// destructor
Shape :: ~Shape()
{}

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
