all: 
	gcc -o main main.c player.c walls.c -lraylib -lm -ldl -lpthread
	./main
	
val:
	valgrind ./main

clean:
	rm -f main