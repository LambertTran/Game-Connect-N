#ifndef BOARD_H
   #define BOARD_H

   void SETUP_BOARD(int numRow,int numCol, char*** board);
   char** MAKE_BOARD(int numRow,int numCol);
   void DISPLAY_BOARD(int numRow, int numCol, char** board);
   void CLEAN_UP_BOARD(char*** board,int numRow);

#endif
