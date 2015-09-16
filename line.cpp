/* line.cpp */

// include files
#include <iostream>
using namespace std;

#include "line.h"

// Line class implementation

    private:
        float x1, x2, y1, y2;
        ColorType c;

    public:
        Line( float x1 = 0.0, float y1 = 0.0, float x2 = 0.0, float y2 = 0.0, ColorType c = ColorType( 0 ) );
        ~Line();
        //void moveTo( float x1, float y1, float x2, float y2 );
        void changeColor( ColorType color )
        {
        	c = color;
        }

        //void changeDimensions( ?? );
        // Should we keep the length in the class too?
        /*We could change the length by changing (x1,y1) or (x2,y2)*/
        void draw() const;
        void erase() const;
        void print( ostream& out ) const;