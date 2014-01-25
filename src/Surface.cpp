#include "Surface.h"

/**
 * Create a surface, object that will draw on display
 */
Surface::Surface(SDL_Surface * screen)
    : surface(NULL), screen(NULL), hidden(false) 
{
    this->setScreen(screen);
}

Surface::~Surface()
{
    SDL_FreeSurface(surface);
}

/**
 * Draw the surface, only if hide is true
 */
void Surface::draw()
{
    Uint32 color = SDL_MapRGB(
		screen->format, 
		this->color.red, 
		this->color.green, 
		this->color.blue
	    );

    // Hide the object
    //
    // Its stupid but, it is the only way I could get it working
    // Is to turn the object black
    if (hidden)
    {
	color = SDL_MapRGB(
		screen->format, 
		0, 
		0, 
		0
	    );
    }

    this->doActualDraw(color);
}

/**
 * Hide the surface
 */
void Surface::hide()
{
    hidden = true;
}

/**
 * Show the surface
 */
void Surface::show()
{
    hidden = false;
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

/**
 * Set the color.
 */
void Surface::setColor(short int r, short int g, short int b)
{
    this->color.red = r;
    this->color.green = g;
    this->color.blue = b;
}
