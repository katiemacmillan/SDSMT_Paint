/* rectangle.cpp */

// include files
#include <iostream>
using namespace std;

#include "rectangle.h"

// Rectangle class implementation

// constructor
/*Rectangle::Rectangle( float x, float y, ColorType c, float w, float h ) : 
    Shape( x, y, c ), width( w ), height( h )
{
    int temp = 5;
}*/
Rectangle( float x = 0.0, float y = 0.0, ColorType fC = ColorType( 0 ), ColorType bC = ColorType( 0 ), float w = 1.0, float h = 1.0, bool fill = false )
: Shape( x, y, fC, bC, fill), width(w), height(h)
{}
~Rectangle(){}
void moveTo( float x, float y )
{}
void changeColor( ColorType color )
{
	c = color;
}

void changeDimensions( float w, float h )
{
	width = w;
	height = h;
	draw();
}

void draw() const;
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
        void erase() const;
        void print( ostream& out ) const;