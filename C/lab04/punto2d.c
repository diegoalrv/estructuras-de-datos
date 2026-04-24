/*
 * Asignatura: Estructuras de Datos (EIN423-B)
 * Laboratorio: 04 - TDA: Punto 2D
 * Universidad: UTFSM
 * Estudiante: [Tu nombre aquí]
 */

#include "punto2d.h"
#include <stdlib.h>
#include <stdio.h>

/* Definición de la estructura (encapsulamiento: el cliente no ve estos campos) */
typedef struct Punto2D {
    double x;
    double y;
} Punto2D;

Punto2D* punto_crear(double x, double y) {
    // TODO: Crear un punto dinámico con malloc
    // Hint: asigna memoria para un Punto2D
    // Hint: inicializa los campos x e y
    // Hint: retorna el puntero a la estructura creada
    return NULL;
}

double punto_x(const Punto2D *p) {
    // TODO: Retornar la coordenada x
    // Hint: simplemente desreferencia y accede al campo
    return 0.0;
}

double punto_y(const Punto2D *p) {
    // TODO: Retornar la coordenada y
    // Hint: simplemente desreferencia y accede al campo
    return 0.0;
}

double punto_distancia_origen(const Punto2D *p) {
    // TODO: Calcular distancia desde el punto hasta (0, 0)
    // Hint: usa la fórmula sqrt(x^2 + y^2)
    // Hint: la función sqrt está disponible en math.h (incluida en punto2d.h)
    return 0.0;
}

double punto_distancia(const Punto2D *p1, const Punto2D *p2) {
    // TODO: Calcular la distancia entre dos puntos
    // Hint: usa la fórmula sqrt((x2-x1)^2 + (y2-y1)^2)
    // Hint: accede a los campos de ambos puntos
    return 0.0;
}

void punto_imprimir(const Punto2D *p) {
    // TODO: Imprimir el punto en formato (x, y)
    // Hint: usa printf con format "(%f, %f)" o similar
    // Hint: accede a los campos del punto
}

void punto_destruir(Punto2D *p) {
    // TODO: Liberar la memoria del punto
    // Hint: usa free(p)
}
