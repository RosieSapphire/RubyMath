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

test: $(BIN)
	$(CC) $(CFLAGS) $^ -o $(BIN_TEST) $(INC) $(LIB) -L. -lrmath

%.o: src/%.c
	$(CC) $(CFLAGS) -c $^ $(INC)

clean:
	rm -f $(BIN) $(BIN_TEST) $(OBJ)
