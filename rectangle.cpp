/* rectangle.cpp */

// include files
#include <iostream>
using namespace std;

#include "rectangle.h"

// Rectangle class implementation

Rectangle::Rectangle( float x1 = 0.0, float y1 = 0.0, float x2 = 0.0, float y2 = 0.0, float[] fC = {0}, float[] bC = {0}, bool fill = false, float h = 0.0, float w = 0.0 )
:  Shape( x1, y1, x2, y2, fc, bc, fill), height( h ), width( w ) {}
Rectangle::~Rectangle(){}

void Rectangle::changeDimensions( float w, float h )
{
	width = w;
	height = h;
	draw();
}

void Rectangle::draw() const;
{
    if (fill)
    {
        glColor3fv( fC );
        glBegin( GL_POLYGON );
            glVertex2f( X1, Y1 );
            glVertex2f( X2, Y1 );
            glVertex2f( X2, Y2 );
            glVertex2f( X1, Y2 );
        glEnd();
    }
    glColor3fv( bC );
    glBegin( GL_LINE_LOOP );
        glVertex2f( X1, Y1 );
        glVertex2f( X2, Y1 );
        glVertex2f( X2, Y2 );
        glVertex2f( X1, Y2 );
    glEnd();
    glFlush();
}
