INCLUDE_DIRS = 
LIB_DIRS =

CC = gcc

CFLAGS = -Wall -I. $(INCLUDE_DIRS:%=-I%)  # Include current directory and add -I for includes
LIBS = -lm $(LIB_DIRS:%=-L%)  # Add -L for library directories

PRODUCT = item 

SRCS = ${HFILES} ${CFILES}
OBJS = ${CFILES:.c=.o}

HFILES = inventory.h
CFILES = item.c inventory.c

all: ${PRODUCT}

$(PRODUCT): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ # Link with all object files and libraries

%.o: %.c $(HFILES)
	$(CC) $(CFLAGS) -c $< -o $@  # Compile each .c file into .o

clean:
	-rm -f *.o *.NEW *~ 
	-rm -rf *.dSYM
	-rm -f ${PRODUCT} ${DERIVED} ${GARBAGE}
	-rm -f ${OBJS} item

.PHONY: all clean  # Declare these as phony targets