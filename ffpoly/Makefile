cflags= -Wall 

default:
	g++ -c *.cc $(cflags)
	ar cr lib_ffpoly.a *.o
	make clean

clean:
	rm -f *.o 
