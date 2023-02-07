all: hormiguero clean

hormiguero: command.o game_loop.o graphic_engine.o game.o space.o libscreen.a
	gcc -o command.o game_loop.o graphic_engine.o game.o space.o -L. -lscreen

game.o: game.c game.h command.h space.h types.h
	gcc -c -g -Wall -pedantic -ansi game.c

game_loop.o: game_loop.c graphic_engine.h game.h command.h
	gcc -c -g -Wall -pedantic -ansi game_loop.c

command.o: command.c command.h 
	gcc -c -g -Wall -pedantic -ansi command.c

graphic_engine.o: graphic_engine.c graphic_engine.h command.h space.h types.h game.h
	gcc -c -g -Wall -pedantic -ansi graphic_engine.c

space.o: space.c types.h space.h
	gcc -c -g -Wall -pedantic -ansi space.c

clean:
	rm *.o