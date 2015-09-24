/* callbacks.cpp */

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

#include <GL/freeglut.h>
#include "callbacks.h"
#include "globals.h"
#include "shape.h"
#include "ellipses.h"
#include "rectangle.h"
#include "line.h"
#include "graphics.h"

// globals to create shape
Shape* CurrentShape; // current shape object about to be drawn
const float* CurrentBorderColor = Yellow; // current border color we have selected for a new shape
const float* CurrentFillColor = Orange;  // current fill color we have selected for a new shape
Shapes CurrentShapeType = RECTANGLE_SHAPE; // the type of shape we're drawing
bool CurrentFillValue = true; // the value of filled or not
int x1, y1, x2, y2; // used to calculate the centerpoint of the shape being drawn

// holds the list of shapes drawn
vector<Shape*> DrawnShapes; // list of shapes that have been drawn

// flags
bool IsShapeSelected = false; // if a shape icon has been selected
bool IsMovingShape = false; // is the shape being moved
int DrawCount = 1; // 1 for first point, 0 for end point and not drawing

// color palette items
float PaletteSize = 46.0;
float IconSize = 30.0;

// first column of colors, bottom to top
Shape* GrayColor = new Rectangle( 23, 23, Black, Gray, PaletteSize, PaletteSize, true);
const Shape* PurpleColor = new Rectangle( 23, 69, Black, Purple, PaletteSize, PaletteSize, true);
const Shape* BlueColor = new Rectangle( 23, 115, Black, Blue, PaletteSize, PaletteSize, true);
const Shape* CyanColor = new Rectangle( 23, 161, Black, Cyan, PaletteSize, PaletteSize, true);
const Shape* GreenColor = new Rectangle( 23, 207, Black, Green, PaletteSize, PaletteSize, true);
const Shape* YellowColor = new Rectangle( 23, 253, Black, Yellow, PaletteSize, PaletteSize, true);
const Shape* OrangeColor = new Rectangle( 23, 299, Black, Orange, PaletteSize, PaletteSize, true);
const Shape* RedColor = new Rectangle( 23, 345, Black, Red, PaletteSize, PaletteSize, true);
const Shape* MagentaColor = new Rectangle( 23, 391, Black, Magenta, PaletteSize, PaletteSize, true);
const Shape* WhiteColor = new Rectangle( 23, 437, Black, White, PaletteSize, PaletteSize, true);
// second column colomn of colors, bottom to top
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

// shapes drawn in paint palette
Shape* EllipsesIcon = new Ellipses( 23, 483, CurrentBorderColor, CurrentFillColor, IconSize / 2, IconSize / 2, false );
Shape* RectangleIcon = new Rectangle( 23, 529, CurrentBorderColor, CurrentFillColor, IconSize, IconSize, false );
////const Shape* CurrentIcon();
Shape* FilledEllipsesIcon = new Ellipses( 69, 483, CurrentBorderColor, CurrentFillColor, IconSize / 2, IconSize / 2, true );
Shape* FilledRectangleIcon = new Rectangle( 69, 529, CurrentBorderColor, CurrentFillColor, IconSize, IconSize, true );
Shape* LineIcon = new Line( 69, 575, CurrentBorderColor, 69 + ( IconSize / 2 ), 575 + IconSize / 2, 69 - IconSize / 2, 575 - IconSize / 2 );

///May add these to the PaintPalette[]
const Shape* PaletteIcons[] = { EllipsesIcon, RectangleIcon, FilledEllipsesIcon, FilledRectangleIcon, LineIcon };

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

    // drawing the icons in the palette for the shape selection
    for( int i = 0; i < 5; i++ )
    {
        PaletteIcons[i] -> draw();
    }

    // write title on top of screen
    DrawTextString( "Chris and Kate Paint!", ScreenWidth / 2 - 92, ScreenHeight - 20, White );

    ////draw the shapes for the shape list here
    
    glutSwapBuffers();
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
            ///loop through and clear out the list of shapes here
            exit( 0 );
            break;
        // Anything else redraws window
        case 'd':
            //deletes items
            break;
        case 'c':
            //clears items
            break;
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
                // is a color or shape being selected?
                if( x < PaletteSize * 2 )
                {
                    if( y < PaletteSize * 10 )
                    {
                        selectBorderColor( x, y );
                    }
                    else
                    {
                        selectShape( x, y );
                    }                
                }
                // draw a shape once it has been selected
                else if( IsShapeSelected == true )
                {
                    if( DrawCount == 1 )
                    {
                        DrawCount = 0;
                        x1 = x;
                        y1 = y;
                    }
                    else
                    {
                        x2 = x;
                        y2 = y;
                        DrawCount = 1;
                        IsShapeSelected = false;
                        ///this function needs to be filled out below
                        ///this will actually initialize Shape* CurrentShape
                        createShape();
                    }
                }
            }
            // release
            //else if( state == GLUT_UP )
                //something if we did left up
            break;
        // right button: select fill color
        case GLUT_RIGHT_BUTTON:
            // press
            if( state == GLUT_DOWN )
            {
                // Selecting a fill color
                if( x < PaletteSize * 2 )
                {
                    if( y < PaletteSize * 10 )
                    {
                        selectFillColor( x, y );
                    }
                }
                else
                {
                    // Move a shape
                    // Test the xy for which shape you're on
                    // IsMovingShape = true
                }
            }
            // release
            else if( state == GLUT_UP )
                // If you're currently dragging a shape when you release you drop the shape
                // if IsMovingShape == true, drop shape
                int hoho = 1; //need something here
            break;
    }
    ///this refreshes the page. I don't know if we need it here yet
    //glutPostRedisplay();
}

void selectBorderColor( int x, int y )
{
    // first column colors
    if( x <= 46 )
    {
	    if( y <  PaletteSize * 1 ) 
            CurrentBorderColor = Gray;
        else if( y < PaletteSize * 2 )
	        CurrentBorderColor = Purple;
	    else if( y < PaletteSize * 3 )
	        CurrentBorderColor = Blue;
	    else if( y < PaletteSize * 4 )
	        CurrentBorderColor = Cyan;
	    else if( y < PaletteSize * 5 )
	        CurrentBorderColor = Green;
	    else if( y < PaletteSize * 6 )
	        CurrentBorderColor = Yellow;
	    else if( y < PaletteSize * 7 )
	        CurrentBorderColor = Orange;
	    else if( y < PaletteSize * 8 )
	        CurrentBorderColor = Red;
	    else if( y < PaletteSize * 9 )
	        CurrentBorderColor = Magenta;
	    else if( y < PaletteSize * 10 )
	        CurrentBorderColor = White;
    }
    // second column colors
    else
    {
        if( y <  PaletteSize * 1 )
            CurrentBorderColor = DarkGray;
        else if( y < PaletteSize * 2 )
            CurrentBorderColor = DarkPurple;
        else if( y < PaletteSize * 3 )
            CurrentBorderColor = DarkBlue;
        else if( y < PaletteSize * 4 )
            CurrentBorderColor = DarkCyan;
        else if( y < PaletteSize * 5 )
            CurrentBorderColor = DarkGreen;
        else if( y < PaletteSize * 6 )
            CurrentBorderColor = DarkYellow;
        else if( y < PaletteSize * 7 )
            CurrentBorderColor = DarkOrange;
        else if( y < PaletteSize * 8 )
            CurrentBorderColor = DarkRed;
        else if( y < PaletteSize * 9 )
            CurrentBorderColor = DarkMagenta;
        else if( y < PaletteSize * 10 )
            CurrentBorderColor = LightGray;
    }        
    
    // change the border color of the shape icons when a new color is selected
    changeIconBorderColor();
}

void selectShape( int x, int y )
{
    IsShapeSelected = true;

    // first column shapes
    if( x <= 46 )
    {
	    if( y <  PaletteSize * 11 )
        {
            CurrentShapeType = ELLIPSES_SHAPE;
            CurrentFillValue = false;
        }
        else if( y < PaletteSize * 12 )
	    {    
            CurrentShapeType = RECTANGLE_SHAPE;
            CurrentFillValue = false;
        }
    }
    // second column shape
    else
    {
        if( y <  PaletteSize * 11 )
        {
            CurrentShapeType = ELLIPSES_SHAPE;
            CurrentFillValue = true;   
        }
        else if( y < PaletteSize * 12 )
        {
            CurrentShapeType = RECTANGLE_SHAPE;
            CurrentFillValue = true;
        }
        else if( y < PaletteSize * 13 )
            CurrentShapeType = LINE_SHAPE;
    }        
}

void selectFillColor( int x, int y )
{
    // first column colors
    if( x <= 46 )
    {
	    if( y <  PaletteSize * 1 )
	        CurrentFillColor = Gray;
	    else if( y < PaletteSize * 2 )
	        CurrentFillColor = Purple;
	    else if( y < PaletteSize * 3 )
	        CurrentFillColor = Blue;
	    else if( y < PaletteSize * 4 )
	        CurrentFillColor = Cyan;
	    else if( y < PaletteSize * 5 )
	        CurrentFillColor = Green;
	    else if( y < PaletteSize * 6 )
	        CurrentFillColor = Yellow;
	    else if( y < PaletteSize * 7 )
	        CurrentFillColor = Orange;
	    else if( y < PaletteSize * 8 )
	        CurrentFillColor = Red;
	    else if( y < PaletteSize * 9 )
	        CurrentFillColor = Magenta;
	    else if( y < PaletteSize * 10 )
	        CurrentFillColor = White;
    }
    // second column colors
    else
    {
        if( y <  PaletteSize * 1 )
            CurrentFillColor = DarkGray;
        else if( y < PaletteSize * 2 )
            CurrentFillColor = DarkPurple;
        else if( y < PaletteSize * 3 )
            CurrentFillColor = DarkBlue;
        else if( y < PaletteSize * 4 )
            CurrentFillColor = DarkCyan;
        else if( y < PaletteSize * 5 )
            CurrentFillColor = DarkGreen;
        else if( y < PaletteSize * 6 )
            CurrentFillColor = DarkYellow;
        else if( y < PaletteSize * 7 )
            CurrentFillColor = DarkOrange;
        else if( y < PaletteSize * 8 )
            CurrentFillColor = DarkRed;
        else if( y < PaletteSize * 9 )
            CurrentFillColor = DarkMagenta;
        else if( y < PaletteSize * 10 )
            CurrentFillColor = LightGray;
    }   
    
    // change the colors of the icons once a new color is selected
    changeIconFillColor();
}

///I was going to use Shape* CurrentShape (it's declared above already) 
/// and initialize it here with global variable above, CurrentFillColor, 
/// CurrentBorderColor, CurrentFillValue, there's x1, y1, x2, y2 which you 
///can figure out the center point from.
///I am really at a loss as to how to do ellipses though
void createShape()
{
    /*Since every shape will start with a line, we only need to find the
    center point once*/
     float xC, yC;
     x1 < x2 ? xC = x1 + (x2-x1)/2 : xC = x2 + (x1-x2)/2;
     y1 < y2 ? yC = y1 + (y2 - y1 )/2 : yC = y2 + (y1 - y2 )/2;
    
    //check the shape type, create the shape, and add it to drawn shapes array
    switch( CurrentShapeType )
    {
        case LINE_SHAPE:
            //a new shape object must be created to add it to the vector
            Line *newLine = new *Line(xC, yC, CurrentBorderColor, x1, y1, x2, y2);
            DrawnShapes.add(newLine);
            //set the current shape to the most recently instantiated
            CurrentShape = newLine;
            break;

        case ELLIPSES_SHAPE:
            //calculate the xRadius and yRadius before creating new ellipses
            float xR, yR;
            xC > x1 ? xR = xC - x1 : xR = xC - x2;
            yC > y1 ? yR = yC - y1 : yR = yC - y2;
            //a new shape object must be created to add it to the vector
            Ellipses *newEllipses = new *Ellipses( xC, yC, CurrentBorderColor, CurrentFillColor, w, h, CurrentFillValue );
            DrawShapes.add(newEllipses);
            //set the current shape to the most recently instantiated
            CurrentShape = newEllipses;
            break;

        case RECTANGLE_SHAPE:
            //calculate the height and width before creating new ellipses
            float h, w;
            x1 > x2 ? w = x1 - x2 : w = x2 - x1;
            y1 > y2 ? h = y1 - y2 : h = y2 - y1;
            //a new shape object must be created to add it to the vector
            Rectangle *newRectangle = new *Rectangle ( xC, yC, CurrentBorderColor, CurrentFillColor, w, h, CurrentFillValue );
            DrawnShapes.add(newRectangle);
            //set the current shape to the most recently instantiated
            CurrentShape = newRectangle;
            break;
    }
}

// change the border color of the icons when a new border color is selected
void changeIconBorderColor()
{
    EllipsesIcon -> setBorderColor( CurrentBorderColor );
    FilledEllipsesIcon -> setBorderColor( CurrentBorderColor );
    RectangleIcon -> setBorderColor( CurrentBorderColor );
    FilledRectangleIcon -> setBorderColor( CurrentBorderColor );
    LineIcon -> setBorderColor( CurrentBorderColor );
 
    // refresh the screen   
    glutPostRedisplay();
}

// change the fill color of the icons when a new fill color is selected
void changeIconFillColor()
{
    // to acess the subclasses, you have to typecast the shape pointer
    ((Ellipses*) FilledEllipsesIcon) -> setFillColor( CurrentFillColor );
    ((Rectangle*) FilledRectangleIcon) -> setFillColor( CurrentFillColor );
    
    // refresh the screen
    glutPostRedisplay();
}

void selectDrawnShape (int x, int y)
{
    new std::vector<*Shape> tempShapeList;
    Shape* tempShape = new *Shape;
    int i;
    /*traverse the list of drawn shapes and add any shape with a center 
    point within a distance of 10 from the selected point to the 
    temporary shape list*/
    for (i = 0; i < DrawShapes.size(); i++)
    {
        tempShape = DrawnShapes[i];
        if ( (abs(x-tempShape->xC) <= 10) && (abs(y-tempShape->yC) <= 10) )
            tempShapeList.add(DrawnShapes[i]);
    }

    //set the current shape to the first shape in the temporary shape list
    CurrentShape = tempShapeList[0];
    /*traverse the temporary shape list, and set the shape with the shortest
    distance to the selected point as the current shape. If multiple shapes
    are the same distance, the most recently added (i.e., last in the list)
    will be the current shape*/
    for (i = 0; i < tempShapeList.size(); i++)
    {
        tempShape = tempShapeList[i];
        if ( (abs(x - tempShape->xC) <= abs(x - currentShape->xC) ) 
            && (abs(y - tempShape->yC) <= abs(y - CurrentShape->yC)))
            CurrentShape = tempShapeList[i];
    }
}