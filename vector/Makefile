vector: vector.o main.o
	clear
	gcc vector.o main.o -o vector

vector.o: vector.c
	clear
	gcc -c vector.c

main.o: main.c vector.h
	clear
	gcc -c main.c

clean:
	clear
	rm *.o
	rm vector

run:
	clear
	./vector

runv:
	clear
	valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         ./vector	