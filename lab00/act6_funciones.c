/*
 * Actividad 6 — Funciones: conversiones y utilidades
 * Lab 00 · EIN423-B Estructuras de Datos · UTFSM
 *
 * Objetivo: definir funciones con y sin retorno de valor,
 * usarlas desde main, y comprender la separación entre
 * declaración (prototipo), definición e invocación.
 *
 * Compilar: gcc act6_funciones.c -o act6
 * Ejecutar: ./act6
 */

#include <stdio.h>

/* ======================================================================
 * PROTOTIPOS (declaraciones anticipadas)
 * Permiten usar las funciones en main aunque estén definidas más abajo.
 * ====================================================================== */
double celsius_a_fahrenheit(double celsius);
int    valor_absoluto(int n);
int    es_primo(int n);
void   fibonacci(int n);


/* ======================================================================
 * DEFINICIÓN DE FUNCIONES
 * ====================================================================== */

/*
 * Convierte grados Celsius a Fahrenheit.
 * Fórmula: F = C * 9/5 + 32
 */
double celsius_a_fahrenheit(double celsius) {
    return celsius * 9.0 / 5.0 + 32.0;
}

/*
 * Retorna el valor absoluto de un entero sin usar abs() de <stdlib.h>.
 * Si n es negativo, retorna -n; si no, retorna n.
 */
int valor_absoluto(int n) {
    if (n < 0) {
        return -n;
    }
    return n;
}

/*
 * Retorna 1 si n es primo, 0 si no lo es.
 * Un número primo es mayor que 1 y solo divisible por 1 y por sí mismo.
 * Optimización: basta verificar divisores hasta sqrt(n).
 */
int es_primo(int n) {
    if (n <= 1) return 0;       /* 0 y 1 no son primos */
    if (n == 2) return 1;       /* 2 es el único primo par */
    if (n % 2 == 0) return 0;   /* cualquier otro par no es primo */

    /* Verificar divisores impares desde 3 hasta sqrt(n) */
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}

/*
 * Imprime los primeros n términos de la serie de Fibonacci.
 * Fibonacci: 0, 1, 1, 2, 3, 5, 8, 13, 21, ...
 * Cada término es la suma de los dos anteriores.
 * void: no retorna valor.
 */
void fibonacci(int n) {
    if (n <= 0) {
        printf("(ninguno)\n");
        return;
    }

    long long a = 0, b = 1;

    for (int i = 0; i < n; i++) {
        printf("%lld ", a);
        long long siguiente = a + b;
        a = b;
        b = siguiente;
    }
    printf("\n");
}


/* ======================================================================
 * MAIN — punto de entrada del programa
 * ====================================================================== */
int main() {

    /* --- Conversión Celsius → Fahrenheit --- */
    double celsius;
    printf("Temperatura en Celsius: ");
    scanf("%lf", &celsius);
    printf("En Fahrenheit: %.2f\n\n", celsius_a_fahrenheit(celsius));

    /* --- Valor absoluto --- */
    int entero;
    printf("Entero: ");
    scanf("%d", &entero);
    printf("Valor absoluto: %d\n\n", valor_absoluto(entero));

    /* --- Número primo --- */
    int num;
    printf("Numero: ");
    scanf("%d", &num);
    if (es_primo(num)) {
        printf("%d es primo\n\n", num);
    } else {
        printf("%d NO es primo\n\n", num);
    }

    /* --- Serie de Fibonacci --- */
    int terminos;
    printf("Terminos Fibonacci: ");
    scanf("%d", &terminos);
    fibonacci(terminos);

    /*
     * EJERCICIO: agrega una quinta función llamada `int factorial(int n)`
     * que calcule el factorial de n usando un ciclo for.
     * Llámala desde main pidiendo un número al usuario.
     * Recuerda: 0! = 1, n! = n * (n-1) * ... * 1
     */

    return 0;
}
