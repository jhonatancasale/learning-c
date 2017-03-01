all: main.o
	gcc -std=c11 -Wall -ggdb3 -O2 -Werror -Wshadow -lm -I . *.o -o main

main.o: main.c perform_test.o
	gcc -std=c11 -Wall -ggdb3 -O2 -Werror -Wshadow -lm -I . -c main.c

perform_test.o: perform_test.c perform_test.h sort.o
	gcc -std=c11 -Wall -ggdb3 -O2 -Werror -Wshadow -lm -I . -c perform_test.c

sort.o: sort.c sort.h
	gcc -std=c11 -Wall -ggdb3 -O2 -Werror -Wshadow -lm -I . -c sort.c

clean:
	@rm -f main *~ *.o

test: 
	@./main 256 128

run:
	@./main

time:
	time ./main 

val:
	valgrind ./main

tags:
	ctags --recurse=yes --verbose=yes .
