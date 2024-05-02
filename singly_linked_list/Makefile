sll: sll.o main.o
	gcc sll.o main.o -o sll

sll.o: sll.c
	gcc -c sll.c

main.o: main.c sll.h
	gcc -c main.c

clean:
	rm *.o
	rm sll

run:
	./sll

runv:
	valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         ./sll
