CC=gcc
CFLAG = -fsanitize=address, -fsanitize=undefined -Og -g -Wall -Werror -std=c11 -lm

fifth: determinant.c
	$(CC) determinant.c -o determinant $(CFLAG)

clean: determinant
	rm -f determinant
