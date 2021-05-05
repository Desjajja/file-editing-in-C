SRC = src
OBJ = obj
LIB = lib
SRCS = $(SRC)/readByNumber.c $(SRC)/writeByLine.c
MAIN = testWriteByNumber.c
OBJS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
STATIC = $(LIB)/static
SHARE = $(LIB)/share
LIBNAME = test

BIN = bin

build-static: static
	mkdir -p $(BIN) && gcc $(SRC)/$(MAIN) -Bstatic -L$(STATIC) -l$(LIBNAME) -o $(BIN)/static-$(LIBNAME)

 build-share: share
	mkdir -p $(BIN) && gcc $(SRC)/$(MAIN) -L$(SHARE) -l$(LIBNAME) -o $(BIN)/share-$(LIBNAME)

# build-share: share
# 	mkdir -p $(BIN) && gcc $(SRC)/$(MAIN) $(SHARE)/lib$(LIBNAME).so -o $(BIN)/share-$(LIBNAME)

# $(BIN): $(OBJS)
# 	mkdir -p ./bin && gcc $(OBJS) -o $@


# static library
static: $(OBJS)
	mkdir -p $(STATIC) && ar -cr $(STATIC)/lib$(LIBNAME).a $(OBJS)

share: $(OBJS)
	mkdir -p $(SHARE) && gcc -shared -fPIC -o $(SHARE)/lib$(LIBNAME).so $(OBJS)

$(OBJ)/%.o: $(SRC)/%.c
	mkdir -p ./obj && gcc -c $< -o $@ 

.PHONY: clean
clean:
	rm -rf $(BIN) $(OBJ) $(LIB)