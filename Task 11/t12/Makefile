flag := -std=c11 -Wall -Wextra -Werror -Wpedantic
name := playlist
CC := clang

all: $(name)

$(name):
	$(CC) $(flag) -Iinc -o $(name) src/*.c

clean:
	rm -rf $(name)

uninstall:
	rm -rf $(name)

reinstall:
	make uninstall
	make
