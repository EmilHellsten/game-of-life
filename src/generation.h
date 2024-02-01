//Not defined block starts
#ifndef GENERATION_H
  #define GENERATION_H
  #include "grid.h"

  extern int generationCount;//Initialized here

  void updateGrid(struct Grid *grid);
  int countNeighbours(struct Grid *grid, int cellX, int cellY);

#endif//Not def block ends
