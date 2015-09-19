/* rectangle.h */

#ifndef _Rectangle_H_
#define _Rectangle_H_

#include "shape.h"

// Rectangle class interface
// If we do decide to have filled rectange inherit from this, do we need to also make some of these methods virtual?
class Rectangle : public Shape
{
    private:
        float width, height;

    public:
        Rectangle( float, float, float, float, float[], float[], bool, float, float );
        ~Rectangle();
        void changeDimensions( float, float );
        void draw() const;
};

#endif
