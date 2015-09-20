/* callbacks.cpp */

// include files
/*#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;

#include <GL/freeglut.h>
#include "callbacks.h"
#include "globals.h"
*/

#include "headers.h"

int PaletteSize = 46;

const Shape* GrayColor = new Rectangle( 23, 23, Black, Gray, PaletteSize, PaletteSize, true);
const Shape* PurpleColor = new Rectangle( 23, 69, Black, Purple, PaletteSize, PaletteSize, true);
const Shape* BlueColor = new Rectangle( 23, 115, Black, Blue, PaletteSize, PaletteSize, true);
const Shape* CyanColor = new Rectangle( 23, 161, Black, Cyan, PaletteSize, PaletteSize, true);
const Shape* GreenColor = new Rectangle( 23, 207, Black, Green, PaletteSize, PaletteSize, true);
const Shape* YellowColor = new Rectangle( 23, 253, Black, Yellow, PaletteSize, PaletteSize, true);
const Shape* OrangeColor = new Rectangle( 23, 299, Black, Orange, PaletteSize, PaletteSize, true);
const Shape* RedColor = new Rectangle( 23, 345, Black, Red, PaletteSize, PaletteSize, true);
const Shape* MagentaColor = new Rectangle( 23, 391, Black, Magenta, PaletteSize, PaletteSize, true);
const Shape* WhiteColor = new Rectangle( 23, 437, Black, White, PaletteSize, PaletteSize, true);

const Shape* DarkGrayColor = new Rectangle( 69, 23, Black, DarkGray, PaletteSize, PaletteSize, true);
const Shape* DarkPurpleColor = new Rectangle( 69, 69, Black, DarkPurple, PaletteSize, PaletteSize, true);
const Shape* DarkBlueColor = new Rectangle( 69, 115, Black, DarkBlue, PaletteSize, PaletteSize, true);
const Shape* DarkCyanColor = new Rectangle( 69, 161, Black, DarkCyan, PaletteSize, PaletteSize, true);
const Shape* DarkGreenColor = new Rectangle( 69, 207, Black, DarkGreen, PaletteSize, PaletteSize, true);
const Shape* DarkYellowColor = new Rectangle( 69, 253, Black, DarkYellow, PaletteSize, PaletteSize, true);
const Shape* DarkOrangeColor = new Rectangle( 69, 299, Black, DarkOrange, PaletteSize, PaletteSize, true);
const Shape* DarkRedColor = new Rectangle( 69, 345, Black, DarkRed, PaletteSize, PaletteSize, true);
const Shape* DarkMagentaColor = new Rectangle( 69, 391, Black, DarkMagenta, PaletteSize, PaletteSize, true);
const Shape* LightGrayColor = new Rectangle( 69, 437, Black, LightGray, PaletteSize, PaletteSize, true);

const Shape* ColorPalette[] = { GrayColor, PurpleColor, BlueColor, CyanColor,
                                GreenColor, YellowColor, OrangeColor, RedColor,
                                MagentaColor, WhiteColor, DarkGrayColor,
                                DarkPurpleColor, DarkBlueColor, DarkCyanColor,
                                DarkGreenColor, DarkYellowColor, DarkOrangeColor,
                                DarkRedColor, DarkMagentaColor, LightGrayColor };






// callback function to tell OpenGL how to redraw window
void display( void )
{
    // clear the display
    glClear( GL_COLOR_BUFFER_BIT );

    ///just testing things out
    Shape* r = new Rectangle( 500.0, 250.0, White, Red, 300.0, 100.0, true );
    r -> draw();

    Shape* l = new Line( 1.0, 1.0, Cyan, 10.4, 30.2, 201.3, 430.0 );
    l -> draw();

    for( int i = 0; i < 20; i++ )
    {
        ColorPalette[i] -> draw();
    }

    // write title on top of screen
    ///Commenting out for now because I'm sick of seeing the depreciated string warning
    ///Need to put this function in a file
    ///DrawTextString( "Chrissy and Kate Paint!", ScreenWidth / 2 - 92, ScreenHeight - 20, White );



    // draw the two color/shape pallette box columns
    /*for( i = 0; i < 13; i++ )
    {
        //DrawRectangle( x1, y1, x2, y2, White );
        DrawFilledRectangle( x1, y1, x2, y2, ColorList[j] );
        DrawRectangle( x1, y1, x2, y2, White );
        y2 = y1;
        y1 = y1 + 46.0;
        if( j < 9 )
            j++;
        else
            j = 20;    
    }

    x1 = 46.0;
    y1 = 46.0;
    x2 = 46.0 * 2;
    y2 = 0.0;
    j = 10;
    for( i = 0; i < 13; i++ )
    {
        DrawFilledRectangle( x1, y1, x2, y2, ColorList[j] );        
        DrawRectangle( x1, y1, x2, y2, White );
        //DrawFilledRectangle( x1, y1, x2, y2, ColorList[j] );
        y2 = y1;
        y1 = y1 + 46.0;
        if( j < 19 )
            j++;
        else
            j = 20;
    }
*/
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
