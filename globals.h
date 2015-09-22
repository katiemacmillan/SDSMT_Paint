/* globals.h */

#ifndef _Globals_H_
#define _Globals_H_

// keypresses
const int EscapeKey = 27;
// colors
const float Black[] = { 0.0, 0.0, 0.0 };
const float Red[] = { 1.0, 0.0, 0.0 };
const float DarkRed[] = { 0.5, 0.0, 0.0 };
const float Orange[] = { 1.0, 0.5, 0.0 };
const float DarkOrange[] = { 0.5, 0.25, 0.0 };
const float Green[] = { 0.0, 1.0, 0.0 };
const float DarkGreen[] = { 0.0, 0.5, 0.0 };
const float Blue[] = { 0.0, 0.0, 1.0 };
const float DarkBlue[] = { 0.0, 0.0, 0.5 };
const float Magenta[] = { 1.0, 0.0, 0.5 };
const float DarkMagenta[] = { 0.5, 0.0, 0.25 };
const float Purple[] = { 0.4, 0.0, 0.4 };
const float DarkPurple[] = { 0.2, 0.0, 0.2 };
const float Cyan[] = { 0.0, 1.0, 1.0 };
const float DarkCyan[] = { 0.0, 0.5, 0.5 };
const float Yellow[] = { 1.0, 1.0, 0.0 };
const float DarkYellow[] = { 0.5, 0.5, 0.0 };
const float White[] = { 1.0, 1.0, 1.0 };
const float LightGray[] = { 0.75, 0.75, 0.75 };
const float Gray[] = { 0.5, 0.5, 0.5 };
const float DarkGray[] = { 0.25, 0.25, 0.25 };

// global vars
extern int ScreenWidth;
extern int ScreenHeight;
extern const float* ColorList[];
extern const float* CurrentBorderColor;
extern const float* CurrentFillColor;
extern bool ShapeFilled;

#endif
