/* ellipses.cpp */

#include <GL/freeglut.h>
#include "ellipses.h"

/**********************************************************************
                            Constructor
**********************************************************************/
Ellipses :: Ellipses( float x, float y, const float* bC, const float* fC, float xR, float yR, bool f) :  Shape( x, y, bC ), fColor( fC ), xRadius( xR ), yRadius( yR ), filled( f )
{}

/**********************************************************************
                            Copy Constructor
**********************************************************************/
Ellipses :: Ellipses( const Ellipses& e ) : Shape( e.locX, e.locY, e.bColor ), fColor( e.fColor ), xRadius( e.xRadius ), yRadius( e.yRadius ), filled( e.filled )
{}

/**********************************************************************
                            Destructor
**********************************************************************/
Ellipses :: ~Ellipses()
{}

/**********************************************************************
                            get*
**********************************************************************
These get functions retrieve the individual components of the
ellipses shape
**********************************************************************/
float Ellipses :: getRadiusX(){ return xRadius; }
float Ellipses :: getRadiusY() {return yRadius; }
const float* Ellipses :: getFillColor(){ return fColor; }
bool Ellipses :: getFilledValue(){ return filled; }

/**********************************************************************
                            set*
**********************************************************************
These set functions set the individual components of the ellipses
shape to new values
**********************************************************************/
void Ellipses :: setFillValue( bool f )
{
    filled = f;
}

void Ellipses :: setFillColor( const float* fC )
{
    fColor = fC;
}

void Ellipses :: changeDimensions( float xR, float yR )
{
	xRadius = xR;
	yRadius = yR;
    draw();
}

/**********************************************************************
                            moveTo
**********************************************************************
moveTo sets a new center point for the shape to be redrawn at
**********************************************************************/
void Ellipses :: moveTo( float x, float y )
{
    locX = x;
    locY = y;
    draw();
}

/**********************************************************************
                                draw
**********************************************************************
draw utilizes openGL functions to create a visual representation of
the line class based on the x radius and y radius
**********************************************************************/
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
