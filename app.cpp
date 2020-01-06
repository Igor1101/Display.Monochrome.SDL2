/*
 * app.cpp
 *
 *  Created on: Jan 6, 2020
 *      Author: igor
 */

#include <SDL2/SDL.h>
#include "app.hpp"
void App::init(void)
{
	init_sdl2();
}

void App::init_sdl2(void)
{
	int rendererFlags, windowFlags;
	rendererFlags = SDL_RENDERER_ACCELERATED;
	windowFlags = 0;
	if (SDL_Init(SDL_INIT_VIDEO) < 0){
		printf("Couldn't initialize SDL: %s\n", SDL_GetError());
		exit(1);
	}
	win = SDL_CreateWindow("Shooter 01", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, actual_width, actual_height, windowFlags);
	if (!win){
		printf("Failed to open %d x %d window: %s\n", actual_width, actual_height, SDL_GetError());
		exit(1);
	}
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	ren = SDL_CreateRenderer(win, -1, rendererFlags);
	if (!ren){
		printf("Failed to create renderer: %s\n", SDL_GetError());
		exit(1);
	}
}
