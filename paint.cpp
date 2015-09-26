/**********************************************************************
                            paint
**********************************************************************
Authors: Christine Sorensen & Katherine MacMillan
**********************************************************************
paint uses a shape class with three derived classes to create and
draw various shapes.

By using the left mouse button to click on a shape icon, or color on
the color palette, the corresponding shape or color can be chosen.
A color chosen in this manner will set the shape's border color to 
the chosen color. 

A shape is then created by using the left mouse button to click on
two different points in the draw window. This program uses the two
coordinates to draw a rectangle, line or ellipses. 

By right clicking on a color in the color palette a color can be chosen
to be used on the interior of a filled shape. By right clicking and 
holding on a drawn shape, the shape with the center closest to the 
selected point will be selected for movement. Moving the mouse without 
releasing the button will cause the shape to be dragged to a new 
location on the screen. When the right mouse button is release the 
shape will stay in that new location. 

**********************************************************************
                            Known Bugs
**********************************************************************
On occation when selecting a shape to be moved, the program will
instead move the previously moved shape to the newly selected point,
rather than selecting a new shape. 
**********************************************************************/

#include <GL/freeglut.h>
#include "globals.h"
#include "callbacks.h"

/******Function Prototypes******/
void initOpenGL( void );


/**********************************************************************
                            Main
**********************************************************************
The primary function of main is to initiate the openGl function, from
which it does not return
**********************************************************************/
int main( int argc, char** argv )
{
    // perform OpenGL initializations
    glutInit( &argc, argv );
    initOpenGL();

    // go into OpenGL/GLUT main loop, NEVER TO RETURN!!!
    glutMainLoop();

    // quit your bitchin, compiler!
    return 0;
}

/**********************************************************************
                            initOpenGL
**********************************************************************
initOpenGL gives OpenGL the definitions on how to handle various
events, from which OpenGL then takes over with the GUI window
**********************************************************************/
void initOpenGL( void )
{
    // 32-bit graphics and single buffering
    glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE );

    // inital window size
    glutInitWindowSize( ScreenWidth, ScreenHeight );
    // inital window position
    glutInitWindowPosition( 100, 50 );
    // window title
    glutCreateWindow( "Paint" );

    // use black for glClear command
    glClearColor( 0.0, 0.0, 0.0, 0.0 );

    // callback routines
    // how to redisplay the window
    glutDisplayFunc( display );

    // how to resize window
    glutReshapeFunc( reshape );

    // how to handle key presses
    glutKeyboardFunc( keyboard );

    // how to handle mouse events
    glutMouseFunc( mouseclick );

    // how to handle mouse movement
    glutPassiveMotionFunc( mousedragpassive );

    // how to handle mouse pressed movement
    glutMotionFunc( mousedrag );
}
