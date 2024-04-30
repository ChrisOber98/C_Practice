dll: dll.o main.o
	gcc dll.o main.o -o dll

main.o: main.c dll.h
	gcc -c main.c

dll.o: dll.c
	gcc -c dll.c

clean:
	rm *.o dll

run:
	./dll

runv:
	valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         ./dll