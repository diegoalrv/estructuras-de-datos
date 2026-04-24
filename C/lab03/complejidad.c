/*
 * Asignatura: Estructuras de Datos (EIN423-B)
 * Laboratorio: 03 - Análisis de Complejidad Experimental
 * Universidad: UTFSM
 * Estudiante: [Tu nombre aquí]
 */

#include "complejidad.h"
#include <stdlib.h>
#include <string.h>

double medir_busqueda_lineal(int *arr, int n, int objetivo) {
    // TODO: Implementar búsqueda lineal y medir tiempo
    // Hint: usa clock() al inicio y al final: clock_t ini = clock(); ... clock_t fin = clock();
    // Hint: retorna (double)(fin - ini) / CLOCKS_PER_SEC;
    // Hint: para valores pequeños, repite la búsqueda varias veces para obtener un tiempo medible
    return 0.0;
}

double medir_busqueda_binaria(int *arr, int n, int objetivo) {
    // TODO: Implementar búsqueda binaria iterativa y medir tiempo
    // Hint: el arreglo debe estar ordenado
    // Hint: usa clock() para medir tiempo similar a busqueda_lineal
    // Hint: para arrays pequeños, repite la búsqueda varias veces
    return 0.0;
}

long burbuja(int *arr, int n) {
    // TODO: Implementar ordenamiento por burbuja y contar comparaciones
    // Hint: dos bucles anidados comparando elementos adyacentes
    // Hint: incrementa un contador cada vez que comparas dos elementos
    // Hint: intercambia si arr[i] > arr[i+1]
    return 0;
}

double medir_burbuja(int *arr, int n) {
    // TODO: Copiar el arreglo, aplicar burbuja y medir tiempo
    // Hint: crea una copia con malloc y memcpy
    // Hint: mide tiempo alrededor de la llamada a burbuja()
    // Hint: libera la memoria con free
    return 0.0;
}

int comparar(const void *a, const void *b) {
    // Función auxiliar para qsort
    int x = *(int *)a;
    int y = *(int *)b;
    return (x > y) - (x < y);
}

double medir_qsort(int *arr, int n) {
    // TODO: Copiar el arreglo, aplicar qsort y medir tiempo
    // Hint: crea una copia con malloc y memcpy
    // Hint: usa qsort(copia, n, sizeof(int), comparar);
    // Hint: mide el tiempo de ejecución
    // Hint: libera memoria con free
    return 0.0;
}
