
run: main
	./main

main: utils buffer
	cc -c main.c -o main.o
	cc modules/compiledModules/utils.o modules/compiledModules/buffer.o main.o -o main

patternmatch_test: patternmatch
	./minigrams/patternmatch/patternmatch.exec < ./minigrams/patternmatch/test.txt

patternmatch: utils
	cc -c minigrams/patternmatch/main.c -o minigrams/patternmatch/main.o
	cc modules/compiledModules/utils.o minigrams/patternmatch/main.o -o minigrams/patternmatch/patternmatch.exec

utils: modules/utils.c
	cc -c modules/utils.c -o modules/compiledModules/utils.o

stack: modules/stack.c
	cc -c modules/stack.c -o modules/compiledModules/stack.o

buffer: modules/buffer.c
	cc -c modules/buffer.c -o modules/compiledModules/buffer.o

pseudomem: modules/pseudomem.c
	cc -c modules/pseudomem.c -o modules/compiledModules/pseudomem.o

.PHONY: clean
clean:
	find . -name "*.o" -not -path ./modules/compiledModules/* -delete

.PHONY: deepclean
deepclean:
	find . -name "*.o" -delete