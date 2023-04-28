CC = gcc
CFLAGS = -lncurses -I$(IDIR)

IDIR = ./include/
IDIR += ./src/inventory/

SRCDIR = ./src/

SOURCES = $(SRCDIR)*.c\
          $(SRCDIR)inventory/*.c

all: valley run clean

valley:
	$(CC) $(SOURCES) $(CFLAGS) -o $@

run:
	./valley

clean:
	rm valley

