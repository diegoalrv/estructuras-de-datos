/*
 * Asignatura: Estructuras de Datos (EIN423-B)
 * Laboratorio: 03 - Análisis de Complejidad Experimental
 * Universidad: UTFSM
 * Estudiante: [Tu nombre aquí]
 */

#ifndef COMPLEJIDAD_H
#define COMPLEJIDAD_H

#include <time.h>

/**
 * Realiza búsqueda lineal y mide el tiempo en segundos.
 * @param arr arreglo de enteros
 * @param n tamaño del arreglo
 * @param objetivo valor a buscar
 * @return tiempo en segundos
 */
double medir_busqueda_lineal(int *arr, int n, int objetivo);

/**
 * Realiza búsqueda binaria y mide el tiempo en segundos.
 * Precondición: arr debe estar ordenado
 * @param arr arreglo ordenado de enteros
 * @param n tamaño del arreglo
 * @param objetivo valor a buscar
 * @return tiempo en segundos
 */
double medir_busqueda_binaria(int *arr, int n, int objetivo);

/**
 * Ordena un arreglo usando algoritmo de burbuja.
 * @param arr arreglo a ordenar (modifica in-place)
 * @param n tamaño del arreglo
 * @return número de comparaciones realizadas
 */
long burbuja(int *arr, int n);

/**
 * Ordena un arreglo usando burbuja y mide el tiempo en segundos.
 * Trabaja sobre una copia para no modificar el original.
 * @param arr arreglo de enteros
 * @param n tamaño del arreglo
 * @return tiempo en segundos
 */
double medir_burbuja(int *arr, int n);

/**
 * Ordena un arreglo usando qsort de stdlib y mide el tiempo en segundos.
 * Trabaja sobre una copia para no modificar el original.
 * @param arr arreglo de enteros
 * @param n tamaño del arreglo
 * @return tiempo en segundos
 */
double medir_qsort(int *arr, int n);

#endif
