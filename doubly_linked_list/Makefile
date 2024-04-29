dll: dll.o
	gcc dll.o -o dll

dll.o: dll.c
	clear
	gcc -g -c dll.c

clean:
	rm *.o dll

run:
	./dll

run_val:
	valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         ./dll