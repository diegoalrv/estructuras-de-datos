/*
 * ============================================================================
 * CURSO:      Estructuras de Datos (EIN423-B)
 * UNIVERSIDAD: Universidad Técnica Federico Santa María
 * LAB:        07 - Pila (Stack)
 * ESTUDIANTE: [Nombre del estudiante]
 * FECHA:      Marzo 2026
 * ============================================================================
 */

#ifndef PILA_H
#define PILA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Nodo de la pila.
 * Contiene un dato entero y un puntero al siguiente nodo.
 */
typedef struct NodoPila {
    int dato;
    struct NodoPila *siguiente;
} NodoPila;

/**
 * Pila (Stack) implementada con lista enlazada.
 * El tope es la cabeza de la lista (para O(1) en push y pop).
 */
typedef struct {
    NodoPila *tope;
    int tamanio;
} Pila;

/**
 * pila_crear - Crea una nueva pila vacía.
 * @return: Puntero a la nueva pila.
 */
Pila* pila_crear(void);

/**
 * pila_push - Inserta un valor en el tope de la pila.
 * @p:     Puntero a la pila.
 * @valor: Valor entero a insertar.
 */
void pila_push(Pila *p, int valor);

/**
 * pila_pop - Extrae y retorna el valor del tope.
 * @p: Puntero a la pila.
 * @return: El valor del tope. Si la pila está vacía, aborta con error.
 */
int pila_pop(Pila *p);

/**
 * pila_peek - Retorna el valor del tope sin extraerlo.
 * @p: Puntero a la pila.
 * @return: El valor del tope. Si la pila está vacía, aborta con error.
 */
int pila_peek(const Pila *p);

/**
 * pila_esta_vacia - Verifica si la pila está vacía.
 * @p: Puntero a la pila.
 * @return: 1 si está vacía, 0 si contiene elementos.
 */
int pila_esta_vacia(const Pila *p);

/**
 * pila_tamanio - Retorna la cantidad de elementos en la pila.
 * @p: Puntero a la pila.
 * @return: Número de elementos.
 */
int pila_tamanio(const Pila *p);

/**
 * pila_destruir - Libera toda la memoria de la pila.
 * @p: Puntero a la pila.
 */
void pila_destruir(Pila *p);

/**
 * balanceada - Verifica si una expresión tiene paréntesis/corchetes/llaves balanceados.
 * Caracteres válidos: ( ) [ ] { }
 * @expresion: Cadena a verificar.
 * @return: 1 si está balanceada, 0 si no.
 * Ejemplo: "({[]})" retorna 1, "({)}" retorna 0
 */
int balanceada(const char *expresion);

/**
 * evaluar_postfija - Evalúa una expresión en notación polaca inversa (RPN).
 * Tokens separados por espacios.
 * Operadores soportados: + - * /
 * @expr: Expresión en RPN como cadena.
 * @return: Resultado de la evaluación.
 * Ejemplo: "3 4 +" retorna 7, "5 1 2 + 4 * + 3 -" retorna 14
 */
int evaluar_postfija(const char *expr);

#endif
