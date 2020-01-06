/*
 * app.cpp
 *
 *  Created on: Jan 6, 2020
 *      Author: igor
 */

#include <SDL2/SDL.h>
#include "common.h"
#include "app.hpp"
void App::init(void)
{
	init_sdl2();
}

void App::init(int width, int height, int pixelperrealpixel)
{
	App::width = width;
	App::height = height;
	App::actual_width = pixelperrealpixel * width;
	App::actual_height = pixelperrealpixel * height;
	init_sdl2();
}

void App::init(int width, int height)
{
	App::width = width;
	App::height = height;
	App::actual_width = width;
	App::actual_height = height;
	init_sdl2();
}

void App::init_sdl2(void)
{
	int rendererFlags, windowFlags;
	rendererFlags = SDL_RENDERER_ACCELERATED;
	windowFlags = SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN;
	if (SDL_Init(SDL_INIT_VIDEO) < 0){
		pr_err("Couldn't initialize SDL: %s", SDL_GetError());
		exit(1);
	}
	win = SDL_CreateWindow(TARGET_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, actual_width, actual_height, windowFlags);
	if (!win){
		pr_err("Failed to open %d x %d window: %s", actual_width, actual_height, SDL_GetError());
		exit(1);
	}
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	ren = SDL_CreateRenderer(win, -1, rendererFlags);
	if (!ren){
		pr_err("Failed to create renderer: %s", SDL_GetError());
		exit(1);
	}
}
