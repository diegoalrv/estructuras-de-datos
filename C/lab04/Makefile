CC=gcc
CFLAGS=-Wall -Wextra -std=c99
TARGET=lab04

all: $(TARGET)

$(TARGET): punto2d.c fraccion.c main_test.c
	$(CC) $(CFLAGS) -o $(TARGET) punto2d.c fraccion.c main_test.c -lm

clean:
	rm -f $(TARGET)

run: all
	./$(TARGET)

.PHONY: all clean run
