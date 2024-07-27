#include "image/app.h"

using namespace raytracer;

int main()
{
    SDL_CHECK(SDL_Init(SDL_INIT_EVERYTHING) == 0, return 1);

    image::window_application raytracer{ "raytracer", 800, 600 };
    raytracer.background_color_set({ 135, 206, 235, 255 });

    raytracer.run();

    return 0;
}
