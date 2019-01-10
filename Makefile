CC = g++
cflags= -Wall

default:
	cd ffpoly && make
	$(CC) -c main.cc $(cflags)
	$(CC) main.o ffpoly/lib_ffpoly.a -o test.out
	rm -f main.o
	cd ffpoly && make clean

clean:
	rm -f test.out
	cd ffpoly && make clean
