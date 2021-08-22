
output: main.o water.o
	gcc main.o water.o -o output

main.o: main.c
	gcc -c main.c
	
water.o: water.c water.h
	gcc -c water.c
	
clean:
	rm *.o output
