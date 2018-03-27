CC=gcc
SRC=readFile.c dataProcess.c neuralNetworkProcess.c stack.c main.c
CFLAGS=-Wall 
LDFLAGS = 
PROGRAMS = SomIris
platform=$(shell uname -s)
ifeq ($(platform),Darwin)
	OBJ=$(SRC:.c=.o) 
else
	OBJ=$(SRC:.c=.o) -lm
endif
all : $(PROGRAMS)
SomIris:    $(OBJ) structure.h 
	$(CC)  -o $@ $(OBJ)
%.o:	%.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm -rf $(PROGRAMS) *.o 
