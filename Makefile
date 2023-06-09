CC+FLAGS = gcc -Wall -MMD

all: palindrome
-include *.d

palindrome: main.o input.o palindrome.o
	$(CC+FLAGS) -o $@ $^

palindrome.o: palindrome.c
	$(CC+FLAGS) -c -o $@ $<

input.o: input.c
	$(CC+FLAGS) -c -o $@ $<

clean:
	rm -rf *.o *.d palindrome


