/*
 * Actividad 4 — Condicionales: calculadora de notas
 * Lab 00 · EIN423-B Estructuras de Datos · UTFSM
 *
 * Objetivo: usar if / else if / else para clasificar un valor
 * según rangos y tomar decisiones.
 *
 * Compilar: gcc act4_condicionales.c -o act4
 * Ejecutar: ./act4
 */

#include <stdio.h>

int main() {
    double nota;

    printf("Ingresa la nota (1.0 - 7.0): ");
    scanf("%lf", &nota);

    /* Clasificación por rangos con if / else if / else */
    if (nota < 1.0 || nota > 7.0) {
        printf("Clasificacion: Nota invalida\n");
    } else if (nota >= 6.0) {
        printf("Clasificacion: Excelente\n");
    } else if (nota >= 5.0) {
        printf("Clasificacion: Bueno\n");
    } else if (nota >= 4.0) {
        printf("Clasificacion: Suficiente\n");
    } else if (nota >= 3.0) {
        printf("Clasificacion: Insuficiente\n");
    } else {
        printf("Clasificacion: Reprobado\n");
    }

    /* Verificación de aprobación (nota mínima: 4.0) */
    if (nota >= 1.0 && nota <= 7.0) {
        if (nota >= 4.0) {
            printf("Estado: Aprobado\n");
        } else {
            printf("Estado: Reprobado\n");
        }
    }

    /*
     * EJERCICIO: agrega un bloque que informe cuántos décimos le
     * faltan al alumno para aprobar si la nota es menor a 4.0.
     * Ejemplo: nota=3.7 → "Te faltan 0.3 décimas para aprobar."
     * Pista: calcula (4.0 - nota) cuando nota < 4.0.
     */

    return 0;
}
