/* line.cpp */

// include files
#include <iostream>
using namespace std;

#include "line.h"

// Line class implementation

    private:
        

    public:
        Line( float X1 = 0.0, float Y1 = 0.0, float X2 = 0.0, float Y2 = 0.0, float[] bColor = float[]( 0 ) );
        ~Line();
        //void moveTo( float x1, float y1, float x2, float y2 );
        void changeColor( float[] color )
        {
        	bColor = color;
        }

        //void changeDimensions( ?? );
        // Should we keep the length in the class too?
        /*We could change the length by changing (x1,y1) or (x2,y2)*/
        void draw() const
        {
            glColor3fv( bColor );
            glBegin( GL_LINES );
                glVertex2f( X1, Y1 );
                glVertex2f( X2, Y2 );
            glEnd();
            glFlush();
        }
        void erase() const;
        void print( ostream& out ) const;