/*
 * Asignatura: Estructuras de Datos (EIN423-B)
 * Laboratorio: 04 - TDA: Fracción
 * Universidad: UTFSM
 * Estudiante: [Tu nombre aquí]
 */

#include "fraccion.h"
#include <stdlib.h>
#include <stdio.h>

/* Definición de la estructura (encapsulamiento: el cliente no ve estos campos) */
typedef struct Fraccion {
    int numerador;
    int denominador;
} Fraccion;

/**
 * Calcula el máximo común divisor usando el algoritmo de Euclides.
 * Esta función es un regalo: ya está implementada.
 */
static int mcd(int a, int b) {
    a = (a < 0) ? -a : a;  /* valor absoluto */
    b = (b < 0) ? -b : b;
    return b == 0 ? a : mcd(b, a % b);
}

Fraccion* fraccion_crear(int numerador, int denominador) {
    // TODO: Crear una fracción y simplificarla
    // Hint: asigna memoria con malloc para una Fraccion
    // Hint: calcula el MCD del numerador y denominador
    // Hint: divide ambos por el MCD para simplificar
    // Hint: maneja el caso en que el denominador sea negativo (mueve el signo al numerador)
    return NULL;
}

Fraccion* fraccion_sumar(const Fraccion *a, const Fraccion *b) {
    // TODO: Sumar dos fracciones
    // Hint: fórmula: (a/b) + (c/d) = (a*d + b*c) / (b*d)
    // Hint: crea una nueva Fraccion con el resultado simplificado
    // Hint: puedes usar fraccion_crear para simplificar automáticamente
    return NULL;
}

Fraccion* fraccion_multiplicar(const Fraccion *a, const Fraccion *b) {
    // TODO: Multiplicar dos fracciones
    // Hint: fórmula: (a/b) * (c/d) = (a*c) / (b*d)
    // Hint: crea una nueva Fraccion con el resultado simplificado
    // Hint: puedes usar fraccion_crear para simplificar automáticamente
    return NULL;
}

void fraccion_imprimir(const Fraccion *f) {
    // TODO: Imprimir la fracción
    // Hint: usa printf con format "%d/%d" para imprimir numerador y denominador
    // Hint: accede a los campos de la fracción
}

void fraccion_destruir(Fraccion *f) {
    // TODO: Liberar la memoria de la fracción
    // Hint: usa free(f)
}
