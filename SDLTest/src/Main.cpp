#include <iostream>
#include <SDL.h>
#include <stdio.h>

int main(){

	/*void init(){		// init SDL and create window

	}
	void close(){		// remove assets and quit SDL

	}
	void loadMedia(){	// load media

	}*/

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		std::cout << "Error initializing SDL" << SDL_GetError();
		return 1;

	SDL_Window *window = SDL_CreateWindow("123",100,100,600,800,SDL_WINDOW_SHOWN);

	if(window == nullptr)
		std::cout << "SDL Error creating window";
		SDL_Quit();
		return 1;

	SDL_Renderer *render  = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if(render == nullptr){
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(render);
		std::cout << "Error creating renderer";
		SDL_Quit();
		return 1;
	}

	std::string image_path = "C:\\Users\\Per\\Downloads\\background_550_400.bmp";

	SDL_Surface *bmp_surface = SDL_LoadBMP(image_path.c_str());
	if(bmp_surface == nullptr){
		SDL_DestroyRenderer(render);
		SDL_DestroyWindow(window);
		std::cout << "SDL error when importing bmp_surface";
		SDL_Quit();
		return 1;
	}
	SDL_Texture* bmp_texture = SDL_CreateTextureFromSurface(render,bmp_surface);
	SDL_FreeSurface(bmp_surface);

	if(bmp_texture == nullptr){
		SDL_DestroyRenderer(render);
		SDL_DestroyWindow(window);
		std::cout << "SDL error SDL_CreateTextureFromSurface";
		SDL_Quit();
		return 1;
	}

	SDL_RenderClear(render); 	// tömmer videobufferten
	SDL_RenderCopy(render,bmp_texture,NULL,NULL);
	SDL_RenderPresent(render);

	// LOOP
	bool running = true;
	while(running){
		SDL_Event event;
		while(SDL_PollEvent(&event)){

		}
	}
	SDL_Delay(4000);



	// CLEAN UP
	SDL_DestroyTexture(bmp_texture);
	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}


