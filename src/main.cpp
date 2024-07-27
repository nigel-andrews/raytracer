#include "image/app.h"

using namespace raytracer;

int main()
{
    if (SDL_Init(SDL_INIT_VIDEO))
    {
        throw std::runtime_error("Failed to init SDL2");
    }

    image::window_application raytracer{ "raytracer", 800, 600 };

    raytracer.run();

    return 0;
}
