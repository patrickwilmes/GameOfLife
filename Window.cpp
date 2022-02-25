/*
 * Copyright (c) 2022, Patrick Wilmes <patrick.wilmes@bit-lake.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */
#include <iostream>
#include <memory>
#include "Window.hpp"
#include "GOL.hpp"
#include "GOLRenderer.hpp"

namespace GUI {

    Window::Window(const char* title, uint32_t width, uint32_t height)
    {
        if (SDL_Init(SDL_INIT_VIDEO) != 0) {
            std::cout << "SDL init failed: " << SDL_GetError() << "\n"
                      << std::flush;
            return;
        }

        // todo - also make the x,y parameters configurable
        m_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, (int)width, (int)height, SDL_WINDOW_SHOWN);
        if (m_window == nullptr) {
            std::cout << "SDL create window failed\n"
                      << std::flush;
            SDL_Quit();
            return;
        }

        m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (m_renderer == nullptr) {
            SDL_DestroyWindow(m_window);
            std::cout << "Failed to create renderer!\n"
                      << std::flush;
            SDL_Quit();
            return;
        }

        m_graphics = std::make_shared<Graphics>(m_renderer);
    }

    Window::~Window()
    {
        if (m_renderer != nullptr)
            SDL_DestroyRenderer(m_renderer);

        if (m_window != nullptr)
            SDL_DestroyWindow(m_window);

        SDL_Quit();
    }

    void Window::run()
    {
        std::shared_ptr<GOL::GOLBoard> gol = std::make_shared<GOL::GOLBoard>(32, 32);
        GOL::GOLRenderer renderer(m_graphics, 800, 600);
        bool quit = false;
        SDL_Event e;
        while (!quit) {
            while (SDL_PollEvent(&e)) {
                if (e.type == SDL_QUIT) {
                    quit = true;
                }
            }
            m_graphics->clear();
            gol->simulate();
            renderer.render(gol);
            m_graphics->present();
            SDL_Delay(100);
        }

        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(m_window);
        SDL_Quit();
    }
}
