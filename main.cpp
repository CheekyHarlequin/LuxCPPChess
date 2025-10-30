#include "main_headers.hpp"
#include "headers/projectlibs.hpp"

#define WIDTH 800
#define HEIGHT 600
#define IMG_PATH "test.png"

int main(int argc, char *argv[])
{
    int test{42}; 
    std::cout << test << std::endl; // Output the test variable to the console
    // variable declarations
    SDL_Window *win = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Texture *img = NULL;
    int w, h; // texture width & height
    
    // Initialize SDL.
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
            return 1;
    
    // create the window and renderer
    // note that the renderer is accelerated
    win = SDL_CreateWindow("C(PP)hess", 100, 100, WIDTH, HEIGHT, 0);
    renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    
    // load our image
    img = IMG_LoadTexture(renderer, IMG_PATH);
    SDL_QueryTexture(img, NULL, NULL, &w, &h); // get the width and height of the texture
                                               // and declare the position
    
    SDL_Rect texr;
    texr.x = 0; texr.y = 0; // Image Position
    texr.w = w; texr.h = h; // Image Scale
    
    // main loop
    while (!false) {
        
        // event handling
        SDL_Event e;
        if ( SDL_PollEvent(&e) ) {
            if (e.type == SDL_QUIT)
                break;
            else if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_ESCAPE)
                break;
        } 
        
        // clear the screen
        SDL_RenderClear(renderer);
        // copy the texture to the rendering context
        SDL_RenderCopy(renderer, img, NULL, &texr);
        // flip the backbuffer
        // this means that everything that we prepared behind the screens is actually shown
        SDL_RenderPresent(renderer);
        
    }
    
    SDL_DestroyTexture(img);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);
    
    return 0;
}