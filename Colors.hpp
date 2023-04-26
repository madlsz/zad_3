#pragma once
#include "Rgb.hpp"

class Colors
{
    private:
        std::string color_end;
    public:
        Colors();
        std::string wrapper(std::string text, Rgb rgb, int color_mode);
};