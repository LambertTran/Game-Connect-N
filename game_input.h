#ifndef GAME_INPUT_H
   #define GAME_INPUT_H

   #include <stdbool.h>
   #include <stdio.h>

   void VALIDATE_INPUT(int argc, char** argv);
   bool ISFORMAT(int argc, char** argv);
   bool ISVALUE (int argc, char** argv);
   void CONSTANT_VALUE(int argc,char** argv,int* numRow,
                       int* numCol,int* num2Win);

#endif
