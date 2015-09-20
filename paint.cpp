/* paint.cpp */

// include files
#include "headers.h"

// funciton prototypes
void initOpenGL( void );

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

// various commands to initialize OpenGL and GLUT
void initOpenGL( void )
{
    // 32-bit graphics and single buffering
    glutInitDisplayMode( GLUT_RGBA | GLUT_SINGLE );

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
}
