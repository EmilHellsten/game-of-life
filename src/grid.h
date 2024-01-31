#ifndef GRID_H//Not def block starts
  #define GRID_H

  //Declare constants used in other files as externs
  extern const int GRIDWIDTH;
  extern const int GRIDHEIGHT;

  //Define a structure to represent a grid
  struct Grid {
    int width;//Represents grid's width on horizontal axis
    int height;//Represents grid's height on vertical axis
    int **cells;//A pointer to 2d array containing 1's or 0's (alive vs dead)
  };

  //Function declarations
  void createGrid(struct Grid *grid, int width, int height);
  void drawScreen(struct Grid *grid);
  void populateRandomly(struct Grid *grid, int fillPercent);
  void clearScreen();
#endif //Not def block ends
