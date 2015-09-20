/* graphics.cpp */

#include "headers.h"

void DrawTextString( char* string, int x, int y, const float color[] )
{
    glColor4fv( color );
    glRasterPos2i( x, y );
    while( *string )
    {
        glutBitmapCharacter( GLUT_BITMAP_8_BY_13, *string++ );
    }
}
