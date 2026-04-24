CC=gcc
CFLAGS=-Wall -Wextra -std=c99
TARGET=lab01

all: $(TARGET)

$(TARGET): punteros.c main_test.c
	$(CC) $(CFLAGS) -o $(TARGET) punteros.c main_test.c

clean:
	rm -f $(TARGET)

run: all
	./$(TARGET)

.PHONY: all clean run
