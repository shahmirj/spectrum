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

	LvlLoader *lvlLoader = new LvlLoader();
	vector<BasicShape> shapes = lvlLoader->Load("C:\\Users\\Iulia\\Documents\\GitHub\\spectrum\\levels\\spectrumtest.spe");

	for(int i = 0; i < shapes.size(); ++i)
	{
		SurfaceRectangle rec(screen, shapes[i].x, shapes[i].y, shapes[i].width, shapes[i].height);
		rec.setColor(255,0,0);
		surfaces.push_back(rec);
	}

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
    if(event->type == SDL_QUIT)
        running = false;
}

/**
 * Game logic. 
 *
 * Simple test to expand the surface
 */ 
void Application::OnLoop()
{ 
	for(int i = 0; i < surfaces.size(); ++i)
	{
		surfaces[i].draw();
	}
}

/**
 * Render our App
 */
void Application::OnRender()
{
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
