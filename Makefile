
run: main
	./main

sort: minigrams/unix_sort/unix_sort.c utils
	cc -c minigrams/unix_sort/unix_sort.c -o minigrams/unix_sort/unix_sort.o
	cc minigrams/unix_sort/unix_sort.o modules/compiledModules/utils.o -o ./minigrams/unix_sort/sort.exec
	./minigrams/unix_sort/sort.exec < ./minigrams/unix_sort/sort.txt

main: utils
	cc -c main.c -o main.o
	cc modules/compiledModules/utils.o main.o -o main

patternmatch: utils
	cc -c minigrams/patternmatch/main.c -o minigrams/patternmatch/main.o
	cc modules/compiledModules/utils.o minigrams/patternmatch/main.o -o minigrams/patternmatch/patternmatch.exec
	./minigrams/patternmatch/patternmatch.exec < ./minigrams/patternmatch/test.txt

utils: modules/utils.c buffer pseudomem
	cc -c modules/utils.c -o modules/compiledModules/pre_utils.o
	ld -r modules/compiledModules/pre_utils.o modules/compiledModules/buffer.o modules/compiledModules/pseudomem.o -o modules/compiledModules/utils.o

stack: modules/stack.c
	cc -c modules/stack.c -o modules/compiledModules/stack.o

buffer: modules/buffer.c
	cc -c modules/buffer.c -o modules/compiledModules/buffer.o

pseudomem: modules/pseudomem.c
	cc -c modules/pseudomem.c -o modules/compiledModules/pseudomem.o

.PHONY: clean
clean:
	find . -name "*.o" -not -path ./modules/compiledModules/* -delete
	rm main

.PHONY: deepclean
deepclean:
	find . -name "*.o" -delete
	rm main