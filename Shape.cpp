#include "Shape.hpp"

Shape::Shape(int height, int width, Coords coords, Rgb rgb, char symbol)
{
    this->symbol = symbol;
    this->rgb = rgb;
    this->coords = coords;
    this->height = height;
    this->width = width;

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
        // for (int x=0; x<this->width; x++)
        // {
        //     this->matrix[y][x] = 1;
        // }
    }
    // this->fill();
}

Shape::~Shape()
{
    for (int y=0; y<this->height; y++)
    {
        delete [] this->matrix[y];
    }
    delete [] this->matrix;
}