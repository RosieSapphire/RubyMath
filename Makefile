CC=cc
CFLAGS=-Wall -Wextra -O2
INC=-Iinclude
LIB=-lm
SRC=$(wildcard src/*.c)
OBJ=$(patsubst src/%.c,%.o,$(SRC))
LIB_OUT=librmath.a
TEST=librmath_test

default: $(LIB_OUT)

$(LIB_OUT): $(OBJ)
	ar rcs $@ $^
	rm -rf *.o
	@echo Successfully created Ruby Math Library!

%.o: src/%.c
	$(CC) $(CFLAGS) -c $< $(INC)

test: $(LIB_OUT)
	$(CC) $(CFLAGS) src/test.c -o $(TEST) $(LIB) -L. -lrmath $(INC)
	rm -f *.o
	@echo Successfully created Ruby Math Library \(with Test\)!

clean:
	rm -f $(LIB_OUT) $(TEST) $(OBJ)
