/*
 * Copyright (c) 2022, Patrick Wilmes <patrick.wilmes@bit-lake.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */
#include <cstddef>
#include <random>
#include "GOL.hpp"

namespace GOL {
    GOLBoard::GOLBoard(int width, int height)
        : m_width(width),
        m_height(height)
    {
        for (size_t i = 0; i < m_width * m_height; ++i) {
            bool mark = rand() > (RAND_MAX / 2);
            if (mark)
                m_field.push_back(1);
            else
                m_field.push_back(0);
        }
    }

    void GOLBoard::simulate()
    {
        auto total_size = m_width * m_height;
        for (size_t x = 0; x < m_width; ++x) {
            for (size_t y = 0; y < m_height; ++y) {
                int living_around = 0;
                auto pos = x + m_width * y;
                auto left = (x-1) + m_width * y;
                auto right = (x+1) + m_width * y;
                auto top = x + m_width * (y - 1);
                auto bottom = x + m_width * (y + 1);
                auto top_left = (x-1) + m_width * (y - 1);
                auto top_right = (x+1) + m_width * (y - 1);
                auto bottom_left = (x-1) + m_width * (y + 1);
                auto bottom_right = (x+1) + m_width * (y + 1);

                if (left >= 0 && left < total_size) {
                    if (m_field[left] == 1)
                        living_around++;
                }
                if (right >= 0 && right < total_size) {
                    if (m_field[right] == 1)
                        living_around++;
                }
                if (top >= 0 && top < total_size) {
                    if (m_field[top] == 1)
                        living_around++;
                }
                if (bottom >= 0 && top < total_size) {
                    if (m_field[bottom] == 1)
                        living_around++;
                }
                if (top_left >= 0 && top < total_size) {
                    if (m_field[top_left] == 1)
                        living_around++;
                }
                if (top_right >= 0 && top < total_size) {
                    if (m_field[top_right] == 1)
                        living_around++;
                }
                if (bottom_left >= 0 && top < total_size) {
                    if (m_field[bottom_left] == 1)
                        living_around++;
                }
                if (bottom_right >= 0 && top < total_size) {
                    if (m_field[bottom_right] == 1)
                        living_around++;
                }
                if (living_around < 2) {
                    m_field[pos] = 0; // underpopulation
                }
                if (living_around > 3) {
                    m_field[pos] = 0; // overpopulation
                }
                if (living_around == 3) {
                    if (m_field[pos] == 0)
                        m_field[pos] = 1; // comes alive
                }
            }
        }
    }

    [[nodiscard]] std::vector<int> GOLBoard::get_field()
    {
        return m_field;
    }

    [[nodiscard]] int GOLBoard::get_width()
    {
        return m_width;
    }

    [[nodiscard]] int GOLBoard::get_height()
    {
        return m_height;
    }
}
