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
    glColor4fv( color );
    glBegin( GL_LINES );
        glVertex2f( x1, y1 );
        glVertex2f( x2, y2 );
    glEnd();
    glFlush();
}

void DrawRectangle( float x1, float y1, float x2, float y2, const float color[] )
{
    glColor4fv( color );
    glBegin( GL_LINE_LOOP );
        glVertex2f( x1, y1 );
        glVertex2f( x2, y1 );
        glVertex2f( x2, y2 );
        glVertex2f( x1, y2 );
    glEnd();
    glFlush();
}
<<<<<<< HEAD
*******************************************************************************/
=======

void DrawFilledRectangle( float x1, float y1, float x2, float y2, const float color[] )
{
	glColor4fv( color );
	glBegin( GL_POLYGON );
        glVertex2f( x1, y1 );
        glVertex2f( x2, y1 );
        glVertex2f( x2, y2 );
        glVertex2f( x1, y2 );
    glEnd();
    glFlush();
}

void DrawEllipse( float xRadius, float yRadius, int x, int y, const float color[] )
{
    float radius = xRadius < yRadius ? xRadius : yRadius;
    glColor4fv( color );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glTranslatef( x, y, 0 );
    glScalef( xRadius / radius, yRadius / radius, 1.0 );
    GLUquadricObj *disk = gluNewQuadric();
    gluDisk( disk, 0, radius, int( radius ), 1 );
    gluDeleteQuadric( disk );
    glLoadIdentity();
    glFlush();
}

void DrawTextString( char* string, int x, int y, const float color[] )
{
    glColor4fv( color );
    glRasterPos2i( x, y );
    while( *string )
    {
        glutBitmapCharacter( GLUT_BITMAP_8_BY_13, *string++ );
    }
}
>>>>>>> 50b7df2c3c024afac6edda4f9500eec13b05e845
