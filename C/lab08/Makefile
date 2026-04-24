###############################################################################
# CURSO:      Estructuras de Datos (EIN423-B)
# UNIVERSIDAD: Universidad Técnica Federico Santa María
# LAB:        08 - Cola y Cola de Prioridad
# FECHA:      Marzo 2026
###############################################################################

CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS =

# Archivos fuente
SOURCES = cola.c cola_prioridad.c main_test.c
HEADERS = cola.h cola_prioridad.h
OBJECTS = $(SOURCES:.c=.o)
TARGET = lab08

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
