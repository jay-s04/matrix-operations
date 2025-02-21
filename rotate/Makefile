CC = gcc
CFLAG = -fsanitize=address, -fsanitize=undefined -Og -g -Wall -Werror -std=c11 -lm

second: rotate.c
	$(CC) rotate.c -o rotate $(CFLAG)

clean: second
	rm -f rotate
