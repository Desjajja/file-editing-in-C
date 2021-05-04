#SRC = ./src/testWriteByNumber.c ./src/readByNumber.c ./src/writeByLine.c
#OBJ = $(subst c, o, $(SRC))

all: 
	mkdir -p bin && gcc -o ./bin/test.out ./src/testWriteByNumber.c ./src/readByNumber.c ./src/writeByLine.c

#${OBJ}: ${SRC}
#	gcc -o $@ -c $<

.PHONY: clean
clean:
	rm -rf ./bin 