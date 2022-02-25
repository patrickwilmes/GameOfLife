/*
 * Copyright (c) 2022, Patrick Wilmes <patrick.wilmes@bit-lake.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */
#pragma once

#include <SDL2/SDL.h>
#include <string>

namespace GUI {
    typedef struct {
        uint8_t r, g, b, a;
    } Color;

    constexpr Color COLOR_WHITE = { .r = 255, .g = 255, .b = 255, .a = 0 };
    constexpr Color COLOR_BLACK = { .r = 0, .g = 0, .b = 0, .a = 0 };
    constexpr Color COLOR_LIGHT_GREY = { .r = 200, .g = 200, .b = 200, .a = 0 };

    typedef struct {
        int x, y, width, height;
        Color color;
    } Rectangle;

    class Graphics final {
    public:
        explicit Graphics(SDL_Renderer* renderer);

        void clear();

        void present();

        void draw_rectangle(Rectangle rectangle);

        SDL_Texture* draw_text(const std::string& message, Color color, int pt = 12);

        static int get_texture_width(SDL_Texture *texture);

        static int get_texture_height(SDL_Texture *texture);

        void draw_texture(SDL_Texture *texture, int x, int y);

    private:
        void use_draw_color(Color color);
        static SDL_Rect create_sdl_rect(Rectangle& rectangle);

    private:
        SDL_Renderer* m_renderer;
    };
}
