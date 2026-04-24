CC=gcc
CFLAGS=-Wall -Wextra -std=c99
TARGET=lab02

all: $(TARGET)

$(TARGET): recursividad.c main_test.c
	$(CC) $(CFLAGS) -o $(TARGET) recursividad.c main_test.c

clean:
	rm -f $(TARGET)

run: all
	./$(TARGET)

.PHONY: all clean run
