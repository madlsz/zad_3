#include <iostream>

#include "Forest.hpp"
#include "Colors.hpp"
#include "Coords.hpp"
#include "Rgb.hpp"
#include "Shape.hpp"

Forest::Forest(int width, int height)
{
    this->width = width;
    this->height = height;
    this->matrix = new int * [height];

    // create the matrix and fill it with zeros
    for (int y=0; y<this->height; y++)
    {
        this->matrix[y] = new int [this->width];
        for (int x=0; x<this->width; x++)
        {
            this->matrix[y][x] = 0;
        }
    }
}

Forest::~Forest()
{
    for (int y=0; y<this->height; y++)
    {
        delete [] this->matrix[y];
    }
    delete [] this->matrix;
    for (auto & tree:this->trees)
    {
        delete tree;
    }
    this->trees.clear();
}

void Forest::add_tree(Shape * tree)
{
    this->trees.push_back(tree);
    // std::cout << "Added!";
}

void Forest::clear_matrix()
{
    for (int y=0; y<this->height; y++)
    {
        for (int x=0; x<this->width; x++)
        {
            this->matrix[y][x] = 0;
        }
    }
}

// adds trees from vector to the forest matrix
void Forest::add_trees_to_matrix()
{
    for (auto & tree : this->trees)
    {
        for(int y=0; y<tree->height; y++)
        {
            for (int x=0; x<tree->width; x++)
            {
                // check if the tree "pixel" is within the forest region
                if (y+tree->coords.y >= this->height || x+tree->coords.x >= this->width)
                {
                    continue;
                }
                if (y+tree->coords.y < 0 || x+tree->coords.x < 0)
                {
                    continue;
                }

                // add the tree "pixel" to the forest matrix, shift its x and y coordinates by the tree's y and x coordinates
                this->matrix[y+tree->coords.y][x+tree->coords.x] = tree->matrix[y][x];
            }
        }
    }
}

void Forest::print()
{
    Colors colors;
    // clear the matrix (fills it with 0)
    this->clear_matrix();
    // add trees to the forest matrix
    this->add_trees_to_matrix();
    // iterate over every forest matrix cell, check which "pixel" belongs to which tree and use that tree's symbol and color
    for (int y=0; y<this->height; y++)
    {
        std::string line = "";
        Rgb border_rgb(181, 126, 220);
        
        for (int x=0; x<this->width; x++)
        {
            // draw the border
            if (y==0 && x==0 || y==0 && x==this->width-1)
            {
                line += colors.wrapper("+", border_rgb, 1);
            }
            else if (y==this->height-1 && x==0 || y==this->height-1 && x==this->width-1)
            {
                line += colors.wrapper("+", border_rgb, 1);
            }
            else if (y==0 || y ==this->height-1)
            {
                line += colors.wrapper("-", border_rgb, 1);
            } 
            else if ( x==0 || x==this->width-1)
            {
                line += colors.wrapper("|", border_rgb, 1);
            }
            
            // draw the tree
            else if (this->matrix[y][x] == 1)
            {
                for (auto & tree : this->trees)
                {
                    Coords collision_checking_coords(x,y);
                    if (tree->collison(collision_checking_coords))
                    {
                        line += colors.wrapper(std::string(1, tree->symbol), tree->rgb, 1);
                        break;
                    }
                }
            }
            
            // draw empty spaces
            else
            {
                line += " ";
            }
        }
        std::cout << line << "\n";
    }
}