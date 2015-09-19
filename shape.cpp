#include shape.h

float X1, Y1, X2, Y2;
        //Center Point
        float Xc, Yc;
        //filled color
        float fColor[];
        //border color
        float bColor[];
        bool filled;

Shape::Shape( float x1 = 0.0, float y1 = 0.0, float x2 = 0.0, float y2 = 0.0, float[] fC = {0}, float[] bC = {0}, bool fill = false )
: X1(x1), Y1(y1), X2(x2), Y2(y2), fColor(fc), bColor(bc), filled(fill)
{
    x1 < x2 ? Xc = x1 + (x2-x1)/2 : Xc = x2 + (x1-x2)/2;
    y1 < y2 ? Yc = y1 + (y2 - y1 )/2 : Yc = y2 + (y1 - y2 )/2;
}


// Change color of the object
void Shape::changeBorderColor( float[] color )
{
	fColor = color;
}

void Shape::changeFillColor( float[] color )
{
	bColor = color;
}

//Move shape to new center point
void moveTo( float x, float y )
{
    //distance from center point to x & y coordinates to create offset
    float xdif, ydiff;
    X1 < X2 ? xdiff = Xc - X1 : xdiff = Xc - X2;
    Y1 < Y2 ? ydiff = Yc - Y1 : ydiff = Yc - Y2;
    //Assign new center point
    Xc = x;
    Yc = y;
    //Nex (x,y) coordinates are at offset from center point
    X1 = Xc - xdiff;
    X2 = Xc + xdiff;
    Y1 = Yc - ydiff;
    Y2 = Yc + ydiff;
    draw();
}

//Erase a selected object
void Shape::erase(ShapeNode* selected) const
{
    ShapeNode* prev = selected->previous;
    ShapeNode* next = selected->next;
    prev->next = next;
    next->previous = prev;
    delete selected();
}