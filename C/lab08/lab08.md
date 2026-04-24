# Laboratorio 8 — Cola (Queue) y Cola de Prioridad

**Curso:** EIN423-B · Estructuras de Datos
**Duración:** 90 minutos
**Horario:** 08:30 – 10:00

## Objetivos del laboratorio
- Implementar el TDA Cola usando lista enlazada con HEAD y TAIL
- Comprender y aplicar el principio FIFO (First In, First Out)
- Simular sistemas reales: colas bancarias
- Implementar colas de prioridad (heaps) y comprender sus aplicaciones

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

Una **cola (queue)** es una estructura **FIFO** (First In, First Out): el primer elemento insertado es el primero en salir.

**Visualización:**
```
frente → [ A ][ B ][ C ][ D ] ← fondo
dequeue                       enqueue
```

**Comparación con pila:**
| Estructura | Operación | Patrón |
|-----------|-----------|--------|
| Pila | push/pop en MISMO extremo | LIFO |
| Cola | enqueue en un extremo, dequeue en otro | FIFO |

**Aplicaciones reales:**
- **Colas bancarias:** Clientes llegan, se sirven en orden de llegada
- **Scheduling:** Procesos esperan en cola; CPU procesa uno por uno
- **BFS (Breadth-First Search):** Exploración por niveles de un grafo
- **Impresoras:** Documentos se imprimen en orden de llegada

---

# 2. Concepto y código guiado (08:40 – 09:10)

## Estructura de Cola

Para que enqueue O(1) y dequeue O(1), necesitamos **punteros al frente Y al fondo**:

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo {
    int dato;
    struct Nodo *siguiente;
} Nodo;

typedef struct {
    Nodo *frente;
    Nodo *fondo;
    int tamanio;
} Cola;
```

## Diagrama: FIFO con HEAD y TAIL

```
Cola vacía:
frente = NULL
fondo = NULL

Después de enqueue(1), enqueue(2), enqueue(3):
frente → [1] → [2] → [3] ← fondo
dequeue ←               enqueue →
```

## Crear cola

```c
Cola crear_cola(void) {
    Cola cola;
    cola.frente = NULL;
    cola.fondo = NULL;
    cola.tamanio = 0;
    return cola;
}
```

## enqueue: Agregar al fondo (O(1))

```c
void enqueue(Cola *cola, int valor) {
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    if (nuevo == NULL) {
        fprintf(stderr, "Error: No se pudo asignar memoria\n");
        return;
    }

    nuevo->dato = valor;
    nuevo->siguiente = NULL;

    if (cola->fondo != NULL) {
        // Cola no vacía: conectar último con nuevo
        cola->fondo->siguiente = nuevo;
    } else {
        // Cola vacía: el nuevo es también el frente
        cola->frente = nuevo;
    }

    cola->fondo = nuevo;
    cola->tamanio++;
}
```

**Análisis:** Sin puntero fondo, necesitaría recorrer O(n). Con fondo, es O(1).

## dequeue: Eliminar del frente (O(1))

```c
int dequeue(Cola *cola) {
    if (cola->frente == NULL) {
        fprintf(stderr, "Error: Cola vacía\n");
        return -1;
    }

    Nodo *temp = cola->frente;
    int valor = temp->dato;

    cola->frente = temp->siguiente;

    if (cola->frente == NULL) {
        // Era el único nodo: actualizar fondo también
        cola->fondo = NULL;
    }

    free(temp);
    cola->tamanio--;
    return valor;
}
```

## frente: Ver el primer elemento sin eliminar

```c
int ver_frente(Cola *cola) {
    if (cola->frente == NULL) {
        fprintf(stderr, "Error: Cola vacía\n");
        return -1;
    }
    return cola->frente->dato;
}
```

## Esta vacía

```c
int esta_vacia(Cola *cola) {
    return cola->frente == NULL;
}
```

## Obtener tamaño

```c
int obtener_tamanio(Cola *cola) {
    return cola->tamanio;
}
```

## Imprimir

```c
void imprimir_cola(Cola *cola) {
    printf("Cola: frente → ");
    Nodo *actual = cola->frente;
    while (actual != NULL) {
        printf("[%d] → ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL (fondo) | tamanio: %d\n", cola->tamanio);
}
```

## Destruir

```c
void destruir_cola(Cola *cola) {
    while (!esta_vacia(cola)) {
        dequeue(cola);
    }
    cola->tamanio = 0;
}
```

---

# 3. Ejercicios (09:10 – 09:55)

## Ejercicio 1 — TDA Cola Completo (★☆☆)

Implementa un programa que:
1. Crea una cola vacía
2. Hace `enqueue` de los números 1, 2, 3, 4, 5 (en ese orden)
3. Imprime la cola (debe mostrar 1 → 2 → 3 → 4 → 5)
4. Verifica que `ver_frente()` retorna 1 (el primer elemento)
5. Hace `dequeue` 5 veces e imprime cada valor (debe ser 1, 2, 3, 4, 5)
6. Verifica que `esta_vacia()` retorna verdadero

**Funciones requeridas:**
```c
Cola crear_cola(void);
void enqueue(Cola *cola, int valor);
int dequeue(Cola *cola);
int ver_frente(Cola *cola);
int esta_vacia(Cola *cola);
int obtener_tamanio(Cola *cola);
void imprimir_cola(Cola *cola);
void destruir_cola(Cola *cola);
```

**Salida esperada:**
```
Tamaño inicial: 0
enqueue(1) enqueue(2) enqueue(3) enqueue(4) enqueue(5)
Cola: frente → [1] → [2] → [3] → [4] → [5] → NULL (fondo) | tamanio: 5
Frente (ver_frente): 1
dequeue(): 1, dequeue(): 2, dequeue(): 3, dequeue(): 4, dequeue(): 5
Cola vacía: 1
```

---

## Ejercicio 2 — Simulación de Cola Bancaria (★★☆)

Implementa una simulación de una **sucursal bancaria** con una cola de atención.

**Entrada:**
- Número de clientes: N = 20
- Duración de la simulación: 60 minutos
- Tiempo de atención por cliente: aleatorio entre 1 y 5 minutos

**Proceso:**
1. Cada minuto:
   - Llegan nuevos clientes (probablemente 0, 1 o 2 por minuto)
   - Si hay cajeadora disponible y hay clientes en cola, atiende a uno
   - Actualiza tiempo de espera acumulado

**Estadísticas al final:**
- Tiempo promedio de espera
- Máximo tiempo de espera
- Mínimo tiempo de espera
- Total de clientes atendidos

**Estructura de cliente:**
```c
typedef struct {
    int id;           // número de cliente
    int hora_llegada; // minuto en que llegó
    int tiempo_atencion; // minutos que tarda
    int hora_inicio_atencion;
    int tiempo_espera;
} Cliente;
```

**Pseudocódigo:**
```
para cada minuto de 0 a 60:
    - Generar nuevos clientes que llegan (probabilidad 30% por minuto)
    - Si cajeadora libre y cola no vacía:
      - Sacar cliente de cola
      - Marcarlo como en atención
      - Restar tiempo de atencion en cada paso
    - Si cajeadora finalizó cliente:
      - Calcular tiempo_espera = hora_inicio_atencion - hora_llegada
      - Marcar cajeadora como libre

Al final:
    - Calcular promedios y estadísticas
```

**Salida esperada (ejemplo):**
```
=== SIMULACIÓN DE COLA BANCARIA ===
Total clientes: 20
Tiempo promedio de espera: 3.45 minutos
Máximo tiempo de espera: 8.2 minutos
Mínimo tiempo de espera: 0.1 minutos
Total minutos simulados: 60
```

---

## Ejercicio 3 — Cola de Prioridad (Min-Heap) (★★★)

Implementa una **cola de prioridad** usando un **heap binario** (array dinámico).

Un heap es un árbol binario completo donde cada padre ≤ sus hijos (min-heap).

**Estructura:**
```c
typedef struct {
    int valor;
    int prioridad;
} Elemento;

typedef struct {
    Elemento *elementos;
    int tamanio;
    int capacidad;
} ColaPrioridad;
```

**Operaciones principales:**

### insert: Insertar con prioridad

```c
void insert(ColaPrioridad *cp, int valor, int prioridad) {
    if (cp->tamanio == cp->capacidad) {
        cp->capacidad *= 2;
        cp->elementos = (Elemento *)realloc(cp->elementos,
                                             cp->capacidad * sizeof(Elemento));
    }

    Elemento nuevo;
    nuevo.valor = valor;
    nuevo.prioridad = prioridad;

    cp->elementos[cp->tamanio] = nuevo;
    cp->tamanio++;

    // Bubble up (heapify_up)
    heapify_up(cp, cp->tamanio - 1);
}
```

### extractMin: Extraer elemento con MENOR prioridad

```c
int extract_min(ColaPrioridad *cp) {
    if (cp->tamanio == 0) {
        fprintf(stderr, "Error: Cola de prioridad vacía\n");
        return -1;
    }

    int min_valor = cp->elementos[0].valor;

    // Mover el último al inicio
    cp->elementos[0] = cp->elementos[cp->tamanio - 1];
    cp->tamanio--;

    // Bubble down (heapify_down)
    heapify_down(cp, 0);

    return min_valor;
}
```

### heapify_up: Subir elemento si es menor que su padre

```c
void heapify_up(ColaPrioridad *cp, int indice) {
    while (indice > 0) {
        int padre = (indice - 1) / 2;
        if (cp->elementos[indice].prioridad < cp->elementos[padre].prioridad) {
            // Intercambiar
            Elemento temp = cp->elementos[indice];
            cp->elementos[indice] = cp->elementos[padre];
            cp->elementos[padre] = temp;
            indice = padre;
        } else {
            break;
        }
    }
}
```

### heapify_down: Bajar elemento si es mayor que sus hijos

```c
void heapify_down(ColaPrioridad *cp, int indice) {
    while (2 * indice + 1 < cp->tamanio) {
        int hijo_izq = 2 * indice + 1;
        int hijo_der = 2 * indice + 2;
        int menor = hijo_izq;

        if (hijo_der < cp->tamanio &&
            cp->elementos[hijo_der].prioridad < cp->elementos[hijo_izq].prioridad) {
            menor = hijo_der;
        }

        if (cp->elementos[indice].prioridad > cp->elementos[menor].prioridad) {
            // Intercambiar
            Elemento temp = cp->elementos[indice];
            cp->elementos[indice] = cp->elementos[menor];
            cp->elementos[menor] = temp;
            indice = menor;
        } else {
            break;
        }
    }
}
```

### peek: Ver el mínimo sin eliminar

```c
int peek(ColaPrioridad *cp) {
    if (cp->tamanio == 0) {
        fprintf(stderr, "Error: Cola de prioridad vacía\n");
        return -1;
    }
    return cp->elementos[0].valor;
}
```

**Prueba en main:**
```c
ColaPrioridad cp;
cp.capacidad = 10;
cp.tamanio = 0;
cp.elementos = (Elemento *)malloc(cp.capacidad * sizeof(Elemento));

// Insertar valores con prioridades
insert(&cp, 10, 3);  // valor 10, prioridad 3
insert(&cp, 20, 1);  // valor 20, prioridad 1 (mayor prioridad)
insert(&cp, 30, 2);  // valor 30, prioridad 2
insert(&cp, 40, 5);  // valor 40, prioridad 5
insert(&cp, 50, 2);  // valor 50, prioridad 2

// Extraer en orden de prioridad
while (cp.tamanio > 0) {
    printf("%d ", extract_min(&cp));  // 20, 30, 50, 10, 40
}
printf("\n");

free(cp.elementos);
```

**Interpretación:**
- Menor prioridad = mayor urgencia (procesarse primero)
- `extract_min()` siempre retorna el elemento de MENOR prioridad

---

# Cierre (09:55 – 10:00)

La **cola es fundamental** en algoritmos y sistemas:

- **Scheduling:** Procesos se atienden en orden FIFO
- **BFS:** Exploración por niveles (colas normales)
- **Dijkstra, A*, Prim:** Algoritmos de grafo (colas de prioridad)
- **Sistemas reales:** Bancos, supermercados, call centers

**Comparación de estructuras:**
| Estructura | Inserción | Eliminación | Caso de uso |
|-----------|-----------|------------|------------|
| Pila | O(1) tope | O(1) tope | Recursión, undo/redo |
| Cola | O(1) fondo | O(1) frente | Scheduling, BFS |
| Cola Prioridad | O(log n) | O(log n) | Dijkstra, urgencias |

**Próximo laboratorio:** Árboles binarios de búsqueda (BST).

---

*EIN423-B · Departamento de Informática · UTFSM*
