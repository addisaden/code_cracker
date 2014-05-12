all: code_cracker

code_cracker: randomizer.o main.o
	gcc randomizer.o main.o -o code_cracker

main.o: main.c
	gcc -c main.c

randomizer.o: randomizer.c
	gcc -c randomizer.c

clean:
	rm -rf *.o code_cracker
