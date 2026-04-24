/*
 * ============================================================================
 * CURSO:      Estructuras de Datos (EIN423-B)
 * UNIVERSIDAD: Universidad Técnica Federico Santa María
 * LAB:        08 - Cola (Queue)
 * ESTUDIANTE: [Nombre del estudiante]
 * FECHA:      Marzo 2026
 * ============================================================================
 */

#ifndef COLA_H
#define COLA_H

#include <stdio.h>
#include <stdlib.h>

/**
 * Nodo de la cola.
 * Contiene un dato entero y un puntero al siguiente nodo.
 */
typedef struct NodoCola {
    int dato;
    struct NodoCola *siguiente;
} NodoCola;

/**
 * Cola (Queue) implementada con lista enlazada.
 * Mantiene punteros a frente (primer nodo) y fondo (último nodo) para O(1) en ambas operaciones.
 */
typedef struct {
    NodoCola *frente;
    NodoCola *fondo;
    int tamanio;
} Cola;

/**
 * cola_crear - Crea una nueva cola vacía.
 * @return: Puntero a la nueva cola.
 */
Cola* cola_crear(void);

/**
 * cola_enqueue - Agrega un valor al fondo de la cola (O(1)).
 * @c:     Puntero a la cola.
 * @valor: Valor entero a agregar.
 */
void cola_enqueue(Cola *c, int valor);

/**
 * cola_dequeue - Elimina y retorna el valor del frente (O(1)).
 * @c: Puntero a la cola.
 * @return: El valor del frente. Si la cola está vacía, retorna -1.
 */
int cola_dequeue(Cola *c);

/**
 * cola_frente - Retorna el valor del frente sin eliminarlo.
 * @c: Puntero a la cola.
 * @return: El valor del frente. Si está vacía, retorna -1.
 */
int cola_frente(const Cola *c);

/**
 * cola_esta_vacia - Verifica si la cola está vacía.
 * @c: Puntero a la cola.
 * @return: 1 si está vacía, 0 si contiene elementos.
 */
int cola_esta_vacia(const Cola *c);

/**
 * cola_tamanio - Retorna la cantidad de elementos en la cola.
 * @c: Puntero a la cola.
 * @return: Número de elementos.
 */
int cola_tamanio(const Cola *c);

/**
 * cola_destruir - Libera toda la memoria de la cola.
 * @c: Puntero a la cola.
 */
void cola_destruir(Cola *c);

#endif
