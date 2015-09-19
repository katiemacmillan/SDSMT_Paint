/* line.h */

#ifndef _Line_H_
#define _Line_H_

#include "shape.h"

// Line class interface
class Line : public Shape
{
    public:
        Line( float, float, float, float, float[], float[], bool);
        ~Line();
        //void changeDimensions( ?? );
        void draw() const;
};

#endif
