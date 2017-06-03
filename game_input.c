#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "game_input.h"

/*
 * Validate user's command inputs
 * If inputs are valid, then convert them to int-type
 */


void VALIDATE_INPUT(int argc, char** argv){

   /*
    * Validade user's command inputs
    * There are 4 inputs for this function:
    *    connect.out - numRow - numCol - number in a row to win
    *
    * If user inputed more than amount needed, print error and
    *    exit program
    */

   if ( !ISFORMAT(argc,argv) || !ISVALUE (argc,argv)) {
      if (argc > 4) {
      printf("Too many arguments entered\n");
      printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
      exit(0);
    }
    else if (argc < 4) {
      printf("Not enough arguments entered\n");
      printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
      exit(0);
    }
   }
   else {
     return;
   }
}

bool ISFORMAT (int argc,char** argv) {

//check the number of inputs was entered
   return (argc == 4);
}

bool ISVALUE (int argc, char** argv) {


   int i;

   for (i=1 ; i<argc; ++i ) {

      if (argv[i] <0) {
        return false;
      }
   }
   return true;
}

void CONSTANT_VALUE(int argc,char** argv,int* numRow,int* numCol,int* num2Win){

//convert all the inputed string to number

   *numRow = atoi(argv[1]);
   *numCol = atoi(argv[2]);
   *num2Win= atoi(argv[3]);

}
