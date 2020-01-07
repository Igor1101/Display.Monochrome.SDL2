/*
 * conf.h
 *
 *  Created on: Jan 6, 2020
 *      Author: igor
 */

#ifndef APP_HPP_
#define APP_HPP_

#include <SDL2/SDL.h>

class App{
private:
	int width;
	int height;
	int actual_width;
	int actual_height;
	SDL_Renderer* ren;
	SDL_Window* win;
	void init_sdl2(void);
	void fill(Uint8 *image, int width, int height);
public:
	void init(void);
	void init(int width, int height, int pixelperrealpixel);
	void init(int width, int height);
	void out(void*image, int width, int height);
	void exit_prog(int stat);
};


#endif /* APP_HPP_ */
