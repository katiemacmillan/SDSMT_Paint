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

// globals to create and alter shapes
Shape* CurrentShape; // current shape object about to be drawn or altered
const float* CurrentBorderColor = Yellow; // current border color selected by user
const float* CurrentFillColor = Orange;  // current fill color selected by user
Shapes CurrentShapeType = RECTANGLE_SHAPE; // the type of shape selected by user
bool CurrentFillValue = true; // the indicator of filled shape or not
int x1, y1, x2, y2; // user selected points used to draw a shape
vector<Shape*> DrawnShapes; // list of shapes that have been drawn

// flags
bool IsShapeSelected = false; // if a shape icon has been selected
bool IsMovingShape = false; // is the shape being moved
int DrawCount = 1; // 1 for first point, 0 for end point and not drawing

// color palette items
float PaletteSize = 46.0;
float IconSize = 30.0;
/**************************************************************************
First column of colors for menu color palette in orderfrom bottom to top
**************************************************************************/
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
/**************************************************************************
Second column of colors for menu color palette in orderfrom bottom to top
**************************************************************************/
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

/**************************************************************************
First column of shape options for menu 
**************************************************************************/
const Shape* EllipsesTool = new Rectangle( 23, 483, White, Black, PaletteSize, PaletteSize, true );
const Shape* RectangleTool = new Rectangle( 23, 529, White, Black, PaletteSize, PaletteSize, true );
const Shape* CurrentShapeDisplay = new Rectangle( 23, 575, White, Black, PaletteSize, PaletteSize, true );
/**************************************************************************
Second column of shape options for menu 
**************************************************************************/
const Shape* FilledEllipsesTool = new Rectangle( 69, 483, White, Black, PaletteSize, PaletteSize, true );
const Shape* FilledRectangleTool = new Rectangle( 69, 529, White, Black, PaletteSize, PaletteSize, true );
const Shape* LineTool = new Rectangle( 69, 575, White, Black, PaletteSize, PaletteSize, true );

/**************************************************************************
Array of all menu shape and color options to be used when rendering the
display.
**************************************************************************/
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

/**********************************************************************
                            display
**********************************************************************
display provides OpenGL with the menue colors and shapes, as well as
the window text to be displayed so that the user interface window
can be drawn.
**********************************************************************/
void display( void )
{
    // clear the display
    glClear( GL_COLOR_BUFFER_BIT );
        
    // drawing the paint palette on the left side of the screen
    for( int i = 0; i < 26; i++ )
        PaintPalette[i] -> draw();

    // drawing the icons in the palette for the shape selection
    for( int i = 0; i < 5; i++ )
        PaletteIcons[i] -> draw();

    // write title on top of screen
    DrawTextString( "Chris and Kate Paint!", ScreenWidth / 2 - 92, ScreenHeight - 20, White );

//May I add the draw methods for the icons?    
    /*for( int i = 0; i < DrawnShapes.size(); i++)
        DrawnShapes[i].draw();*/

    glutSwapBuffers();
    // flush graphical output
    glFlush();
}

/**********************************************************************
                            reshape
**********************************************************************
reshape takes a height and width and uses openGL to redraw the window
for the user to fit the new dimentions.

parameters:     w - the desired window width
                h - the desired window height
**********************************************************************/
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

/**********************************************************************
                            keyboard
**********************************************************************
keyboard begins by compensating for the reverse y coordinate system 
within openGL. It then determines which key on the keyboard was pressed
by the user. The only significant keys are 'q', 'd', 'c' and the
esape key.

Both 'q' and the escape key will close the program. 'd' will delete 
an item and 'c' will clear all items, both will redraw the window
when their processes are complete. Any other key strokes will redraw
the window, but nothing more

parameters:     key - the character value of the key pressed
                x - the x value of the selected coordinate
                y - the y value of the selected coordinate
**********************************************************************/
void keyboard( unsigned char key, float x, float y )
{
    //correct for upside-down screen coordinates
    y = ScreenHeight - y;

    switch( key )
    {
        // Escape or 'q' quits program
        case 'q':
        case EscapeKey:
            for (int i = 0; i < DrawnShapes.size(); i++)
            {
                CurrentShape = DrawnShapes[i];
                //erase shape from DrawnShapes
                DrawnShapes.erase(DrawnShapes.begin());
                //delete shape to prevent memory leak
                delete (CurrentShape);
            }            exit( 0 );
            break;
        // Anything else redraws window
        case 'd':
            int index = selectDrawnShape(x, y);
            //erase shape from DrawnShapes
            DrawnShapes.erase(DrawnShapes.begin()+(index - 1));
            //delete shape to prevent memory leak
            delete (CurrentShape);
            break;
        //clear all shapes from display
        case 'c':
            for (int i = 0; i < DrawnShapes.size(); i++)
            {
                CurrentShape = DrawnShapes[i];
                //erase shape from DrawnShapes
                DrawnShapes.erase(DrawnShapes.begin());
                //delete shape to prevent memory leak
                delete (CurrentShape);
            }
            break;
        default:
            glutPostRedisplay();
            break;
    }
}

/**********************************************************************
                            mouseclick
**********************************************************************
mouseclick begins by compensating for the reverse y coordinate 
system within openGL. It then determines whether the left or right
mouse button was pressed by the user. Next it determines the state of 
the button, whether it has been pressed down or release.

If the left button is pressed down, it evaluates the location of the
press to determine if a shape or color is being selected, or if 
coordinates are being selected to draw a shape.

If the right button is pressed down it evaluates the location of the
press to determine if a fill color, or if an existing shape is being 
selected to be moved.

When the right button is released the x,y coordinate will become the 
new center coordinate of the CurrentShape if it is currently being 
moved.

parameters:     button - the value of the button that was clicked
                state - the state of the button
                x - the x value of the selected coordinate
                y - the y value of the selected coordinate
**********************************************************************/
void mouseclick( int button, int state, float x, float y )
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
                        createShape();
                    }
                }
            }
//What should the program do when the Left Button is released? Anything?
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
                        selectFillColor( x, y );
                }
                else
                {
                    // Test the xy for which shape you're on
                    selectDrawnShape(x,y);
                    // Move a shape
                    IsMovingShape = true
                }
            }
            // release
            else if( state == GLUT_UP )
/*I have no clue how to drag a shape... This would be the spot though where
when the right button is released, the move function should be called on CurrentShape*/
                // If you're currently dragging a shape when you release you drop the shape
                // if IsMovingShape == true, drop shape
                if(IsMovingShape)
                {
                    CurrentShape.move(x,y);
                    IsMovingShape = false;
                }
//Can this go away now?
                int hoho = 1; //need something here
            break;
    }
    ///this refreshes the page. I don't know if we need it here yet
    //glutPostRedisplay();
}

/**********************************************************************
                            
**********************************************************************
selectBorderColor examines where a button click was made to determine
which section of the menu was selected. An X coordinate under 47
indicates the first column of color options, while an x value of 47 or greater
indicates the second column of color options.

The exact color chosen is determined by the y coordinate's value.

parameters:     x - the x value of the selected coordinate
                y - the y value of the selected coordinate
**********************************************************************/
void selectBorderColor( float x, float y )
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

/**********************************************************************
                            selectShape
**********************************************************************
selectShape examines where a button click was made to determine
which section of the menu was selected. An X coordinate under 47
indicates the first column of shape options which are unfilled, while 
an x value of 47 or greater indicates the second column of shape 
options, which are either filled or a line.

The exact shape chosen is determined by the y coordinate's value.

parameters:     x - the x value of the selected coordinate
                y - the y value of the selected coordinate
**********************************************************************/
void selectShape( float x, float y )
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

/**********************************************************************
                            selectFillColor
**********************************************************************
selectFillColor examines where a button click was made to determine
which section of the menu was selected. An X coordinate under 47
indicates the first column of color options, while an x value of 47 or greater
indicates the second column of color options.

The exact color chosen is determined by the y coordinate's value.

parameters:     x - the x value of the selected coordinate
                y - the y value of the selected coordinate
**********************************************************************/
void selectFillColor( float x, float y )
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

/**********************************************************************
                            createShape
**********************************************************************
createShape looks at the global x1, x2, y1, and y2 variables to 
calculate the new shape's center point. Once this is done it looks
at the CurrentShapeType variable to determine which shape subclass
is to be instantiated.

A new object coresponding to CurrentShapeType is created and added to
the DrawnShapes vector. CurrentShape is then set to this new shape
and drawn.

If the CurrentShapeType indicates the new shape is to be an ellipses,
the x-radius and y-radius are calculated before the object is created.
Likewise, if a rectangle shape is indicated, the height and width are
calculated before it is instantiated.
**********************************************************************/
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
    CurrentShape.draw();
}

/**********************************************************************
                        changeIconBorderColor
**********************************************************************
changeIconBorderColor changes the menu icon borders to a new border
color whenever a new one is selected
**********************************************************************/
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

/**********************************************************************
                        changeIconFillColor
**********************************************************************
changeIconFillColor changes the menu icons for filled shapes
to the currently selected fill color.
**********************************************************************/
void changeIconFillColor()
{
    // to acess the subclasses, you have to typecast the shape pointer
    ((Ellipses*) FilledEllipsesIcon) -> setFillColor( CurrentFillColor );
    ((Rectangle*) FilledRectangleIcon) -> setFillColor( CurrentFillColor );
    
    // refresh the screen
    glutPostRedisplay();
}

/**********************************************************************
                        selectDrawnShape
**********************************************************************
selectDrawnShape traverses the vector of drawn shapes, examining
each shape's center point. If the center point is within a distance
of 10 from the selected coordinate it is added to a temporary vector
of shape pointers.

Once the  vector of drawn shapes has been examined, the CurrentShape
variable is set to the first shape in the temporary vector. he temporary
vector is then traversed. If a shape is found to have a smaller distance 
from the selected coordinate than CurrentShape, CurrentShape is set to
this new shape.

If multiple shapes have the same distance from the selected coordiante,
then the most recently drawn shape will be set as the value for
CurrentShape.

parameters:     x - x value of the selected coordinate
                y - y value of the selected coordinate

returns:        int - the shape's position in the vector
**********************************************************************/
int selectDrawnShape (float x, float y)
{
    new std::vector<*Shape> tempShapeList;  //holds possibly selected shapes
    new std::vector<int> shapeLocation; //holds possibly selected shapes' index
    Shape* tempShape = new *Shape; //holds shape currently being examined
    int deleteIndex = -1; //index of shape incase it is to be deleted

    //store shapes within 10 from selected point
    for (i = 0; i < DrawShapes.size(); i++)
    {
        tempShape = DrawnShapes[i];
        if ( (abs(x-tempShape->xC) <= 10) && (abs(y-tempShape->yC) <= 10) )
        {
                tempShapeList.add(DrawnShapes[i]);
                int index = i; //create a new object to be added to shapeLocation
                shapeLocation.add(index);
        }
    }

    //set the current shape to the first shape in the temporary shape list
    CurrentShape = tempShapeList[0];
    deleteIndex = shapeLocation[0];

    //set CurrentShape to closest, most recent shape
    for (i = 0; i < tempShapeList.size(); i++)
    {
        tempShape = tempShapeList[i];
        if ( (abs(x - tempShape->xC) <= abs(x - CurrentShape->xC) ) 
            && (abs(y - tempShape->yC) <= abs(y - CurrentShape->yC)))
            CurrentShape = tempShapeList[i];
            deleteIndex = shapeLocation[i];
    }
    //return index of CurrentShape in DrawnShapes
    return deleteIndex;
}