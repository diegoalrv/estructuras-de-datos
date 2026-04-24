/*
 * Actividad 3 — Entrada/salida interactiva
 * Lab 00 · EIN423-B Estructuras de Datos · UTFSM
 *
 * Objetivo: usar scanf para leer doubles desde la entrada estándar
 * y aplicar lógica básica (verificación de división por cero).
 *
 * Compilar: gcc act3_io.c -o act3
 * Ejecutar: ./act3
 */

#include <stdio.h>

int main() {
    double x, y;

    /* Leer dos números reales del usuario */
    printf("Ingresa el primer numero : ");
    scanf("%lf", &x);   /* %lf es el especificador correcto para double en scanf */

    printf("Ingresa el segundo numero: ");
    scanf("%lf", &y);

    /* Operaciones básicas */
    printf("\nSuma      : %.4f\n", x + y);
    printf("Diferencia: %.4f\n",  x - y);
    printf("Producto  : %.4f\n",  x * y);

    /* Verificar división por cero antes de dividir */
    if (y != 0.0) {
        printf("Cociente  : %.4f\n", x / y);
    } else {
        printf("Cociente  : Division no definida\n");
    }

    /*
     * EJERCICIO: agrega una quinta línea que imprima el módulo (resto) de
     * la división entera de (int)x / (int)y. Recuerda verificar que y != 0.
     * Pista: usa el operador % con variables de tipo int.
     */

    return 0;
}
