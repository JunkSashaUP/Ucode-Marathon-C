TARGET=mx_cp
CC=clang -std=c11 -Wall -Wextra -Werror -Wpedantic

all: $(TARGET)

$(TARGET):
	$(CC) src/*.c -o $(TARGET)

clean:
	rm -f $(TARGET)

uninstall:
	rm -f $(TARGET)

reinstall:
	make uninstall
	make
