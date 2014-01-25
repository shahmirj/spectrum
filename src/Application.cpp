#include "Application.h"
    
Application::Application()
    : running(true), screen(NULL), x(1)
{
}

/**
 * Initialize our Application.
 *
 * Really should be in the constructor
 */
bool Application::OnInit()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) 
        return false;
 
    SDL_WM_SetCaption("Spectrum", NULL);

    screen = SDL_SetVideoMode(
		    640,
		    480, 
		    32, 
		    SDL_SWSURFACE | SDL_DOUBLEBUF | SDL_ANYFORMAT
	    );

    if(screen == NULL)
        return false;

    surface1 = new SurfaceRectangle(screen, 10, 10, 100, 10);
    surface1->setColor(255, 0, 0);
    surface2 = new SurfaceRectangle(screen, 10, 30, 50, 10);
    surface2->setColor(0, 0, 255);
 
    return true;
}

/**
 * Start our execute loop
 */
int Application::run()
{
    if(OnInit() == false) 
        return -1;

    SDL_Event Event;

    while(running) 
    {
        while(SDL_PollEvent(&Event)) 
        {
            OnEvent(&Event);
        }

        OnLoop();
        OnRender();

	SDL_Delay(25);
    }

    return 0;
}

/**
 * Check for events
 */
void Application::OnEvent(SDL_Event * event) 
{
    switch (event->type)
    {
	case SDL_QUIT:
	    running = false;
	    break;
	case SDL_KEYUP:
	    OnKeyEvent(&event->key);
	    break;
	default:
	    break;
    }
}

/**
 * Game logic. 
 *
 * Simple test to expand the surface
 */ 
void Application::OnLoop()
{ 
}

/**
 * Render our App
 */
void Application::OnRender()
{
    surface1->draw();
    surface2->draw();
    SDL_Flip(screen);
}

/**
 * Clean up our variables
 */
Application::~Application()
{
    SDL_FreeSurface(screen);
    SDL_Quit();
}

/**
 * Handle key events when key is pressed
 */
void Application::OnKeyEvent(SDL_KeyboardEvent * const key)
{
    if (key->type == SDL_KEYUP)
    {
	if (key->keysym.sym == SDLK_0)
	{
	    surface1->hide();
	    surface2->show();
	}
	else
	{
	    surface1->show();
	    surface2->hide();
	}
    }
    else if (key->type == SDL_KEYDOWN)
    {

    }
}
