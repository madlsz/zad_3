#include "Shape.hpp"

class Rectangle:public Shape
{
    public:
        using Shape::Shape;
        bool collison(Coords coords) override;
        void fill();
};