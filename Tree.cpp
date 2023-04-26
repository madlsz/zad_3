#include "Tree.hpp"
#include "Coords.hpp"
#include "Rgb.hpp"

Tree::Tree(int height, Coords coords, Rgb rgb, char symbol)
{
    this->symbol = symbol;
    this->rgb = rgb;
    this->coords = coords;
    this->height = height;
    this->width = height*2-1;

    // create the matrix
    this->matrix = new int * [height];
    for (int y=0; y<this->height; y++)
    {
        this->matrix[y] = new int [this->width];
        // fill the matrix row with 0
        for (int x=0; x<this->width; x++)
        {
            this->matrix[y][x] = 0;
        }
        // put 1 where the tree shape is
        for (int x=this->height-y-1; x<this->height-y+2*y; x++)
        {
            this->matrix[y][x] = 1;
        }
    }
}

Tree::~Tree()
{
    for (int y=0; y<this->height; y++)
    {
        delete [] this->matrix[y];
    }
    delete [] this->matrix;
}

bool Tree::collison(Coords coords)
{
    for (int y=0; y<this->height; y++)
    {
        for (int x=this->height-y-1; x<this->height-y+2*y; x++)
        {
            if (coords.x-this->coords.x == x && coords.y-this->coords.y == y)
            {
                return true;
            }
        }
    }
    return false;
}