CC = g++ 
cflags= -Wall 

default:
	$(CC) -c *.cc $(cflags)
	ar cr lib_ffpoly.a *.o
	make clean

clean:
	rm -f *.o 
