/* shape.cpp */

#include "shape.h"

/**********************************************************************
                            Constructor
**********************************************************************/
Shape :: Shape( float x, float y, const float* bC ) : locX( x ), locY( y ), bColor( bC )
{}

/**********************************************************************
                            Copy Constructor
**********************************************************************/
Shape :: Shape( const Shape& s ) : locX( s.locX ), locY( s.locY ), bColor( s.bColor )
{}

/**********************************************************************
                            Destructor
**********************************************************************/
Shape :: ~Shape()
{}

/**********************************************************************
                            get*
**********************************************************************
These get functions retrieve the individual components of the shape
object
**********************************************************************/
float Shape :: getCenterX(){ return locX; }
float Shape :: getCenterY(){ return locY; }
const float* Shape :: getBorderColor(){ return bColor; }

/**********************************************************************
                            set*
**********************************************************************
These set functions set the individual components of the shape object
to new values
**********************************************************************/
void Shape :: setCenterCoordinate( float x, float y )
{
    locX = x;
    locY = y;
}

void Shape :: setBorderColor( const float* bC )
{
    bColor = bC;
}

/**********************************************************************
                            moveTo
**********************************************************************
moveTo is a virtual function which will be over written in derived 
classes to change the center point and redraw a shape object
**********************************************************************/
void Shape :: moveTo (float x, float y)
{}
