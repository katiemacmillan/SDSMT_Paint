/* callbacks.h */

#ifndef _Callbacks_H_
#define _Callbacks_H_

#include "globals.h"

/*****Function Prototypes*****/
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
void dragDraw();

void selectShape( float, float );
void createShape();
void selectDrawnShape (float, float);



/*****Data for settings of currently selected shape*****/
extern const float* CurrentBorderColor;
extern const float* CurrentFillColor;
extern Shapes CurrentDrawingShape;


/*****Flags*****/
extern bool IsShapeSelected;
extern bool IsMovingShape;
extern int DrawCount;

#endif
