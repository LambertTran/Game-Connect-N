#include <stdio.h>
#include <stdlib.h>
#include "board.h"

/*
 * Set up the board with number of columns and rows inputed
 * Display the board that was made
 */


void SETUP_BOARD(int numRow,int numCol, char*** board){

// define board
   *board = MAKE_BOARD(numRow,numCol);
}

char** MAKE_BOARD(int numRow,int numCol){

   /*
    * Make the board with corresponding number of rows and columns
    * then, initially the board with * as blank space or empty
    * space.
    */

   int i,j;

   // allocate memory
   char** board = (char**) malloc(numRow * sizeof(char*));

   for (i=0; i<numRow; ++i) {

      board[i] = (char*) malloc(numCol * sizeof(char));

      for (j=0 ; j < numCol; ++j) {

         // initialize board with blank space
         board[i][j] = '*';
      }
   }

   return board;
}

void DISPLAY_BOARD(int numRow, int numCol, char** board) {

   /*
    * Display the board with current value in each row and column
    *    print number of row and column on the bottom and left of
    *    the board
    */

   int i,j;

   for (i=numRow-1; i >= 0; --i) {

     //print number of column on the left
     printf("%d ", i);

     //print the board
     for (j=0; j < numCol; ++j) {

         printf("%c ",board[i][j]);
      }

      printf("\n");
   }

   printf("  ");

   for (i= 0; i < numCol; ++i) {
      printf("%d ", i);
   }
   printf("\n");
}

void CLEAN_UP_BOARD(char*** board,int numRow) {

// Free all memories were allocated for the board

   int i;

   for (i=0; i < numRow; ++i) {
      free( (*board)[i] );
   }

   free(*board);
   *board =NULL;
}
