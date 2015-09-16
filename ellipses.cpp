/* ellipses.cpp */

// include files
#include <iostream>
using namespace std;

#include "ellipses.h"


// Ellipses class implementation
Ellipses( float x = 0.0, float y = 0.0, ColorType c = ColorType( 0 ), float xRaius = 1.0, float yRadius = 1.0 ){};


~Ellipses();
//Is x,y the new center of the elipse?
void moveTo( float x, float y );

void changeColor( ColorType color )
{
	c = color
}

void changeDimensions( float xR, float yR )
{
	xRadius = xR;
	yRadius = yR;
}

void draw( float xR, float yR, int x, int y, const float color[] )
{
    float radius = xR < yR ? xR : yR;	// stretch circle into ellipse
    glColor3fv( color );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glTranslatef( x, y, 0 );
    glScalef( xR / radius, yR / radius, 1.0 );	// by ratio of major to minor axes
    GLUquadricObj *disk = gluNewQuadric();
    gluDisk( disk, radius - 1, radius, int( radius ), 1 );
    gluDeleteQuadric( disk );
    glLoadIdentity();
    glFlush();
}

void erase() const;
void print( ostream& out ) const;