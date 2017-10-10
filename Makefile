.PHONY: all

all: main.c effects.c
	gcc -Wall -o ./carbon $^ -lhidapi-hidraw
