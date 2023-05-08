CC=cc
CFLAGS=-Wall -Wextra -O2
INC=-Iinclude
LIB=-lm
SRC=$(wildcard src/*.c)
OBJ=$(patsubst src/%.c,%.o,$(SRC))
LIB_OUT=librmath.a
TEST=librmath_test

default: $(LIB_OUT)

<<<<<<< HEAD
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
=======
test: $(LIB_OUT)
	$(CC) $(CFLAGS) $^ -o $(TEST) $(INC) $(LIB) -L. -l:$<
	rm -rf *.o

$(LIB_OUT): $(OBJ)
	ar rcs $@ $^
	rm -rf *.o

%.o: src/%.c
	$(CC) $(CFLAGS) -c $< $(INC)

clean:
	rm -f $(LIB_OUT) $(TEST) $(OBJ)
>>>>>>> fb7b51f3558d6e42df3d40402ac6ee3b157c2ffd
