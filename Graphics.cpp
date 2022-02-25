/*
 * Copyright (c) 2022, Patrick Wilmes <patrick.wilmes@bit-lake.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */
#include <SDL_ttf.h>
#include <iostream>
#include "Graphics.hpp"

namespace GUI {

    Graphics::Graphics(SDL_Renderer* renderer)
        : m_renderer(renderer)
    {
    }

    void Graphics::clear()
    {
        use_draw_color(COLOR_BLACK);
        SDL_RenderClear(m_renderer);
    }

    void Graphics::present()
    {
        SDL_RenderPresent(m_renderer);
    }

    void Graphics::draw_rectangle(Rectangle rectangle)
    {
        use_draw_color(rectangle.color);
        auto sdl_rect = create_sdl_rect(rectangle);
        SDL_RenderFillRect(m_renderer, &sdl_rect);
    }

    SDL_Texture* Graphics::draw_text(const std::string &message, Color color, int pt)
    {
        // todo - make the font dynamic and also the font size
        TTF_Font *font = TTF_OpenFont("Meta/SourceSansPro-Regular.ttf", pt);
        if (font == nullptr) {
            std::cout << "failed to create font!\n" << std::flush;
            return nullptr;
        }

        SDL_Color sdl_color = {.r = color.r, .g = color.g, .b = color.b, .a = color.a};
        SDL_Surface *surface = TTF_RenderText_Blended(font, message.c_str(), sdl_color);
        if (surface == nullptr) {
            std::cout << "Failed to create surface\n" << std::flush;
            TTF_CloseFont(font);
            return nullptr;
        }

        SDL_Texture *texture = SDL_CreateTextureFromSurface(m_renderer, surface);
        if (texture == nullptr) {
            std::cout << "Failed to create texture\n" << std::flush;
            return nullptr;
        }
        SDL_FreeSurface(surface);
        TTF_CloseFont(font);
        return texture;
    }

    int Graphics::get_texture_width(SDL_Texture *texture) {
        SDL_Rect rect;
        SDL_QueryTexture(texture, nullptr, nullptr, &rect.w, &rect.h);
        return rect.w;
    }

    int Graphics::get_texture_height(SDL_Texture *texture) {
        SDL_Rect rect;
        SDL_QueryTexture(texture, nullptr, nullptr, &rect.w, &rect.h);
        return rect.h;
    }

    void Graphics::draw_texture(SDL_Texture *texture, int x, int y) {
        SDL_Rect rect;
        rect.x = x;
        rect.y = y;

        SDL_QueryTexture(texture, nullptr, nullptr, &rect.w, &rect.h);
        SDL_RenderCopy(m_renderer, texture, nullptr, &rect);
    }

    void Graphics::use_draw_color(Color color)
    {
        SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a);
    }

    SDL_Rect Graphics::create_sdl_rect(Rectangle& rectangle)
    {
        return {
            .x = rectangle.x,
            .y = rectangle.y,
            .w = rectangle.width,
            .h = rectangle.height,
        };
    }

}