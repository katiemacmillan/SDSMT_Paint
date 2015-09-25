/* line.cpp */

#include <GL/freeglut.h>
#include "line.h"
#include "globals.h"

Line :: Line( float x, float y, const float* bC, float x1, float y1, float x2, float y2) : Shape( x, y, bC ), x1( x1 ), y1( y1 ), x2( x2 ), y2( y2 )
{}

Line :: ~Line()
{}

//
float Line :: getX1 (){return x1;}
float Line :: getY1 (){return y1;}
float Line :: getX2 (){return x2;}
float Line :: getY2 (){return y2;}

void Line :: setXY1(float x, float y)
{
	x1 = x;
	y1 = y;
}
void Line :: setXY2(float x, float y)
{
	x2 = x;
	y2 = y;
}
/*We could change the length by changing (x1,y1) or (x2,y2)*/

/**********************************************************************
                            
**********************************************************************

parameters:    
returns:        
**********************************************************************/
void Line :: draw() const
{
    glColor3fv( bColor );
    glBegin( GL_LINES );
        glVertex2f( x1, y1 );
        glVertex2f( x2, y2 );
    glEnd();
    glFlush();
}
