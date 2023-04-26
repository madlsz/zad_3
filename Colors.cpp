#include <iostream>

#include "Colors.hpp"
#include "Rgb.hpp"

Colors::Colors()
{
    this->color_end = "\033[;0m";
}

// returns colored string
std::string Colors::wrapper(std::string text, Rgb rgb, int color_mode)
{
    std::string r = std::to_string(rgb.r);
    std::string g = std::to_string(rgb.g);
    std::string b = std::to_string(rgb.b);
    std::string color_beginning;
    
    // 0-nothing, 1-text, 2-background, 3-text and background
    switch (color_mode)
    {
        case 1:
            color_beginning = "\033[38;2;" + r + ";" + g + ";" + b + "m";
            break;
        case 2:
            color_beginning = "\033[48;2;" + r + ";" + g + ";" + b + "m";
            break;
        case 3:
            color_beginning = "\033[48;2;" + r + ";" + g + ";" + b + "m";
            color_beginning += "\033[38;2;" + r + ";" + g + ";" + b + "m";
            break;        
        default:
            color_beginning = "";
            break;
    }
    
    return color_beginning + text + this->color_end;
}