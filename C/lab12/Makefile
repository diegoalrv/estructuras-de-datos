# Estructuras de Datos — EIN423-B
# Universidad Técnica Federico Santa María
# Laboratorio 12: Tabla Hash con Encadenamiento

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -lm
TARGET = prueba_hash

SOURCES = tabla_hash.c main_test.c
HEADERS = tabla_hash.h
OBJECTS = $(SOURCES:.c=.o)

# Regla por defecto: compilar todo
all: $(TARGET)

# Compilar programa ejecutable
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)
	@echo "Compilación exitosa: $(TARGET)"

# Compilar archivos objeto
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $<

# Ejecutar programa
run: $(TARGET)
	./$(TARGET)

# Limpiar archivos generados
clean:
	rm -f $(OBJECTS) $(TARGET)
	@echo "Archivos limpios"

.PHONY: all run clean
