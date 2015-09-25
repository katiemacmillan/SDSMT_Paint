/* rectangle.cpp */

#include <GL/freeglut.h>
#include "rectangle.h"
#include "globals.h"
// constructor
Rectangle :: Rectangle( float x, float y, const float* bC, const float* fC, float w, float h, bool f ) : Shape( x, y, bC ), fColor( fC ), width( w ), height( h ), filled( f )
{}

Rectangle :: ~Rectangle()
{}

float Rectangle :: getWidth(){return width;}
float Rectangle :: getHeight(){return height;}
const float* Rectangle :: getFillColor(){return fColor;}
bool Rectangle :: getFilledValue(){return filled;}

void Rectangle :: setHeight(float h)
{
    height = h;
}
void Rectangle :: setWidth(float w)
{
    width = w;
}

void Rectangle :: setFillValue( bool f )
{
    filled = f;
}

void Rectangle :: setFillColor( const float* fC )
{
    fColor = fC;
}

void Rectangle :: changeDimensions( float w, float h )
{
    width = w;
    height = h;
    draw();
}

void Rectangle :: draw() const
{
    // if it's a filled shape, draw a filled shape first
    if( filled )
    {
        glColor3fv( fColor );
        glBegin( GL_POLYGON );
            glVertex2f( locX - ( width / 2 ), locY + ( height / 2) );
            glVertex2f( locX - ( width / 2 ), locY - ( height / 2) );
            glVertex2f( locX + ( width / 2 ), locY - ( height / 2) );
            glVertex2f( locX + ( width / 2 ), locY + ( height / 2) );
        glEnd();
    }
    
    // draw the border shape
    glColor3fv( bColor );
    glBegin( GL_LINE_LOOP );
        glVertex2f( locX - ( width / 2 ), locY + ( height / 2) );
        glVertex2f( locX - ( width / 2 ), locY - ( height / 2) );
        glVertex2f( locX + ( width / 2 ), locY - ( height / 2) );
        glVertex2f( locX + ( width / 2 ), locY + ( height / 2) );
    glEnd();

    glFlush();
}
