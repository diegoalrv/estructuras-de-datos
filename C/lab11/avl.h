/*
 * Estructuras de Datos — EIN423-B
 * Universidad Técnica Federico Santa María
 * Laboratorio 11: Árbol AVL (Auto-balanceado)
 *
 * Estudiante: [Nombre Completo]
 * Fecha: [Fecha de entrega]
 */

#ifndef AVL_H
#define AVL_H

#include <stdio.h>
#include <stdlib.h>

/**
 * Estructura de nodo para Árbol AVL
 * Similar a BST pero con información de altura para balanceo
 */
typedef struct NodoAVL {
    int clave;              /**< Valor/clave del nodo */
    int altura;             /**< Altura del subárbol rooted en este nodo */
    struct NodoAVL *izq;    /**< Puntero al hijo izquierdo */
    struct NodoAVL *der;    /**< Puntero al hijo derecho */
} NodoAVL;

/* === Funciones auxiliares (ya implementadas) === */

/**
 * Obtiene la altura de un nodo
 * @param n Puntero al nodo
 * @return Altura del nodo, o -1 si NULL
 */
int avl_altura_nodo(const NodoAVL *n);

/**
 * Calcula el factor de balance de un nodo
 * Factor de balance = altura(izq) - altura(der)
 * @param n Puntero al nodo
 * @return Factor de balance
 */
int avl_factor_balance(const NodoAVL *n);

/**
 * Actualiza la altura de un nodo basado en sus hijos
 * @param n Puntero al nodo
 */
void avl_actualizar_altura(NodoAVL *n);

/* === Rotaciones (TODO: implementar) === */

/**
 * Realiza una rotación hacia la derecha
 * Se usa cuando el árbol está desbalanceado hacia la izquierda
 *
 * Transformación:
 *     y              x
 *    / \    →      / \
 *   x   T3        T1   y
 *  / \                / \
 * T1  T2            T2   T3
 *
 * @param y Puntero al nodo desbalanceado
 * @return Puntero a la nueva raíz del subárbol
 */
NodoAVL* avl_rotar_derecha(NodoAVL *y);

/**
 * Realiza una rotación hacia la izquierda
 * Se usa cuando el árbol está desbalanceado hacia la derecha
 *
 * Transformación:
 *   x              y
 *  / \    →      / \
 * T1  y         x   T4
 *    / \       / \
 *   T2  T4   T1   T2
 *
 * @param x Puntero al nodo desbalanceado
 * @return Puntero a la nueva raíz del subárbol
 */
NodoAVL* avl_rotar_izquierda(NodoAVL *x);

/* === Operaciones principales === */

/**
 * Inserta una clave en el árbol AVL con auto-balanceo
 * @param raiz Puntero a la raíz actual del árbol
 * @param clave Valor a insertar
 * @return Puntero a la nueva raíz del árbol
 */
NodoAVL* avl_insertar(NodoAVL *raiz, int clave);

/**
 * Valida que el árbol es un AVL válido
 * Verifica que el factor de balance de todos los nodos está en [-1, 1]
 * @param raiz Puntero a la raíz del árbol
 * @return 1 si es válido, 0 en caso contrario
 */
int avl_es_valido(const NodoAVL *raiz);

/* === Recorridos === */

/**
 * Imprime el árbol en recorrido inorden (ordenado)
 * @param raiz Puntero a la raíz del árbol
 */
void avl_inorden(const NodoAVL *raiz);

/**
 * Imprime la estructura del árbol de forma visual
 * Útil para visualizar el balanceo
 * @param raiz Puntero a la raíz del árbol
 * @param nivel Nivel actual (comenzar con 0)
 */
void avl_imprimir_estructura(const NodoAVL *raiz, int nivel);

/* === Limpieza === */

/**
 * Libera toda la memoria asociada al árbol
 * @param raiz Puntero a la raíz del árbol
 */
void avl_destruir(NodoAVL *raiz);

#endif /* AVL_H */
