calc: header.o main.o
	gcc header.o main.o -o calc
header.o: header.h header.c 
	gcc header.c -c 
main.o: header.h main.c 
	gcc main.c -c 
clean: 
	rm -rf *calc *.o
rebuild: 
	clean calc