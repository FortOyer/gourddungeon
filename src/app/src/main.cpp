#include <SDL2/SDL.h>

#include <memory>

int main (int argc, char** argv)
{
    // 1. Initialize the game.

    // 2. Begin game loop.
    bool quit = false;
    while (!quit)
    {
        //  3. Process input
        //  4. Process network.
        //  5. Process game logic.
        //  7. Process graphics.
    }

    std::unique_ptr<SDL_Window, void (*) (SDL_Window*)> window(
        SDL_CreateWindow(
            "The Gourd Dungeon", 
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            640,
            480,
            SDL_WINDOW_SHOWN
        ),
        SDL_DestroyWindow
    );

    // Setup renderer
    std::unique_ptr<SDL_Renderer, void (*) (SDL_Renderer*)> renderer(
        SDL_CreateRenderer(window.get(), -1, SDL_RENDERER_ACCELERATED),
        SDL_DestroyRenderer
    );

    // Set render color to red ( background will be rendered in this color )
    SDL_SetRenderDrawColor( renderer.get(), 255, 0, 0, 255 );

    // Clear winow
    SDL_RenderClear( renderer.get() );

    // Creat a rect at pos ( 50, 50 ) that's 50 pixels wide and 50 pixels high.
    SDL_Rect r;
    r.x = 50;
    r.y = 50;
    r.w = 50;
    r.h = 50;

    // Set render color to blue ( rect will be rendered in this color )
    SDL_SetRenderDrawColor( renderer.get(), 0, 0, 255, 255 );

    // Render rect
    SDL_RenderFillRect( renderer.get(), &r );

    // Render the rect to the screen
    SDL_RenderPresent(renderer.get());

    // Wait for 5 sec
    SDL_Delay( 5000 );

    SDL_Quit();

    return EXIT_SUCCESS;
}