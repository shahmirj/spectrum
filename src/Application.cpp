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
#ifdef __WIN32__
	vector<BasicShape> shapes = lvlLoader->Load("..\\levels\\spectrumtest.spe");
#else
	vector<BasicShape> shapes = lvlLoader->Load("./levels/spectrumtest.spe");
#endif

	for(int i = 0; i < shapes.size(); ++i)
	{
		SurfaceRectangle rec(screen, shapes[i].x, shapes[i].y, shapes[i].width, shapes[i].height);
		rec.setColor(colorDefinitions.map[shapes[i].color].r, colorDefinitions.map[shapes[i].color].g, colorDefinitions.map[shapes[i].color].b);
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
	for(int i = 0; i < surfaces.size(); ++i)
	{
		surfaces[i].draw();
	}

    SDL_Flip(screen);
}

void Application::OnKeyEvent(SDL_KeyboardEvent * const key) 
{                                                           
    if (key->type == SDL_KEYUP)                             
    {                                                       
        if (key->keysym.sym == SDLK_1)                      
        {                                                   
            surfaces[0].hide();                               
            surfaces[1].show();                               
        }                                                   
        else if(key->keysym.sym == SDLK_2)                  
        {                                                   
            surfaces[0].show();                               
            surfaces[1].hide();                               
        }                                                   
    }                                                       
    else if (key->type == SDL_KEYDOWN)                      
    {                                                       
                                                            
    }                                                       
}

/**
 * Clean up our variables
 */
Application::~Application()
{
    SDL_FreeSurface(screen);
    SDL_Quit();
}


