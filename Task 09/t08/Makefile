all: copy object.o move clear calc

copy:
	mkdir obj
	cp inc/*.h obj
	cp src/*.c obj

object.o:
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic -c obj/*.c

move:
	cp *.o obj

clear:
	rm *.o
	rm obj/*.h
	rm obj/*.c

calc:
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic -o calc obj/*.o

uninstall:
	rm -rf obj
	rm calc
	rm -rf *.o

reinstall:
	make uninstall
	make
