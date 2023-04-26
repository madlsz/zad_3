#pragma once
#include "Coords.hpp"
#include "Rgb.hpp"
#include <iostream>

class Shape
{
    public:
        int ** matrix;
        char symbol;
        int height;
        int width;
        Coords coords;
        Rgb rgb;
        Shape(int height, int width, Coords coords, Rgb rgb, char symbol);
        ~Shape();
        virtual bool collison(Coords coords){return true;}
};