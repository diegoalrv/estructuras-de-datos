# Laboratorio 15 — Grafos: DFS y Caminos

**Curso:** EIN423-B · Estructuras de Datos  
**Duración:** 90 minutos  
**Horario:** 08:30 – 10:00

## Objetivos del laboratorio
- Entender búsqueda en profundidad (DFS) recursiva e iterativa
- Usar colores para rastrear el estado de nodos (blanco, gris, negro)
- Detectar ciclos en grafos dirigidos
- Implementar ordenamiento topológico usando DFS

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

**DFS (Depth-First Search)** es un algoritmo de exploración que sigue un camino tan profundo como es posible antes de retroceder. A diferencia de BFS que usa una cola, DFS usa una pila (explícita o implícita en la recursión).

**Colores:** Para entender mejor lo que sucede durante DFS, usamos tres colores:
- **BLANCO:** nodo nunca visitado
- **GRIS:** nodo visitado pero aún en procesamiento (en la pila de recursión)
- **NEGRO:** nodo completamente procesado

**Detección de ciclos:** En un grafo dirigido, un **back-edge** (arista que apunta a un nodo gris) indica un ciclo. En grafos no dirigidos, lo detectamos diferente.

**Ordenamiento topológico:** Orden válido de tareas donde si A depende de B, entonces B aparece antes que A. Solo existe en DAGs (grafos acíclicos dirigidos).

---

# 2. Concepto y código guiado

## DFS recursivo con 3-colores

```c
#include <stdio.h>
#include <stdlib.h>

typedef enum { BLANCO, GRIS, NEGRO } ColorNodo;

typedef struct Vecino {
    int destino;
    struct Vecino *sig;
} Vecino;

typedef struct {
    Vecino **listas;
    int V;
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

void grafo_agregar_arista_dirigida(Grafo *g, int u, int v) {
    // Solo dirigida: agregar v a lista de u
    Vecino *nuevo = malloc(sizeof(Vecino));
    nuevo->destino = v;
    nuevo->sig = g->listas[u];
    g->listas[u] = nuevo;
}

// DFS que retorna 1 si detecta ciclo, 0 si no
int dfs_visit(Grafo *g, int u, ColorNodo *color, int *tiempo,
              int *tiempo_desc, int *tiempo_fin) {
    color[u] = GRIS;
    tiempo_desc[u] = (*tiempo)++;
    printf("Visitando nodo %d (tiempo_desc = %d)\n", u, tiempo_desc[u]);
    
    Vecino *v_node = g->listas[u];
    while (v_node) {
        int v = v_node->destino;
        
        // Back-edge: arista a un nodo gris indica ciclo
        if (color[v] == GRIS) {
            printf("  -> Ciclo detectado: %d es ancestro de %d\n", v, u);
            return 1;
        }
        
        // Arista a nodo blanco: explorar recursivamente
        if (color[v] == BLANCO) {
            if (dfs_visit(g, v, color, tiempo, tiempo_desc, tiempo_fin)) {
                return 1;
            }
        }
        // Si color[v] == NEGRO, es forward-edge o cross-edge, ignorar para ciclos
        
        v_node = v_node->sig;
    }
    
    color[u] = NEGRO;
    tiempo_fin[u] = (*tiempo)++;
    printf("Terminando nodo %d (tiempo_fin = %d)\n", u, tiempo_fin[u]);
    return 0;
}

int dfs_detectar_ciclo(Grafo *g) {
    ColorNodo *color = malloc(g->V * sizeof(ColorNodo));
    int *tiempo_desc = malloc(g->V * sizeof(int));
    int *tiempo_fin = malloc(g->V * sizeof(int));
    int tiempo = 0;
    
    for (int i = 0; i < g->V; i++) {
        color[i] = BLANCO;
    }
    
    printf("Detectando ciclos con DFS...\n");
    for (int i = 0; i < g->V; i++) {
        if (color[i] == BLANCO) {
            if (dfs_visit(g, i, color, &tiempo, tiempo_desc, tiempo_fin)) {
                free(color);
                free(tiempo_desc);
                free(tiempo_fin);
                return 1;  // Ciclo encontrado
            }
        }
    }
    
    free(color);
    free(tiempo_desc);
    free(tiempo_fin);
    return 0;  // No hay ciclo
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

## Ordenamiento topológico

```c
void dfs_topsort(Grafo *g, int u, ColorNodo *color, int *pila,
                 int *indice_pila) {
    color[u] = GRIS;
    
    Vecino *v_node = g->listas[u];
    while (v_node) {
        int v = v_node->destino;
        if (color[v] == BLANCO) {
            dfs_topsort(g, v, color, pila, indice_pila);
        }
        v_node = v_node->sig;
    }
    
    color[u] = NEGRO;
    // Agregar u al final cuando termina
    pila[(*indice_pila)++] = u;
}

void ordenamiento_topologico(Grafo *g) {
    ColorNodo *color = malloc(g->V * sizeof(ColorNodo));
    int *pila = malloc(g->V * sizeof(int));
    int indice_pila = 0;
    
    for (int i = 0; i < g->V; i++) {
        color[i] = BLANCO;
    }
    
    // Visitar todos los nodos (grafo puede tener múltiples componentes)
    for (int i = 0; i < g->V; i++) {
        if (color[i] == BLANCO) {
            dfs_topsort(g, i, color, pila, &indice_pila);
        }
    }
    
    printf("\nOrdenamiento topológico (de atrás hacia adelante):\n");
    for (int i = g->V - 1; i >= 0; i--) {
        printf("%d ", pila[i]);
    }
    printf("\n");
    
    free(color);
    free(pila);
}

int main() {
    // Grafo dirigido: 0->1, 0->2, 1->3, 2->3, 3->4
    // Es un DAG (sin ciclos)
    Grafo *g = grafo_crear(5);
    grafo_agregar_arista_dirigida(g, 0, 1);
    grafo_agregar_arista_dirigida(g, 0, 2);
    grafo_agregar_arista_dirigida(g, 1, 3);
    grafo_agregar_arista_dirigida(g, 2, 3);
    grafo_agregar_arista_dirigida(g, 3, 4);
    
    int hay_ciclo = dfs_detectar_ciclo(g);
    printf("\n¿Hay ciclo? %s\n\n", hay_ciclo ? "SÍ" : "NO");
    
    ordenamiento_topologico(g);
    
    grafo_destruir(g);
    return 0;
}
```

---

# 3. Ejercicios

## Ejercicio 1 — DFS recursivo en grafo no dirigido (★☆☆)

Implementa DFS completamente para un grafo **no dirigido**. Usa el mismo grafo del Lab 14 (6 nodos, aristas: 0-1, 0-2, 1-3, 1-4, 2-4, 3-5, 4-5).

Requisitos:
- Implementa grafo no dirigido (agregar arista en ambas direcciones)
- Implementa DFS recursivo usando colores BLANCO, GRIS, NEGRO
- Imprime el orden de visita (cuándo se marca GRIS, cuándo se marca NEGRO)
- Imprime el tiempo de descubrimiento y tiempo de finalización para cada nodo
- Compara el orden de visita con BFS del lab anterior

**Salida esperada:**
```
DFS desde vértice 0:
Visitando nodo 0 (tiempo_desc = 0)
  Visitando nodo 1 (tiempo_desc = 1)
    Visitando nodo 3 (tiempo_desc = 2)
      Visitando nodo 5 (tiempo_desc = 3)
      Terminando nodo 5 (tiempo_fin = 4)
    Terminando nodo 3 (tiempo_fin = 5)
    Visitando nodo 4 (tiempo_desc = 6)
      Visitando nodo 2 (tiempo_desc = 7)
      Terminando nodo 2 (tiempo_fin = 8)
    Terminando nodo 4 (tiempo_fin = 9)
  Terminando nodo 1 (tiempo_fin = 10)
Terminando nodo 0 (tiempo_fin = 11)

Tiempos:
Nodo 0: desc=0, fin=11
Nodo 1: desc=1, fin=10
[...]
```

## Ejercicio 2 — Detección de ciclos en grafo dirigido (★★☆)

Implementa detección de ciclos usando DFS con 3-colores. Prueba con dos grafos:
- Grafo A: DAG sin ciclos (aristas: 0→1, 1→2, 2→3)
- Grafo B: con ciclo (aristas: 0→1, 1→2, 2→0)

Requisitos:
- Implementa grafo dirigido
- Implementa DFS que detecte back-edges (arista a nodo GRIS)
- Para el Grafo B, imprime qué arista crea el ciclo
- Retorna 1 si hay ciclo, 0 si es DAG

**Salida esperada:**
```
Grafo A (sin ciclos):
Visitando 0...
  Visitando 1...
    Visitando 2...
      Visitando 3...
      Terminando 3
    Terminando 2
  Terminando 1
Terminando 0

¿Hay ciclo en Grafo A? NO

---

Grafo B (con ciclo):
Visitando 0...
  Visitando 1...
    Visitando 2...
      Ciclo detectado: arista 2->0 (0 es ancestro)
      
¿Hay ciclo en Grafo B? SÍ
Arista que crea ciclo: 2->0
```

## Ejercicio 3 — Ordenamiento topológico (★★★)

Implementa ordenamiento topológico usando DFS en un grafo de **requisitos de cursos**. Grafo dirigido: 0→1, 0→2, 1→3, 2→3, 3→4 (donde arista A→B significa "A es requisito de B").

Requisitos:
- Verifica que el grafo sea un DAG (sin ciclos)
- Implementa ordenamiento topológico usando DFS con tiempos de finalización
- Imprime un orden válido de cursos
- Valida que tu orden respeta las dependencias (para cada arista A→B, A aparece antes que B en tu orden)

**Interpretación de dependencias:**
```
Nodo 0: Algoritmos (sin prerequisitos)
Nodo 1: Estructuras de Datos (requiere Algoritmos)
Nodo 2: BD Básico (requiere Algoritmos)
Nodo 3: Aplicaciones (requiere Estructuras de Datos Y BD Básico)
Nodo 4: Proyecto Final (requiere Aplicaciones)
```

**Salida esperada:**
```
Grafo de requisitos: 0->1, 0->2, 1->3, 2->3, 3->4

¿Es DAG? SÍ

Ordenamiento topológico válido:
0 2 1 3 4
(o: 0 1 2 3 4 - también es válido)

Validación:
✓ 0 debe venir antes de 1: 0 está en posición 0, 1 en posición 2 ✓
✓ 0 debe venir antes de 2: 0 está en posición 0, 2 en posición 1 ✓
✓ 1 debe venir antes de 3: 1 está en posición 2, 3 en posición 3 ✓
✓ 2 debe venir antes de 3: 2 está en posición 1, 3 en posición 3 ✓
✓ 3 debe venir antes de 4: 3 está en posición 3, 4 en posición 4 ✓

Todas las dependencias respetadas.
```

---

# Cierre

**DFS, detección de ciclos y ordenamiento topológico son fundamentales en ciencias de la computación:**

- **DFS:** Aparece en algoritmos de componentes fuertemente conectadas (Tarjan, Kosaraju)
- **Detección de ciclos:** Crítico en:
  - Compiladores (detectar recursión infinita)
  - Gestión de dependencias (npm, apt, cargo)
  - Análisis de deadlocks en sistemas
- **Ordenamiento topológico:** Usado en:
  - Planificación de tareas con dependencias
  - Sistemas de compilación (make, gradle)
  - Compiladores (orden de evaluación de expresiones)

**¡Buen trabajo este semestre!** Has recorrido todo el programa del curso: punteros, TDA, complejidad, listas, pilas, colas, árboles, hashing, grafos y ordenamiento. Cada una de estas estructuras aparecerá en los sistemas que construirás como ingeniero.

---

*EIN423-B · Departamento de Informática · UTFSM*
