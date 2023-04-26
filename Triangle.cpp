#include <iostream>

#include "Triangle.hpp"

bool Triangle::collison(Coords coords)
{
    if(this->orientation == 1)
    {
        for(int y=0; y<this->height; y++)
        {
            for(int x=0; x<=y; x++)
            {
                if (coords.x-this->coords.x == x && coords.y-this->coords.y == y)
                {
                    return true;
                }
            }

        }
    }
    else if(this->orientation == 2)
    {
        for(int y=0; y<this->height; y++)
        {
            for(int x=this->height-1; x>=0; x--)
            {
                if (coords.x-this->coords.x == x && coords.y-this->coords.y == y)
                {
                    return true;
                }
            }

        }  
    }

    return false;
}

void Triangle::fill()
{
    // kąt prosty w lewym dolnym
    if(this->orientation == 1)
    {
        for(int y=0; y<this->height; y++)
        {
            for(int x=0; x<=y; x++)
            {
                if(y==0 || x==0 || y==this->height-1 || x==y)
                {
                    this->matrix[y][x] = 1;
                }
                
            }
        }
    }
    // kąt prosty w prawym dolnym
    else if(this->orientation == 2)
    {
        for(int y=0; y<this->height; y++)
        {
            for(int x=this->height-1; x>=0; x--)
            {
                if((y==0&&x==this->height-1) || y==this->height-1 || x==this->height-y-1 || x==this->height-1)
                {
                    this->matrix[y][x] = 1;
                }
                
            }
        }        
    }

}

void Triangle::flip()
{
    this->orientation += 1;
    if(this->orientation >=4)
    {
        this->orientation = 1;
    }
}