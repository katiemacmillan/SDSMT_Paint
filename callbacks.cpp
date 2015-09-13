/* callbacks.cpp */

// include files
#include <cstdlib>
#include <iostream>
using namespace std;

#include <GL/freeglut.h>
#include "globals.h"
#include "callbacks.h"
#include "graphics.h"

// callback function to tell OpenGL how to redraw window
void display( void )
{
    // clear the display
    glClear( GL_COLOR_BUFFER_BIT );

    // draw stuffff
    ///DrawLine( 10, 20, ScreenWidth - 10, ScreenHeight - 20, Yellow );

    // flush graphical output
    glFlush();
}

// callback function that tells OpenGL how to resize window
void reshape( int w, int h )
{
    // store new window dimensions globally
    ScreenWidth = w;
    ScreenHeight = h;

    // how to project 3-D scene onto 2-D
    // use an orthographic projection
    glMatrixMode( GL_PROJECTION );
    // Initailze transformation matrix
    glLoadIdentity();
    // Make OpenGL coordinates
    gluOrtho2D( 0.0, w, 0.0, h );
    // the same as the screen coordinates
    glViewport( 0, 0, w, h );   
}

// callback function that tells OpenGL how to handle keystrokes
void keyboard( unsigned char key, int x, int y )
{
    //correct for upside-down screen coordinates
    y = ScreenHeight - y;

    switch( key )
    {
        // Excape quits program
        case 'q':
        case EscapeKey:
            exit( 0 );
            break;
        // Anything else redraws window
        default:
            glutPostRedisplay();
            break;
    }
}

// callback function for mouse button click events
void mouseclick( int button, int state, int x, int y )
{
    //correct for upside-down screen coordinates
    y = ScreenHeight - y;

    ///Needed something to do in the if-else for texting
    int temp;

    // handle mouse click events
    switch( button )
    {
        // left button: create objects
        case GLUT_LEFT_BUTTON:
            // press
            if( state == GLUT_DOWN )
                temp = 1;
                //pressing at x,y
            // release
            else if( state == GLUT_UP )
                temp = 2;
                //releaseing at x,y
            break;
        case GLUT_RIGHT_BUTTON:
            // press
            if( state == GLUT_DOWN )
                //pressing stuff at x,y
                temp = 3;
            else if( state == GLUT_UP )
                //releasing at x,y
                temp = 4;
            break;
    }
}
