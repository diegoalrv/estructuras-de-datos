# Laboratorio 6 — Lista Doblemente Enlazada

**Curso:** EIN423-B · Estructuras de Datos
**Duración:** 90 minutos
**Horario:** 08:30 – 10:00

## Objetivos del laboratorio
- Extender listas enlazadas simples a listas doblemente enlazadas
- Implementar operaciones eficientes en ambos extremos
- Practicar navegación bidireccional
- Implementar un deque y aplicarlo a problemas reales
- Entender por qué el puntero "cola" optimiza push_back a O(1)

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

Una **lista doblemente enlazada** (doubly linked list) agrega un puntero `anterior` a cada nodo, permitiendo navegar en ambas direcciones.

**Ventaja clave:** Con un puntero `cola` que apunta al último nodo, `push_back` es O(1) en lugar de O(n).

Casos de uso:
- Historial de navegador (atrás/adelante)
- Listas de reproducción (siguiente/anterior)
- **Deques** (double-ended queues)
- Undo/Redo en editores

---

# 2. Concepto y código guiado (08:40 – 09:10)

## Estructura de nodo doblemente enlazado

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct NodoDL {
    int dato;
    struct NodoDL *anterior;
    struct NodoDL *siguiente;
} NodoDL;

typedef struct {
    NodoDL *cabeza;
    NodoDL *cola;
    int tamanio;
} ListaDL;
```

## Diagrama en memoria

Lista con valores [10, 20, 30]:

```
NULL ← [10|•|•] ↔ [20|•|•] ↔ [30|•|•] → NULL
       cabeza                 cola
```

Cada nodo tiene dos punteros: uno al anterior, uno al siguiente.

## Inicialización

```c
ListaDL crearListaDL(void) {
    ListaDL lista;
    lista.cabeza = NULL;
    lista.cola = NULL;
    lista.tamanio = 0;
    return lista;
}
```

## push_front: Insertar al inicio

```c
void push_front(ListaDL *lista, int valor) {
    NodoDL *nuevo = (NodoDL *)malloc(sizeof(NodoDL));
    if (nuevo == NULL) {
        fprintf(stderr, "Error: No se pudo asignar memoria\n");
        return;
    }

    nuevo->dato = valor;
    nuevo->anterior = NULL;
    nuevo->siguiente = lista->cabeza;

    if (lista->cabeza != NULL) {
        // Hay nodos: actualizar puntero anterior del viejo primero
        lista->cabeza->anterior = nuevo;
    } else {
        // Lista vacía: el nuevo es también la cola
        lista->cola = nuevo;
    }

    lista->cabeza = nuevo;
    lista->tamanio++;
}
```

## push_back: Insertar al final (¡AHORA O(1)!)

Sin puntero cola, esto sería O(n). Con `cola`, es O(1):

```c
void push_back(ListaDL *lista, int valor) {
    NodoDL *nuevo = (NodoDL *)malloc(sizeof(NodoDL));
    if (nuevo == NULL) {
        fprintf(stderr, "Error: No se pudo asignar memoria\n");
        return;
    }

    nuevo->dato = valor;
    nuevo->siguiente = NULL;
    nuevo->anterior = lista->cola;

    if (lista->cola != NULL) {
        // Hay nodos: conectar el viejo último con el nuevo
        lista->cola->siguiente = nuevo;
    } else {
        // Lista vacía: el nuevo es también la cabeza
        lista->cabeza = nuevo;
    }

    lista->cola = nuevo;
    lista->tamanio++;
}
```

## pop_front: Eliminar del inicio

```c
int pop_front(ListaDL *lista) {
    if (lista->cabeza == NULL) {
        fprintf(stderr, "Error: Lista vacía\n");
        return -1;
    }

    NodoDL *temp = lista->cabeza;
    int valor = temp->dato;

    lista->cabeza = temp->siguiente;

    if (lista->cabeza != NULL) {
        lista->cabeza->anterior = NULL;
    } else {
        // Era el único nodo: actualizar cola también
        lista->cola = NULL;
    }

    free(temp);
    lista->tamanio--;
    return valor;
}
```

## pop_back: Eliminar del final

```c
int pop_back(ListaDL *lista) {
    if (lista->cola == NULL) {
        fprintf(stderr, "Error: Lista vacía\n");
        return -1;
    }

    NodoDL *temp = lista->cola;
    int valor = temp->dato;

    lista->cola = temp->anterior;

    if (lista->cola != NULL) {
        lista->cola->siguiente = NULL;
    } else {
        // Era el único nodo: actualizar cabeza también
        lista->cabeza = NULL;
    }

    free(temp);
    lista->tamanio--;
    return valor;
}
```

## Imprimir hacia adelante

```c
void imprimir_adelante(ListaDL *lista) {
    printf("Adelante: NULL ← ");
    NodoDL *actual = lista->cabeza;
    while (actual != NULL) {
        printf("[%d] ↔ ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL (tamanio: %d)\n", lista->tamanio);
}
```

## Imprimir hacia atrás

```c
void imprimir_atras(ListaDL *lista) {
    printf("Atrás:   NULL ← ");
    NodoDL *actual = lista->cola;
    while (actual != NULL) {
        printf("[%d] ↔ ", actual->dato);
        actual = actual->anterior;
    }
    printf("NULL (tamanio: %d)\n", lista->tamanio);
}
```

## Destruir

```c
void destruir(ListaDL *lista) {
    NodoDL *actual = lista->cabeza;
    while (actual != NULL) {
        NodoDL *temp = actual;
        actual = actual->siguiente;
        free(temp);
    }
    lista->cabeza = NULL;
    lista->cola = NULL;
    lista->tamanio = 0;
}
```

---

# 3. Ejercicios (09:10 – 09:55)

## Ejercicio 1 — Operaciones Completas (★☆☆)

Implementa una lista doblemente enlazada con todas las operaciones:
- `push_front(lista, valor)`
- `push_back(lista, valor)`
- `pop_front(lista)`
- `pop_back(lista)`
- `imprimir_adelante(lista)`
- `imprimir_atras(lista)`
- `obtener_tamanio(lista)`
- `destruir(lista)`

**En main:**
```c
ListaDL lista = crearListaDL();

push_back(&lista, 10);   // [10]
push_back(&lista, 20);   // [10] ↔ [20]
push_front(&lista, 5);   // [5] ↔ [10] ↔ [20]
push_back(&lista, 30);   // [5] ↔ [10] ↔ [20] ↔ [30]

imprimir_adelante(&lista);
imprimir_atras(&lista);

pop_front(&lista);  // Elimina 5
pop_back(&lista);   // Elimina 30

imprimir_adelante(&lista);  // [10] ↔ [20]
imprimir_atras(&lista);      // [20] ↔ [10]

destruir(&lista);
```

**Verificación:**
- Después de `push_back` y `push_front`, tanto adelante como atrás muestran datos correctos
- El tamaño es consistente
- `pop_front` y `pop_back` manejan lista vacía sin crash

---

## Ejercicio 2 — Inserción Ordenada (★★☆)

Implementa `void insertar_ordenado(ListaDL *lista, int valor)` que mantiene la lista **ordenada de menor a mayor**.

**Algoritmo:**
1. Si lista vacía → `push_front`
2. Si valor ≤ primer elemento → `push_front`
3. Si valor ≥ último elemento → `push_back`
4. Si no → recorrer hasta encontrar posición correcta e insertar ahí

**También implementa:**
`int eliminar(ListaDL *lista, int valor)` — elimina la primera ocurrencia (aprovechar `anterior` para simplificar).

**Prueba en main:**
```c
ListaDL lista = crearListaDL();

// Inserta desordenado: 5, 3, 7, 1, 9
insertar_ordenado(&lista, 5);  // [5]
insertar_ordenado(&lista, 3);  // [3] ↔ [5]
insertar_ordenado(&lista, 7);  // [3] ↔ [5] ↔ [7]
insertar_ordenado(&lista, 1);  // [1] ↔ [3] ↔ [5] ↔ [7]
insertar_ordenado(&lista, 9);  // [1] ↔ [3] ↔ [5] ↔ [7] ↔ [9]

imprimir_adelante(&lista);

eliminar(&lista, 5);
imprimir_adelante(&lista);  // [1] ↔ [3] ↔ [7] ↔ [9]

destruir(&lista);
```

---

## Ejercicio 3 — Deque y Verificador de Palíndromes (★★★)

Implementa un **deque** (double-ended queue, cola de dos extremos) usando la lista doblemente enlazada.

```c
typedef struct {
    ListaDL lista;
} Deque;

Deque crear_deque(void);
void deque_push_front(Deque *d, int valor);
void deque_push_back(Deque *d, int valor);
int deque_pop_front(Deque *d);
int deque_pop_back(Deque *d);
int deque_frente(Deque *d);
int deque_fondo(Deque *d);
int deque_esta_vacio(Deque *d);
void deque_destruir(Deque *d);
```

**Aplicación: Verificador de palíndromes**

Implementa `int es_palindromo(const char *palabra)` que:
1. Inserta cada carácter de la palabra en el deque (adelante)
2. Extrae del frente y del fondo simultáneamente
3. Compara que sean iguales en cada paso
4. Retorna 1 si es palíndromo, 0 si no

**Ejemplo:**
```
Palabra: "racecar"
- push_front('r'), push_front('a'), push_front('c'), push_front('e'), push_front('c'), push_front('a'), push_front('r')
- Deque: [r] ↔ [a] ↔ [c] ↔ [e] ↔ [c] ↔ [a] ↔ [r]
- pop_front()='r', pop_back()='r' → iguales
- pop_front()='a', pop_back()='a' → iguales
- pop_front()='c', pop_back()='c' → iguales
- pop_front()='e' (elemento central) → es palíndromo

Palabra: "hello"
- Deque: [h] ↔ [e] ↔ [l] ↔ [l] ↔ [o]
- pop_front()='h', pop_back()='o' → NO iguales → NO es palíndromo
```

**En main, prueba:**
```c
printf("%d\n", es_palindromo("racecar"));   // 1
printf("%d\n", es_palindromo("hello"));     // 0
printf("%d\n", es_palindromo("level"));     // 1
printf("%d\n", es_palindromo("a"));         // 1
printf("%d\n", es_palindromo("ab"));        // 0
```

---

# Cierre (09:55 – 10:00)

La **lista doblemente enlazada + puntero cola** es la estructura base del deque.

Puntos clave:
- **Puntero cola:** Hace `push_back` O(1) en lugar de O(n)
- **Puntero anterior:** Simplifica eliminación sin necesidad de puntero "previo"
- **Deque:** Combinación poderosa para problemas que requieren dos extremos

**Próximo laboratorio:** Pila (Stack) LIFO — aplicaciones: paréntesis balanceados, notación postfija.

---

*EIN423-B · Departamento de Informática · UTFSM*
