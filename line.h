/* line.h */

#ifndef _Line_H_
#define _Line_H_

#include "shape.h"

// Line class interface
class Line : public Shape
{
    private:
        float x1, x2, y1, y2;
        float[] c;

    public:
        Line( float, float, float, float, float[] );
        ~Line();
        //void moveTo( float x1, float y1, float x2, float y2 );
        void changeColor( float[] );
        //void changeDimensions( ?? );
        // Should we keep the length in the class too?
        void draw() const;
        void erase() const;
        void print( ostream& ) const;
};

#endif
