all: program

program: program.c
	gcc -o program program.c

clearprog: program
	rm program

clean: clearprog