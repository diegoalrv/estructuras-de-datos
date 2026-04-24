CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -lm
TARGETS = test

SOURCES = hash_abierto.c main_test.c
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGETS)

test: $(OBJECTS)
	$(CC) $(CFLAGS) -o test $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: test
	./test

clean:
	rm -f $(OBJECTS) $(TARGETS)

.PHONY: all run clean
