all: hormiguero

hormiguero: command.o game_loop.o graphic_engine.o game.o space.o game_reader.o player.o object.o set.o enemy.o libscreen.a
	gcc -o hormiguero command.o game_loop.o graphic_engine.o game.o game_reader.o space.o player.o object.o set.o enemy.o -lscreen -L.

game.o: game.c game.h command.h space.h object.h player.h enemy.o types.h
	gcc -c -g -Wall -pedantic -ansi game.c

game_loop.o: game_loop.c graphic_engine.h game.h command.h game_reader.h
	gcc -c -g -Wall -pedantic -ansi game_loop.c

command.o: command.c command.h 
	gcc -c -g -Wall -pedantic -ansi command.c

graphic_engine.o: graphic_engine.c graphic_engine.h command.h space.h types.h game.h
	gcc -c -g -Wall -pedantic -ansi graphic_engine.c

game_reader.o: game_reader.c game.h space.h types.h
	gcc -c -g -Wall -pedantic -ansi game_reader.c

space.o: space.c set.h types.h space.h
	gcc -c -g -Wall -pedantic -ansi space.c

player.o: player.c types.h
	gcc -c -g -Wall -pedantic -ansi player.c

enemy.o: enemy.c types.h
	gcc -c -g -Wall -pedantic -ansi enemy.c

object.o: object.c types.h
	gcc -c -g -Wall -pedantic -ansi object.c

set.o: set.c types.h
	gcc -c -g -Wall -pedantic -ansi set.c


clean:
	rm *.o hormiguero