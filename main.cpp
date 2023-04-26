#include <iostream>

#include "Forest.hpp"
#include "Colors.hpp"
#include "Coords.hpp"
#include "Rgb.hpp"
#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Triangle.hpp"


int main()
{    
    const int forest_width = 150;
    const int forest_height = 80;
    Forest forest(forest_width, forest_height);


    Coords coords(0,0);
    Rgb rgb;
    rgb.set(255, 255, 255);

    // coords.x = 15;
    // coords.y = 20;
    // Rectangle * house = new Rectangle(10, 25, coords, rgb, '#');
    // house->fill();
    // forest.add_tree(house);

    // coords.x = 20;
    // coords.y = 24;
    // Rectangle * door = new Rectangle(6, 5, coords, rgb, '#');
    // door->fill();
    // forest.add_tree(door);

    // coords.x = 30;
    // coords.y = 24;
    // Rectangle * window = new Rectangle(4, 5, coords, rgb, '#');
    // window->fill();
    // forest.add_tree(window);

    // coords.x = 15;
    // coords.y = 16;
    // Rectangle * roof_rect = new Rectangle(5, 25, coords, rgb, '#');
    // roof_rect->fill();
    // forest.add_tree(roof_rect);

    // coords.x = 30;
    // coords.y = 13;
    // Rectangle * chimney = new Rectangle(4, 3, coords, rgb, '#');
    // chimney->fill();
    // forest.add_tree(chimney);

    // coords.x = 39;
    // coords.y = 16;
    // Triangle * roof_right = new Triangle(5, 5, coords, rgb, '#');
    // roof_right->orientation = 1;
    // roof_right->fill();
    // forest.add_tree(roof_right);

    // coords.x = 11;
    // coords.y = 16;
    // Triangle * roof_left = new Triangle(5, 5, coords, rgb, '#');
    // roof_left->orientation = 2;
    // roof_left->fill();
    // forest.add_tree(roof_left);

    coords.x = 17;
    coords.y = 20;
    Rectangle * house = new Rectangle(20, 50, coords, rgb, '#');
    house->fill();
    forest.add_tree(house);

    coords.x = 25;
    coords.y = 28;
    Rectangle * door = new Rectangle(12, 10, coords, rgb, '#');
    door->fill();
    forest.add_tree(door);

    coords.x = 27;
    coords.y = 29;
    Rectangle * door_window = new Rectangle(5, 6, coords, rgb, '#');
    door_window->fill();
    forest.add_tree(door_window);

    coords.x = 46;
    coords.y = 28;
    Rectangle * window = new Rectangle(8, 12, coords, rgb, '#');
    window->fill();
    forest.add_tree(window);

    coords.x = 48;
    coords.y = 29;
    Rectangle * window_inner = new Rectangle(6, 8, coords, rgb, '#');
    window_inner->fill();
    forest.add_tree(window_inner);

    coords.x = 17;
    coords.y = 16;
    Rectangle * roof_rect = new Rectangle(7, 50, coords, rgb, '#');
    roof_rect->fill();
    forest.add_tree(roof_rect);

    coords.x = 50;
    coords.y = 12;
    Rectangle * chimney = new Rectangle(5, 6, coords, rgb, '#');
    chimney->fill();
    forest.add_tree(chimney);

    coords.x = 66;
    coords.y = 16;
    Triangle * roof_right = new Triangle(7, 7, coords, rgb, '#');
    roof_right->orientation = 1;
    roof_right->fill();
    forest.add_tree(roof_right);

    coords.x = 11;
    coords.y = 16;
    Triangle * roof_left = new Triangle(7, 7, coords, rgb, '#');
    roof_left->orientation = 2;
    roof_left->fill();
    forest.add_tree(roof_left);
    

    #ifdef _WIN32
        system("color");
    #endif

    forest.print();
    
    return 0;
}