vector: vector.o main.o test_vector.o
	gcc vector.o main.o test_vector.o -o vector

vector.o: vector.c
	gcc -c vector.c

test_vector.o: test_vector.c
	gcc -c test_vector.c

main.o: main.c vector.h
	gcc -c main.c

clean:
	rm *.o vector

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