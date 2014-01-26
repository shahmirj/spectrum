#ifndef COLOR_H_
#define COLOR_H_

#include <SDL.h>

class Color
{
public:
    Uint8 red;
    Uint8 blue;
    Uint8 green;
    Uint8 alpha;

    Color() : red(255), blue(255), green(255), alpha(255) {}
};

#endif
