CC=gcc
CFLAG = -fsanitize=address, -fsanitize=undefined -Og -g -Wall -Werror -std=c11 -lm

fourth: rref.c
	$(CC) rref.c -o rref $(CFLAG)

clean: rref
	rm -f rref
