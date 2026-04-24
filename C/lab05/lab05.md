# Laboratorio 5 — Lista Enlazada Simple

**Curso:** EIN423-B · Estructuras de Datos
**Duración:** 90 minutos
**Horario:** 08:30 – 10:00

## Objetivos del laboratorio
- Comprender la estructura de nodos y listas enlazadas simples
- Implementar operaciones fundamentales de inserción y eliminación con malloc/free
- Practicar manipulación de punteros y navegación en listas
- Manejar correctamente casos borde (lista vacía, un elemento, etc.)
- Resolver problemas avanzados como inversión de lista in-place

---

# Estructura de la clase

| Hora | Actividad |
|------|-----------|
| 08:30 – 08:40 | Introducción |
| 08:40 – 09:10 | Concepto y código guiado |
| 09:10 – 09:55 | Ejercicios |
| 09:55 – 10:00 | Cierre |

---

# 1. Introducción (08:30 – 08:40)

La **lista enlazada simple** es una estructura de datos fundamental que almacena elementos en nodos conectados por punteros. A diferencia de los arrays, permite inserción y eliminación eficiente O(1) en el frente, aunque el acceso a un elemento toma O(n).

En este laboratorio implementarás las operaciones básicas y aprenderás por qué los punteros son tan poderosos (y por qué olvidar actualizar un puntero causa que tu programa falle espectacularmente).

---

# 2. Concepto y código guiado (08:40 – 09:10)

## Estructura de nodo y lista

Una lista enlazada consta de **nodos**, cada uno conteniendo datos y un puntero al siguiente:

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo *siguiente;
} Nodo;

typedef struct {
    Nodo *cabeza;
    int tamanio;
} ListaEnlazada;
```

## Diagrama en memoria

Una lista con valores [10 → 20 → 30]:

```
cabeza → [10|•]  →  [20|•]  →  [30|NULL]
         ↑           ↑           ↑
       Nodo 1     Nodo 2     Nodo 3
```

El puntero `siguiente` apunta a la dirección del próximo nodo. El último nodo apunta a `NULL`.

## Creación e inicialización

```c
ListaEnlazada crearLista(void) {
    ListaEnlazada lista;
    lista.cabeza = NULL;
    lista.tamanio = 0;
    return lista;
}
```

## push_front: Insertar al inicio

**Paso a paso:**
1. Crear nuevo nodo con malloc
2. Asignar dato al nuevo nodo
3. Hacer que el nuevo nodo apunte a la cabeza actual
4. Actualizar la cabeza para que sea el nuevo nodo
5. Incrementar tamaño

```c
void push_front(ListaEnlazada *lista, int valor) {
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    if (nuevo == NULL) {
        fprintf(stderr, "Error: No se pudo asignar memoria\n");
        return;
    }

    nuevo->dato = valor;
    nuevo->siguiente = lista->cabeza;
    lista->cabeza = nuevo;
    lista->tamanio++;
}
```

**Visualización de push_front(lista, 5) en lista vacía:**

```
ANTES:  cabeza = NULL

PASO 1: nuevo = malloc(sizeof(Nodo))
        nuevo → [5|?]

PASO 2: nuevo->siguiente = NULL
        nuevo → [5|NULL]

PASO 3: cabeza = nuevo
        cabeza → [5|NULL]
```

## push_back: Insertar al final

Para insertar al final, debemos recorrer hasta el final de la lista:

```c
void push_back(ListaEnlazada *lista, int valor) {
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    if (nuevo == NULL) {
        fprintf(stderr, "Error: No se pudo asignar memoria\n");
        return;
    }

    nuevo->dato = valor;
    nuevo->siguiente = NULL;

    if (lista->cabeza == NULL) {
        // Lista vacía: el nuevo es la cabeza
        lista->cabeza = nuevo;
    } else {
        // Recorrer hasta el último nodo
        Nodo *actual = lista->cabeza;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        // Conectar el último nodo con el nuevo
        actual->siguiente = nuevo;
    }
    lista->tamanio++;
}
```

## pop_front: Eliminar del inicio

```c
int pop_front(ListaEnlazada *lista) {
    if (lista->cabeza == NULL) {
        fprintf(stderr, "Error: Lista vacía\n");
        return -1;
    }

    Nodo *temp = lista->cabeza;
    int valor = temp->dato;
    lista->cabeza = temp->siguiente;
    free(temp);
    lista->tamanio--;
    return valor;
}
```

## imprimir: Recorrer y mostrar

El patrón típico de recorrido: `while (actual != NULL)`:

```c
void imprimir(ListaEnlazada *lista) {
    printf("Lista: ");
    Nodo *actual = lista->cabeza;
    while (actual != NULL) {
        printf("[%d] → ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL (tamanio: %d)\n", lista->tamanio);
}
```

## obtener_tamanio

```c
int obtener_tamanio(ListaEnlazada *lista) {
    return lista->tamanio;
}
```

## destruir: Liberar toda la memoria

**Errores comunes:**
- Olvidar liberar nodos → memory leak
- Liberar primero la cabeza → perder referencia a otros nodos
- Liberar sin hacer free() → dangling pointers

```c
void destruir(ListaEnlazada *lista) {
    Nodo *actual = lista->cabeza;
    while (actual != NULL) {
        Nodo *temp = actual;
        actual = actual->siguiente;
        free(temp);
    }
    lista->cabeza = NULL;
    lista->tamanio = 0;
}
```

---

# 3. Ejercicios (09:10 – 09:55)

## Ejercicio 1 — Operaciones Básicas (★☆☆)

Implementa un programa completo que:
1. Crea una lista vacía
2. Inserta 5 elementos [1, 2, 3, 4, 5] usando `push_front` y `push_back` alternadamente
3. Imprime la lista después de cada operación
4. Elimina 3 elementos del frente
5. Imprime el tamaño final

**Funciones requeridas:**
- `push_front(lista, valor)`
- `push_back(lista, valor)`
- `pop_front(lista)`
- `imprimir(lista)`
- `obtener_tamanio(lista)`
- `destruir(lista)`

**Salida esperada (ejemplo):**
```
push_front(1): Lista: [1] → NULL (tamanio: 1)
push_back(2): Lista: [1] → [2] → NULL (tamanio: 2)
push_front(0): Lista: [0] → [1] → [2] → NULL (tamanio: 3)
...
pop_front: retorna 0, Lista: [1] → [2] → NULL (tamanio: 2)
```

---

## Ejercicio 2 — Búsqueda, Acceso y Eliminación (★★☆)

Implementa:

**a) buscar(lista, valor) → índice**
- Recorre la lista comparando cada dato
- Retorna el índice (0-based) si lo encuentra
- Retorna -1 si no existe

**b) obtener(lista, i) → valor**
- Recorre hasta la posición i
- Retorna el valor
- Maneja índice fuera de rango (retorna -1 o imprime error)

**c) eliminar(lista, valor)**
- Elimina la PRIMERA ocurrencia de valor
- Libera la memoria del nodo
- Maneja casos: lista vacía, elemento en cabeza, elemento al final

**Caso borde a considerar:**
```
Lista: [5] → [5] → [3] → NULL
eliminar(5) debe quedar: [5] → [3] → NULL (solo la primera ocurrencia)
```

**Prueba en main:**
```
Lista inicial: [10] → [20] → [30] → [40] → [50]
Índice de 30: 2
Valor en posición 1: 20
Eliminar 30: [10] → [20] → [40] → [50]
Buscar 100: -1 (no encontrado)
```

---

## Ejercicio 3 — Invertir Lista In-Place (★★★)

Implementa `void invertir(ListaEnlazada *lista)` que revierte la lista **sin crear nuevos nodos**, solo reencadenando punteros.

**Algoritmo (iterativo con 3 punteros):**

```
ANTES: cabeza → [1|•] → [2|•] → [3|NULL]

PASO 1: anterior=NULL, actual=cabeza
        [1|•] ← anterior
        [2|•] → actual

PASO 2: anterior=[1], actual=[2]
        [1|NULL] (reencadenado)
        [2|•] ← nuevo anterior
        [3|•] → nuevo actual

PASO 3: anterior=[2], actual=[3]
        [2|•←1|NULL] (reencadenado)
        [3|NULL] ← nuevo anterior
        NULL → nuevo actual

PASO 4: anterior=[3], actual=NULL
        [3|•←2] (reencadenado)
        Terminar, cabeza = [3]

RESULTADO: cabeza → [3|•] → [2|•] → [1|NULL]
```

**Pistas:**
- Mantén tres punteros: `anterior`, `actual`, `siguiente`
- En cada iteración, guarda el siguiente antes de reencadenar
- Al final, `anterior` es la nueva cabeza

**Verificación:**
```
ANTES:  [1] → [2] → [3] → [4] → [5] → NULL
DESPUÉS: [5] → [4] → [3] → [2] → [1] → NULL
```

---

# Cierre (09:55 – 10:00)

La **lista enlazada es la piedra angular** de pilas, colas y muchas otras estructuras de datos.

Los puntos clave de este laboratorio:
- **malloc/free:** Gestiona memoria manualmente; errores aquí causen memory leaks
- **Punteros:** Actualiza siempre la cabeza; un puntero mal apuntado rompe toda la lista
- **Recorrido:** El patrón `while (actual != NULL)` es fundamental
- **Casos borde:** Lista vacía, un nodo, eliminación en la cabeza

**Próximo laboratorio:** Lista doblemente enlazada + deque (colas con dos extremos).

---

*EIN423-B · Departamento de Informática · UTFSM*
