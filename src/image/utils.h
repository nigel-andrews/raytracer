#pragma once

#include <format>
#include <iostream>

#define SDL_CHECK(Expr, ...)                                                   \
    do                                                                         \
    {                                                                          \
        if (!(Expr))                                                           \
        {                                                                      \
            std::cerr << std::format("{}\n", SDL_GetError());                  \
            __VA_ARGS__;                                                       \
        }                                                                      \
    } while (false)
