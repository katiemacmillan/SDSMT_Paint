/* callbacks.cpp */

#include "headers.h"

////I'm struggling with the header file of callbacks and global. I'm throwing all
//shape related items here for now

// globals
///Shape* currentShape;


// color palette items
float PaletteSize = 46.0;

// first column, bottom to top
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
// second column, bottom to top
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

// shape palette
// first column, adding on top of colors
const Shape* EllipsesTool = new Rectangle( 23, 483, White, Black, PaletteSize, PaletteSize, true );
const Shape* RectangleTool = new Rectangle( 23, 529, White, Black, PaletteSize, PaletteSize, true );
const Shape* CurrentShapeDisplay = new Rectangle( 23, 575, White, Black, PaletteSize, PaletteSize, true );
// second column, adding on top of colors
const Shape* FilledEllipsesTool = new Rectangle( 69, 483, White, Black, PaletteSize, PaletteSize, true );
const Shape* FilledRectangleTool = new Rectangle( 69, 529, White, Black, PaletteSize, PaletteSize, true );
const Shape* LineTool = new Rectangle( 69, 575, White, Black, PaletteSize, PaletteSize, true );

// paint pallette, includes colors, shapes, and current shape display
const Shape* PaintPalette[] = { GrayColor, PurpleColor, BlueColor, CyanColor, 
                                GreenColor, YellowColor, OrangeColor, RedColor, 
                                MagentaColor, WhiteColor, EllipsesTool, RectangleTool,
                                CurrentShapeDisplay, DarkGrayColor, DarkPurpleColor, 
                                DarkBlueColor, DarkCyanColor, DarkGreenColor, 
                                DarkYellowColor, DarkOrangeColor, DarkRedColor, 
                                DarkMagentaColor, LightGrayColor, FilledEllipsesTool, 
                                FilledRectangleTool, LineTool };

// callback function to tell OpenGL how to redraw window
void display( void )
{
    // clear the display
    glClear( GL_COLOR_BUFFER_BIT );

    // drawing the paint palette on the left side of the screen
    for( int i = 0; i < 26; i++ )
    {
        PaintPalette[i] -> draw();
    }

    // write title on top of screen
    ///Commenting out for now because I'm sick of seeing the depreciated string warning
    ///Need to put this function in a file
    ///DrawTextString( "Chrissy and Kate Paint!", ScreenWidth / 2 - 92, ScreenHeight - 20, White );

    ////draw the shapes for the shape list here

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
        // left button: create objects, select border color, select shape
        case GLUT_LEFT_BUTTON:
            // press
            if( state == GLUT_DOWN )
            {    
                cerr << "mouse click: left down at (" << x << "," << y << ")\n";
                if( x < PaletteSize * 2 )
                {
                    if( y < PaletteSize * 10 )
                    {
                        selectBorderColor();
                    }
                    else
                    {
                        selectShape();
                    }                
                }
            }
            // release
            else if( state == GLUT_UP )
                cerr << "mouse click: left up at (" << x << ","<< y << ")\n";
            break;
        // right button: select fill color
        case GLUT_RIGHT_BUTTON:
            // press
            if( state == GLUT_DOWN )
            {
                if( x < PaletteSize * 2 )
                {
                    if( y < PaletteSize * 10 )
                    {
                        selectFillColor();
                    }
                }
                cerr << "mouse click: right down at (" << x << ","<< y << ")\n";
            }
            // release
            else if( state == GLUT_UP )
                cerr << "mouse click: right up at (" << x << ","<< y << ")\n";
            break;
    }
}

///Obviously for testing purposes
void selectBorderColor( /*int x, int y*/)
{
    cout << "Select a border color!!" << endl;
    //const float* selectedColor = White; //change me!
    ///compare the x and y to a color and set it
    //currentShape -> changeBorderColor( selectedColor );
        
}

void selectShape( /* shapeSelected */)
{
    cout << "Selecting a shape!!" << endl;
    // selected shape constructor
}

void selectFillColor( /* selectedColor */)
{
    cout << "Selecting a FILL color!!" << endl;
    // currentShape -> setFillColor( selectedColor );
}
