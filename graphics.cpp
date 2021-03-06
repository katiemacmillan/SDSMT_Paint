/* graphics.cpp */

#include <GL/freeglut.h>
#include "graphics.h"

/**********************************************************************
                        DrawTextString
**********************************************************************
DrawTextString tells OpenGL where and how to display a desired
string of text in the OpenGL window
**********************************************************************/
void DrawTextString( char* string, int x, int y, const float color[] )
{
    glColor4fv( color );
    glRasterPos2i( x, y );
    while( *string )
    {
        glutBitmapCharacter( GLUT_BITMAP_8_BY_13, *string++ );
    }
}
