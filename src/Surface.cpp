#include "Surface.h"

/**
 * Create a surface, object that will draw on display
 */
Surface::Surface(SDL_Surface * display)
    : surface(NULL), display(NULL)
{
    this->setDisplay(display);
    /*
    surface = SDL_CreateRGBSurface(
	    0, 
	    100, 
	    100, 
	    32, 
	    //0x000000ff, 
	    //0x0000ff00, 
	    //0x00ff0000, 
	    //0xff000000
	    0xff000000, 
	    0x00ff0000, 
	    0x0000ff00, 
	    0x000000ff
	);

    if (surface == NULL)
	throw Exception("SDL_CreateRGBSurface failed!");
	*/
}

Surface::~Surface()
{
    SDL_FreeSurface(surface);
}

/**
 * Draw the actual surface object, give the x and y offset
 */ 
void Surface::draw(int x, int y)
{
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = 20;
    rect.w = 30;

    Uint32 blue = SDL_MapRGB(display->format, 100, 100, 200);
    SDL_FillRect(display, &rect, blue);

    SDL_BlitSurface(surface, NULL, display, &rect);
}

/**
 * Setter for display
 */
void Surface::setDisplay(SDL_Surface * display)
{
    if (display == NULL)
	throw Exception("Invalid display");

    this->display = display;
}
