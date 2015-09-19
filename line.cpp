/* line.cpp */

// include files
#include <iostream>
using namespace std;

#include "line.h"

// Line class implementation

Line::Line( float x1 = 0.0, float y1 = 0.0, float x2 = 0.0, float y2 = 0.0, float[] fC = {0}, float[] bC = {0}, bool fill = false)
:  Shape( x1, y1, x2, y2, fc, bc, fill) {}

Line::~Line();

//void changeDimensions( ?? );
/*We could change the length by changing (x1,y1) or (x2,y2)*/

void Line::draw() const
{
    glColor3fv( bColor );
    glBegin( GL_LINES );
        glVertex2f( X1, Y1 );
        glVertex2f( X2, Y2 );
    glEnd();
    glFlush();
}
