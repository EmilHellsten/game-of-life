# game-of-life
This project is an attempt to build Conway's Game of Life in C.

Game of Life is a simple simulation. In it, individual 'cells' live and die by four rules:

- #1 If a live cell currently has less than two neighbours, it will die in the next generation.
- #2 If a live cell has exactly two or three live neighbours, it will continue to live.
- #3 If a live cell has more than three live neighbours, it will die in the next generation.
- #4 If a dead cell has exaclty three live neighbours, it will gain life in the next generation.

These rules boil down to a simple if statement, which is the core of the program. The simulation initially sets up a grid of zeroes (0), and randomly flips some of these zeroes (0) to ones (1). After this setup, the simulation runs until the generation cap (3000) is reached. It can be mesmerizing to watch the simulation run it's course, generating patterns out of an initially random value.

Live cells are represented by the integer one, whereas dead cells are represented as integer zeroes.
Each cell (except for cells on the perimeter) has eight neighbouring cells.

INSTALLATION INSTRUCTIONS
The project should be installed by running 'make' in the project's root. This should compile a working version that can be run in the terminal with './gameOfLife'



TO-DO:
Ask user for starting parameters
  - classic
  - classic with extra rules
    - randomly choose a cluster of dead cells to flip into a pattern
    - spawn gliders on map to cause chaos
    - randomly swap some zeroes to ones and vice versa
  - preset maps that show cool patterns
    - 'glider' collision
  - Alternative visual representations for cells
  - Multiple states for cells
    - 0-9 with high 'fertility' around ages 2, 3, and 4
    - flip from live to dead more likely as age grows?
    - death by old age at 9?

Display additional info
  - total number of cells
  - number of live cells
  - population change per generation
    - trending up or down?

Keyboard control
  - pause functionality
    - have sleep functions argument tied to amount of live cells?
    - ask user input while paused
      - keyboard shortcuts
        - quit simu    (Q)
        - resume/pause (P)
        - wipe board   (W)
        - repop board  (R)
        - more speed   (F)
        - less speed   (S)
        - reset speed  (Z)
        - spawn shape  (X)

Notify viewer if simulation has reached a stable point
  - if board state is somehow cyclical within X generations, alert user

Refactoring
  - OS-agnostic functions (clearScreen currently only works on mac)
  - file for custom starting scenarios
  - file for shapes?
  - file for useful helper methods

  - more efficiency for larger boards

AKNOWLEDGEMENTS:
* The Coding Train's youtube channel provides a great explanation on the inner workings of Conway's Game of Life. 
* Bruce A. Maxwells 'A simple makefile tutorial' was a great resource. 
* The LifeWiki over at conwayslife.com/wiki. 