/*
 * Actividad 1 — Hola, mundo personalizado
 * Lab 00 · EIN423-B Estructuras de Datos · UTFSM
 *
 * Objetivo: familiarizarse con la estructura básica de un programa en C
 * y el uso de printf con cadenas de texto.
 *
 * Compilar: gcc act1_hola_mundo.c -o act1
 * Ejecutar: ./act1
 */

#include <stdio.h>

int main() {
    /* Declaración de variables de tipo char[] (arreglo de caracteres = string) */
    char nombre[]  = "Diego";
    char carrera[] = "Ingeniería Civil Informática";
    int  anio      = 2023;

    /* printf con especificador %s para cadenas y %d para enteros */
    printf("Nombre : %s\n",  nombre);
    printf("Carrera: %s\n",  carrera);
    printf("Año    : %d\n",  anio);

    /*
     * EJERCICIO: modifica las variables nombre, carrera y anio con tus
     * propios datos y vuelve a compilar. ¿Cambia la salida?
     */

    return 0;  /* 0 indica que el programa terminó sin errores */
}
