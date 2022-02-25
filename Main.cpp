/*
 * Copyright (c) 2022, Patrick Wilmes <patrick.wilmes@bit-lake.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */
#include "Window.hpp"

int main(int argc, char **argv) 
{
    GUI::Window window("Conway's Game Of Life", 800, 600);
    window.run();
}
