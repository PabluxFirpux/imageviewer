//
// Created by pabluxfirpux on 12/19/25.
//
#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#define TITLE "ImageViewer by BinaryB"

int main(int argc, char *argv[] ) {
    int width = 640;
    int height = 480;

    SDL_Window *window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, width, height, 0);
    SDL_Surface *screen = SDL_GetWindowSurface(window);
    SDL_Rect rect = {0,0,1,1};
    Uint32 color = SDL_MapRGB(screen->format,0,0,0);


    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            color = SDL_MapRGB(screen->format,x+y,x-y,x*y);
            rect.x = x;
            rect.y = y;
            SDL_FillRect(screen, &rect, color);
        }
    }


    SDL_UpdateWindowSurface(window);





    SDL_Event event;
    while (event.type != SDL_QUIT) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    SDL_Quit();
            }
        }
        SDL_Delay(100);
    }


    return 0;
}