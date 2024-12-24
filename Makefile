SOURCES = main.c player.c walls.c screens.c

all: 
	gcc -o main $(SOURCES) -lraylib -lm -ldl -lpthread
	./main
	
val:
	valgrind ./main

clean:
	rm -f main