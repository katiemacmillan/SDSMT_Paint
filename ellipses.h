/* ellipses.h */

#ifndef _Ellipses_H_
#define _Ellipses_H_

#include "shape.h"
#include "globals.h"

class Ellipses : public Shape
{
    /******Class Data******/
    private: 
        const float* fColor;
        float xRadius, yRadius;
        bool filled;

    public:
        /******Constructor******/
        Ellipses( float x = 0.0, float y = 0.0, const float* bColor = Black, const float* fColor = Black, float xR = 1.0, float yR = 1.0, bool f = false );
        
        /******Copy Constructor******/
        Ellipses( const Ellipses& );        

        /******Destructor******/
        ~Ellipses();

        /******Get Functions******/
        float getRadiusX();
        float getRadiusY();
        const float* getFillColor();
        bool getFilledValue();

        /******Set Functions******/
        void setFillValue( bool );
        void setFillColor( const float* );
        void changeDimensions( float, float );

        /******Display Functions******/
        void moveTo( float, float );
        void draw() const;
};

#endif
