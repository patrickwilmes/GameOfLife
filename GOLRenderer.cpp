/*
 * Copyright (c) 2022, Patrick Wilmes <patrick.wilmes@bit-lake.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */
#include <iostream>
#include "GOLRenderer.hpp"

namespace GOL {
    GOLRenderer::GOLRenderer(const std::shared_ptr<GUI::Graphics>& graphics, int window_width, int window_height)
        : m_graphics(graphics),
        m_window_width(window_width),
        m_window_height(window_height)
    {
    }

    void GOLRenderer::render(const std::shared_ptr<GOLBoard>& gol)
    {
        auto cell_col_count = gol->get_width();
        auto cell_row_count = gol->get_height();
        std::cout << "col count: " << cell_col_count << std::endl;
        std::cout << "row count: " << cell_row_count << std::endl;
        int current_col = 0;
        int current_row = 0;
        auto field = gol->get_field();
        for (size_t i = 0; i < cell_col_count * cell_row_count; ++i) {
            if (current_col >= cell_col_count) {
                current_row++;
                current_col = 0;
            }
            int x_pos = current_col * m_rect_width;
            int y_pos = current_row * m_rect_height;
            std::cout << "x pos: " << x_pos << " y pos: " << y_pos << std::endl;
            GUI::Rectangle rect;
            if (field[i] == 0) {
                rect = {.x = x_pos, .y = y_pos, .width = m_rect_width-1, .height = m_rect_height-1, .color = GUI::COLOR_WHITE};
            } else {
                rect = {.x = x_pos, .y = y_pos, .width = m_rect_width-1, .height = m_rect_height-1, .color = GUI::COLOR_LIGHT_GREY};
            }
            m_graphics->draw_rectangle(rect);
            current_col++;
        }
    }
}
