/* line.cpp */

#include <GL/freeglut.h>
#include "line.h"
#include "globals.h"

Line :: Line( float x, float y, const float* bC, float x1, float y1, float x2, float y2) : Shape( x, y, bC ), x1( x1 ), y1( y1 ), x2( x2 ), y2( y2 )
{
    // calculate the midpoint of the line
    x = ( x1 + x2 ) / 2;
    y = ( y1 + y2 ) / 2;
}

Line :: ~Line()
{}

void Line :: setFill( bool f )
{}

//void changeDimensions( ?? );
/*We could change the length by changing (x1,y1) or (x2,y2)*/

void Line :: draw() const
{
    glColor3fv( bColor );
    glBegin( GL_LINES );
        glVertex2f( x1, y1 );
        glVertex2f( x2, y2 );
    glEnd();
    glFlush();
}
