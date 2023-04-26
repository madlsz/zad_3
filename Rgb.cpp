#include <random>
#include <chrono>

#include "Rgb.hpp"

Rgb::Rgb()
{
    this->seed = std::chrono::system_clock::now().time_since_epoch().count();
    this->r = 0;
    this->g = 0;
    this->b = 0;
}

Rgb::Rgb(int r, int g, int b)
{
    this->seed = std::chrono::system_clock::now().time_since_epoch().count();
    this->r = r;
    this->g = g;
    this->b = b;
}

void Rgb::randomize_color()
{
    std::mt19937 gen(this->seed);
    std::uniform_int_distribution<> dist_r(37, 129);
    std::uniform_int_distribution<> dist_g(58, 140);
    std::uniform_int_distribution<> dist_b(14, 60);
    this->r = dist_r(gen);
    this->g = dist_g(gen);
    this->b = dist_b(gen);
    this->seed += 2137;
}

void Rgb::set(int r, int g, int b)
{
    this->r = r;
    this->g = g;
    this->b = b;    
}