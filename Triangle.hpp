#include "Shape.hpp"

class Triangle:public Shape
{
    public:
        using Shape::Shape;
        bool collison(Coords coords) override;
        void fill();
        void flip();
        int orientation = 1;
};