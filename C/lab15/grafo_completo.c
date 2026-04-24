/*
 * Estructuras de Datos - EIN423-B
 * Laboratorio 15: Grafos - IMPLEMENTACIÓN COMPLETA (Lab 14)
 *
 * Este archivo contiene la implementación completa de las funciones de Lab 14.
 * Los estudiantes pueden usar estas funciones en Lab 15 y enfocarse en DFS.
 */

#include "grafo.h"

/**
 * Implementación completa de grafo_crear
 */
Grafo* grafo_crear(int V, int dirigido) {
    Grafo *g = (Grafo *)malloc(sizeof(Grafo));
    if (g == NULL) return NULL;

    g->listas = (Vecino **)malloc(V * sizeof(Vecino *));
    if (g->listas == NULL) {
        free(g);
        return NULL;
    }

    for (int i = 0; i < V; i++) {
        g->listas[i] = NULL;
    }

    g->V = V;
    g->E = 0;
    g->dirigido = dirigido;

    return g;
}

/**
 * Implementación completa de grafo_agregar_arista
 */
void grafo_agregar_arista(Grafo *g, int u, int v) {
    if (u < 0 || u >= g->V || v < 0 || v >= g->V) return;

    // Crear nuevo vecino para u→v
    Vecino *nuevo = (Vecino *)malloc(sizeof(Vecino));
    nuevo->destino = v;
    nuevo->siguiente = g->listas[u];
    g->listas[u] = nuevo;

    // Si no dirigido, agregar también v→u
    if (!g->dirigido) {
        Vecino *nuevo2 = (Vecino *)malloc(sizeof(Vecino));
        nuevo2->destino = u;
        nuevo2->siguiente = g->listas[v];
        g->listas[v] = nuevo2;
    }

    g->E++;
}

/**
 * Implementación completa de grafo_grado
 */
int grafo_grado(const Grafo *g, int v) {
    if (v < 0 || v >= g->V) return 0;

    int grado = 0;
    Vecino *actual = g->listas[v];
    while (actual != NULL) {
        grado++;
        actual = actual->siguiente;
    }
    return grado;
}

/**
 * Implementación completa de grafo_imprimir
 */
void grafo_imprimir(const Grafo *g) {
    for (int i = 0; i < g->V; i++) {
        printf("V%d:", i);
        Vecino *actual = g->listas[i];
        while (actual != NULL) {
            printf(" V%d", actual->destino);
            actual = actual->siguiente;
        }
        printf("\n");
    }
}

/**
 * Implementación completa de grafo_bfs
 */
void grafo_bfs(const Grafo *g, int origen, int *distancias, int *padres) {
    if (origen < 0 || origen >= g->V) return;

    // Inicializar arrays
    for (int i = 0; i < g->V; i++) {
        distancias[i] = INF;
        padres[i] = -1;
    }

    // Cola simple usando array
    int cola[MAX_VERTICES];
    int frente = 0, fondo = 0;

    // Enqueue origen
    cola[fondo++] = origen;
    distancias[origen] = 0;

    // BFS
    while (frente < fondo) {
        int u = cola[frente++];

        // Recorrer vecinos de u
        Vecino *vec = g->listas[u];
        while (vec != NULL) {
            int v = vec->destino;

            // Si v no ha sido visitado
            if (distancias[v] == INF) {
                distancias[v] = distancias[u] + 1;
                padres[v] = u;
                cola[fondo++] = v;
            }

            vec = vec->siguiente;
        }
    }
}

/**
 * Implementación completa de grafo_imprimir_camino
 */
void grafo_imprimir_camino(int *padres, int origen, int destino) {
    if (destino == origen) {
        printf("%d", origen);
        return;
    }

    if (padres[destino] == -1) {
        printf("(no hay camino)");
        return;
    }

    grafo_imprimir_camino(padres, origen, padres[destino]);
    printf(" → %d", destino);
}

/**
 * Implementación completa de grafo_destruir
 */
void grafo_destruir(Grafo *g) {
    if (g == NULL) return;

    for (int i = 0; i < g->V; i++) {
        Vecino *actual = g->listas[i];
        while (actual != NULL) {
            Vecino *temp = actual;
            actual = actual->siguiente;
            free(temp);
        }
    }

    free(g->listas);
    free(g);
}
