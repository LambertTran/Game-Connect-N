#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "game_over.h"

/*
 * Check if game is over
 */

bool GAME_OVER (char** board,int numRow, int numCol, int num2Win) {

   /*
    * game is over if someone win or the board is filled
    */

   return (SOMEONE_WIN (board, numRow, numCol, num2Win) ||
           BOARD_FILLED(board, numRow, numCol));
}

bool BOARD_FILLED(char** board,int numRow, int numCol){

   /*
    * check if the board is filled with '*'
    */

   int i,j;
   bool value = false;

   for (i=0; i<numRow; ++i) {
      for (j=0; j<numCol; ++j) {
         if (board[i][j] == '*') {
            value = false;
            break;
         }
         else {
            value = true;
         }
      }
   }
   return value;
}

bool SOMEONE_WIN (char** board, int numRow, int numCol, int num2Win) {

   /*
    * There are 3 ways to win:
    *    connect N numbers of same symbol in same row
    *                                  or in same columns
    *                                  or in same diagonal
    */

   return (ISCOL_WIN(board,numRow,numCol,num2Win) ||
           ISROW_WIN(board,numRow,numCol,num2Win) ||
           ISDIAGONAL_WIN(board,numRow,numCol,num2Win)) ;
}

bool ISCOL_WIN (char** board, int numRow, int numCol, int num2Win) {

// check if player connect N numbers of symbol in same column

   return (COLUMN_WIN(board,numRow,numCol,num2Win,'X') ||
           COLUMN_WIN(board,numRow,numCol,num2Win,'O'));
}

bool ISROW_WIN (char** board, int numRow, int numCol, int num2Win){

// check if player connect N numbers of symbol in same row

   return (ROW_WIN(board,numRow,numCol,num2Win,'X') ||
           ROW_WIN(board,numRow,numCol,num2Win,'O'));
}

bool ISDIAGONAL_WIN(char** board,int numRow,int numCol,int num2Win) {

/*
 * Check if player connect N numbers of symbol in same diagonal
 * There are 2 diagonals: left and right
 */

   return (RIGHT_DIAGONAL_WIN(board,numRow,numCol,num2Win,'X') ||
           RIGHT_DIAGONAL_WIN(board,numRow,numCol,num2Win,'O') ||
           LEFT_DIAGONAL_WIN(board,numRow,numCol,num2Win,'X') ||
           LEFT_DIAGONAL_WIN(board,numRow,numCol,num2Win,'O')) ;
}

bool COLUMN_WIN (char** board, int numRow, int numCol, int num2Win, char symbol) {

  /*  2   X
   *  1   X
   *  0   X
   *    0 1 2 3 4
   */

   int i,j;
   int next;
   bool check = false;

   for (j=0 ; j < numCol ; ++j ) {

      for (i=0; i < (numRow - num2Win) ; ++i) {

         if (board[i][j] == symbol) {
            for (next = 1; next < num2Win; ++next ) {

               if (board[i+next][j] == symbol) {
                  check = true;

                  continue;
               }
               else {
                  check = false;
                  break;
               }
            }
            if (check == true) {
               return true;
            }
         }
      }

   }
   return false;

}

bool ROW_WIN (char** board, int numRow, int numCol, int num2Win, char symbol) {

   /*  2
    *  1
    *  0 X X X O O
    *    0 1 2 3 4
    */

   int next;
   int i,j;
   bool check = false;

   for (i = 0; i <numRow; ++i) {
      for (j = 0; j < (numCol-num2Win); ++j) {
         if (board[i][j] == symbol) {

            for (next = 1; next < num2Win; ++next ) {

               if (board[i][j+next] == symbol) {
                 check = true;
                 continue;
               }
               else {
                 check = false;
                 break;
             }
            }
            if (check == true) {
               return true;
            }
         }
       }
   }
   return false;
}

bool RIGHT_DIAGONAL_WIN (char** board, int numRow, int numCol, int num2Win, char symbol){


    /*  3
     *  2        X
     *  1     X
     *  0   X
     *    0 1 2 3 4
     */

    int i,j;
    int next;
    bool check = false;

    for (i =(numRow-1) ; i >= (num2Win-1) ; --i) {
       for (j = (numCol-1); j >= (num2Win-1); --j) {
         if (board[i][j] == symbol) {

           for (next = 1; next < num2Win; ++next ) {

              if (board[i-next][j-next] == symbol) {
                 check = true;
                 continue;
              }
              else {
                 check = false;
                 break;
                 }
           }
           if (check == true) {
              return true;
           }
        }
      }
    }

    return false;
}

bool LEFT_DIAGONAL_WIN (char** board, int numRow, int numCol, int num2Win, char symbol) {

  /*  3
   *  2   X
   *  1     X
   *  0       X
   *    0 1 2 3 4
   */


  int i,j;
  int next;
  bool check = false;

  for (i =(numRow -1) ; i >= (num2Win-1) ; --i) {
     for (j = 0; j <= (numCol-num2Win); ++j) {
       if (board[i][j] == symbol) {
         for (next = 1; next < num2Win; ++next ) {

            if (board[i-next][j+next] == symbol) {
               check = true;
               continue;
            }
            else {
               check = false;
               break;
               }
         }
         if (check == true) {
            return true;
         }
      }
    }
  }

  return false;
}
