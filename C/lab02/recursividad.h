/*
 * Asignatura: Estructuras de Datos (EIN423-B)
 * Laboratorio: 02 - Recursividad
 * Universidad: UTFSM
 * Estudiante: [Tu nombre aquí]
 */

#ifndef RECURSIVIDAD_H
#define RECURSIVIDAD_H

/**
 * Calcula el factorial de n de forma recursiva.
 * Precondición: n >= 0
 * @param n número entero no negativo
 * @return n! (factorial)
 */
long factorial(int n);

/**
 * Calcula el n-ésimo número de Fibonacci de forma recursiva.
 * Precondición: n >= 0
 * @param n índice de Fibonacci
 * @return Fibonacci(n)
 */
long fibonacci(int n);

/**
 * Realiza búsqueda binaria en un arreglo ordenado.
 * @param arr arreglo ordenado de enteros
 * @param izq índice izquierdo
 * @param der índice derecho
 * @param objetivo valor a buscar
 * @return índice del elemento si se encuentra, -1 si no existe
 */
int busqueda_binaria(int *arr, int izq, int der, int objetivo);

/**
 * Resuelve el problema de las Torres de Hanoi imprimiendo los movimientos.
 * @param n número de discos
 * @param origen varilla de inicio ('A', 'B' o 'C')
 * @param destino varilla final ('A', 'B' o 'C')
 * @param auxiliar varilla auxiliar ('A', 'B' o 'C')
 */
void hanoi(int n, char origen, char destino, char auxiliar);

/**
 * Calcula el número de movimientos necesarios para Hanoi sin imprimirlos.
 * @param n número de discos
 * @return 2^n - 1 (número de movimientos)
 */
int contar_movimientos_hanoi(int n);

#endif
