/*
 * Asignatura: Estructuras de Datos (EIN423-B)
 * Laboratorio: 01 - Punteros Básicos
 * Universidad: UTFSM
 * Estudiante: [Tu nombre aquí]
 */

#ifndef PUNTEROS_H
#define PUNTEROS_H
#include <stddef.h>

/**
 * Intercambia el valor de dos enteros usando punteros.
 * @param a puntero al primer entero
 * @param b puntero al segundo entero
 */
void swap(int *a, int *b);

/**
 * Calcula estadísticas de un arreglo.
 * @param arr   arreglo de enteros
 * @param n     tamaño del arreglo
 * @param max   [salida] valor máximo
 * @param min   [salida] valor mínimo
 * @param prom  [salida] promedio
 */
void estadisticas(int *arr, int n, int *max, int *min, double *prom);

/**
 * Invierte un arreglo in-place usando aritmética de punteros.
 * No se permite usar [] para indexar — solo *, + y -.
 * @param arr arreglo a invertir
 * @param n   tamaño del arreglo
 */
void invertir(int *arr, int n);

#endif
