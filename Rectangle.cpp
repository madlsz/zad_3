#include <iostream>

#include "Rectangle.hpp"

bool Rectangle::collison(Coords coords)
{
    for(int y=0; y<this->height; y++)
    {
        for (int x=0; x<this->width; x++)
        {
            if (coords.x-this->coords.x == x && coords.y-this->coords.y == y)
            {
                return true;
            }
        }
    }
    return false;
}

void Rectangle::fill()
{
    // std::cout << "fill!@";
    for(int y=0; y<this->height; y++)
    {
        for(int x=0; x<this->width; x++)
        {
            if(y==0 || y==this->height-1 || x==0 || x==this->width-1)
            // if(y==0 && x==0)
            {
                this->matrix[y][x] = 1;
            }
        }
    }
}