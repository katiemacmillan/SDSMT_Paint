/* line.cpp */

#include <GL/freeglut.h>
#include "line.h"
#include "globals.h"

/**********************************************************************
                            Constructor
**********************************************************************/
Line :: Line( float x, float y, const float* bC, float x1, float y1, float x2, float y2) : Shape( x, y, bC ), x1( x1 ), y1( y1 ), x2( x2 ), y2( y2 )
{}
/**********************************************************************
                        Copy Constructor
**********************************************************************/

Line :: Line( const Line& l ) : Shape( l.locX, l.locY, l.bColor ), x1( l.x1 ), y1( l.y1 ), x2( l.x2 ), y2( l.y2 )
{}
/**********************************************************************
                            Destructor
**********************************************************************/
Line :: ~Line()
{}

/**********************************************************************
                            get*
**********************************************************************
These get functions retrieve the individual x and y coordinates of
the line
**********************************************************************/
float Line :: getX1 (){return x1;}
float Line :: getY1 (){return y1;}
float Line :: getX2 (){return x2;}
float Line :: getY2 (){return y2;}

/**********************************************************************
                            set*
**********************************************************************
These set functions set the individual components of the line
shape to new values
**********************************************************************/
void Line :: setXY1(float x, float y)
{
	x1 = x;
	y1 = y;
}

void Line :: setXY2(float x, float y)
{
	x2 = x;
	y2 = y;
}

/**********************************************************************
                            moveTo
**********************************************************************
moveTo sets a new center point for the shape to be redrawn at. In
order to redraw a line shape, the new (x,y)1 and (x,y)2 are recalculate
based on the difference from the original coordinates from the original
center point
**********************************************************************/
void Line :: moveTo( float x, float y )
{
    //distance from center point to x & y coordinates to create offset
    float xdiff, ydiff;
    
       //Nex (x,y) coordinates are at offset from center point
    if (x1 < x2)
    {
        xdiff = locX - x1;
        x1 = x - xdiff;
        x2 = x + xdiff;
    }
    else
    {
        xdiff = locX - x2;
        x1 = x + xdiff;
        x2 = x - xdiff;
    }
    if (y1 < y2)
    {
        ydiff = locY - y1;
        y1 = y - ydiff;
        y2 = y + ydiff;
    }
    else
    {
        ydiff = locY - y2;
        y1 = y + ydiff;
        y2 = y - ydiff;
    }

    //Assign new center point
    locX = x;
    locY = y;
    draw();
}

/**********************************************************************
                                draw
**********************************************************************
draw utilizes openGL functions to create a visual representation of
the line class based on the point(x1, y1) and (x2,y2)
**********************************************************************/
void Line :: draw() const
{
    glColor3fv( bColor );
    glBegin( GL_LINES );
        glVertex2f( x1, y1 );
        glVertex2f( x2, y2 );
    glEnd();
    glFlush();
}
