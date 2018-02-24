all: fork_example3

run:
	./fork_example3 56

fork_example3: collatz.o fork_example3.o 
	gcc collatz.o fork_example3.o -o fork_example3

collatz.o: collatz.c 
	gcc -c collatz.c

fork_example3.o: fork_example3.c
	gcc -c fork_example3.c 

clean: 
	rm *.o fork_example3
