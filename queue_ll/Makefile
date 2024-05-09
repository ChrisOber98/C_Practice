queue_ll: main.o dll.o queue_ll.o
	gcc main.o dll.o queue_ll.o -o queue_ll

main.o: main.c
	gcc -c main.c -I../doubly_linked_list

queue_ll.o: queue_ll.c 
	gcc -c queue_ll.c -I../doubly_linked_list

dll.o: ../doubly_linked_list/dll.c
	gcc -c ../doubly_linked_list/dll.c

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

