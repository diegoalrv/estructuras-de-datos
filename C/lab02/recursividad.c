/*
 * Asignatura: Estructuras de Datos (EIN423-B)
 * Laboratorio: 02 - Recursividad
 * Universidad: UTFSM
 * Estudiante: [Tu nombre aquí]
 */

#include "recursividad.h"
#include <stdio.h>

long factorial(int n) {
    // TODO: Implementar factorial de forma recursiva
    // Hint: caso base es n == 0, que retorna 1
    // Hint: caso recursivo es n * factorial(n-1)
    return 0;
}

long fibonacci(int n) {
    // TODO: Implementar Fibonacci de forma recursiva
    // Hint: caso base: fib(0)=0, fib(1)=1
    // Hint: caso recursivo: fib(n) = fib(n-1) + fib(n-2)
    return 0;
}

int busqueda_binaria(int *arr, int izq, int der, int objetivo) {
    // TODO: Implementar búsqueda binaria recursivamente
    // Hint: si izq > der, el elemento no existe (retorna -1)
    // Hint: calcula el punto medio y compara con el objetivo
    // Hint: recursión en la mitad izquierda o derecha según corresponda
    return -1;
}

void hanoi(int n, char origen, char destino, char auxiliar) {
    // TODO: Implementar Torres de Hanoi
    // Hint: caso base: si n==1, imprime "Mover disco 1 de {origen} a {destino}"
    // Hint: caso recursivo: primero mueve n-1 discos de origen a auxiliar (usando destino como auxiliar),
    //       luego mueve el disco n de origen a destino,
    //       finalmente mueve n-1 discos de auxiliar a destino (usando origen como auxiliar)
}

int contar_movimientos_hanoi(int n) {
    // TODO: Contar movimientos de Hanoi sin imprimirlos
    // Hint: usa la fórmula directa 2^n - 1 sin llamar a hanoi()
    // Hint: puedes calcular la potencia recursivamente o usando un bucle
    return 0;
}
