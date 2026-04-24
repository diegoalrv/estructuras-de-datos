/*
 * ============================================================================
 * CURSO:      Estructuras de Datos (EIN423-B)
 * UNIVERSIDAD: Universidad Técnica Federico Santa María
 * TEMA:       Recursividad — SOLUCION
 * ============================================================================
 */

#include <stdio.h>

/* ---------- SOLUCIONES ---------- */

long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

long fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int busqueda_binaria(int *arr, int izq, int der, int objetivo) {
    if (izq > der) return -1;

    int mid = izq + (der - izq) / 2;

    if (arr[mid] == objetivo) return mid;
    if (arr[mid] < objetivo) return busqueda_binaria(arr, mid + 1, der, objetivo);
    return busqueda_binaria(arr, izq, mid - 1, objetivo);
}

void hanoi(int n, char origen, char destino, char auxiliar, int *movs) {
    if (n == 1) {
        printf("  Mover disco 1 de %c a %c\n", origen, destino);
        (*movs)++;
        return;
    }
    hanoi(n - 1, origen, auxiliar, destino, movs);
    printf("  Mover disco %d de %c a %c\n", n, origen, destino);
    (*movs)++;
    hanoi(n - 1, auxiliar, destino, origen, movs);
}

/* ---------- PROGRAMA PRINCIPAL ---------- */

int main(void) {
    printf("=== RECURSIVIDAD ===\n\n");

    printf("--- Factorial ---\n");
    printf("factorial(0)  = %ld (esperado: 1)\n", factorial(0));
    printf("factorial(5)  = %ld (esperado: 120)\n", factorial(5));
    printf("factorial(10) = %ld (esperado: 3628800)\n\n", factorial(10));

    printf("--- Fibonacci ---\n");
    printf("fibonacci(0)  = %ld (esperado: 0)\n", fibonacci(0));
    printf("fibonacci(1)  = %ld (esperado: 1)\n", fibonacci(1));
    printf("fibonacci(10) = %ld (esperado: 55)\n\n", fibonacci(10));

    printf("--- Busqueda Binaria ---\n");
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = 10;
    printf("Buscar 7:  indice %d (esperado: 3)\n", busqueda_binaria(arr, 0, n-1, 7));
    printf("Buscar 6:  indice %d (esperado: -1)\n", busqueda_binaria(arr, 0, n-1, 6));
    printf("Buscar 19: indice %d (esperado: 9)\n\n", busqueda_binaria(arr, 0, n-1, 19));

    printf("--- Torres de Hanoi (n=3) ---\n");
    int movimientos = 0;
    hanoi(3, 'A', 'C', 'B', &movimientos);
    printf("Total movimientos: %d (esperado: 7)\n", movimientos);

    return 0;
}
