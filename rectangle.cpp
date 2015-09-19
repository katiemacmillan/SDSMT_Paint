/* rectangle.cpp */

// include files
#include <iostream>
using namespace std;

#include "rectangle.h"

// Rectangle class implementation

Rectangle( float x1 = 0.0, float y1 = 0.0, float x2 = 0.0, float y2 = 0.0, float[] fC = {0}, float[] bC = {0}, bool fill = false, float h = 0.0, float w = 0.0 )
:  Shape( x1, y1, x2, y2, fc, bc, fill), height( h ), width( w ) {}
~Rectangle(){}

void changeDimensions( float w, float h )
{
	width = w;
	height = h;
	draw();
}

void draw() const;
{
    if (fill)
    {
        glColor3fv( fC );
        glBegin( GL_POLYGON );
            glVertex2f( x1, y1 );
            glVertex2f( x2, y1 );
            glVertex2f( x2, y2 );
            glVertex2f( x1, y2 );
        glEnd();
    }
    glColor3fv( bC );
    glBegin( GL_LINE_LOOP );
        glVertex2f( x1, y1 );
        glVertex2f( x2, y1 );
        glVertex2f( x2, y2 );
        glVertex2f( x1, y2 );
    glEnd();
    glFlush();
}
