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

    if (argc != 2) {
        printf("Please provide image path\n");
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Unable to open file %s\n", argv[1]);
        exit(1);
    }

    // Scan for encoding
    char buffer[256];
    fscanf(file, "%s", &buffer);
    printf("Image encoding: %s\n", buffer);

    //Scan for dimensions
    fscanf(file, "%d %d", &width, &height);
    printf("Image dimensions: %dx%d\n", width, height);
    //Discard next two chars meant for max hue
    char l;
    l = (int) fgetc(file);
    l = (int) fgetc(file);





    SDL_Window *window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, width, height, 0);
    SDL_Surface *screen = SDL_GetWindowSurface(window);
    SDL_Rect rect = {0,0,1,1};
    Uint32 color = SDL_MapRGB(screen->format,0,0,0);

    char r, g, b;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {

            r = fgetc(file);
            g = fgetc(file);
            b = fgetc(file);
            color = SDL_MapRGB(screen->format,r,g,b);
            rect.x = x;
            rect.y = y;
            SDL_FillRect(screen, &rect, color);

        }
    }


    SDL_UpdateWindowSurface(window);
    fclose(file);




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