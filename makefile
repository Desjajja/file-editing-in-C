SRC = src
OBJ = obj
SRCS = readByNumber.c writeByLine.c
MAIN = testWriteByNumber.c
OBJS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
STATIC = lib/static
SHARE = lib/share
LIBNAME = test

BIN = bin

build-static: static
	mkdir -p $(BIN) && gcc $(SRC)/$(MAIN) -Bstatic -L.$(STATIC) -l$(LIBNAME) -o $(BIN)/static-$(LIBNAME)
#build-share

# $(BIN): $(OBJS)
# 	mkdir -p ./bin && gcc $(OBJS) -o $@


# static library
static: $(OBJS)
	mkdir -p $(STATIC) && ar -cr $(STATIC)/libtest.a $(OBJS)

share: $(OBJS)
	mkdir -p $(SHARE) && gcc -shared -fPIC -o $(SHARE)/libtest.so $(OBJS)

$(OBJ)/%.o: $(SRC)/%.c
	mkdir -p ./obj && gcc -c $< -o $@ 

.PHONY: clean
clean:
	rm -rf ./bin ./obj ./lib