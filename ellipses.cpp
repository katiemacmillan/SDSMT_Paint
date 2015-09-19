/* ellipses.cpp */

// include files
#include <iostream>
using namespace std;

#include "ellipses.h"


// Ellipses class implementation
Ellipses( float x = 0.0, float y = 0.0, float[] c = float[]( 0 ), float xRaius = 1.0, float yRadius = 1.0 ){};


~Ellipses();
//Is x,y the new center of the elipse?
void moveTo( float x, float y );

void changeFillColor( float[] color )
{
	fColor = color
}

void changeBorderColor( float[] color )
{
    bColor = color
}

void changeDimensions( float xR, float yR )
{
	xRadius = xR;
	yRadius = yR;
}

void draw( int x, int y )
{
    float radius = xRadius < yRadius ? xRadius : yRadius;	// stretch circle into ellipse
    glColor3fv( bColor );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glTranslatef( x, y, 0 );
    glScalef( xRadius / radius, yRadius / radius, 1.0 );	// by ratio of major to minor axes
    GLUquadricObj *disk = gluNewQuadric();
    gluDisk( disk, radius - 1, radius, int( radius ), 1 );
    gluDeleteQuadric( disk );
    glLoadIdentity();
    glFlush();
}

