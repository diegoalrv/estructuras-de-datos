###############################################################################
# CURSO:      Estructuras de Datos (EIN423-B)
# UNIVERSIDAD: Universidad Técnica Federico Santa María
# LAB:        07 - Pila (Stack)
# FECHA:      Marzo 2026
###############################################################################

CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS =

# Archivos fuente
SOURCES = pila.c main_test.c
HEADERS = pila.h
OBJECTS = $(SOURCES:.c=.o)
TARGET = lab07

# Reglas
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $<

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all run clean
