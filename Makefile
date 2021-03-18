CXX=g++
CFLAGS=-O0 -G

test1: test1.o
	$(CXX) -o test1 test1.o

test2: test2.o
	$(CXX) -o test2 test2.o

test3: test3.o
	$(CXX) -o test3 test3.o -lpthread

all: test1 test2 test3
