/* callbacks.h */

#ifndef _Callbacks_H_
#define _Callbacks_H_

#include "globals.h"

// function prototypes
void display( void );
void reshape( int w, int h );
void keyboard( unsigned char key, int x, int y );
void mouseclick( int button, int state, int x, int y );
void mousedragpassive( int x, int y );
void mousedrag( int x, int y );

void selectBorderColor( float x, float y );
void selectShape( float x, float y );
void selectFillColor( float x, float y );
void changeIconBorderColor();
void changeIconFillColor();
void changeCurrentIcon();

void selectShape( float, float );
void createShape();
void selectDrawnShape (float, float);



///if we are only using these globals in callbacks, do we need the extern?
extern const float* CurrentBorderColor;
extern const float* CurrentFillColor;
extern Shapes CurrentDrawingShape;


// flags
// is a shape selected? A new one to be drawn or to be edited
extern bool IsShapeSelected;
// are we moving a shape?
extern bool IsMovingShape;
// if a shape is selected to draw, are we on point one or two?
extern int DrawCount;

#endif
