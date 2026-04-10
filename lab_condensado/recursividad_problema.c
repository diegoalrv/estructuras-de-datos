/*
 * ============================================================================
 * CURSO:      Estructuras de Datos (EIN423-B)
 * UNIVERSIDAD: Universidad Técnica Federico Santa María
 * TEMA:       Recursividad
 * ESTUDIANTE: [Tu nombre aquí]
 * ============================================================================
 *
 * ENUNCIADO:
 * ----------
 * Implementa las siguientes funciones recursivas:
 *
 * 1) long factorial(int n)
 *    - Retorna n! de forma recursiva.
 *    - Caso base: n <= 1 → retorna 1
 *    - Caso recursivo: n * factorial(n-1)
 *
 * 2) long fibonacci(int n)
 *    - Retorna el n-ésimo número de Fibonacci.
 *    - Caso base: fib(0)=0, fib(1)=1
 *    - Caso recursivo: fib(n) = fib(n-1) + fib(n-2)
 *
 * 3) int busqueda_binaria(int *arr, int izq, int der, int objetivo)
 *    - Busca 'objetivo' en arr[izq..der] (arreglo ordenado).
 *    - Retorna el índice si lo encuentra, -1 si no.
 *    - Caso base: izq > der → retorna -1 (no encontrado)
 *    - Caso base: arr[mid] == objetivo → retorna mid
 *    - Caso recursivo: busca en mitad izquierda o derecha según comparación.
 *
 * 4) void hanoi(int n, char origen, char destino, char auxiliar, int *movs)
 *    - Imprime los movimientos para resolver Torres de Hanói con n discos.
 *    - Incrementa el contador *movs en cada movimiento.
 *    - Caso base: n == 1 → imprime movimiento y cuenta.
 *    - Caso recursivo:
 *        a) Mover n-1 discos de origen a auxiliar (usando destino)
 *        b) Mover disco n de origen a destino
 *        c) Mover n-1 discos de auxiliar a destino (usando origen)
 *
 * SALIDA ESPERADA:
 *   factorial(0)=1, factorial(5)=120, factorial(10)=3628800
 *   fibonacci(0)=0, fibonacci(1)=1, fibonacci(10)=55
 *   Búsqueda de 7 → índice 3, Búsqueda de 6 → -1
 *   Hanói n=3 → 7 movimientos
 * ============================================================================
 */

#include <stdio.h>

/* ---------- FUNCIONES A IMPLEMENTAR ---------- */

long factorial(int n) {
    /* TODO: Implementar factorial recursivo
     * Hint: caso base n <= 1 retorna 1
     * Hint: caso recursivo retorna n * factorial(n-1) */
    return 0;
}

long fibonacci(int n) {
    /* TODO: Implementar Fibonacci recursivo
     * Hint: caso base n == 0 retorna 0, n == 1 retorna 1
     * Hint: caso recursivo retorna fibonacci(n-1) + fibonacci(n-2) */
    return 0;
}

int busqueda_binaria(int *arr, int izq, int der, int objetivo) {
    /* TODO: Implementar búsqueda binaria recursiva
     * Hint: si izq > der retorna -1
     * Hint: calcula mid = izq + (der - izq) / 2
     * Hint: compara arr[mid] con objetivo y recursa en la mitad correcta */
    return -1;
}

void hanoi(int n, char origen, char destino, char auxiliar, int *movs) {
    /* TODO: Implementar Torres de Hanói
     * Hint: caso base n == 1: imprime movimiento, incrementa *movs
     * Hint: caso recursivo:
     *   hanoi(n-1, origen, auxiliar, destino, movs)
     *   imprime "Mover disco n de origen a destino", incrementa *movs
     *   hanoi(n-1, auxiliar, destino, origen, movs) */
}

/* ---------- PROGRAMA PRINCIPAL (NO MODIFICAR) ---------- */

int main(void) {
    printf("=== RECURSIVIDAD ===\n\n");

    /* Test factorial */
    printf("--- Factorial ---\n");
    printf("factorial(0)  = %ld (esperado: 1)\n", factorial(0));
    printf("factorial(5)  = %ld (esperado: 120)\n", factorial(5));
    printf("factorial(10) = %ld (esperado: 3628800)\n\n", factorial(10));

    /* Test Fibonacci */
    printf("--- Fibonacci ---\n");
    printf("fibonacci(0)  = %ld (esperado: 0)\n", fibonacci(0));
    printf("fibonacci(1)  = %ld (esperado: 1)\n", fibonacci(1));
    printf("fibonacci(10) = %ld (esperado: 55)\n\n", fibonacci(10));

    /* Test búsqueda binaria */
    printf("--- Busqueda Binaria ---\n");
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = 10;
    printf("Buscar 7:  indice %d (esperado: 3)\n", busqueda_binaria(arr, 0, n-1, 7));
    printf("Buscar 6:  indice %d (esperado: -1)\n", busqueda_binaria(arr, 0, n-1, 6));
    printf("Buscar 19: indice %d (esperado: 9)\n\n", busqueda_binaria(arr, 0, n-1, 19));

    /* Test Torres de Hanói */
    printf("--- Torres de Hanoi (n=3) ---\n");
    int movimientos = 0;
    hanoi(3, 'A', 'C', 'B', &movimientos);
    printf("Total movimientos: %d (esperado: 7)\n", movimientos);

    return 0;
}
