#include <SDL2/SDL.h>
#include <iostream>
#include "app.hpp"
using namespace std;
const unsigned char logo [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0x00, 0x0F, 0xFF, 0xFE, 0x0F, 0xFF, 0xC0, 0x1F, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xFE, 0x00, 0x00, 0xFC, 0x0F, 0xFF, 0xFC, 0x0F, 0xFF, 0x80, 0x1F, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xFC, 0x00, 0x00, 0xFC, 0x07, 0xFF, 0xF8, 0x0F, 0xFE, 0x00, 0x0F, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xF8, 0x00, 0x00, 0xFC, 0x03, 0xFF, 0xF8, 0x0F, 0xFE, 0x00, 0x07, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xF0, 0x00, 0x0F, 0xFC, 0x01, 0xFF, 0xF0, 0x0F, 0xFC, 0x00, 0x03, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xF0, 0x3C, 0x07, 0xFC, 0x01, 0xFF, 0xE0, 0x0F, 0xF8, 0x0F, 0x83, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xF0, 0x7F, 0x07, 0xFC, 0x00, 0xFF, 0xC0, 0x0F, 0xF8, 0x1F, 0x81, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xE0, 0xFF, 0x87, 0xFC, 0x20, 0x7F, 0xC1, 0x0F, 0xF8, 0x3F, 0xE1, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xE1, 0xFF, 0x83, 0xFC, 0x30, 0x7F, 0x81, 0x0F, 0xF8, 0x7F, 0xE1, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xE1, 0xFF, 0xC3, 0xFC, 0x38, 0xFF, 0xC3, 0x0F, 0xF8, 0x7F, 0xE0, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xE1, 0xFF, 0xC3, 0xFC, 0x39, 0xFF, 0xE7, 0x0F, 0xF0, 0xFF, 0xF0, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xE3, 0xFF, 0xC3, 0xFC, 0x3D, 0xFF, 0xFF, 0x0F, 0xF0, 0xFF, 0xF0, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xE1, 0xFF, 0xC3, 0xFC, 0x3F, 0xFF, 0xFF, 0x0F, 0xF0, 0xFF, 0xF0, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xE1, 0xFF, 0xC3, 0xFC, 0x3F, 0xFF, 0xFF, 0x0F, 0xF0, 0xFF, 0xF0, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xE1, 0xFF, 0xC3, 0xFC, 0x3F, 0xFF, 0xFF, 0x0F, 0xF0, 0xFF, 0xF0, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xE1, 0xFF, 0xC3, 0xFC, 0x3F, 0xFF, 0xFF, 0x0F, 0xF0, 0xFF, 0xF0, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xE3, 0xFF, 0xC3, 0xFC, 0x3F, 0xFF, 0xFF, 0x0F, 0xF0, 0xFF, 0xF0, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xE3, 0xFF, 0xC3, 0xFC, 0x3F, 0xFF, 0xFF, 0x0F, 0xF8, 0xFF, 0xF0, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xE3, 0xFF, 0xC3, 0xFC, 0x3F, 0xFF, 0xFF, 0x0F, 0xF8, 0xFF, 0xF0, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xE3, 0xFF, 0xC3, 0xFC, 0x3F, 0xFF, 0xFF, 0x0F, 0xF8, 0xFF, 0xF0, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xE3, 0xFF, 0xC3, 0xFC, 0x3F, 0xFF, 0xFF, 0x0F, 0xF8, 0xFF, 0xF0, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xE3, 0xFF, 0xC3, 0xFC, 0x3F, 0xFF, 0xFF, 0x0F, 0xF8, 0xFF, 0xF0, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xE3, 0xFF, 0xC3, 0xFC, 0x3F, 0xFF, 0xFF, 0x0F, 0xF8, 0xFF, 0xF0, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xE3, 0xFF, 0xC3, 0xFC, 0x3F, 0xFF, 0xFF, 0x0F, 0xF8, 0xFF, 0xF0, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xE3, 0xFF, 0xC3, 0xFC, 0x3F, 0xFF, 0xFF, 0x0F, 0xF8, 0xFF, 0xF0, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xE3, 0xFF, 0xC3, 0xFC, 0x3F, 0xFF, 0xFF, 0x0F, 0xF8, 0xFF, 0xF0, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xE3, 0xFF, 0xC3, 0xFC, 0x3F, 0xFF, 0xFF, 0x0F, 0xF8, 0xFF, 0xF0, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xE3, 0xFF, 0xC3, 0xFC, 0x3F, 0xFF, 0xFF, 0x0F, 0xF8, 0xFF, 0xF0, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xE3, 0xFF, 0xC3, 0xFC, 0x3F, 0xFF, 0xFF, 0x0F, 0xF8, 0xFF, 0xF0, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xE3, 0xFF, 0xC3, 0xFC, 0x3F, 0xFF, 0xFF, 0x0F, 0xF8, 0xFF, 0xF0, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xE3, 0xFF, 0xC3, 0xFC, 0x3F, 0xFF, 0xFF, 0x0F, 0xF8, 0xFF, 0xF0, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xE3, 0xFF, 0xC3, 0xFC, 0x3F, 0xFF, 0xFF, 0x0F, 0xF8, 0xFF, 0xF0, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xE3, 0xFF, 0xC3, 0xFC, 0x3F, 0xFF, 0xFF, 0x0F, 0xF8, 0xFF, 0xF0, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xE1, 0xFF, 0xC3, 0xFC, 0x3F, 0xFF, 0xFF, 0x0F, 0xF8, 0x7F, 0xE0, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xE1, 0xFF, 0xC3, 0xFC, 0x3F, 0xFF, 0xFF, 0x0F, 0xF8, 0x7F, 0xE1, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xE1, 0xFF, 0x87, 0xFC, 0x3F, 0xFF, 0xFF, 0x0F, 0xF8, 0x7F, 0xE1, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xE0, 0xFF, 0x87, 0xFC, 0x3F, 0xFF, 0xFF, 0x0F, 0xF8, 0x3F, 0xC1, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xF0, 0x7F, 0x07, 0xFC, 0x3F, 0xFF, 0xFF, 0x0F, 0xF8, 0x1F, 0x83, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xF0, 0x00, 0x0F, 0xFC, 0x3F, 0xFF, 0xFF, 0x0F, 0xFC, 0x00, 0x03, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xF8, 0x00, 0x0F, 0xFC, 0x3F, 0xFF, 0xFF, 0x0F, 0xFE, 0x00, 0x07, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xFC, 0x00, 0x1F, 0xFC, 0x3F, 0xFF, 0xFF, 0x0F, 0xFE, 0x00, 0x07, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xFC, 0x00, 0x1F, 0xFC, 0x3F, 0xFF, 0xFF, 0x0F, 0xFF, 0x00, 0x0F, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xFE, 0x00, 0x3F, 0xFC, 0x3F, 0xFF, 0xFF, 0x0F, 0xFF, 0x80, 0x1F, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xFF, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0x7F, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

int main(int argc, char **argv)
{
	App mainwin;
	mainwin.init(128,64,15);
	mainwin.out((void*)logo, 128, 64);

	SDL_Delay(1000);
	while (1){
		SDL_Event event;
		SDL_PollEvent(&event);
		if(event.type == SDL_QUIT || event.key.keysym.sym == 'q') {
			mainwin.exit(0);
		}
		mainwin.out((void*)logo, 128, 64);
	}
	return 0;
}
