/*
* Copyright (c) 2022, Patrick Wilmes <patrick.wilmes@bit-lake.com>
*
* SPDX-License-Identifier: BSD-2-Clause
*/
#pragma once
#include <SDL2/SDL.h>
#include <memory>

#include "Graphics.hpp"

namespace GUI {
    class Window {
    public:
        Window(const char* title, uint32_t width, uint32_t height);

        ~Window();

        void run();

    private:
        SDL_Window* m_window = nullptr;
        SDL_Renderer* m_renderer = nullptr;
        std::shared_ptr<Graphics> m_graphics = nullptr;
    };
}
