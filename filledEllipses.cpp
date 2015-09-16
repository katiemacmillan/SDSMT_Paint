/* filledEllipses.cpp */

// include files
#include <iostream>
using namespace std;

#include "filledEllipses.h"
float xRadius, yRadius;
        ColorType cBorder, cFill;

// Filled Ellipses class implementation

FilledEllipses( float x = 0.0, float y = 0.0, ColorType cBorder = ColorType( 0 ), ColorType cFill = ColorType( 0 ), float xRaius = 1.0, float yRadius = 1.0 );
~FilledEllipses();
void moveTo( float x, float y );
void changeBorderColor( ColorType color )
{
	cBorder = color;
}
void changeFillColor( ColorType color )
{
	cFill = color;
}

void changeDimensions( float xR, float yR )
{
	xRadius = xR;
	yRadius = yR;
}

void Draw ( float xR, float yR, int x, int y, const float color[] )
{
    float radius = xR < yR ? xR : yR;	// stretch circle into ellipse
    glColor3fv( color );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glTranslatef( x, y, 0 );
    glScalef( xR / radius, yR / radius, 1.0 );	// by ratio of major to minor axes
    GLUquadricObj *disk = gluNewQuadric();
    gluDisk( disk, 0, radius, int( radius ), 1 );
    gluDeleteQuadric( disk );
    glLoadIdentity();
    glFlush();
}

        void erase() const;
        void print( ostream& ) const;
