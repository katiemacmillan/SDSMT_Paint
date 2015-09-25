/* rectangle.h */

#ifndef _Rectangle_H_
#define _Rectangle_H_

#include "shape.h"
#include "globals.h"

class Rectangle : public Shape
{
    /******Class Data******/
    private:
        const float* fColor;
        float width, height;
        bool filled;

    public:
        /******Constructor******/
        Rectangle( float x = 0.0, float y = 0.0, const float* bColor = Black, const float* fColor = Black, float w = 1.0, float h = 1.0, bool f = false );
        
        /******Copy Constructor******/
        Rectangle( const Rectangle& );        

        /******Destructor******/
        ~Rectangle();

        /******Get Functions******/
        float getWidth();
        float getHeight();
        const float* getFillColor();
        bool getFilledValue();

        /******Set Functions******/
        void setHeight(float);
        void setWidth(float);
        void changeDimensions( float, float );
        void setFillValue( bool );
        void setFillColor( const float* );

        /******Display Functions******/
        void moveTo( float, float );
        void draw() const;
};

#endif
