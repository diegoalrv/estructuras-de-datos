/*
 * ============================================================================
 * CURSO:      Estructuras de Datos (EIN423-B)
 * UNIVERSIDAD: Universidad Técnica Federico Santa María
 * LAB:        06 - Lista Doblemente Enlazada
 * ESTUDIANTE: [Nombre del estudiante]
 * FECHA:      Marzo 2026
 * ============================================================================
 */

#ifndef LISTA_DOBLE_H
#define LISTA_DOBLE_H

#include <stdio.h>
#include <stdlib.h>

/**
 * Nodo de la lista doblemente enlazada.
 * Contiene un dato entero, un puntero al nodo anterior y uno al siguiente.
 */
typedef struct NodoD {
    int dato;
    struct NodoD *anterior;
    struct NodoD *siguiente;
} NodoD;

/**
 * Lista doblemente enlazada.
 * Mantiene punteros a cabeza (primer nodo) y cola (último nodo) para O(1) en push_back.
 */
typedef struct {
    NodoD *cabeza;
    NodoD *cola;
    int tamanio;
} ListaDoble;

/**
 * listad_crear - Crea una nueva lista doblemente enlazada vacía.
 * @return: Puntero a la nueva lista.
 */
ListaDoble* listad_crear(void);

/**
 * listad_push_front - Agrega un valor al inicio de la lista.
 * @l:     Puntero a la lista.
 * @valor: Valor entero a agregar.
 */
void listad_push_front(ListaDoble *l, int valor);

/**
 * listad_push_back - Agrega un valor al final de la lista (O(1)).
 * @l:     Puntero a la lista.
 * @valor: Valor entero a agregar.
 */
void listad_push_back(ListaDoble *l, int valor);

/**
 * listad_pop_front - Elimina y retorna el primer elemento.
 * @l: Puntero a la lista.
 * @return: El valor del primer nodo, o -1 si está vacía.
 */
int listad_pop_front(ListaDoble *l);

/**
 * listad_pop_back - Elimina y retorna el último elemento.
 * @l: Puntero a la lista.
 * @return: El valor del último nodo, o -1 si está vacía.
 */
int listad_pop_back(ListaDoble *l);

/**
 * listad_imprimir_adelante - Imprime la lista de cabeza a cola.
 * Formato: [1 2 3 4 5]
 * @l: Puntero a la lista.
 */
void listad_imprimir_adelante(const ListaDoble *l);

/**
 * listad_imprimir_atras - Imprime la lista de cola a cabeza.
 * Formato: [5 4 3 2 1]
 * @l: Puntero a la lista.
 */
void listad_imprimir_atras(const ListaDoble *l);

/**
 * listad_eliminar - Elimina la primera ocurrencia de un valor.
 * @l:     Puntero a la lista.
 * @valor: Valor a eliminar.
 * @return: 1 si se eliminó exitosamente, 0 si no existe.
 */
int listad_eliminar(ListaDoble *l, int valor);

/**
 * listad_insertar_ordenado - Inserta un valor manteniendo orden ascendente.
 * @l:     Puntero a la lista.
 * @valor: Valor a insertar.
 */
void listad_insertar_ordenado(ListaDoble *l, int valor);

/**
 * listad_destruir - Libera toda la memoria de la lista.
 * @l: Puntero a la lista.
 */
void listad_destruir(ListaDoble *l);

/**
 * listad_esta_vacia - Verifica si la lista está vacía.
 * @l: Puntero a la lista.
 * @return: 1 si está vacía, 0 si contiene elementos.
 */
int listad_esta_vacia(const ListaDoble *l);

#endif
