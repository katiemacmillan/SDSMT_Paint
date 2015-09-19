

Shape( float, float,float, float, float[], float[], bool);

// Destructor
virtual ~Shape();

// Move object
void moveTo( float, float );

// Change color of the object
void changeColor( float[] );

//Erase a selected object
void erase(ShapeNode* selected) const
{
    ShapeNode* prev = selected->previous;
    ShapeNode* next = selected->next;
    prev->next = next;
    next->previous = prev;
    delete selected();
}

// Draw a shape object
virtual void draw() const = 0;
