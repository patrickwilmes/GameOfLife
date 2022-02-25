# Conway's Game Of Life

This is a implementation of Conway's Game Of Life in C++. The application uses a fixed grid (32x32)
and applies the following rules:
- Any live cell with fewer than two live neighbours dies, as if by underpopulation.
- Any live cell with two or three live neighbours lives on to the next generation.
- Any live cell with more than three live neighbours dies, as if by overpopulation.
- Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

## How to build and run
**Hint:** Make sure to have conan installed as it's used to manage dependencies in this project.

```
mkdir build
cd build
conan install .. --build=missing # install dependencies
cmake .. # generate makefiles
make # compile
bin/cgol #run
```
