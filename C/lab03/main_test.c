/*
 * Asignatura: Estructuras de Datos (EIN423-B)
 * Laboratorio: 03 - Análisis de Complejidad Experimental
 * Universidad: UTFSM
 * Pruebas de complejidad: genera datos aleatorios y mide rendimiento
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "complejidad.h"

/* Comparador para qsort */
int comparador(const void *a, const void *b) {
    int x = *(int *)a;
    int y = *(int *)b;
    return (x > y) - (x < y);
}

/* Función auxiliar para generar arreglo de números aleatorios */
int* generar_arreglo_aleatorio(int n) {
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (n * 10);
    }
    return arr;
}

/* Función auxiliar para crear arreglo ordenado */
int* generar_arreglo_ordenado(int n) {
    int *arr = generar_arreglo_aleatorio(n);
    qsort(arr, n, sizeof(int), comparador);
    return arr;
}

int main(void) {
    printf("=== Pruebas Lab 03: Análisis de Complejidad Experimental ===\n\n");
    srand(time(NULL));

    int tamanios[] = {1000, 5000, 10000, 20000};
    int num_tamanios = 4;

    printf("╔════════╦════════════════════╦════════════════════╦════════════════════╦════════════════════╗\n");
    printf("║   n    ║ Búsqueda lineal    ║ Búsqueda binaria   ║ Burbuja            ║ qsort              ║\n");
    printf("╠════════╬════════════════════╬════════════════════╬════════════════════╬════════════════════╣\n");

    for (int i = 0; i < num_tamanios; i++) {
        int n = tamanios[i];
        int *arr = generar_arreglo_aleatorio(n);
        int *arr_ordenado = (int *)malloc(n * sizeof(int));
        memcpy(arr_ordenado, arr, n * sizeof(int));
        qsort(arr_ordenado, n, sizeof(int), comparador);

        /* Medir búsqueda lineal */
        int objetivo = arr[n / 2];
        double t_lineal = medir_busqueda_lineal(arr, n, objetivo);

        /* Medir búsqueda binaria */
        double t_binaria = medir_busqueda_binaria(arr_ordenado, n, objetivo);

        /* Medir burbuja */
        double t_burbuja = medir_burbuja(arr, n);

        /* Medir qsort */
        double t_qsort = medir_qsort(arr, n);

        printf("║ %6d ║ %15.6fs ║ %15.6fs ║ %15.6fs ║ %15.6fs ║\n",
               n, t_lineal, t_binaria, t_burbuja, t_qsort);

        free(arr);
        free(arr_ordenado);
    }

    printf("╚════════╩════════════════════╩════════════════════╩════════════════════╩════════════════════╝\n\n");

    printf("Notas sobre complejidad:\n");
    printf("- Búsqueda lineal: O(n) — tiempo crece linealmente\n");
    printf("- Búsqueda binaria: O(log n) — tiempo crece logarítmicamente\n");
    printf("- Burbuja: O(n²) — tiempo crece cuadráticamente\n");
    printf("- qsort: O(n log n) en promedio — mucho más rápido que burbuja\n\n");

    return EXIT_SUCCESS;
}
