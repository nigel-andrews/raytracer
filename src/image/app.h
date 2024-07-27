#pragma once

#include <SDL2/SDL.h>
#include <cassert>
#include <memory>

namespace raytracer::image
{
    class window_application
    {
    public:
        window_application(const char* title, int width, int height)
            : window_application(title, width, height, 0, 0)
        {}

        window_application(const char* title, int width, int height,
                           std::uint32_t window_flags,
                           std::uint32_t renderer_flags)
            : window_(SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED,
                                       SDL_WINDOWPOS_UNDEFINED, width, height,
                                       window_flags))
            , renderer_(SDL_CreateRenderer(window_, -1, renderer_flags))
        {
            if (!window_ || !renderer_)
            {
                throw std::runtime_error("Failed to create SDL window !");
            }
        }

        window_application(const window_application&) = delete;
        window_application& operator=(const window_application&) = delete;

        void run()
        {
            // TODO: run
            SDL_Delay(1000);
        }

    private:
        SDL_Window* window_;
        SDL_Renderer* renderer_;
    };

} // namespace raytracer::image
