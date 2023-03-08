NAME=mx_cat
CC=clang -std=c11 -Wall -Wextra -Werror -Wpedantic

all: $(NAME)

$(NAME):
	$(CC) src/*.c -o $(NAME)

clean:
	rm -f $(NAME)

uninstall:
	rm -f $(NAME)

reinstall:
	make uninstall
	make
