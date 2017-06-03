#include <stdio.h>
#include <stdlib.h>
#include "play_move.h"
#include "game_over.h"

/*
 * Play the move that user entered
 * Then switch to the other user
 * Then if a player win, declear the winner
 */

void PLAY_MOVE(int move,char** board,int numRow,int turn){

   /*
    * first user's piece is X
    * second user's piece is O
    */

   char piece[] = {'X','O'};

   int i;
   for (i=0; i<numRow; ++i) {

     /*
      * run through the column in each row
      * if the position is still empty, has '*',
      * then assign that position with corresponding user's piece
      */

     if (board[i][move] == '*') {
        board[i][move] = piece[turn];
        break;
     }
   }
}

void SWITCH_USER(int* turn){

//switch user between each turn
  *turn = (*turn + 1) % 2;
}

void DECLEAR_WINNER(char** board, int numRow,int numCol, int num2Win,int turn) {


   /*
    * If a player win, declear the winner
    * If the board is full and noone win, declear a tie game
    */

   if ( SOMEONE_WIN(board,numRow,numCol,num2Win)) {
      if (turn == 1) {
         printf("Player 1 Won!\n");
      }
      else
         printf("Player 2 Won!\n");
   }
   else {
     printf("Tie game!\n");
   }
}
