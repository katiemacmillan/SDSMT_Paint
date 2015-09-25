/* line.h */

#ifndef _Line_H_
#define _Line_H_

#include "shape.h"
#include "globals.h"

class Line : public Shape
{
    /******Class Data******/
    private:
        float x1, y1, x2, y2;
    
    public:
        /******Constructor******/
        Line( float x = 0.0, float y = 0.0, const float* bColor = Black, float x1 = 0.0, float y1 = 0.0, float x2 = 0.0, float y2 = 0.0 );
        
        /******Copy Constructor******/
        Line( const Line& );

        /******Destructor******/
        ~Line();

        /******Get Functions******/
        float getX1 ();
        float getY1 ();
        float getX2 ();
        float getY2 ();

        /******Set Functions******/
        void setXY1(float, float);
        void setXY2(float, float);

        /******Display Functions******/
        void moveTo( float, float );        
        void draw() const;
};

#endif
