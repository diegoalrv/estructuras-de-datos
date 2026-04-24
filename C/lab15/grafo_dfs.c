/*
 * Estructuras de Datos - EIN423-B
 * Laboratorio 15: Grafos - DFS IMPLEMENTACIÓN
 *
 * Alumno: ___________________________________
 * Sección: _________________________________
 */

#include "grafo_dfs.h"

/**
 * Función auxiliar recursiva para DFS.
 * Visita un nodo y explora todos sus vecinos.
 */
static void dfs_visita(const Grafo *g, int v, ColorNodo *color,
                       int *orden_visita, int *n_visitados) {
    // TODO: Implementar
    // Hint: Marca v como GRIS
    //       Agrega v a orden_visita
    //       Recorre vecinos de v, llamando recursivamente a dfs_visita si BLANCO
    //       Marca v como NEGRO al terminar
}

/**
 * TODO: Implementar grafo_dfs
 * DFS desde vértice inicio.
 * Inicializa array de colores (todos BLANCO).
 * Llama dfs_visita para explorar el grafo.
 * Hint: color[v] = BLANCO para todos
 *       Llama dfs_visita(g, inicio, color, orden_visita, n_visitados)
 */
void grafo_dfs(const Grafo *g, int inicio, int *orden_visita, int *n_visitados) {
    // TODO: Implementar
}

/**
 * Función auxiliar recursiva para detectar ciclos en DFS.
 * Retorna 1 si encuentra un ciclo (back-edge).
 */
static int dfs_ciclo(const Grafo *g, int v, ColorNodo *color,
                     int *ciclo_u, int *ciclo_v) {
    // TODO: Implementar
    // Hint: Marca v como GRIS
    //       Para cada vecino u de v:
    //         Si u es BLANCO: llamar recursivamente, si retorna 1, retornar 1
    //         Si u es GRIS: encontró back-edge (ciclo), almacenar en ciclo_u/v, retornar 1
    //       Marca v como NEGRO
    //       Retornar 0
}

/**
 * TODO: Implementar grafo_tiene_ciclo
 * Detecta ciclos iniciando DFS desde cada vértice BLANCO.
 * Hint: color[v] = BLANCO para todos
 *       Para cada v BLANCO: si dfs_ciclo retorna 1, hay ciclo
 */
int grafo_tiene_ciclo(const Grafo *g, int *ciclo_u, int *ciclo_v) {
    // TODO: Implementar
    return 0;
}

/**
 * Función auxiliar para ordenamiento topológico.
 * Ordena basado en tiempos de finalización (cuando nodo se pone NEGRO).
 */
static void dfs_topo(const Grafo *g, int v, ColorNodo *color,
                     int *orden_topo, int *pos) {
    // TODO: Implementar
    // Hint: Marca v como GRIS
    //       Para cada vecino u: si BLANCO, llamar recursivamente dfs_topo
    //       Cuando v se pone NEGRO, insertar en posición --*pos del arreglo
    //       (esto ordena por tiempo de finalización descendente)
}

/**
 * TODO: Implementar grafo_orden_topologico
 * Ordenamiento topológico usando DFS con tiempos de finalización.
 * Hint: Primero detectar ciclos; si hay, retornar 0
 *       Si no hay ciclos (DAG), hacer DFS desde cada BLANCO
 *       Inserts nodos en orden de finalización (al revés)
 */
int grafo_orden_topologico(const Grafo *g, int *orden_topologico) {
    // TODO: Implementar
    return 0;
}
