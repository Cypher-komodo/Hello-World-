// #include <SDL/include/SDL3/SDL.h>
#include <SDL2/SDL.h>
// #include <SDL3/SDL_stdinc.h> 

int main(int argc, char* argv[]) {
    SDL_Window* window = NULL;

    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow(
        "SDL Window", 
        SDL_WINDOWPOS_UNDEFINED, 
        SDL_WINDOWPOS_UNDEFINED, 
        200, 200, 
        SDL_WINDOW_SHOWN
    );

    SDL_Delay(2000);  // Keep window open for 2 seconds

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
/*
#include <SDL2/SDL.h>
#include <stdio.h>

int main() {
    SDL_Init(SDL_INIT_VIDEO);
    
    SDL_Window* window = SDL_CreateWindow(
        "My SDL Window", 
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, 
        640, 480, 
        SDL_WINDOW_SHOWN
    );
    
    if (!window) {
        printf("Window creation error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Delay(2000);  // Wait 2 seconds
    
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return 0;
}*/