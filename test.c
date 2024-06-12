#include "utils.h"

#include<SDL2/SDL.h>
#include<SDL2/SDL_hints.h>
#include<SDL2/SDL_error.h>
#include<SDL2/SDL_log.h>
#include<SDL2/SDL_video.h>
#include<SDL2/SDL_render.h>
#include<SDL2/SDL_pixels.h>
#include<SDL2/SDL_rect.h>
#include<SDL2/SDL_surface.h>
#include<SDL2/SDL_clipboard.h>
#include<SDL2/SDL_events.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDl_timer.h>
#include<SDL2/SDL_keyboard.h>
#include<SDL2/SDL_scancode.h>

#undef main

//SIZE OF THE WINDOW WILL BE CONTAINED HEAR

#define WIDTH  1600 
#define HEIGHT 800

//ALSO RENDERER AND WINDOW OBJECTS WILL BE HEAR

SDL_Window   *window;
SDL_Renderer *renderer;
u8           isClose;






i32 mapHeight = 16;
i32 mapWidth  = 64;

char map[] =  "................................................................"
						  "................................................................"
						  "................................................................"
						  "................................................................"
						  "................................................................"
						  "................................................................"
						  "................................................................"
						  "................................................................"
						  "................................................................"
						  "................................................................"
						  "................................................................"
						  "................................................................"
						  "................................................................"
						  "................................................................"
						  "................................................................"
						  "................................................................";



void initGame(){
	if(SDL_Init(SDL_INIT_EVERYTHING)) {
		ERROR_BREAK("Init Error!!!\n");
		}

	SDL_Window *window =  SDL_CreateWindow(
	                        "asd",
	                        SDL_WINDOWPOS_CENTERED,
	                        SDL_WINDOWPOS_CENTERED,
	                        WIDTH,
	                        HEIGHT,
	                        SDL_WINDOW_OPENGL
	                      );
	if(window == NULL) {
		ERROR_BREAK("Window not inited!!!\n");
		}

	renderer = SDL_CreateRenderer(window, -1, 0);

	if(renderer == NULL) {
		ERROR_BREAK("Renderer not init!!!\n");
		}
	isClose = FALSE;
	
	
}




int main(){
	initGame();
	system("Pause");
	
	printf("Nesto");
	return 0;
}