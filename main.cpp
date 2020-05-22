// Programmer: Jessmer John Palanca
#include <iostream>
#include "Grid.hpp"

int main() {

    Grid grid{22, 36};

    int rowEdge = grid.nRows() - 1;                 // row parameter for the farthest edge (most bottom of grid)
    int colEdge = grid.nColumns() - 1;              // column parameter fot the farthest edge (most right of grid)
    int moverCurrentRow = grid.row();               // current row position of the mover
    int moverCurrentCol = grid.column();            // current column position of the mover
    bool moverOnEdge = false;                       // variable for setting whether the mover is on the edge or not

    while ((moverCurrentRow != 0) and (moverCurrentRow != rowEdge) and (moverCurrentCol != 0) and
           (moverCurrentCol !=
            colEdge)) {          // while the mover is still inside the grid, do the next statement, else, return 0
        while (!(grid.frontIsClear()) or
               (!(grid.frontIsClear()) and
                !(grid.rightIsClear()))) {     // if the front of the mover is not clear, force the mover to turn left
            moverOnEdge = true;              // the mover is on the edge of the grid
            grid.turnLeft();                 // the mover turns left to make a counter-clockwise patter around the grid
            grid.display();
        }

        while (grid.frontIsClear()) {        // while the front of the mover is clear, execute the next instructions
            if ((grid.frontIsClear() and grid.rightIsClear() and moverOnEdge == true) or
                ((!grid.frontIsClear() and grid.rightIsClear() and moverOnEdge == true))) {
                grid.turnRight();           // if the statements above are correct, this "if" statement makes the
                grid.move();                // mover exit the grid
                grid.display();             // ...
                return 0;                   // THE MOVER HAS ESCAPED THE GRID!
            } else {
                grid.move();                // else the mover keeps moving until it reaches the edge of the grid
                grid.display();
            }
        }
        if (!(grid.frontIsClear()) and grid.rightIsClear() and moverOnEdge == true) {
            grid.turnRight();
            grid.move();
            grid.display();
            return 0;
        }

    }

    grid.display();
    return 0;
}