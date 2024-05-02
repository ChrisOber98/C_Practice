queue_arr: main.o queue_arr.o vector.o
	gcc main.o queue_arr.o vector.o -o queue_arr

main.o: main.c queue_arr.h vector.h
	gcc -c main.c

queue_arr.o: queue_arr.c
	gcc -c queue_arr.c

vector.o: vector.c
	gcc -c vector.c

clean:
	rm *.o queue_arr

run:
	clear
	./queue_arr

runv:
	clear
	valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         ./queue_arr