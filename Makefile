CC=cc
CFLAGS=-Wall -Wextra -Og -g3
INC=-Iinclude
LIB=$(shell pkg-config --libs glfw3) -lm
SRC=$(wildcard src/*.c)
OBJ=$(patsubst src/%.c, %.o, $(SRC))
BIN=librmath.a
BIN_TEST=librmath_test

default: $(BIN)

$(BIN): $(OBJ)
	ar rcs $@ $^
	rm -f *.o
	@echo Successfully created Ruby Math Library!

test: $(BIN)
	$(CC) $(CFLAGS) $^ -o $(BIN_TEST) $(INC) $(LIB) -L. -lrmath
	@echo Successfully linked Ruby Math test executable!

%.o: src/%.c
	$(CC) $(CFLAGS) -c $^ $(INC)

clean:
	rm -f $(BIN) $(BIN_TEST) $(OBJ)
