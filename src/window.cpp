#include "core.h"
#include "window.h"
#include <stdio.h>

//#ifdef _WIN32
//#include <SDL2\SDL.h>
//#include <SDL2\SDL_image.h>
//#elif __APPLE__
//#include <SDL.h>
//#include <SDL_image.h>
//#endif

/* GLOBALS */
SDL_Window *WIN;
SDL_Renderer *REN;

void init_window()
{
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);

    WIN = SDL_CreateWindow(WINDOW_TITLE,
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE);

    if (WIN == NULL) {
        printf("Failed to create window!: %s\n", SDL_GetError());
    }

    REN = SDL_CreateRenderer(WIN, -1, SDL_RENDERER_ACCELERATED);
    if(!REN) {
		printf("Failed to make REN:%s\n", SDL_GetError());
	}
}

void pause(int time)
{
    SDL_Delay(time);
}

void close_window()
{
    SDL_DestroyRenderer(REN);
    SDL_DestroyWindow(WIN);
    IMG_Quit();
    SDL_Quit();
}
