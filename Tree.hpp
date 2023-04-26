#pragma once
#include "Coords.hpp"
#include "Rgb.hpp"

class Tree
{
    private:
        friend class Forest;
        int ** matrix;
        char symbol;
        Coords coords;
        Rgb rgb;
    public:
        int height;
        int width;
        Tree(int height, Coords coords, Rgb rgb, char symbol);
        ~Tree();
        bool collison(Coords coords);
};