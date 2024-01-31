//Include standard libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>
//Include relevant header files
#include "grid.h"
#include "generation.h"

//Looping rules
const int numGenerations = 3000;
const int sleepTime = 1;

//Main loop
int main(){
  srand(time(NULL));//RNG seed value

  //Declare and create grid
  struct Grid grid;
  createGrid(&grid, GRIDWIDTH, GRIDHEIGHT);

  //Populate grid
  populateRandomly(&grid, 50);

  //Visualize grid
  for (int gen = 0; gen < numGenerations; gen++){
    printf("Generation: %d\n", gen);
    drawScreen(&grid);
    updateGrid(&grid);
    sleep(sleepTime);
    clearScreen();
  }

  //After simulation, free memory
  for (int i = 0; i < grid.height; i++) {
    free(grid.cells[i]);
  }
  free(grid.cells);

return 0;
}