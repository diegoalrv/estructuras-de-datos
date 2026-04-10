# Laboratorio Condensado — Estructuras de Datos

**Curso:** EIN423-B · Estructuras de Datos
**Universidad:** UTFSM

---

## Descripción General

Este laboratorio integra los conceptos fundamentales de los Laboratorios 2 al 6 en una sola sesión práctica. Cada problema es un archivo `.c` autocontenido que se puede compilar y ejecutar de forma independiente en cualquier compilador de C online.

Se abordan **6 temas**, cada uno con un archivo de **problema** (código base con `TODO`) y un archivo de **solución** (implementación completa de referencia).

---

## Temas y Problemas

### 1. Recursividad (`recursividad_problema.c` / `recursividad_solucion.c`)

Implementar funciones recursivas clásicas: factorial, Fibonacci, búsqueda binaria y Torres de Hanói. El objetivo es comprender caso base, caso recursivo y la pila de llamadas.

**Funciones a implementar:**
- `long factorial(int n)` — Factorial recursivo
- `long fibonacci(int n)` — N-ésimo número de Fibonacci
- `int busqueda_binaria(int *arr, int izq, int der, int objetivo)` — Búsqueda binaria recursiva
- `void hanoi(int n, char origen, char destino, char auxiliar)` — Torres de Hanói

---

### 2. Estructuras de Datos: Fracción (`fraccion_problema.c` / `fraccion_solucion.c`)

Diseñar e implementar un Tipo de Dato Abstracto (TDA) `Fraccion` usando `struct`. Las fracciones se simplifican automáticamente al crearse usando el algoritmo de Euclides (MCD).

**Funciones a implementar:**
- `Fraccion fraccion_crear(int num, int den)` — Crea fracción simplificada
- `Fraccion fraccion_sumar(Fraccion a, Fraccion b)` — Suma de fracciones
- `Fraccion fraccion_multiplicar(Fraccion a, Fraccion b)` — Multiplicación
- `void fraccion_imprimir(Fraccion f)` — Imprime en formato `num/den`

---

### 3. Lista Enlazada Simple (`lista_simple_problema.c` / `lista_simple_solucion.c`)

Implementar una lista enlazada simple con nodos dinámicos (`malloc`/`free`). Se practican inserciones, eliminaciones, búsqueda, acceso por índice e inversión in-place.

**Funciones a implementar:**
- `Lista lista_crear()` — Crea lista vacía
- `void lista_push_front(Lista *l, int valor)` — Insertar al inicio
- `void lista_push_back(Lista *l, int valor)` — Insertar al final
- `int lista_pop_front(Lista *l)` — Eliminar del inicio
- `int lista_buscar(Lista *l, int valor)` — Buscar valor (retorna índice)
- `int lista_obtener(Lista *l, int idx)` — Obtener valor en posición
- `int lista_eliminar(Lista *l, int valor)` — Eliminar primera ocurrencia
- `void lista_invertir(Lista *l)` — Invertir la lista in-place
- `void lista_imprimir(Lista *l)` — Imprimir la lista
- `void lista_destruir(Lista *l)` — Liberar toda la memoria

---

### 4. Lista Doblemente Enlazada (`lista_doble_problema.c` / `lista_doble_solucion.c`)

Extender el concepto de lista enlazada con punteros `anterior` y `siguiente`, más un puntero `cola` para lograr `push_back` en O(1). Se implementa inserción ordenada y eliminación.

**Funciones a implementar:**
- `ListaDoble listad_crear()` — Crea lista vacía
- `void listad_push_front(ListaDoble *l, int valor)` — Insertar al inicio
- `void listad_push_back(ListaDoble *l, int valor)` — Insertar al final O(1)
- `int listad_pop_front(ListaDoble *l)` — Eliminar del inicio
- `int listad_pop_back(ListaDoble *l)` — Eliminar del final
- `void listad_insertar_ordenado(ListaDoble *l, int valor)` — Inserción ordenada
- `int listad_eliminar(ListaDoble *l, int valor)` — Eliminar primera ocurrencia
- `void listad_imprimir_adelante(ListaDoble *l)` — Imprimir cabeza→cola
- `void listad_imprimir_atras(ListaDoble *l)` — Imprimir cola→cabeza
- `void listad_destruir(ListaDoble *l)` — Liberar memoria

---

### 5. Pila — Stack LIFO (`pila_problema.c` / `pila_solucion.c`)

Implementar una Pila (Stack) usando un arreglo estático de tamaño máximo 100. La pila sigue el principio LIFO (Last In, First Out). Se aplica a verificación de paréntesis balanceados.

**Funciones a implementar:**
- `Pila pila_crear()` — Crea pila vacía
- `void pila_push(Pila *p, int valor)` — Apilar valor
- `int pila_pop(Pila *p)` — Desapilar valor
- `int pila_peek(Pila *p)` — Ver tope sin desapilar
- `int pila_esta_vacia(Pila *p)` — Verificar si está vacía
- `int pila_esta_llena(Pila *p)` — Verificar si está llena
- **Aplicación:** `int parentesis_balanceados(const char *expr)` — Verificar paréntesis

---

### 6. Cola — Queue FIFO (`cola_problema.c` / `cola_solucion.c`)

Implementar una Cola (Queue) usando un arreglo circular de tamaño máximo 100. La cola sigue el principio FIFO (First In, First Out). Se aplica a simulación de atención de clientes.

**Funciones a implementar:**
- `Cola cola_crear()` — Crea cola vacía
- `void cola_enqueue(Cola *c, int valor)` — Encolar valor
- `int cola_dequeue(Cola *c)` — Desencolar valor
- `int cola_frente(Cola *c)` — Ver el frente sin desencolar
- `int cola_esta_vacia(Cola *c)` — Verificar si está vacía
- `int cola_esta_llena(Cola *c)` — Verificar si está llena
- **Aplicación:** Simulación de cola de atención

---

## Archivos

| Tema | Problema (código base) | Solución (pauta) |
|------|----------------------|------------------|
| Recursividad | `recursividad_problema.c` | `recursividad_solucion.c` |
| Struct Fracción | `fraccion_problema.c` | `fraccion_solucion.c` |
| Lista Simple | `lista_simple_problema.c` | `lista_simple_solucion.c` |
| Lista Doble | `lista_doble_problema.c` | `lista_doble_solucion.c` |
| Pila (Stack) | `pila_problema.c` | `pila_solucion.c` |
| Cola (Queue) | `cola_problema.c` | `cola_solucion.c` |

---

## Instrucciones de Compilación

Cada archivo `.c` es autocontenido. Para compilar cualquiera de ellos:

```bash
gcc -Wall -o programa archivo.c -lm
./programa
```

O simplemente copia y pega el contenido en un compilador C online.

---

*EIN423-B · Departamento de Informática · UTFSM*
