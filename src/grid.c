#include "grid.h"
#include <stdio.h>
#include <stdlib.h>

//Constants for grid size defined here
    //Width and height could by anything, but these numbers work nicely for my terminal size 
const int GRIDWIDTH = 120;
const int GRIDHEIGHT = 65;

void createGrid(struct Grid *grid, int width, int height) {
    grid->width = width;//Sets grid's width to the passed in parameter
    grid->height = height;//Sets height

    //Malloc memory for the 2d array of cells
    grid->cells = (int**)malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++) {
        grid->cells[i] = (int*)malloc(width * sizeof(int));
        //Initialize each cell to 0 (dead)
        for (int j = 0; j < width; j++) {
            grid->cells[i][j] = 0;
        }
    }
}

void drawScreen(struct Grid *grid){//This function loops through the nested 2d grid and prints the appropriate char
    for (int i = 0; i < grid->height; i++){
        for (int j = 0; j < grid->width; j++){
            printf("%s ", grid->cells[i][j] ? "●" : " "); //"." or "," also work pretty well for 'dead' cells
        }
        printf("\n");//Ensures that the horizontal rows are properly aligned
    }
}

void populateRandomly(struct Grid *grid, int fillPercent){//Randomly assigns starting value for cells by using the fillPercent parameter
    for (int i = 0; i < grid->height; i++){
        for (int j = 0; j < grid->width; j++){
            grid->cells[i][j] = (rand() % 100) < fillPercent ? 1 : 0;
        }
    }
}

void clearScreen() {//Clears the screen so the next generation's grid can be drawn
    system("clear"); //Only works on mac
}
