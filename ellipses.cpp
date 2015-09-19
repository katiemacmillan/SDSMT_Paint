/* ellipses.cpp */

// include files
#include <iostream>
using namespace std;

#include "ellipses.h"


// Ellipses class implementation
Ellipses::Ellipses( float x1 = 0.0, float y1 = 0.0, float x2 = 0.0, float y2 = 0.0, float[] fC = {0}, float[] bC = {0}, bool fill = false, float xR = 1.0, float yR = 1.0 )
:  Shape( x1, y1, x2, y2, fc, bc, fill), xRadius(xR), yRadius(yR) {}


Ellipses::~Ellipses();

void Ellipses::changeDimensions( float xR, float yR )
{
	xRadius = xR;
	yRadius = yR;
    draw()
}

void Ellipses::draw( int x, int y )
{
    float radius = xRadius < yRadius ? xRadius : yRadius;	// stretch circle into ellipse
    glColor3fv( bColor );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glTranslatef( Xc, Yc, 0 );
    glScalef( xRadius / radius, yRadius / radius, 1.0 );	// by ratio of major to minor axes
    GLUquadricObj *disk = gluNewQuadric();
    gluDisk( disk, radius - 1, radius, int( radius ), 1 );
    gluDeleteQuadric( disk );
    glLoadIdentity();
    glFlush();
}

