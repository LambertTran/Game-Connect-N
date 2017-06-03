#ifndef PLAY_MOVE_H
   #define PLAY_MOVE_H

   void PLAY_MOVE(int move,char** board,int numRow,int turn);
   void SWITCH_USER(int* turn);
   void DECLEAR_WINNER(char** board, int numRow,int numCol,int num2Win, int turn);

#endif
