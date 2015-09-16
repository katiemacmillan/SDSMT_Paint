/* graphics.cpp */

/***********************************************************************
These are unnessasary. The shape class derivations are there so we don't need these functions


// include files
#include <cstdlib>
#include <iostream>
using namespace std;

#include <GL/freeglut.h>
#include "graphics.h"

void DrawLine( float x1, float y1, float x2, float y2, const float color[] )
{
    glColor3fv( color );
    glBegin( GL_LINES );
        glVertex2f( x1, y1 );
        glVertex2f( x2, y2 );
    glEnd();
    glFlush();
}

void DrawRectangle( float x1, float y1, float x2, float y2, const float color[] )
{
    glColor3fv( color );
    glBegin( GL_LINE_LOOP );
        glVertex2f( x1, y1 );
        glVertex2f( x2, y1 );
        glVertex2f( x2, y2 );
        glVertex2f( x1, y2 );
    glEnd();
    glFlush();
}
*******************************************************************************/