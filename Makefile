.PHONY: all clean

all: main.c effects.c ls.o
	gcc -Wall -o ./carbon $^ -lhidapi-hidraw

ls.o: ls.c
	gcc -Wall -c $^ -lhidapi-libusb

clean:
	rm -vf ./carbon ./ls.o
