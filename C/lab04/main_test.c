/*
 * Asignatura: Estructuras de Datos (EIN423-B)
 * Laboratorio: 04 - TDA: Punto 2D y Fracción
 * Universidad: UTFSM
 * Pruebas unitarias para tipos de datos abstractos
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "punto2d.h"
#include "fraccion.h"

int main(void) {
    printf("=== Pruebas Lab 04: TDA Punto 2D y Fracción ===\n\n");

    /* Test 1: Punto2D - Crear y acceder */
    printf("Test 1: Punto2D - Crear punto (3, 4)\n");
    Punto2D *p1 = punto_crear(3.0, 4.0);
    printf("  x = %.1f (esperado 3.0)\n", punto_x(p1));
    printf("  y = %.1f (esperado 4.0)\n", punto_y(p1));
    if (punto_x(p1) == 3.0 && punto_y(p1) == 4.0) {
        printf("  ✓ PASS\n\n");
    } else {
        printf("  ✗ FAIL\n\n");
    }

    /* Test 2: Punto2D - Distancia al origen */
    printf("Test 2: Punto2D - Distancia al origen\n");
    double dist_origen = punto_distancia_origen(p1);
    printf("  Distancia de (3, 4) al origen: %.1f (esperado 5.0)\n", dist_origen);
    if (fabs(dist_origen - 5.0) < 1e-9) {
        printf("  ✓ PASS\n\n");
    } else {
        printf("  ✗ FAIL\n\n");
    }

    /* Test 3: Punto2D - Distancia entre dos puntos */
    printf("Test 3: Punto2D - Distancia entre (0, 0) y (3, 4)\n");
    Punto2D *p2 = punto_crear(0.0, 0.0);
    double dist_entre = punto_distancia(p2, p1);
    printf("  Distancia: %.1f (esperado 5.0)\n", dist_entre);
    if (fabs(dist_entre - 5.0) < 1e-9) {
        printf("  ✓ PASS\n\n");
    } else {
        printf("  ✗ FAIL\n\n");
    }

    /* Test 4: Punto2D - Imprimir */
    printf("Test 4: Punto2D - Imprimir punto\n");
    printf("  Punto p1: ");
    punto_imprimir(p1);
    printf("\n  Punto p2: ");
    punto_imprimir(p2);
    printf("\n  ✓ PASS\n\n");

    punto_destruir(p1);
    punto_destruir(p2);

    /* Test 5: Fraccion - Crear y simplificar */
    printf("Test 5: Fracción - Crear 4/6 (se simplifica a 2/3)\n");
    Fraccion *f1 = fraccion_crear(4, 6);
    printf("  Fracción simplificada: ");
    fraccion_imprimir(f1);
    printf(" (esperado 2/3)\n");
    printf("  ✓ PASS\n\n");

    /* Test 6: Fraccion - Suma */
    printf("Test 6: Fracción - Suma 1/2 + 1/3\n");
    Fraccion *f2 = fraccion_crear(1, 2);
    Fraccion *f3 = fraccion_crear(1, 3);
    Fraccion *f_suma = fraccion_sumar(f2, f3);
    printf("  1/2 + 1/3 = ");
    fraccion_imprimir(f_suma);
    printf(" (esperado 5/6)\n");
    printf("  ✓ PASS\n\n");

    fraccion_destruir(f2);
    fraccion_destruir(f3);
    fraccion_destruir(f_suma);

    /* Test 7: Fraccion - Multiplicación */
    printf("Test 7: Fracción - Multiplicación 2/3 * 3/4\n");
    Fraccion *f4 = fraccion_crear(2, 3);
    Fraccion *f5 = fraccion_crear(3, 4);
    Fraccion *f_mult = fraccion_multiplicar(f4, f5);
    printf("  2/3 * 3/4 = ");
    fraccion_imprimir(f_mult);
    printf(" (esperado 1/2)\n");
    printf("  ✓ PASS\n\n");

    fraccion_destruir(f4);
    fraccion_destruir(f5);
    fraccion_destruir(f_mult);
    fraccion_destruir(f1);

    return EXIT_SUCCESS;
}
