# Laboratorio 14 — Grafos: Representación y BFS

**Curso:** EIN423-B · Estructuras de Datos  
**Duración:** 90 minutos  
**Horario:** 08:30 – 10:00

## Objetivos del laboratorio
- Entender dos formas de representar grafos: matriz de adyacencia y lista de adyacencia
- Implementar un grafo con lista de adyacencia
- Implementar búsqueda en amplitud (BFS) para encontrar caminos más cortos
- Comparar complejidad espacial de ambas representaciones

---

# Estructura de la clase

| Hora | Actividad |
|------|-----------|
| 08:30 – 08:40 | Introducción |
| 08:40 – 09:10 | Concepto y código guiado |
| 09:10 – 09:55 | Ejercicios |
| 09:55 – 10:00 | Cierre |

---

# 1. Introducción

Un **grafo** es una estructura de datos que representa relaciones entre objetos. Tiene dos componentes:
- **Vértices (nodos):** objetos individuales
- **Aristas (edges):** conexiones entre vértices

Existen dos formas principales de representar un grafo en memoria:

1. **Matriz de adyacencia:** matriz V×V donde entrada [i][j] = 1 si hay arista i→j
   - Espacio: O(V²) 
   - Ventaja: búsqueda rápida de si existe arista (i,j)
   - Desventaja: desperdicia espacio si grafo es disperso

2. **Lista de adyacencia:** array de listas enlazadas, donde lista[i] contiene vecinos de i
   - Espacio: O(V + E)
   - Ventaja: eficiente para grafos dispersos
   - Desventaja: búsqueda de arista específica es más lenta

**BFS (Búsqueda en Amplitud)** es un algoritmo que explora un grafo nivel por nivel desde un nodo de inicio, encontrando la distancia más corta a todos los nodos alcanzables.

---

# 2. Concepto y código guiado

## Representación con lista de adyacencia

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Vecino {
    int destino;
    struct Vecino *sig;
} Vecino;

typedef struct {
    Vecino **listas;  // array de punteros a listas de vecinos
    int V;            // número de vértices
} Grafo;

Grafo* grafo_crear(int V) {
    Grafo *g = malloc(sizeof(Grafo));
    g->V = V;
    g->listas = malloc(V * sizeof(Vecino*));
    for (int i = 0; i < V; i++) {
        g->listas[i] = NULL;
    }
    return g;
}

void grafo_agregar_arista(Grafo *g, int u, int v) {
    // Agregar v a la lista de u (si es dirigido, aquí termina)
    Vecino *nuevo = malloc(sizeof(Vecino));
    nuevo->destino = v;
    nuevo->sig = g->listas[u];
    g->listas[u] = nuevo;

    // Para grafo no dirigido, también agregar u a la lista de v
    nuevo = malloc(sizeof(Vecino));
    nuevo->destino = u;
    nuevo->sig = g->listas[v];
    g->listas[v] = nuevo;
}

void grafo_imprimir(Grafo *g) {
    printf("\nLista de adyacencia:\n");
    for (int i = 0; i < g->V; i++) {
        printf("Vértice %d: ", i);
        Vecino *temp = g->listas[i];
        while (temp) {
            printf("%d ", temp->destino);
            temp = temp->sig;
        }
        printf("\n");
    }
}
```

## Búsqueda en Amplitud (BFS) con Cola

BFS usa una cola para explorar nodos en orden de distancia desde el origen:

```c
#include <stdint.h>

typedef struct {
    int *datos;
    int frente, final, capacidad;
} Cola;

Cola* cola_crear(int capacidad) {
    Cola *c = malloc(sizeof(Cola));
    c->datos = malloc(capacidad * sizeof(int));
    c->frente = 0;
    c->final = -1;
    c->capacidad = capacidad;
    return c;
}

void cola_encolar(Cola *c, int valor) {
    if (c->final < c->capacidad - 1) {
        c->final++;
        c->datos[c->final] = valor;
    }
}

int cola_desencolar(Cola *c) {
    if (c->frente <= c->final) {
        return c->datos[c->frente++];
    }
    return -1;
}

int cola_vacia(Cola *c) {
    return c->frente > c->final;
}

void cola_destruir(Cola *c) {
    free(c->datos);
    free(c);
}

void bfs(Grafo *g, int inicio) {
    int *visitado = malloc(g->V * sizeof(int));
    int *distancia = malloc(g->V * sizeof(int));
    
    for (int i = 0; i < g->V; i++) {
        visitado[i] = 0;
        distancia[i] = -1;
    }
    
    Cola *c = cola_crear(g->V);
    
    visitado[inicio] = 1;
    distancia[inicio] = 0;
    cola_encolar(c, inicio);
    
    printf("\nBFS desde vértice %d:\n", inicio);
    printf("Orden de visita: ");
    
    while (!cola_vacia(c)) {
        int u = cola_desencolar(c);
        printf("%d ", u);
        
        Vecino *vecino = g->listas[u];
        while (vecino) {
            int v = vecino->destino;
            if (!visitado[v]) {
                visitado[v] = 1;
                distancia[v] = distancia[u] + 1;
                cola_encolar(c, v);
            }
            vecino = vecino->sig;
        }
    }
    
    printf("\n\nDistancias desde vértice %d:\n", inicio);
    for (int i = 0; i < g->V; i++) {
        if (distancia[i] == -1) {
            printf("Vértice %d: no alcanzable\n", i);
        } else {
            printf("Vértice %d: distancia %d\n", i, distancia[i]);
        }
    }
    
    cola_destruir(c);
    free(visitado);
    free(distancia);
}

void grafo_destruir(Grafo *g) {
    for (int i = 0; i < g->V; i++) {
        Vecino *temp = g->listas[i];
        while (temp) {
            Vecino *borrar = temp;
            temp = temp->sig;
            free(borrar);
        }
    }
    free(g->listas);
    free(g);
}
```

## Ejemplo de uso

```c
int main() {
    // Crear grafo con 6 vértices
    Grafo *g = grafo_crear(6);
    
    // Agregar aristas (no dirigido)
    // Aristas: 0-1, 0-2, 1-3, 1-4, 2-4, 3-5, 4-5
    grafo_agregar_arista(g, 0, 1);
    grafo_agregar_arista(g, 0, 2);
    grafo_agregar_arista(g, 1, 3);
    grafo_agregar_arista(g, 1, 4);
    grafo_agregar_arista(g, 2, 4);
    grafo_agregar_arista(g, 3, 5);
    grafo_agregar_arista(g, 4, 5);
    
    grafo_imprimir(g);
    bfs(g, 0);
    
    grafo_destruir(g);
    return 0;
}
```

---

# 3. Ejercicios

## Ejercicio 1 — Grafo con lista de adyacencia (★☆☆)

Implementa un grafo con lista de adyacencia. Agrega las aristas del ejemplo: 0-1, 0-2, 1-3, 1-4, 2-4, 3-5, 4-5.

Requisitos:
- Implementa `grafo_crear()` y `grafo_agregar_arista()`
- Implementa función `grado(int v)` que retorna el grado de un vértice
- Imprime la lista de adyacencia completa
- Imprime el grado de cada vértice

**Salida esperada:**
```
Lista de adyacencia:
Vértice 0: 2 1
Vértice 1: 4 3 0
Vértice 2: 4 0
Vértice 3: 5 1
Vértice 4: 5 2 1
Vértice 5: 4 3

Grados:
Vértice 0: grado 2
Vértice 1: grado 3
Vértice 2: grado 2
Vértice 3: grado 2
Vértice 4: grado 3
Vértice 5: grado 2
```

## Ejercicio 2 — BFS y distancias más cortas (★★☆)

Implementa BFS completamente y úsalo para encontrar distancias desde un vértice de origen a todos los demás.

Requisitos:
- Usa el grafo del Ejercicio 1
- Ejecuta BFS desde vértice 0
- Imprime el orden de visita (nivel por nivel)
- Imprime la distancia (número de aristas) desde 0 a cada vértice
- **Pregunta clave:** ¿Cuál es la distancia más corta de 0 a 5? ¿Hay múltiples caminos con esa distancia?

**Salida esperada:**
```
BFS desde vértice 0:
Orden de visita: 0 1 2 3 4 5

Distancias desde vértice 0:
Vértice 0: distancia 0
Vértice 1: distancia 1
Vértice 2: distancia 1
Vértice 3: distancia 2
Vértice 4: distancia 2
Vértice 5: distancia 3
```

## Ejercicio 3 — Reconstrucción de camino más corto (★★★)

Modifica BFS para guardar el **padre** de cada vértice durante la búsqueda. Luego, implementa función que reconstruye y imprime el camino actual desde un vértice destino al vértice de origen.

Requisitos:
- Mantén un array `padre[]` durante BFS
- Implementa `imprimir_camino(int destino, int *padre)` que backtrackea desde destino a origen
- Ejecuta BFS desde vértice 0
- Imprime los caminos más cortos para pares: (0,3), (0,4), (0,5), (0,1)
- **Pregunta:** ¿Hay múltiples caminos más cortos de 0 a 5? ¿Cuáles son?

**Salida esperada:**
```
BFS desde vértice 0:

Camino de 0 a 1: 0 -> 1 (distancia 1)
Camino de 0 a 3: 0 -> 1 -> 3 (distancia 2)
Camino de 0 a 4: 0 -> 1 -> 4 o 0 -> 2 -> 4 (distancia 2)
Camino de 0 a 5: 0 -> 1 -> 3 -> 5 o 0 -> 1 -> 4 -> 5 o 0 -> 2 -> 4 -> 5 (distancia 3)
```

---

# Cierre

**BFS es fundamental en algoritmos de grafos.** Encuentra el camino más corto entre dos nodos en grafos sin pesos (donde cada arista tiene "costo" 1). Aplicaciones reales incluyen:
- Navegación en mapas (Google Maps, antes de Dijkstra)
- Análisis de redes sociales (grados de separación)
- Detección de componentes conectadas
- Rompecabezas y juegos (exploración de espacios de estados)

La representación del grafo importa: **lista de adyacencia es mejor para grafos dispersos**, **matriz de adyacencia es mejor para grafos densos**.

**Próximo laboratorio:** DFS (Depth-First Search), detección de ciclos y ordenamiento topológico.

---

*EIN423-B · Departamento de Informática · UTFSM*
