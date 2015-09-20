/* globals.cpp */

// include files
/*#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
*/

#include <GL/freeglut.h>
#include "callbacks.h"
#include "globals.h"
#include "headers.h"
#include "shape.h"

// global vars
int ScreenWidth = 900;
int ScreenHeight = 600;
//int PaletteSize = 46;

const float* ColorList[] = { Gray, Purple, Blue, Cyan, Green, 
        Yellow, Orange, Red, Magenta, White, 
        DarkGray, DarkPurple, DarkBlue, DarkCyan, DarkGreen, 
        DarkYellow, DarkOrange, DarkRed, DarkMagenta, LightGray, 
        Black };

/*
// color palette shapes
// fist column, bottom to top
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

const Shape* ColorPalette[] = { GrayColor, PurpleColor, BlueColor, CyanColor,
                                GreenColor, YellowColor, OrangeColor, RedColor,
                                MagentaColor, WhiteColor, DarkGrayColor, 
                                DarkPurpleColor, DarkBlueColor, DarkCyanColor, 
                                DarkGreenColor, DarkYellowColor, DarkOrangeColor, 
                                DarkRedColor, DarkMagentaColor, LightGrayColor };
*/
