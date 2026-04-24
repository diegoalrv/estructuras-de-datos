/*
 * Actividad 5 — Ciclos: tablas y series
 * Lab 00 · EIN423-B Estructuras de Datos · UTFSM
 *
 * Objetivo: practicar los tres ciclos de C:
 *   - for     → cuando conocemos el número de iteraciones de antemano
 *   - while   → cuando iteramos mientras se cumpla una condición
 *   - do-while → cuando queremos ejecutar al menos una vez antes de verificar
 *
 * Compilar: gcc act5_ciclos.c -o act5
 * Ejecutar: ./act5
 */

#include <stdio.h>

int main() {

    /* ------------------------------------------------------------------ */
    /* Parte 1: tabla de multiplicar con for                               */
    /* ------------------------------------------------------------------ */
    int tabla;
    printf("Ingresa el numero de la tabla: ");
    scanf("%d", &tabla);

    printf("\n--- Tabla del %d ---\n", tabla);
    for (int i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", tabla, i, tabla * i);
    }

    /* ------------------------------------------------------------------ */
    /* Parte 2: cuenta regresiva con while                                 */
    /* ------------------------------------------------------------------ */
    int n;
    printf("\nCuenta regresiva desde: ");
    scanf("%d", &n);

    printf("\n--- Cuenta regresiva desde %d ---\n", n);
    int contador = n;
    while (contador >= 1) {
        printf("%d ", contador);
        contador--;   /* decrementar en cada iteración */
    }
    printf("¡Despegue!\n");

    /* ------------------------------------------------------------------ */
    /* Parte 3: suma de dígitos con do-while                               */
    /* ------------------------------------------------------------------ */
    int numero;
    printf("\nIngresa un numero entero positivo: ");
    scanf("%d", &numero);

    int suma   = 0;
    int temp   = (numero < 0) ? -numero : numero;  /* valor absoluto simple */

    /*
     * do-while garantiza que el cuerpo se ejecuta al menos una vez,
     * útil cuando el número puede ser 0 (un solo dígito).
     */
    do {
        suma += temp % 10;  /* extraer el dígito menos significativo */
        temp /= 10;         /* eliminar ese dígito */
    } while (temp > 0);

    printf("\n--- Suma de digitos de %d ---\n", numero);
    printf("Suma: %d\n", suma);

    /*
     * EJERCICIO: agrega una cuarta sección que use un for para imprimir
     * solo los números pares entre 1 y N (valor que el usuario ingrese).
     * Pista: usa el operador % para verificar si i % 2 == 0.
     */

    return 0;
}
