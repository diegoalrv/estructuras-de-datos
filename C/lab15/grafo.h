/*
 * Estructuras de Datos - EIN423-B
 * Laboratorio 15: Grafos - DFS y Caminos
 *
 * Alumno: ___________________________________
 * Sección: _________________________________
 *
 * Descripción:
 * Implementación de búsqueda en profundidad (DFS) y análisis de grafos.
 * Incluye detección de ciclos y ordenamiento topológico.
 */

#ifndef GRAFO_H
#define GRAFO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100
#define INF 999999

/**
 * Estructura para representar un vecino en la lista de adyacencia.
 */
typedef struct Vecino {
    int destino;           /**< Vértice destino de la arista */
    struct Vecino *siguiente;  /**< Siguiente vecino en la lista */
} Vecino;

/**
 * Estructura para representar un grafo usando listas de adyacencia.
 */
typedef struct {
    Vecino **listas;   /**< Array de punteros a listas de vecinos */
    int V;             /**< Número de vértices */
    int E;             /**< Número de aristas */
    int dirigido;      /**< 1 si es dirigido, 0 si no dirigido */
} Grafo;

/**
 * Crea un nuevo grafo vacío.
 *
 * @param V Número de vértices (0 a V-1)
 * @param dirigido 1 para grafo dirigido, 0 para no dirigido
 * @return Puntero al nuevo grafo, o NULL si falla
 */
Grafo* grafo_crear(int V, int dirigido);

/**
 * Agrega una arista entre vértices u y v.
 * Si el grafo no es dirigido, agrega arista en ambas direcciones.
 *
 * @param g Grafo a modificar
 * @param u Vértice origen
 * @param v Vértice destino
 */
void grafo_agregar_arista(Grafo *g, int u, int v);

/**
 * Retorna el grado de un vértice.
 * Para grafos dirigidos, retorna grado de salida.
 *
 * @param g Grafo a consultar
 * @param v Vértice
 * @return Número de adyacencias (aristas salientes para dirigido)
 */
int grafo_grado(const Grafo *g, int v);

/**
 * Imprime la representación en lista de adyacencia del grafo.
 *
 * @param g Grafo a imprimir
 */
void grafo_imprimir(const Grafo *g);

/**
 * Realiza búsqueda en amplitud (BFS) desde un vértice origen.
 * Calcula distancias más cortas (en número de aristas) y padres para reconstruir caminos.
 *
 * @param g Grafo a buscar
 * @param origen Vértice desde donde inicia BFS
 * @param distancias Array salida de tamaño V con distancia a cada vértice (INF si no alcanzable)
 * @param padres Array salida de tamaño V con padre de cada vértice en árbol BFS (-1 si no tiene padre)
 */
void grafo_bfs(const Grafo *g, int origen, int *distancias, int *padres);

/**
 * Reconstruye e imprime el camino más corto desde origen a destino.
 * Usa el array padres calculado por BFS.
 *
 * @param padres Array de padres desde BFS
 * @param origen Vértice inicial del camino
 * @param destino Vértice final del camino
 */
void grafo_imprimir_camino(int *padres, int origen, int destino);

/**
 * Libera la memoria ocupada por el grafo.
 *
 * @param g Grafo a destruir
 */
void grafo_destruir(Grafo *g);

#endif
