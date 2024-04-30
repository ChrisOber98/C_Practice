queue_ll: main.o dll.o queue_ll.o
	gcc main.o dll.o queue_ll.o -o queue_ll

main.o: main.c queue_ll.h dll.h
	gcc -c main.c queue_ll.c dll.c

queue_ll.o: queue_ll.c
	gcc -c queue_ll.c

dll.o: dll.c
	gcc -c dll.c

clean:
	rm *.o queue_ll

run:
	./queue_ll

runv:
	valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         ./queue_ll

