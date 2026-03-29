/*
 * Asignatura: Estructuras de Datos (EIN423-B)
 * Laboratorio: 01 - Punteros Básicos
 * Universidad: UTFSM
 * Estudiante: [Tu nombre aquí]
 */

#include "punteros.h"

void swap(int *a, int *b) {
    // TODO: Implementar intercambio de valores usando una variable temporal
    // Hint: necesitas una variable temporal para guardar uno de los valores
    // Hint: desreferencia los punteros con *a y *b para acceder a los valores
}

void estadisticas(int *arr, int n, int *max, int *min, double *prom) {
    // TODO: Implementar cálculo de máximo, mínimo y promedio
    // Hint: recorre el arreglo usando aritmética de punteros o desreferenciación
    // Hint: para el promedio, suma todos los valores y divide por n
    // Hint: asegúrate de manejar correctamente los punteros de salida (*max, *min, *prom)
}

void invertir(int *arr, int n) {
    // TODO: Invertir el arreglo in-place sin usar []
    // Hint: usa dos punteros, uno al inicio y otro al final
    // Hint: avanza con + y retrocede con - para intercambiar pares de elementos
}
