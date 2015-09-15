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
    DrawRectangle( 8.0, 500.0, 50.0, 200.0, White );    


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

    // handle mouse click events
    switch( button )
    {
        // left button: create objects
        case GLUT_LEFT_BUTTON:
            // press
            if( state == GLUT_DOWN )
                cerr << "mouse click: left down at (" << x << "," << y << ")\n";
            // release
            else if( state == GLUT_UP )
                cerr << "mouse click: left up at (" << x << ","<< y << ")\n";
            break;
        case GLUT_RIGHT_BUTTON:
            // press
            if( state == GLUT_DOWN )
                cerr << "mouse click: right down at (" << x << ","<< y << ")\n";
            else if( state == GLUT_UP )
                cerr << "mouse click: right up at (" << x << ","<< y << ")\n";
            break;
    }
}
