/*
 * Copyright (c) 2022, Patrick Wilmes <patrick.wilmes@bit-lake.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */
#pragma once
#include <memory>
#include "Graphics.hpp"
#include "GOL.hpp"

namespace GOL {
    /*
     * The renderer takes care of rendering a GOL game field.
     */
    class GOLRenderer final 
    {
    public:
        GOLRenderer(const std::shared_ptr<GUI::Graphics>& graphics, int window_width, int window_height);

        void render(const std::shared_ptr<GOLBoard>& gol);

    private:
        std::shared_ptr<GUI::Graphics> m_graphics;
        int m_window_width, m_window_height;
        const int m_rect_width = 10;
        const int m_rect_height = 10;
    };
}
