/* line.h */

#ifndef _Line_H_
#define _Line_H_

#include "shape.h"
#include "globals.h"

class Line : public Shape
{
    private:
        float x1, y1, x2, y2;
    
    public:
        // constructor
        Line( float x = 0.0, float y = 0.0, const float* bColor = Black, float x1 = 0.0, float y1 = 0.0, float x2 = 0.0, float y2 = 0.0 );
        
        // destructor
        ~Line();

        //retrieve various point coordinates of the line
        float getX1 ();
        float getY1 ();
        float getX2 ();
        float getY2 ();
        //void changeDimensions( ?? );

        void draw() const;
};

#endif
