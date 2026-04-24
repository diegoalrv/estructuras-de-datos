/*
 * Estructuras de Datos - EIN423-B
 * Laboratorio 16: Algoritmos de Ordenamiento
 *
 * Alumno: ___________________________________
 * Sección: _________________________________
 *
 * Descripción:
 * Implementación de diversos algoritmos de ordenamiento.
 * Incluye algoritmos simples (burbuja, selección, inserción) y avanzados (merge, quick).
 */

#ifndef ORDENAMIENTO_H
#define ORDENAMIENTO_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

/**
 * Intercambia dos enteros.
 *
 * @param a Puntero al primer entero
 * @param b Puntero al segundo entero
 */
void swap_int(int *a, int *b);

/**
 * Copia un array de enteros a otro.
 *
 * @param dst Array destino
 * @param src Array fuente
 * @param n Cantidad de elementos
 */
void copiar_array(int *dst, const int *src, int n);

/**
 * Imprime un array de enteros.
 *
 * @param arr Array a imprimir
 * @param n Cantidad de elementos
 */
void imprimir_array(const int *arr, int n);

/**
 * Comparador para qsort: orden ascendente.
 *
 * @param a Puntero a primer elemento
 * @param b Puntero a segundo elemento
 * @return Negativo si a<b, 0 si a==b, positivo si a>b
 */
int comparar_int_asc(const void *a, const void *b);

/**
 * Bubble Sort: ordena mediante comparaciones e intercambios repetidos.
 * Complejidad: O(n²) peor y promedio, O(n) mejor caso.
 *
 * @param arr Array a ordenar (in-place)
 * @param n Cantidad de elementos
 * @return Número total de comparaciones realizadas
 */
long burbuja_sort(int *arr, int n);

/**
 * Selection Sort: selecciona el mínimo en cada pasada.
 * Complejidad: O(n²) en todos los casos.
 *
 * @param arr Array a ordenar (in-place)
 * @param n Cantidad de elementos
 * @return Número total de comparaciones realizadas
 */
long seleccion_sort(int *arr, int n);

/**
 * Insertion Sort: inserta elementos en posición correcta.
 * Complejidad: O(n²) peor y promedio, O(n) mejor caso.
 *
 * @param arr Array a ordenar (in-place)
 * @param n Cantidad de elementos
 * @return Número total de comparaciones realizadas
 */
long insercion_sort(int *arr, int n);

/**
 * Merge Sort: divide y conquista con merging.
 * Complejidad: O(n log n) en todos los casos.
 * Estable y requiere espacio O(n).
 *
 * @param arr Array a ordenar (in-place, pero usa espacio auxiliar)
 * @param n Cantidad de elementos
 */
void merge_sort(int *arr, int n);

/**
 * Quick Sort: divide y conquista con pivote.
 * Complejidad: O(n log n) promedio, O(n²) peor caso.
 * Pivote = mediana de arr[0], arr[n/2], arr[n-1].
 *
 * @param arr Array a ordenar (in-place)
 * @param n Cantidad de elementos
 */
void quick_sort(int *arr, int n);

/**
 * Quick Sort genérico compatible con qsort de stdlib.
 * Firma idéntica a qsort para permitir comparaciones justas.
 *
 * @param base Puntero al primer elemento
 * @param nmemb Número de elementos
 * @param size Tamaño en bytes de cada elemento
 * @param compar Función comparadora (a, b) retorna <0, 0, o >0
 */
void mi_quicksort(void *base, size_t nmemb, size_t size,
                  int (*compar)(const void*, const void*));

#endif
