/*
 * ============================================================================
 * CURSO:      Estructuras de Datos (EIN423-B)
 * UNIVERSIDAD: Universidad Técnica Federico Santa María
 * LAB:        08 - Cola de Prioridad (Priority Queue)
 * ESTUDIANTE: [Nombre del estudiante]
 * FECHA:      Marzo 2026
 * ============================================================================
 */

#ifndef COLA_PRIORIDAD_H
#define COLA_PRIORIDAD_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP 256

/**
 * Elemento almacenado en la cola de prioridad.
 * Contiene un valor y su prioridad (menor prioridad = mayor urgencia).
 */
typedef struct {
    int valor;
    int prioridad;
} ElementoHeap;

/**
 * Cola de Prioridad implementada con un min-heap (arreglo).
 * Los elementos se organizan en un árbol binario completo donde cada padre
 * tiene prioridad menor (más urgente) que sus hijos.
 */
typedef struct {
    ElementoHeap datos[MAX_HEAP];
    int tamanio;
} ColaPrioridad;

/**
 * cp_crear - Crea una nueva cola de prioridad vacía.
 * @return: Puntero a la nueva cola de prioridad.
 */
ColaPrioridad* cp_crear(void);

/**
 * cp_insertar - Inserta un valor con una prioridad en la cola.
 * @cp:        Puntero a la cola de prioridad.
 * @valor:     Valor a insertar.
 * @prioridad: Nivel de prioridad (menor valor = mayor urgencia).
 */
void cp_insertar(ColaPrioridad *cp, int valor, int prioridad);

/**
 * cp_extraer_minimo - Extrae y retorna el elemento con menor prioridad (máxima urgencia).
 * @cp: Puntero a la cola de prioridad.
 * @return: ElementoHeap (valor y prioridad) del mínimo.
 *          Si la cola está vacía, retorna {-1, -1}.
 */
ElementoHeap cp_extraer_minimo(ColaPrioridad *cp);

/**
 * cp_ver_minimo - Retorna el elemento con menor prioridad sin extraerlo.
 * @cp: Puntero a la cola de prioridad.
 * @return: ElementoHeap (valor y prioridad) del mínimo.
 *          Si la cola está vacía, retorna {-1, -1}.
 */
ElementoHeap cp_ver_minimo(const ColaPrioridad *cp);

/**
 * cp_esta_vacia - Verifica si la cola de prioridad está vacía.
 * @cp: Puntero a la cola de prioridad.
 * @return: 1 si está vacía, 0 si contiene elementos.
 */
int cp_esta_vacia(const ColaPrioridad *cp);

/**
 * cp_destruir - Libera toda la memoria de la cola de prioridad.
 * @cp: Puntero a la cola de prioridad.
 */
void cp_destruir(ColaPrioridad *cp);

/* Funciones auxiliares privadas (implementadas en cola_prioridad.c) */

/**
 * heapify_up - Reestablece la propiedad de heap hacia arriba.
 * Se utiliza después de insertar un elemento al final.
 * @cp: Puntero a la cola de prioridad.
 * @i:  Índice del elemento a ajustar.
 */
void heapify_up(ColaPrioridad *cp, int i);

/**
 * heapify_down - Reestablece la propiedad de heap hacia abajo.
 * Se utiliza después de extraer el mínimo (raíz).
 * @cp: Puntero a la cola de prioridad.
 * @i:  Índice del elemento a ajustar (usualmente 0).
 */
void heapify_down(ColaPrioridad *cp, int i);

#endif
