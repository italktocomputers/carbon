.PHONY: all clean install

all: main.c effects.c ls.o
	gcc -Wall -o ./carbon $^ -lhidapi-hidraw

ls.o: ls.c
	gcc -Wall -c $^ -lhidapi-libusb

install: all
	cp -v ./carbon /usr/bin/carbon

clean:
	rm -vf ./carbon ./ls.o
