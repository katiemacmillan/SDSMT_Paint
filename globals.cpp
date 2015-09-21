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

const float* ColorList[] = { Gray, Purple, Blue, Cyan, Green, 
        Yellow, Orange, Red, Magenta, White, 
        DarkGray, DarkPurple, DarkBlue, DarkCyan, DarkGreen, 
        DarkYellow, DarkOrange, DarkRed, DarkMagenta, LightGray, 
        Black };

