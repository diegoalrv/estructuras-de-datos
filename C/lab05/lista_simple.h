/*
 * ============================================================================
 * CURSO:      Estructuras de Datos (EIN423-B)
 * UNIVERSIDAD: Universidad Técnica Federico Santa María
 * LAB:        05 - Lista Enlazada Simple
 * ESTUDIANTE: [Nombre del estudiante]
 * FECHA:      Marzo 2026
 * ============================================================================
 */

#ifndef LISTA_SIMPLE_H
#define LISTA_SIMPLE_H

#include <stdio.h>
#include <stdlib.h>

/**
 * Nodo de la lista enlazada simple.
 * Contiene un dato entero y un puntero al siguiente nodo.
 */
typedef struct Nodo {
    int dato;
    struct Nodo *siguiente;
} Nodo;

/**
 * Lista enlazada simple.
 * Mantiene un puntero a la cabeza (primer nodo) y el tamaño total.
 */
typedef struct {
    Nodo *cabeza;
    int tamanio;
} Lista;

/**
 * lista_crear - Crea una nueva lista enlazada simple vacía.
 * @return: Puntero a la nueva lista (ya asignada en memoria).
 */
Lista* lista_crear(void);

/**
 * lista_push_front - Agrega un valor al inicio de la lista.
 * @l:     Puntero a la lista.
 * @valor: Valor entero a agregar.
 */
void lista_push_front(Lista *l, int valor);

/**
 * lista_push_back - Agrega un valor al final de la lista.
 * @l:     Puntero a la lista.
 * @valor: Valor entero a agregar.
 */
void lista_push_back(Lista *l, int valor);

/**
 * lista_pop_front - Elimina y retorna el primer elemento.
 * @l: Puntero a la lista.
 * @return: El valor del primer nodo. Si la lista está vacía, retorna -1 (error).
 */
int lista_pop_front(Lista *l);

/**
 * lista_imprimir - Imprime todos los elementos de la lista en orden.
 * Formato: [1 2 3 4 5] para una lista con esos elementos.
 * @l: Puntero a la lista.
 */
void lista_imprimir(const Lista *l);

/**
 * lista_tamanio - Retorna la cantidad de elementos en la lista.
 * @l: Puntero a la lista.
 * @return: Número de nodos.
 */
int lista_tamanio(const Lista *l);

/**
 * lista_buscar - Busca un valor en la lista.
 * @l:     Puntero a la lista.
 * @valor: Valor a buscar.
 * @return: Índice (0-basado) del primer elemento encontrado, o -1 si no existe.
 */
int lista_buscar(const Lista *l, int valor);

/**
 * lista_obtener - Obtiene el valor en un índice específico.
 * @l:   Puntero a la lista.
 * @idx: Índice (0-basado).
 * @return: El valor en ese índice, o -1 si el índice es inválido.
 */
int lista_obtener(const Lista *l, int idx);

/**
 * lista_eliminar - Elimina la primera ocurrencia de un valor.
 * @l:     Puntero a la lista.
 * @valor: Valor a eliminar.
 * @return: 1 si se eliminó exitosamente, 0 si el valor no existe.
 */
int lista_eliminar(Lista *l, int valor);

/**
 * lista_invertir - Invierte el orden de la lista in-place.
 * NO crea nuevos nodos, solo redirige punteros.
 * @l: Puntero a la lista.
 */
void lista_invertir(Lista *l);

/**
 * lista_destruir - Libera toda la memoria de la lista.
 * @l: Puntero a la lista.
 */
void lista_destruir(Lista *l);

/**
 * lista_esta_vacia - Verifica si la lista está vacía.
 * @l: Puntero a la lista.
 * @return: 1 si está vacía, 0 si contiene elementos.
 */
int lista_esta_vacia(const Lista *l);

#endif
