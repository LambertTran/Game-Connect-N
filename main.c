#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "board.h"
#include "game_input.h"
#include "game_over.h"
#include "move_input.h"
#include "play_move.h"


int main(int argc,char** argv) {

   int numRow,numCol,num2Win;
   char** board= NULL;
   int move;
   int turn = 0;

   VALIDATE_INPUT(argc,argv);
   CONSTANT_VALUE(argc,argv,&numRow,&numCol,&num2Win);

   SETUP_BOARD(numRow,numCol, &board);
   DISPLAY_BOARD(numRow,numCol,board);

while (!GAME_OVER(board,numRow,numCol,num2Win)) {
   GET_USER_MOVE(&move,board,numRow,numCol);
   PLAY_MOVE(move,board,numRow,turn);
   DISPLAY_BOARD(numRow,numCol,board);
   SWITCH_USER(&turn);
 }

   DECLEAR_WINNER(board,numRow,numCol,num2Win,turn);
   CLEAN_UP_BOARD(&board,numRow);
return 0;

}
