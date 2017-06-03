#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "move_input.h"

/*
 * Get user input to play the game
 * If user inputed a number outside of the board or
 *    on a full column, then continue asking user to enter
 *    another number until its correct
 */

void GET_USER_MOVE(int* move, char** board,int numRow, int numCol) {

   do {

      printf("Enter a column between 0 and %d to play in: ",(numCol-1));
      scanf("%d",move);

   } while ( !ISMOVE_ON_BOARD(*move,numRow,numCol) ||
             !ISMOVE_ON_COLS_FULL(*move, board, numRow));


}

bool ISMOVE_ON_BOARD (int move, int numRow, int numCol) {

// check if the number entered is inside the board
   return (move >= 0) && (move < numCol);
}

bool ISMOVE_ON_COLS_FULL (int move,char** board, int numRow){

// check if the move entered is not on a full collumn
   int i;
   bool value = false;

   for (i=numRow -1 ; i>= 0 ; --i) {

      if (board[i][move] == '*') {
         value = true;
         break;
      }
      else {
         value = false;
       }

      }

   return value;
}
