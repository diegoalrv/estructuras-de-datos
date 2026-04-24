/*
 * Estructuras de Datos — EIN423-B
 * Universidad Técnica Federico Santa María
 * Laboratorio 10: Recorridos y Operaciones Avanzadas en BST
 *
 * Estudiante: [Nombre Completo]
 * Fecha: [Fecha de entrega]
 */

#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>

/**
 * Estructura de nodo para Árbol Binario de Búsqueda
 */
typedef struct NodoBST {
    int clave;              /**< Valor/clave del nodo */
    struct NodoBST *izq;    /**< Puntero al hijo izquierdo */
    struct NodoBST *der;    /**< Puntero al hijo derecho */
} NodoBST;

/**
 * Inserta una clave en el BST manteniendo la propiedad BST
 * @param raiz Puntero a la raíz actual del árbol
 * @param clave Valor a insertar
 * @return Puntero a la nueva raíz del árbol
 */
NodoBST* bst_insertar(NodoBST *raiz, int clave);

/**
 * Busca una clave en el árbol
 * @param raiz Puntero a la raíz del árbol
 * @param clave Valor a buscar
 * @return Puntero al nodo encontrado, o NULL si no existe
 */
NodoBST* bst_buscar(NodoBST *raiz, int clave);

/**
 * Imprime el árbol en recorrido inorden (izquierda-raíz-derecha)
 * Produce salida ordenada ascendente para un BST válido
 * @param raiz Puntero a la raíz del árbol
 */
void bst_inorden(const NodoBST *raiz);

/**
 * Imprime el árbol en recorrido preorden (raíz-izquierda-derecha)
 * @param raiz Puntero a la raíz del árbol
 */
void bst_preorden(const NodoBST *raiz);

/**
 * Imprime el árbol en recorrido postorden (izquierda-derecha-raíz)
 * @param raiz Puntero a la raíz del árbol
 */
void bst_postorden(const NodoBST *raiz);

/**
 * Calcula la altura del árbol
 * @param raiz Puntero a la raíz del árbol
 * @return Altura del árbol; retorna -1 si el árbol es NULL
 */
int bst_altura(const NodoBST *raiz);

/**
 * Cuenta el número total de nodos en el árbol
 * @param raiz Puntero a la raíz del árbol
 * @return Número de nodos
 */
int bst_contar_nodos(const NodoBST *raiz);

/**
 * Busca el valor mínimo (clave más pequeña) en el árbol
 * Precondición: el árbol no debe estar vacío
 * @param raiz Puntero a la raíz del árbol
 * @return Valor mínimo del árbol
 */
int bst_buscar_min(const NodoBST *raiz);

/**
 * Busca el valor máximo (clave más grande) en el árbol
 * Precondición: el árbol no debe estar vacío
 * @param raiz Puntero a la raíz del árbol
 * @return Valor máximo del árbol
 */
int bst_buscar_max(const NodoBST *raiz);

/**
 * Elimina una clave del árbol
 * Maneja tres casos: nodo hoja, nodo con un hijo, nodo con dos hijos
 * @param raiz Puntero a la raíz actual del árbol
 * @param clave Valor a eliminar
 * @return Puntero a la nueva raíz del árbol
 */
NodoBST* bst_eliminar(NodoBST *raiz, int clave);

/**
 * Libera toda la memoria asociada al árbol
 * @param raiz Puntero a la raíz del árbol
 */
void bst_destruir(NodoBST *raiz);

#endif /* BST_H */
