// #include <iostream>

#include "scene/camera.h"
// #include "scene/light.h"
// #include "window.h"

int main(void)
{
    // if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0)
    //     std::cout << SDL_GetError();
    //
    // {
    //     int w = 800;
    //     int h = 600;
    //
    //     Window window("Raytracer", w, h,
    //                   SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN);
    //
    //     if (!window)
    //         std::cout << SDL_GetError();
    //
    //     bool run = true;
    //     SDL_Event event;
    //
    //     while (run)
    //     {
    //         if (!SDL_PollEvent(&event))
    //             continue;
    //
    //         switch (event.type)
    //         {
    //         case SDL_KEYDOWN:
    //             run = event.key.keysym.sym != SDLK_ESCAPE;
    //             break;
    //         case SDL_QUIT:
    //             run = false;
    //             break;
    //         default:
    //             break;
    //         }
    //
    //         // Compute and draw
    //         window.draw();
    //     }
    // }
    //
    // std::cout << "Quitting\n";
    // SDL_Quit();

    Camera camera{ 0.5f, M_PI_2, { 0, 0, 0 }, { 0, 0, 1 }, { 0, 1, 0 } };
    camera.shoot_rays(800, 600);

    return 0;
}
