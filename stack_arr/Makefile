stack_arr: stack_arr.o main.o vector.o
	gcc stack_arr.o main.o vector.o -o stack_arr

main.o: main.c stack_arr.h vector.h
	gcc -c main.c 

vector.o: vector.c
	gcc -c vector.c	

stack_arr.o: stack_arr.c
	gcc -c stack_arr.c

clean:
	rm *.o stack_arr

run:
	./stack_arr

runv:
	valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         ./stack_arr