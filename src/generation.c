//Include only header files that are used within this file
#include "generation.h"
#include "grid.h"

#include <stdlib.h>//Added for malloc

//Define generationCount which is initialized as an extern int inside of generation.h
int generationCount = 0;


void updateGrid(struct Grid *grid) {
    //Mallocate for the temp grid to store the next generation's state
    int **tempGrid = (int**)malloc(grid->height * sizeof(int*));
    for (int i = 0; i < grid->height; i++) {
        tempGrid[i] = (int*)malloc(grid->width * sizeof(int));
        for (int j = 0; j < grid->width; j++) {
            //Initialize all cells in the tempGrid to dead (0)
            tempGrid[i][j] = 0;
        }
    }

    //Apply Game of Life rules to populate tempGrid
    for (int cellY = 0; cellY < grid->height; cellY++) {
        for (int cellX = 0; cellX < grid->width; cellX++) {
            int liveNeighbours = countNeighbours(grid, cellY, cellX);//Find live neighbours for current cell

            //Game of Life rules with wrapping boundaries
            if (grid->cells[cellY][cellX] == 1 && (liveNeighbours == 2 || liveNeighbours == 3)) {//IF alive AND 2-3 Neigh
                //Cell stays alive
                tempGrid[cellY][cellX] = 1;
            } else if (grid->cells[cellY][cellX] == 0 && liveNeighbours == 3) {//If dead and has 3 neigh
                //Cell becomes alive
                tempGrid[cellY][cellX] = 1;
            } else {
                //Cell dies or remains dead
                tempGrid[cellY][cellX] = 0;
            }
        }
    }

    //Copy tempGrid back to the original grid
    for (int tempY = 0; tempY < grid->height; tempY++) {
        for (int tempX = 0; tempX < grid->width; tempX++) {
            grid->cells[tempY][tempX] = tempGrid[tempY][tempX];
        }
    }
    generationCount++;//Update generationCounter

    //Free the memory allocated for tempGrid
    for (int i = 0; i < grid->height; i++) {
        free(tempGrid[i]);
    }
    free(tempGrid);
}

//WRAPPING
/*
int countNeighbours(struct Grid *grid, int cellY, int cellX) {
    int liveNeighbours = 0;
    int neighborX, neighborY;

    for (int verOffset = -1; verOffset <= 1; verOffset++) {
        for (int horOffset = -1; horOffset <= 1; horOffset++) {
            //Exclude the cell itself from the count
            if (!(verOffset == 0 && horOffset == 0)) {
                //Calculate neighbor coordinates with wrapping
                neighborX = (cellX + verOffset + grid->width) % grid->width;
                neighborY = (cellY + horOffset + grid->height) % grid->height;

                //Increment count if neighbor is alive
                liveNeighbours += grid->cells[neighborY][neighborX];//Represented as either 1 or 0
            }
        }
    }
    return liveNeighbours;
}
*/

//NOWRAP
int countNeighbours(struct Grid *grid, int col, int row) {
    int liveNeighbours = 0;
    for (int verOffset = -1; verOffset <= 1; verOffset++) {
        for (int horOffset = -1; horOffset <= 1; horOffset++) {
            // Exclude the cell itself from the count
            if (verOffset == 0 && horOffset == 0) {
                continue;
            }
            
            int neighbourCol = col + verOffset; //Neighbor row
            int neighbourRow = row + horOffset; //Neighbor column

            // Check boundaries
            if (neighbourCol >= 0 && neighbourCol < grid->height && neighbourRow >= 0 && neighbourRow < grid->width) {
                liveNeighbours += grid->cells[neighbourCol][neighbourRow];
            }
        }
    }
    return liveNeighbours;
}
