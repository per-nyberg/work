#include <iostream>
#include <SDL.h>
#include <stdio.h>

int main(){

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		std::cout << "Error initializing SDL" << SDL_GetError();
		return 1;

	SDL_Window *window = SDL_CreateWindow("123",100,100,600,800,SDL_WINDOW_SHOWN);

	if(window == nullptr)
		std::cout << "SDL Error creating window";
		return 1;

	SDL_Renderer *render  = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if(render == nullptr){
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(render);
		std::cout << "Error creating renderer";
		SDL_Quit();
		return 1;
	}

	std::string image_path = sökväg till bild

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
	//




	SDL_Render_Clear(render); 	// tömmer videobufferten
	SDL_RenderCopy(render,bmp_texture,NULL,NULL);
	SDL_RenderPresent(render);

	SDL_Delay(2000);

	SDL_Quit();
	return 0;
}

