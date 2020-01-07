/*
 * app.cpp
 *
 *  Created on: Jan 6, 2020
 *      Author: igor
 */

#include <SDL2/SDL.h>
#include "common.h"
#include "app.hpp"
static void fill_surface(uint8_t*image, SDL_Renderer*ren, int width, int height);
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
	rendererFlags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
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

void App::out(void*image, int width, int height)
{
	SDL_SetRenderDrawColor(ren, 0,0,0,0);
	SDL_RenderClear(ren);
	SDL_SetRenderDrawColor(ren, 0, 0, 0, 0);
	// here get info to render
    fill((Uint8*)image, width, height);
    SDL_UpdateWindowSurface(win);
	SDL_RenderPresent(ren);
}

void App::fill(Uint8 *image, int width, int height)
{
	int pperrealp = App::actual_height / App::height;
	int x = 0;
	int y = 0;
	// for every byte
	for (int i = 0; i < width * height / 8; i++){
	    //read the byte
	    uint8_t b = image[i];
	    for (int j = 7; j >= 0; j--) {
	        //read 1 bit from the original byte
	        bool pixel = (b >> j) & 1;
	        SDL_Rect rect = {
	        		.x = x * pperrealp,
					.y = y * pperrealp,
					.w = pperrealp,
					.h = pperrealp
	        };
	        SDL_SetRenderDrawColor(ren, 96, 128, 255, 255);
	        if(pixel)
	        	SDL_RenderFillRect(ren, &rect);
	        SDL_SetRenderDrawColor(ren, 96, 128, 255, 0);
	        // show individual pixels
	        if(pperrealp > 6)
	        	SDL_RenderDrawRect(ren, &rect);
	        //if end of line reached, go to the next line
	        if (((x + 1) % width) == 0){
	            x = 0;
	            y++;
	        }
	        else{
	            x++;
	        }
	    }
	}
}

void App::exit_prog(int stat)
{
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
	exit(0);
}
