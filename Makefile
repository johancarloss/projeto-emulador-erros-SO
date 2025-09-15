# Makefile na raiz
CC=gcc
CFLAGS=-pthread -Wall -Wextra
SRC_DIR=erros
OUT_DIR=output

ERROS=memory_leak race_condition deadlock

all: $(ERROS)

$(ERROS):
	$(CC) $(SRC_DIR)/$@.c -o $(OUT_DIR)/$@ $(CFLAGS)

clean:
	rm -f $(OUT_DIR)/*