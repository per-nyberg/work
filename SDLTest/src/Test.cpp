#include <SDL.h>
#include <stdio.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main( int argc, char* args[] ){
	bool quit = false;
	SDL_Event e;
	while(!quit){	// game loop
		while(SDL_PollEvent(&e) != 0){	// event loop
			if(e.type == SDL_QUIT){		// if user exits
				quit = true;
			}
		}
	}

	return 0;

	//The window we'll be rendering to
	    /*SDL_Window* window = NULL;

	    //The surface contained by the window
	    SDL_Surface* screenSurface = NULL;

	    //Initialize SDL...
	    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	    {
	        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	    }

	    else
	     {
	         //Create window
	         window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
	         if( window == NULL )
	         {
	             printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
	         }

	         else
	         {
	             //Get window surface
	             screenSurface = SDL_GetWindowSurface(window);

	             //Fill the surface white
	             SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );

	             //Update the surface
	             SDL_UpdateWindowSurface(window);

	             //Wait two seconds
	             SDL_Delay(2000);
	         }
	     }
	    //Destroy window
	    SDL_DestroyWindow(window);

	    //Quit SDL subsystems
	    SDL_Quit();
		*/

}
