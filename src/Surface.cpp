#include "Surface.h"

/**
 * Create a surface, object that will draw on display
 */
Surface::Surface(SDL_Surface * screen)
    : surface(NULL), screen(NULL)
{
    this->setScreen(screen);
}

Surface::~Surface()
{
    SDL_FreeSurface(surface);
}

/**
 * Move the surface
 */ 
void Surface::deltaMoveX(int x)
{
    this->rect.x += x;
}

/**
 * Move in the Y coordinate
 */
void Surface::deltaMoveY(int y)
{
    this->rect.y += y;
}

/**
 * Stretch the surface width
 */
void Surface::deltaStretchWidth(int w)
{
    this->rect.w += w;
}

/**
 * Stretch the surface height
 */
void Surface::deltaStretchHeight(int h)
{
    this->rect.h += h;
}

/**
 * Setter for screen
 */
void Surface::setScreen(SDL_Surface * screen)
{
    if (screen == NULL)
	throw Exception("Invalid screen");

    this->screen = screen;
}

/**
 * Set the rectangle value
 */
void Surface::setRectangle(const SDL_Rect * const rect)
{
    if (rect == NULL)
	throw Exception("Invalid rect");
	
    this->rect = *(rect);
}
