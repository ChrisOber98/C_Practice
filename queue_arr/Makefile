queue_arr: main.o queue_arr.o vector.o
	gcc main.o queue_arr.o vector.o -o queue_arr

queue_arr.o: queue_arr.c
	gcc -c queue_arr.c -I../vector/

vector.o: ../vector/vector.c
	gcc -c ../vector/vector.c

main.o: main.c
	gcc -c main.c -I../vector/

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