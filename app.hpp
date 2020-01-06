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
public:
	void init(void);
};


#endif /* APP_HPP_ */
