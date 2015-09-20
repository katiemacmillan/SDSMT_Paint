/* rectangle.h */

#ifndef _Rectangle_H_
#define _Rectangle_H_

class Rectangle : public Shape
{
    private:
        float width, height;
        const float* fColor;
        bool filled;

    public:
        // constructor
        Rectangle( float x = 0.0, float y = 0.0, const float* bColor = Black, const float* fColor = Black, float w = 1.0, float h = 1.0, bool f = false );
        
        // destructor
        ~Rectangle();

        // change the dimensions of the rectangle
        void changeDimensions( float, float );
        
        // draw the rectangle
        void draw() const;

        ///need to put these in shape.h I believe
        void setBorderColor( const float* bC ) const;
        void setFillColor( const float* fC ) const;

};

#endif
