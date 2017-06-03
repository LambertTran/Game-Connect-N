#ifndef MOVE_INPUT_H
   #define MOVE_INPUT_H

   void GET_USER_MOVE(int* move, char** board,int numRow, int numCol);
   bool ISMOVE_ON_BOARD (int move, int numRow, int numCol);
   bool ISMOVE_ON_COLS_FULL (int move,char** board, int numRow);

#endif
