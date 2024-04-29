sll: sll.o
	gcc sll.o -o sll

sll.o: sll.c
	gcc -c sll.c

clean:
	rm *.o
	rm sll

run:
	./sll

run_val:
	valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         ./sll
