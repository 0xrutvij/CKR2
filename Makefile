
run: main
	./main
	
main: utils
	cc -c main.c -o main.o
	cc modules/compiledModules/utils.o main.o -o main

utils: modules/compiledModules/utils.o

modules/compiledModules/utils.o: modules/utils.c
	cc -c modules/utils.c -o modules/compiledModules/utils.o