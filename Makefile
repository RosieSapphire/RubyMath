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
	@echo Generating static library...
	@ar rcs $@ $^
	@echo Deleting object files...
	@rm -f *.o
	@echo Successfully created static library!

test: $(BIN)
	@echo Linking test executable...
	@$(CC) $(CFLAGS) $^ -o $(BIN_TEST) $(INC) $(LIB) -L. -lrmath
	@echo Successfully linked test executable!

%.o: src/%.c
	@echo Compiling "'"$^"'"...
	@$(CC) $(CFLAGS) -c $^ $(INC)

clean:
	@rm -f $(BIN) $(BIN_TEST) $(OBJ)
	@echo Cleaned up all build files.
