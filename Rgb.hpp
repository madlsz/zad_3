#pragma once

class Rgb
{
    private:
        unsigned seed;
    public:
        int r;
        int g;
        int b;
        Rgb();
        Rgb(int r, int g, int b);
        void randomize_color();
        void set(int r, int g, int b);
};