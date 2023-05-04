CC = gcc
CFLAGS = -lncurses -lm -I$(IDIR)

IDIR = ./include/
SRCDIR = ./src/

SOURCES = $(SRCDIR)*.c
all: valley run clean

valley:
	$(CC) $(SOURCES) $(CFLAGS) -o $@

run:
	./valley

clean:
	rm valley
