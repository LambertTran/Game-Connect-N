connectn.out: board.o game_input.o game_over.o move_input.o main.o play_move.o
	 gcc -g -Wall -Werror -o connectn.out board.o game_input.o game_over.o move_input.o play_move.o main.o



board.o: board.c board.h
	gcc -g -Wall -Werror -c board.c


game_over.o: game_over.c game_over.h
	gcc -g -Wall -Werror -c game_over.c

game_input.o: game_input.c game_input.h
	gcc -g -Wall -Werror -c game_input.c

move_input.o: move_input.c move_input.h
	gcc -g -Wall -Werror -c move_input.c

play_move.o: play_move.c play_move.h
	gcc -g -Wall -Werror -c play_move.c

main.o: main.c board.h game_input.h game_over.h move_input.h
	gcc -g -Wall -Werror -c main.c

clean:
	rm -fr *.o *.out
