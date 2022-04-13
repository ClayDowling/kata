# Using This Template

This template can be used for any programming kata.  The most popular kata for
code retreats, by far, is Conway's Game of Life, and this repository has been
set up with that assumption.  The fundamentals are present for any TDD kata,
and you are encouraged to vary your practice exercise to avoid the tedium of
repetition.

## Conway's Game of Life

The universe of the Game of Life is an infinite, two-dimensional orthogonal
grid of square cells, each of which is in one of two possible states, live or
dead (or populated and unpopulated, respectively). Every cell interacts with
its eight neighbours, which are the cells that are horizontally, vertically, or
diagonally adjacent. At each step in time, the following transitions occur:

1. Any live cell with fewer than two live neighbours dies, as if by
   underpopulation.
2. Any live cell with two or three live neighbours lives on to the next
   generation.
3. Any live cell with more than three live neighbours dies, as if by
   overpopulation.
4. Any dead cell with exactly three live neighbours becomes a live cell, as if
   by reproduction.
