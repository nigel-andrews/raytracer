#pragma once

#include <SDL2/SDL.h>

class Window
{
public:
    Window(const char* name, int x, int y, int w, int h, int flags = 0)
        : width(w)
        , height(h)
        , window_(SDL_CreateWindow(name, x, y, w, h, flags))
        , renderer_(
              SDL_CreateRenderer(this->window_, -1, SDL_RENDERER_TARGETTEXTURE))
    {}

    Window(const char* name, int w, int h, int flags = 0)
        : Window(name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h,
                 flags)
    {}

    ~Window()
    {
        SDL_DestroyWindow(window_);
    }

    operator bool() const
    {
        return this->window_ != nullptr;
    }

    // TODO : Pass image to draw
    void draw() const
    {
        SDL_RenderClear(this->renderer_);
        SDL_RenderPresent(this->renderer_);
    }

    int width;
    int height;

private:
    SDL_Window* window_;
    SDL_Renderer* renderer_;
};
