/* ellipses.h */

#ifndef _Ellipses_H_
#define _Ellipses_H_

#include "shape.h"
#include "globals.h"

class Ellipses : public Shape
{
    private: 
        float xRadius, yRadius;
        const float* fColor;
        bool filled;

    public:
        // constructor
        Ellipses( float x = 0.0, float y = 0.0, const float* bColor = Black, const float* fColor = Black, float xR = 1.0, float yR = 1.0, bool f = false );
        
        // destructor
        ~Ellipses();

        // make the shape fill or no fill
        void setFillValue( bool );
        // set the fill color of the shape        
        void setFillColor( const float* );

        // change the dimentions of the ellipses
        void changeDimensions( float, float );

        // draw the ellipses, overridding the shape draw
        void draw() const;


};

#endif
