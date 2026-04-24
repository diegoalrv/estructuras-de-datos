# Laboratorio 4 — TDA: Diseño e Implementación

**Curso:** EIN423-B · Estructuras de Datos
**Duración:** 90 minutos
**Horario:** 08:30 – 10:00

## Objetivos del laboratorio
- Comprender el concepto de Tipo de Dato Abstracto (TDA)
- Separar **interfaz** (qué se puede hacer) de **implementación** (cómo se hace)
- Implementar TDA usando archivos `.h` y `.c`
- Practicar gestión de memoria dinámica con `malloc` y `free`
- Diseñar API clara y robusta para estructuras personalizadas

---

# Estructura de la clase

| Hora | Actividad |
|------|-----------|
| 08:30 – 08:40 | Introducción: ¿Qué es un TDA? |
| 08:40 – 09:10 | Concepto y código guiado |
| 09:10 – 09:55 | Ejercicios |
| 09:55 – 10:00 | Cierre |

---

# 1. Introducción (08:30 – 08:40)

Un **Tipo de Dato Abstracto (TDA)** es un **contrato** entre el programador y el usuario de código:

- **Interfaz (header `.h`):** Define QUÉ operaciones están disponibles
- **Implementación (`.c`):** Define CÓMO se implementan internamente

**¿Por qué es importante?**
1. El usuario del TDA nunca accede directamente a los campos internos
2. El implementador puede cambiar la implementación sin romper el código cliente
3. Fomenta **encapsulamiento** (información hiding)
4. Facilita mantenimiento y depuración

**Patrón clave en C:** El **opaque pointer** (puntero opaco).

```c
// En el header (contador.h), declaramos una estructura incompleta:
typedef struct Contador Contador;

// El usuario NO SABE cómo es Contador internamente
// Solo conoce las funciones públicas

Contador* contador_crear();
void contador_incrementar(Contador *c);
int contador_obtener_valor(Contador *c);
void contador_destruir(Contador *c);
```

En la implementación (contador.c), definimos la estructura **completa**:

```c
struct Contador {
    int valor;
};

struct Contador* contador_crear() {
    Contador *c = (Contador *)malloc(sizeof(Contador));
    c->valor = 0;
    return c;
}
```

El usuario **nunca puede acceder a `c->valor` directamente** — solo a través de las funciones públicas.

---

# 2. Concepto y código guiado (08:40 – 09:10)

## Ejemplo 1: TDA Contador (simple)

**Archivo: contador.h**
```c
#ifndef CONTADOR_H
#define CONTADOR_H

typedef struct Contador Contador;

// Crear un contador inicializado en 0
Contador* contador_crear();

// Incrementar el valor en 1
void contador_incrementar(Contador *c);

// Decrementar el valor en 1
void contador_decrementar(Contador *c);

// Obtener el valor actual
int contador_obtener_valor(const Contador *c);

// Destruir y liberar memoria
void contador_destruir(Contador *c);

#endif
```

**Archivo: contador.c**
```c
#include "contador.h"
#include <stdlib.h>

struct Contador {
    int valor;
};

Contador* contador_crear() {
    Contador *c = (Contador *)malloc(sizeof(Contador));
    c->valor = 0;
    return c;
}

void contador_incrementar(Contador *c) {
    c->valor++;
}

void contador_decrementar(Contador *c) {
    c->valor--;
}

int contador_obtener_valor(const Contador *c) {
    return c->valor;
}

void contador_destruir(Contador *c) {
    free(c);
}
```

**Archivo: main.c (usando el TDA)**
```c
#include <stdio.h>
#include "contador.h"

int main() {
    Contador *c = contador_crear();

    printf("Valor inicial: %d\n", contador_obtener_valor(c));

    contador_incrementar(c);
    contador_incrementar(c);
    contador_incrementar(c);

    printf("Después de 3 incrementos: %d\n", contador_obtener_valor(c));

    contador_decrementar(c);
    printf("Después de 1 decremento: %d\n", contador_obtener_valor(c));

    // IMPORTANTE: liberar memoria
    contador_destruir(c);

    return 0;
}
```

**Compilar:**
```bash
gcc -Wall -c contador.c -o contador.o
gcc -Wall -c main.c -o main.o
gcc -Wall contador.o main.o -o programa
./programa
```

---

## Ejemplo 2: TDA Punto2D

**Archivo: punto.h**
```c
#ifndef PUNTO_H
#define PUNTO_H

typedef struct {
    double x;
    double y;
} Punto2D;

// Crear un punto con coordenadas (x, y)
Punto2D punto_crear(double x, double y);

// Distancia desde el origen (0, 0)
double punto_distancia_origen(Punto2D p);

// Distancia entre dos puntos
double punto_distancia(Punto2D p1, Punto2D p2);

// Imprimir punto
void punto_imprimir(Punto2D p);

#endif
```

**Archivo: punto.c**
```c
#include "punto.h"
#include <stdio.h>
#include <math.h>

Punto2D punto_crear(double x, double y) {
    Punto2D p;
    p.x = x;
    p.y = y;
    return p;
}

double punto_distancia_origen(Punto2D p) {
    return sqrt(p.x * p.x + p.y * p.y);
}

double punto_distancia(Punto2D p1, Punto2D p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

void punto_imprimir(Punto2D p) {
    printf("(%.2f, %.2f)", p.x, p.y);
}
```

**Uso:**
```c
Punto2D p1 = punto_crear(3.0, 4.0);
Punto2D p2 = punto_crear(0.0, 0.0);

printf("Distancia origen: %.2f\n", punto_distancia_origen(p1));  // 5.00
printf("Distancia entre puntos: %.2f\n", punto_distancia(p1, p2)); // 5.00
```

---

## Ejemplo 3: TDA Pila (Stack) — opaque pointer

**Archivo: pila.h**
```c
#ifndef PILA_H
#define PILA_H
#include <stdbool.h>

typedef struct Pila Pila;

// Crear una pila vacía (máximo 100 elementos)
Pila* pila_crear();

// Apilar un valor
void pila_push(Pila *p, int valor);

// Desapilar un valor (retorna el elemento)
int pila_pop(Pila *p);

// Ver el tope sin desapilar
int pila_peek(Pila *p);

// ¿Está vacía?
bool pila_esta_vacia(Pila *p);

// ¿Está llena?
bool pila_esta_llena(Pila *p);

// Obtener tamaño
int pila_tamaño(Pila *p);

// Liberar memoria
void pila_destruir(Pila *p);

#endif
```

**Archivo: pila.c**
```c
#include "pila.h"
#include <stdlib.h>
#include <stdio.h>

#define MAX_PILA 100

struct Pila {
    int elementos[MAX_PILA];
    int tope;  // índice del próximo elemento a insertar
};

Pila* pila_crear() {
    Pila *p = (Pila *)malloc(sizeof(Pila));
    p->tope = 0;
    return p;
}

void pila_push(Pila *p, int valor) {
    if (pila_esta_llena(p)) {
        printf("Error: pila llena\n");
        return;
    }
    p->elementos[p->tope] = valor;
    p->tope++;
}

int pila_pop(Pila *p) {
    if (pila_esta_vacia(p)) {
        printf("Error: pila vacía\n");
        return -1;
    }
    p->tope--;
    return p->elementos[p->tope];
}

int pila_peek(Pila *p) {
    if (pila_esta_vacia(p)) {
        printf("Error: pila vacía\n");
        return -1;
    }
    return p->elementos[p->tope - 1];
}

bool pila_esta_vacia(Pila *p) {
    return p->tope == 0;
}

bool pila_esta_llena(Pila *p) {
    return p->tope == MAX_PILA;
}

int pila_tamaño(Pila *p) {
    return p->tope;
}

void pila_destruir(Pila *p) {
    free(p);
}
```

---

# 3. Ejercicios (09:10 – 09:55)

## Ejercicio 1 — TDA Punto2D (★☆☆)

Diseña e implementa el TDA `Punto2D`:

**Funciones requeridas:**
- `Punto2D punto_crear(double x, double y)`
- `double punto_distancia_origen(Punto2D p)` — distancia desde (0, 0)
- `double punto_distancia(Punto2D p1, Punto2D p2)` — distancia entre dos puntos
- `void punto_imprimir(Punto2D p)` — imprime "(x, y)"
- `void punto_destruir(Punto2D *p)` — si usas punteros

En el `main`, prueba:
```c
Punto2D p1 = punto_crear(3.0, 4.0);
Punto2D p2 = punto_crear(6.0, 8.0);
Punto2D p3 = punto_crear(0.0, 0.0);

printf("Distancia p1 al origen: %.2f\n", punto_distancia_origen(p1));  // 5.00
printf("Distancia p1-p2: %.2f\n", punto_distancia(p1, p2));  // 5.00
printf("Imprimir p1: "); punto_imprimir(p1); printf("\n");  // (3.00, 4.00)
```

**Pistas:**
- Usa `#include <math.h>` para `sqrt()`
- Crea archivos `punto.h` y `punto.c`
- Compila con `gcc -Wall punto.c main.c -o punto -lm` (el `-lm` vincula la librería math)

---

## Ejercicio 2 — TDA Pila (★★☆)

Implementa el TDA `Pila` (Stack) con máximo de 100 elementos usando array estatico:

**Funciones requeridas:**
- `Pila* pila_crear()` — crea pila vacía
- `void pila_push(Pila *p, int valor)` — apilar
- `int pila_pop(Pila *p)` — desapilar (retorna valor)
- `int pila_peek(Pila *p)` — ver tope sin desapilar
- `bool pila_esta_vacia(Pila *p)`
- `bool pila_esta_llena(Pila *p)`
- `void pila_destruir(Pila *p)`

En el `main`, prueba:
```c
Pila *p = pila_crear();

pila_push(p, 10);
pila_push(p, 20);
pila_push(p, 30);

printf("Tope: %d\n", pila_peek(p));  // 30

printf("Pop: %d\n", pila_pop(p));  // 30
printf("Pop: %d\n", pila_pop(p));  // 20
printf("Pop: %d\n", pila_pop(p));  // 10

printf("¿Vacía?: %s\n", pila_esta_vacia(p) ? "sí" : "no");  // sí

pila_destruir(p);
```

**Pistas:**
- Usa struct con array estático: `int elementos[100]` y `int tope`
- El `tope` es el índice del próximo elemento a insertar
- Valida sobre/bajo-flujo en push/pop

---

## Ejercicio 3 — TDA Fracción (★★★)

Implementa el TDA `Fraccion` con **reducción automática**:

**Funciones requeridas:**
- `Fraccion fraccion_crear(int num, int den)` — crea fracción (num/den)
- `Fraccion fraccion_sumar(Fraccion f1, Fraccion f2)` — suma f1 + f2
- `Fraccion fraccion_multiplicar(Fraccion f1, Fraccion f2)` — multiplica f1 × f2
- `Fraccion fraccion_simplificar(Fraccion f)` — reduce a forma irreducible (usa MCD)
- `void fraccion_imprimir(Fraccion f)` — imprime "3/4"

**Requisitos especiales:**
- Todas las fracciones se guardan **siempre reducidas** (simplificadas)
- Implementa `int mcd(int a, int b)` usando algoritmo de Euclides
- Maneja denominador negativo (p. ej., 3/-4 → -3/4)
- Valida que denominador ≠ 0

En el `main`, prueba:
```c
Fraccion f1 = fraccion_crear(2, 4);  // Se reduce a 1/2 automáticamente
Fraccion f2 = fraccion_crear(1, 3);

Fraccion suma = fraccion_sumar(f1, f2);
printf("Suma: "); fraccion_imprimir(suma); printf("\n");  // 5/6

Fraccion producto = fraccion_multiplicar(f1, f2);
printf("Producto: "); fraccion_imprimir(producto); printf("\n");  // 1/6

Fraccion f3 = fraccion_crear(6, 9);
printf("Simplificar 6/9: "); fraccion_imprimir(f3); printf("\n");  // 2/3
```

**Pistas:**
- Algoritmo de Euclides para MCD:
  ```c
  int mcd(int a, int b) {
      a = abs(a);
      b = abs(b);
      while (b != 0) {
          int tmp = b;
          b = a % b;
          a = tmp;
      }
      return a;
  }
  ```
- Cuando crees una fracción, automáticamente simplifica
- Para sumar: (a/b) + (c/d) = (a*d + b*c) / (b*d), luego simplifica
- Para multiplicar: (a/b) × (c/d) = (a*c) / (b*d), luego simplifica

---

# Cierre (09:55 – 10:00)

Hoy aprendimos que **buenos TDAs son la base de la ingeniería de software**:

1. **Separación de interfaz e implementación:** El usuario nunca ve los detalles internos
2. **Encapsulamiento:** Si necesitas cambiar cómo funciona internamente, el código cliente no se rompe
3. **Contratos claros:** Las funciones públicas son el "contrato" con el usuario

**Todos los laboratorios siguientes usarán este patrón:**
- Lista enlazada = TDA con operaciones como `insertar()`, `eliminar()`, `buscar()`
- Árbol = TDA con `insertar()`, `buscar()`, `recorrer()`
- Grafo = TDA con `agregar_arista()`, `buscar_camino()`

El patrón de TDA nos permite trabajar con estructuras complejas de forma segura y mantenible. Es la forma en que los programadores profesionales organizan código en C.

---

*EIN423-B · Departamento de Informática · UTFSM*
