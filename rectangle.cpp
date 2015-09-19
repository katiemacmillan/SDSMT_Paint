/* rectangle.cpp */

// include files
#include <iostream>
using namespace std;

#include "rectangle.h"

// Rectangle class implementation

// constructor
/*Rectangle::Rectangle( float x, float y, float[] c, float w, float h ) : 
    Shape( x, y, c ), width( w ), height( h )
{
    int temp = 5;
}*/
Rectangle::Rectangle( float x = 0.0, float y = 0.0, float[] fC = float[]( 0 ), float[] bC = float[]( 0 ), float w = 1.0, float h = 1.0, bool fill = false )
: Shape( x, y, fC, bC, fill), width(w), height(h)
{}
Rectangle::~Rectangle(){}
void Rectangle::moveTo( float x, float y )
{}
void Rectangle::changeColor( float[] color )
{
	c = color;
}

void Rectangle::changeDimensions( float w, float h )
{
	width = w;
	height = h;
	draw();
}

void Rectangle::draw() const;
//float x1, float y1, float x2, float y2, const float bC[], const float fC[], bool fill )
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
