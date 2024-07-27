#include "app.h"

namespace raytracer::image
{
    void window_application::render_scene()
    {
        throw std::runtime_error("Not implemented !");
    }

    void window_application::run()
    {
        while (running_)
        {
            SDL_Event event;
            while (SDL_PollEvent(&event))
            {
                SDL_RenderClear(renderer_);

                // render_scene();

                SDL_RenderPresent(renderer_);

                running_ = event.type != SDL_QUIT;
            }
        }
    }
} // namespace raytracer::image
