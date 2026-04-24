CC=gcc
CFLAGS=-Wall -Wextra -std=c99
TARGET=lab03

all: $(TARGET)

$(TARGET): complejidad.c main_test.c
	$(CC) $(CFLAGS) -o $(TARGET) complejidad.c main_test.c -lm

clean:
	rm -f $(TARGET)

run: all
	./$(TARGET)

.PHONY: all clean run
