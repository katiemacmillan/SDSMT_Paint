/* ellipses.cpp */

// include files
#include "headers.h"

// constructor
Ellipses :: Ellipses( float x, float y, const float* bColor, const float* fColor, float xR, float yR, bool f) :  Shape( x, y, bColor), fColor( fColor ), xRadius( xR ), yRadius( yR ), filled( f )
{}


Ellipses :: ~Ellipses()
{}

void Ellipses :: changeDimensions( float xR, float yR )
{
	xRadius = xR;
	yRadius = yR;
    draw();
}

void Ellipses :: draw() const
{
    float radius = xRadius < yRadius ? xRadius : yRadius;	// stretch circle into ellipse
    glColor3fv( bColor );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glTranslatef( locX, locY, 0 );
    glScalef( xRadius / radius, yRadius / radius, 1.0 );	// by ratio of major to minor axes
    GLUquadricObj *disk = gluNewQuadric();
    gluDisk( disk, radius - 1, radius, int( radius ), 1 );
    gluDeleteQuadric( disk );
    glLoadIdentity();
    glFlush();
}

