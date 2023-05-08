CC=cc
CFLAGS=-Wall -Wextra -O2
INC=-Iinclude
LIB=-lm
SRC=$(wildcard src/*.c)
OBJ=$(patsubst src/%.c, %.o, $(SRC))
LIB_OUT=librmath.a
TEST=librmath_test

default: $(LIB_OUT)

test: $(LIB_OUT)
	$(CC) $(CFLAGS) $^ -o $(TEST) $(INC) $(LIB) -L. -l:$<
	@echo Successfully linked Ruby Math Test Program!
	@rm -rf *.o

$(LIB_OUT): $(OBJ)
	@ar rcs $@ $^
	@echo Successfully created Ruby Math Library!
	@rm -rf *.o

%.o: src/%.c
	$(CC) $(CFLAGS) -c $< $(INC)

clean:
	@rm -f $(LIB_OUT) $(TEST) $(OBJ)
	@echo Cleaned up all Ruby Math build files.
