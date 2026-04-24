/*
 * Estructuras de Datos - EIN423-B
 * Laboratorio 15: Grafos - DFS y Caminos
 *
 * Alumno: ___________________________________
 * Sección: _________________________________
 *
 * Descripción:
 * Funciones de DFS, detección de ciclos y ordenamiento topológico.
 */

#ifndef GRAFO_DFS_H
#define GRAFO_DFS_H

#include "grafo.h"
#include <stdbool.h>

/**
 * Estados de coloreo para DFS.
 * BLANCO: No visitado
 * GRIS:   Actualmente siendo visitado (en la pila)
 * NEGRO:  Completamente visitado (finalizó)
 */
typedef enum {
    BLANCO,
    GRIS,
    NEGRO
} ColorNodo;

/**
 * Búsqueda en profundidad (DFS) desde un vértice inicial.
 * Realiza DFS recursivo y registra el orden de visita.
 *
 * @param g Grafo a buscar
 * @param inicio Vértice de inicio
 * @param orden_visita Array salida donde se registra el orden de visita
 * @param n_visitados Puntero a entero que se incrementa con cada vértice visitado
 */
void grafo_dfs(const Grafo *g, int inicio, int *orden_visita, int *n_visitados);

/**
 * Detecta si un grafo dirigido tiene ciclos.
 * Un grafo dirigido acíclico (DAG) es fundamental para ordenamiento topológico.
 *
 * @param g Grafo dirigido a analizar
 * @param ciclo_u Puntero donde almacenar primer vértice de la arista que causa ciclo
 * @param ciclo_v Puntero donde almacenar segundo vértice de la arista que causa ciclo
 * @return 1 si hay ciclo, 0 si el grafo es acíclico (DAG)
 */
int grafo_tiene_ciclo(const Grafo *g, int *ciclo_u, int *ciclo_v);

/**
 * Ordenamiento topológico de un DAG (Directed Acyclic Graph).
 * Ordena los vértices de modo que para cada arista u→v, u aparece antes de v.
 * Útil para dependencias, compilación, scheduling, etc.
 *
 * @param g Grafo dirigido (debe ser acíclico)
 * @param orden_topologico Array salida con orden topológico de vértices
 * @return 1 si el ordenamiento fue exitoso (grafo acíclico), 0 si hay ciclo
 */
int grafo_orden_topologico(const Grafo *g, int *orden_topologico);

#endif
