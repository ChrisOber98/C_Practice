sll: sll.o main.o test_sll.o
	gcc sll.o main.o test_sll.o -o sll

sll.o: sll.c
	gcc -c sll.c

main.o: main.c sll.h
	gcc -c main.c

test_sll.o: test_sll.c sll.h
	gcc -c test_sll.c

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
