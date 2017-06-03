#ifndef GAME_OVER_H
   #define GAME_OVER_H

   #include <stdio.h>
   #include <stdlib.h>
   #include <stdbool.h>

   bool GAME_OVER (char** board,int numRow, int numCol, int num2Win);
   bool BOARD_FILLED(char** board,int numRow, int numCol);
   bool SOMEONE_WIN (char** board, int numRow, int numCol, int num2Win);
   bool ISCOL_WIN (char** board, int numRow, int numCol, int num2Win);
   bool ISROW_WIN (char** board, int numRow, int numCol, int num2Win);
   bool COLUMN_WIN (char** board, int numRow, int numCol, int num2Win, char symbol);
   bool ROW_WIN (char** board, int numRow, int numCol, int num2Win, char symbol);
   bool LEFT_DIAGONAL_WIN (char** board, int numRow, int numCol, int num2Win, char symbol);
   bool RIGHT_DIAGONAL_WIN (char** board, int numRow, int numCol, int num2Win, char symbol);
   bool ISDIAGONAL_WIN(char** board,int numRow,int numCol,int num2Win);

#endif
