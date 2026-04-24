/*
 * Asignatura: Estructuras de Datos (EIN423-B)
 * Laboratorio: 04 - TDA: Fracción
 * Universidad: UTFSM
 * Estudiante: [Tu nombre aquí]
 */

#ifndef FRACCION_H
#define FRACCION_H

/* Tipo opaco: la definición de la estructura está en fraccion.c */
typedef struct Fraccion Fraccion;

/**
 * Crea una nueva fracción simplificada.
 * @param numerador valor del numerador
 * @param denominador valor del denominador (debe ser != 0)
 * @return puntero a una nueva Fraccion simplificada
 */
Fraccion* fraccion_crear(int numerador, int denominador);

/**
 * Suma dos fracciones.
 * @param a primera fracción
 * @param b segunda fracción
 * @return nueva fracción simplificada que es a + b
 */
Fraccion* fraccion_sumar(const Fraccion *a, const Fraccion *b);

/**
 * Multiplica dos fracciones.
 * @param a primera fracción
 * @param b segunda fracción
 * @return nueva fracción simplificada que es a * b
 */
Fraccion* fraccion_multiplicar(const Fraccion *a, const Fraccion *b);

/**
 * Imprime la fracción en formato "numerador/denominador".
 * @param f puntero a la fracción
 */
void fraccion_imprimir(const Fraccion *f);

/**
 * Libera la memoria asociada a la fracción.
 * @param f puntero a la fracción
 */
void fraccion_destruir(Fraccion *f);

#endif
