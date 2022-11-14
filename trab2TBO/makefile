CC=gcc
CFLAGS=\
	-g \
	-Wall \
	-Wextra \
	-pedantic \
	#-ansi 
LIBS=-lm -I ./headers 

SRC=$(wildcard ./src/*.c)

all: clean trab2

trab2: $(SRC)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	$(RM) ./trab2

test:
	bash ./utils/test.sh

docs:
	doxygen ./Doxyfile

format:
	clang-format --style=file -i ./src/*.c ./headers/*.h

.PHONY: all clean test docs format

tes: all
	./trab2 in >saida.txt