#include <iostream>

#include "window.h"

int main()
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0)
        std::cout << SDL_GetError();

    Window window("Raytracer", 800, 600,
                  SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN);

    if (!window)
        std::cout << SDL_GetError();

    bool run = true;
    SDL_Event event;

    while (run)
    {
        if (!SDL_PollEvent(&event))
            continue;

        switch (event.type)
        {
        case SDL_KEYDOWN:
            run = event.key.keysym.sym != SDLK_ESCAPE;
            break;
        case SDL_QUIT:
            run = false;
            break;
        default:
            break;
        }

        window.draw();
    }

    std::cout << "Quitting\n";
    SDL_Quit();

    return 0;
}
