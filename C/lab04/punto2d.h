/*
 * Asignatura: Estructuras de Datos (EIN423-B)
 * Laboratorio: 04 - TDA: Punto 2D
 * Universidad: UTFSM
 * Estudiante: [Tu nombre aquí]
 */

#ifndef PUNTO2D_H
#define PUNTO2D_H

#include <math.h>

/* Tipo opaco: la definición de la estructura está en punto2d.c */
typedef struct Punto2D Punto2D;

/**
 * Crea un nuevo punto con las coordenadas especificadas.
 * @param x coordenada x
 * @param y coordenada y
 * @return puntero a un nuevo Punto2D
 */
Punto2D* punto_crear(double x, double y);

/**
 * Obtiene la coordenada x del punto.
 * @param p puntero al punto
 * @return valor de x
 */
double punto_x(const Punto2D *p);

/**
 * Obtiene la coordenada y del punto.
 * @param p puntero al punto
 * @return valor de y
 */
double punto_y(const Punto2D *p);

/**
 * Calcula la distancia desde el punto hasta el origen (0, 0).
 * @param p puntero al punto
 * @return distancia al origen
 */
double punto_distancia_origen(const Punto2D *p);

/**
 * Calcula la distancia entre dos puntos.
 * @param p1 primer punto
 * @param p2 segundo punto
 * @return distancia entre p1 y p2
 */
double punto_distancia(const Punto2D *p1, const Punto2D *p2);

/**
 * Imprime el punto en formato (x, y).
 * @param p puntero al punto
 */
void punto_imprimir(const Punto2D *p);

/**
 * Libera la memoria asociada al punto.
 * @param p puntero al punto
 */
void punto_destruir(Punto2D *p);

#endif
