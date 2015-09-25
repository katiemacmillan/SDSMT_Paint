/* rectangle.cpp */

#include <GL/freeglut.h>
#include "rectangle.h"
#include "globals.h"
/**********************************************************************
                            Constructor
**********************************************************************/
Rectangle :: Rectangle( float x, float y, const float* bC, const float* fC, float w, float h, bool f ) : Shape( x, y, bC ), fColor( fC ), width( w ), height( h ), filled( f )
{}

/**********************************************************************
                           Copy Constructor
**********************************************************************/
Rectangle :: Rectangle( const Rectangle& r ) : Shape( r.locX, r.locY, r.bColor ), fColor( r.fColor ), width( r.width ), height( r.height ), filled( r.filled )
{}

/**********************************************************************
                            Destructor
**********************************************************************/
Rectangle :: ~Rectangle()
{}

/**********************************************************************
                            get*
**********************************************************************
These get functions retrieve the individual components of the 
rectangle shape. 
**********************************************************************/
float Rectangle :: getWidth(){return width;}
float Rectangle :: getHeight(){return height;}
const float* Rectangle :: getFillColor(){return fColor;}
bool Rectangle :: getFilledValue(){return filled;}


/**********************************************************************
                            set*
**********************************************************************
These set functions set the individual components of the rectangle
shape to new values
**********************************************************************/
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

/**********************************************************************
                            moveTo
**********************************************************************
moveTo sets a new center point for the shape to be redrawn at
**********************************************************************/
void Rectangle :: moveTo( float x, float y )
{
    locX = x;
    locY = y;
    draw();
}

/**********************************************************************
                                draw
**********************************************************************
draw utilizes openGL functions to create a visual representation of
the line class based on the height and width
**********************************************************************/
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
