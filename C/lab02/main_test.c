/*
 * Asignatura: Estructuras de Datos (EIN423-B)
 * Laboratorio: 02 - Recursividad
 * Universidad: UTFSM
 * Pruebas unitarias para funciones recursivas
 */

#include <stdio.h>
#include <stdlib.h>
#include "recursividad.h"

int main(void) {
    printf("=== Pruebas Lab 02: Recursividad ===\n\n");

    /* Test 1: factorial */
    printf("Test 1: Factorial\n");
    long fact0 = factorial(0);
    long fact5 = factorial(5);
    long fact10 = factorial(10);
    printf("  factorial(0) = %ld (esperado 1)\n", fact0);
    printf("  factorial(5) = %ld (esperado 120)\n", fact5);
    printf("  factorial(10) = %ld (esperado 3628800)\n", fact10);
    if (fact0 == 1 && fact5 == 120 && fact10 == 3628800) {
        printf("  ✓ PASS\n\n");
    } else {
        printf("  ✗ FAIL\n\n");
    }

    /* Test 2: fibonacci */
    printf("Test 2: Fibonacci\n");
    long fib0 = fibonacci(0);
    long fib1 = fibonacci(1);
    long fib10 = fibonacci(10);
    printf("  fibonacci(0) = %ld (esperado 0)\n", fib0);
    printf("  fibonacci(1) = %ld (esperado 1)\n", fib1);
    printf("  fibonacci(10) = %ld (esperado 55)\n", fib10);
    if (fib0 == 0 && fib1 == 1 && fib10 == 55) {
        printf("  ✓ PASS\n\n");
    } else {
        printf("  ✗ FAIL\n\n");
    }

    /* Test 3: búsqueda binaria */
    printf("Test 3: Búsqueda Binaria\n");
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = 10;
    int idx_7 = busqueda_binaria(arr, 0, n - 1, 7);
    int idx_6 = busqueda_binaria(arr, 0, n - 1, 6);
    printf("  Buscar 7 en {1,3,5,7,9,11,13,15,17,19}: índice %d (esperado 3)\n", idx_7);
    printf("  Buscar 6 en {1,3,5,7,9,11,13,15,17,19}: índice %d (esperado -1)\n", idx_6);
    if (idx_7 == 3 && idx_6 == -1) {
        printf("  ✓ PASS\n\n");
    } else {
        printf("  ✗ FAIL\n\n");
    }

    /* Test 4: hanoi */
    printf("Test 4: Torres de Hanoi (n=3)\n");
    printf("  Movimientos:\n");
    hanoi(3, 'A', 'C', 'B');
    printf("\n");

    /* Test 5: contar_movimientos_hanoi */
    printf("Test 5: Contar Movimientos Hanoi\n");
    int movs_3 = contar_movimientos_hanoi(3);
    int movs_4 = contar_movimientos_hanoi(4);
    printf("  contar_movimientos_hanoi(3) = %d (esperado 7)\n", movs_3);
    printf("  contar_movimientos_hanoi(4) = %d (esperado 15)\n", movs_4);
    if (movs_3 == 7 && movs_4 == 15) {
        printf("  ✓ PASS\n\n");
    } else {
        printf("  ✗ FAIL\n\n");
    }

    return EXIT_SUCCESS;
}
