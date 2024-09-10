# Building variables
CC := gcc
AR := ar rcs
CFLAGS := -Wall -Wextra
# Files 
TGT := libstatistics.a
OBJ := statistics.o
SRC := src/statistics.c

.PHONY: test

$(TGT): $(OBJ)
	$(AR) $(TGT) $(OBJ)

$(OBJ): $(SRC)
	$(CC) -c $< $(CFLAGS)

test:
	$(MAKE) test/tst.exe

test/tst.exe: test/tst.c
	$(CC) $< -o $@ -lstatistics -L./
