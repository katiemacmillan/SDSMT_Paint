/* filledFectangle.cpp */

// include files
#include <iostream>
using namespace std;

#include "filledRectangle.h"

// Filled Rectangle class implementation
    private:
        float width, height;
        ColorType cBorder, cFill;

    public:
        FilledRectangle( float x = 0.0, float y = 0.0, ColorType cBorder = ColorType( 0 ), ColorType cFill = ColorType( 0 ), float w = 1.0, float h = 1.0 );
        ~FilledRectangle();
        void moveTo( float x, float y );
        void changeBorderColor (ColorType color)
        {
        	cBorder = color;
        }
        void changeFillColor( ColorType color )
        {
        	cFill = color;
        }
        void changeDimensions( float w, float h )
        {
        	width = w;
        	height = h;
        	draw();
        }
void draw(float x1, float y1, float x2, float y2, const float color[] )
{
    glColor3fv( color );
    glBegin( GL_POLYGON );
        glVertex2f( x1, y1 );
        glVertex2f( x2, y1 );
        glVertex2f( x2, y2 );
        glVertex2f( x1, y2 );
    glEnd();
    glFlush();
}
        void erase() const;
        void print( ostream& out ) const;