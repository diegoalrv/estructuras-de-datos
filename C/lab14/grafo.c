/*
 * Estructuras de Datos - EIN423-B
 * Laboratorio 14: Grafos - IMPLEMENTACIÓN
 *
 * Alumno: ___________________________________
 * Sección: _________________________________
 */

#include "grafo.h"

/**
 * TODO: Implementar grafo_crear
 * Crea una estructura Grafo vacía.
 * Inicializa el array de listas de adyacencia.
 * Hint: Asigna memoria para Grafo y array de Vecino*. Inicializa listas[i]=NULL para todos.
 */
Grafo* grafo_crear(int V, int dirigido) {
    // TODO: Implementar
    return NULL;
}

/**
 * TODO: Implementar grafo_agregar_arista
 * Agrega arista u→v creando un Vecino.
 * Inserta el nuevo Vecino al FRENTE de listas[u].
 * Si no dirigido, también agrega v→u (inserta en listas[v]).
 * Hint: Crea Vecino, enlaza en lista, incrementa E
 */
void grafo_agregar_arista(Grafo *g, int u, int v) {
    // TODO: Implementar
}

/**
 * TODO: Implementar grafo_grado
 * Cuenta la cantidad de vecinos del vértice v.
 * Para grafos dirigidos, cuenta vecinos salientes.
 * Hint: Recorre listas[v] contando nodos
 */
int grafo_grado(const Grafo *g, int v) {
    // TODO: Implementar
    return 0;
}

/**
 * TODO: Implementar grafo_imprimir
 * Imprime lista de adyacencia en formato:
 * V0: V_adj1 V_adj2 ...
 * V1: ...
 * Hint: Para cada vértice, recorre su lista de vecinos
 */
void grafo_imprimir(const Grafo *g) {
    // TODO: Implementar
}

/**
 * TODO: Implementar grafo_bfs
 * Búsqueda en amplitud desde vértice origen.
 * Calcula distancias y padres para todos los vértices.
 * Hint: Usa arreglo cola[MAX_VERTICES] con frente y fondo
 *       Inicializa distancias[]=INF, padres[]=-1
 *       Enqueue origen, distancias[origen]=0
 *       Mientras cola no vacía: dequeue u, para cada vecino v:
 *         si distancias[v]==INF: distancias[v]=distancias[u]+1, padres[v]=u, enqueue v
 */
void grafo_bfs(const Grafo *g, int origen, int *distancias, int *padres) {
    // TODO: Implementar
}

/**
 * TODO: Implementar grafo_imprimir_camino
 * Imprime el camino desde origen a destino.
 * Usa recursión o pila basado en array padres.
 * Formato: origen → ... → destino
 * Hint: Si destino==origen, imprime origen
 *       Si padres[destino]==-1, no hay camino
 *       Sino, llama recursivamente con padres[destino] y luego imprime destino
 */
void grafo_imprimir_camino(int *padres, int origen, int destino) {
    // TODO: Implementar
}

/**
 * TODO: Implementar grafo_destruir
 * Libera toda la memoria de listas y aristas.
 * Hint: Para cada vértice, libera su lista de Vecino
 *       Luego libera array listas y estructura Grafo
 */
void grafo_destruir(Grafo *g) {
    // TODO: Implementar
}
