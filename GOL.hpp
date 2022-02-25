/*
 * Copyright (c) 2022, Patrick Wilmes <patrick.wilmes@bit-lake.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */
#pragma once
#include <vector>

namespace GOL {
    /*
     * Contains all the logic to play the game of life.
     */
    class GOLBoard final 
    {
    public:
        /*
         * The game of life will be initialized with a width and height,
         * but the final field will be represented using a one dimensional
         * vector.
         */
        GOLBoard(int width, int height);

        /*
         * performs the next iteration following
         * the game of life rules.
         */
        void simulate();

        [[nodiscard]] std::vector<int> get_field();

        [[nodiscard]] int get_width();

        [[nodiscard]] int get_height();

    private:
        int m_width, m_height;
        std::vector<int> m_field {};
    };
}
