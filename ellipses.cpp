/* ellipses.cpp */

#include <GL/freeglut.h>
#include "ellipses.h"

// constructor
Ellipses :: Ellipses( float x, float y, const float* bC, const float* fC, float xR, float yR, bool f) :  Shape( x, y, bC ), fColor( fC ), xRadius( xR ), yRadius( yR ), filled( f )
{}


Ellipses :: ~Ellipses()
{}

void Ellipses :: setFill( bool f )
{
    filled = f;
}


void Ellipses :: changeDimensions( float xR, float yR )
{
	xRadius = xR;
	yRadius = yR;
    draw();
}

void Ellipses :: draw() const
{
    float radius = xRadius < yRadius ? xRadius : yRadius;	// stretch circle into ellipse
    // draw the filled shape before the border
    if( filled )
    {
        glColor3fv( fColor );
        glMatrixMode( GL_MODELVIEW );
        glLoadIdentity();
        glTranslatef( locX, locY, 0 );
        glScalef( xRadius / radius, yRadius / radius, 1.0 );
        GLUquadricObj *disk = gluNewQuadric();
        gluDisk( disk, 0, radius, int( radius ), 1 );
        gluDeleteQuadric( disk );
        glLoadIdentity();
        glFlush();    
    }

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

