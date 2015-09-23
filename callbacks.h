/* callbacks.h */

#ifndef _Callbacks_H_
#define _Callbacks_H_

// function prototypes
void display( void );
void reshape( int w, int h );
void keyboard( unsigned char key, int x, int y );
void mouseclick( int button, int state, int x, int y );
void mousedrag( int x, int y );

void selectBorderColor( int x, int y );
void selectShape( int x, int y );
void selectFillColor( int x, int y );

//extern const float* CurrentBorderColor;
//extern const float* CurrentFillColor;

// flags
// is a shape selected? A new one to be drawn or to be edited
extern bool IsShapeSelected;
extern bool IsMovingShape;
extern int DrawCount;

#endif
