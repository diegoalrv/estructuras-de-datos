/*
 * Actividad 2 — Variables y tipos de datos
 * Lab 00 · EIN423-B Estructuras de Datos · UTFSM
 *
 * Objetivo: practicar la declaración de variables, operadores aritméticos
 * y la relación entre caracteres y sus valores ASCII.
 *
 * Compilar: gcc act2_variables.c -o act2
 * Ejecutar: ./act2
 */

#include <stdio.h>

int main() {
    /* ------------------------------------------------------------------ */
    /* Parte 1: operaciones con enteros                                    */
    /* ------------------------------------------------------------------ */
    int a = 10;
    int b = 3;

    printf("a=%d, b=%d\n", a, b);
    printf("Suma     : %d\n", a + b);
    printf("Resta    : %d\n", a - b);
    printf("Producto : %d\n", a * b);
    printf("Cociente : %d\n", a / b);   /* División entera: descarta decimales */
    printf("Resto    : %d\n", a % b);   /* Operador módulo                     */

    /* ------------------------------------------------------------------ */
    /* Parte 2: área y perímetro de un círculo con double                  */
    /* ------------------------------------------------------------------ */
    double pi    = 3.14159265;
    double radio = 5.0;
    double area       = pi * radio * radio;
    double perimetro  = 2 * pi * radio;

    printf("\nRadio=%.2f, Area=%.2f, Perimetro=%.2f\n", radio, area, perimetro);

    /* ------------------------------------------------------------------ */
    /* Parte 3: char y conversión ASCII minúscula ↔ mayúscula              */
    /* ------------------------------------------------------------------ */
    char letra_minus = 'a';
    /*
     * En ASCII las mayúsculas van de 65 ('A') a 90 ('Z') y
     * las minúsculas de 97 ('a') a 122 ('z'). La diferencia es 32.
     * Restar 32 convierte minúscula → mayúscula.
     */
    char letra_mayus = letra_minus - 32;

    printf("\nLetra minuscula: %c  ->  Mayuscula: %c\n", letra_minus, letra_mayus);
    printf("(Valor ASCII:   %d  ->  %d)\n", letra_minus, letra_mayus);

    /*
     * EJERCICIO: cambia los valores de a, b, radio y letra_minus,
     * recompila y verifica que los resultados sean correctos.
     */

    return 0;
}
