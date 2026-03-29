/*
 * Asignatura: Estructuras de Datos (EIN423-B)
 * Laboratorio: 01 - Punteros Básicos
 * Universidad: UTFSM
 * Pruebas unitarias para funciones de punteros
 */

#include <stdio.h>
#include <stdlib.h>
#include "punteros.h"

int main(void) {
    printf("=== Pruebas Lab 01: Punteros Básicos ===\n\n");

    /* Test 1: swap */
    printf("Test 1: swap(3, 7)\n");
    int a = 3, b = 7;
    printf("  Antes: a=%d, b=%d\n", a, b);
    swap(&a, &b);
    printf("  Después: a=%d, b=%d\n", a, b);
    if (a == 7 && b == 3) {
        printf("  ✓ PASS\n\n");
    } else {
        printf("  ✗ FAIL\n\n");
    }

    /* Test 2: estadisticas */
    printf("Test 2: estadisticas({5,3,8,1,9,2,7})\n");
    int arr[] = {5, 3, 8, 1, 9, 2, 7};
    int n = 7;
    int max_val, min_val;
    double prom_val;
    estadisticas(arr, n, &max_val, &min_val, &prom_val);
    printf("  Max: %d (esperado 9)\n", max_val);
    printf("  Min: %d (esperado 1)\n", min_val);
    printf("  Promedio: %.2f (esperado 5.00)\n", prom_val);
    if (max_val == 9 && min_val == 1 && prom_val == 5.0) {
        printf("  ✓ PASS\n\n");
    } else {
        printf("  ✗ FAIL\n\n");
    }

    /* Test 3: invertir */
    printf("Test 3: invertir({1,2,3,4,5})\n");
    int arr2[] = {1, 2, 3, 4, 5};
    int n2 = 5;
    printf("  Antes: ");
    for (int i = 0; i < n2; i++) printf("%d ", arr2[i]);
    printf("\n");
    invertir(arr2, n2);
    printf("  Después: ");
    for (int i = 0; i < n2; i++) printf("%d ", arr2[i]);
    printf("\n");
    int invertido_correcto = 1;
    int esperado[] = {5, 4, 3, 2, 1};
    for (int i = 0; i < n2; i++) {
        if (arr2[i] != esperado[i]) {
            invertido_correcto = 0;
            break;
        }
    }
    if (invertido_correcto) {
        printf("  ✓ PASS\n\n");
    } else {
        printf("  ✗ FAIL\n\n");
    }

    return EXIT_SUCCESS;
}
