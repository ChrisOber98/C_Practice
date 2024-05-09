stack_arr: stack_arr.o main.o vector.o
	gcc stack_arr.o main.o vector.o -o stack_arr

main.o: main.c
	gcc -c main.c -I../vector

stack_arr.o: stack_arr.c
	gcc -c stack_arr.c -I../vector

vector.o: ../vector/vector.c
	gcc -c ../vector/vector.c	

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