make: main.c
	gcc -g main.c -o rods

clean: rods
	rm rods
