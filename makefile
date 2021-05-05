SRC = ./src
OBJ = ./obj
SRCS = $(wildcard $(SRC)/*.c)
OBJS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

BIN = ./bin/test.out

all: $(BIN)

$(BIN): $(OBJS)
	mkdir -p ./bin && gcc $(OBJS) -o $@

$(OBJ)/%.o: $(SRC)/%.c
	mkdir -p ./obj && gcc -c $< -o $@ 
#${OBJ}: ${SRC}
#	gcc -o $@ -c $<

.PHONY: clean
clean:
	rm -rf ./bin ./obj