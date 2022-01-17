
run: patternmatch_test

patternmatch_test: patternmatch
	./minigrams/patternmatch/patternmatch.exec < ./minigrams/patternmatch/test.txt

main: utils
	cc -c main.c -o main.o
	cc modules/compiledModules/utils.o main.o -o main

utils: modules/compiledModules/utils.o

modules/compiledModules/utils.o: modules/utils.c
	cc -c modules/utils.c -o modules/compiledModules/utils.o

patternmatch: utils
	cc -c minigrams/patternmatch/main.c -o minigrams/patternmatch/main.o
	cc modules/compiledModules/utils.o minigrams/patternmatch/main.o -o minigrams/patternmatch/patternmatch.exec

.PHONY: clean
clean:
	find . -name "*.o" -not -path ./modules/compiledModules/* -delete

.PHONY: deepclean
deepclean:
	find . -name "*.o" -delete