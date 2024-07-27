#pragma once

#include <SDL2/SDL.h>
#include <cassert>
#include <memory>

#include "linalg/functions.h"
#include "linalg/vec_fwd.h"
#include "utils.h"

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
            , width_(width)
            , height_(height)
        {
            if (!window_ || !renderer_)
            {
                throw std::runtime_error("Failed to create SDL window !");
            }
        }

        ~window_application()
        {
            SDL_DestroyWindow(window_);
            SDL_DestroyRenderer(renderer_);
        }

        window_application(const window_application&) = delete;
        window_application& operator=(const window_application&) = delete;

        void background_color_set(const rgba& background_color)
        {
            background_color_.r = background_color.r;
            background_color_.g = background_color.g;
            background_color_.b = background_color.b;
            background_color_.a = background_color.a;

            SDL_SetRenderDrawColor(renderer_, background_color_.r,
                                   background_color_.g, background_color_.g,
                                   background_color_.a);
        }

        void color_pixel(const rgb& pixel_color, const vec2i& coords)
        {
            SDL_SetRenderDrawColor(renderer_, pixel_color.r, pixel_color.g,
                                   pixel_color.g, 255u);
            SDL_RenderDrawPoint(renderer_, coords.x, coords.y);
            SDL_SetRenderDrawColor(renderer_, background_color_.r,
                                   background_color_.g, background_color_.g,
                                   background_color_.a);
        }

        void render_scene();

        void run();

    private:
        SDL_Window* window_;
        SDL_Renderer* renderer_;
        rgba background_color_;
        int width_;
        int height_;
        bool running_ = true;
    };

} // namespace raytracer::image
