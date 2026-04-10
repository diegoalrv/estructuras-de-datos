/*
 * ============================================================================
 * CURSO:      Estructuras de Datos (EIN423-B)
 * UNIVERSIDAD: Universidad Técnica Federico Santa María
 * TEMA:       Estructuras de Datos — struct Fraccion
 * ESTUDIANTE: [Tu nombre aquí]
 * ============================================================================
 *
 * ENUNCIADO:
 * ----------
 * Implementa un TDA Fracción usando struct. Todas las fracciones deben
 * almacenarse SIEMPRE simplificadas (reducidas a su forma irreducible).
 *
 * 1) int mcd(int a, int b)
 *    - Calcula el máximo común divisor usando el algoritmo de Euclides.
 *    - Trabaja con valores absolutos.
 *
 * 2) Fraccion fraccion_crear(int num, int den)
 *    - Crea una fracción simplificada.
 *    - Valida que den != 0. Si den < 0, mueve el signo al numerador.
 *    - Simplifica dividiendo num y den por su MCD.
 *
 * 3) Fraccion fraccion_sumar(Fraccion a, Fraccion b)
 *    - Suma: (a/b) + (c/d) = (a*d + b*c) / (b*d), luego simplifica.
 *
 * 4) Fraccion fraccion_multiplicar(Fraccion a, Fraccion b)
 *    - Multiplica: (a/b) * (c/d) = (a*c) / (b*d), luego simplifica.
 *
 * 5) void fraccion_imprimir(Fraccion f)
 *    - Imprime la fracción en formato "num/den".
 *
 * SALIDA ESPERADA:
 *   Crear 4/6 → 2/3
 *   1/2 + 1/3 = 5/6
 *   2/3 * 3/4 = 1/2
 *   Crear 6/9 → 2/3
 *   Crear 3/-4 → -3/4
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/* ---------- ESTRUCTURA ---------- */

typedef struct {
    int num;
    int den;
} Fraccion;

/* ---------- FUNCIONES A IMPLEMENTAR ---------- */

int mcd(int a, int b) {
    /* TODO: Implementar algoritmo de Euclides
     * Hint: usa valores absolutos de a y b
     * Hint: mientras b != 0: tmp=b, b=a%b, a=tmp
     * Hint: retorna a */
    return 1;
}

Fraccion fraccion_crear(int num, int den) {
    /* TODO: Crear fracción simplificada
     * Hint: si den == 0, imprime error y usa den=1
     * Hint: si den < 0, multiplica num y den por -1
     * Hint: calcula g = mcd(num, den), divide ambos por g
     * Hint: retorna la fracción con num/g y den/g */
    Fraccion f = {0, 1};
    return f;
}

Fraccion fraccion_sumar(Fraccion a, Fraccion b) {
    /* TODO: Sumar dos fracciones
     * Hint: nuevo_num = a.num * b.den + b.num * a.den
     * Hint: nuevo_den = a.den * b.den
     * Hint: retorna fraccion_crear(nuevo_num, nuevo_den) para simplificar */
    Fraccion f = {0, 1};
    return f;
}

Fraccion fraccion_multiplicar(Fraccion a, Fraccion b) {
    /* TODO: Multiplicar dos fracciones
     * Hint: nuevo_num = a.num * b.num
     * Hint: nuevo_den = a.den * b.den
     * Hint: retorna fraccion_crear(nuevo_num, nuevo_den) para simplificar */
    Fraccion f = {0, 1};
    return f;
}

void fraccion_imprimir(Fraccion f) {
    /* TODO: Imprimir fracción en formato "num/den"
     * Hint: usa printf("%d/%d", f.num, f.den) */
}

/* ---------- PROGRAMA PRINCIPAL (NO MODIFICAR) ---------- */

int main(void) {
    printf("=== STRUCT FRACCION ===\n\n");

    /* Test crear y simplificar */
    printf("--- Crear y simplificar ---\n");
    Fraccion f1 = fraccion_crear(4, 6);
    printf("Crear 4/6 = "); fraccion_imprimir(f1); printf(" (esperado: 2/3)\n");

    Fraccion f2 = fraccion_crear(6, 9);
    printf("Crear 6/9 = "); fraccion_imprimir(f2); printf(" (esperado: 2/3)\n");

    Fraccion f3 = fraccion_crear(3, -4);
    printf("Crear 3/-4 = "); fraccion_imprimir(f3); printf(" (esperado: -3/4)\n\n");

    /* Test sumar */
    printf("--- Suma ---\n");
    Fraccion a = fraccion_crear(1, 2);
    Fraccion b = fraccion_crear(1, 3);
    Fraccion suma = fraccion_sumar(a, b);
    printf("1/2 + 1/3 = "); fraccion_imprimir(suma); printf(" (esperado: 5/6)\n");

    Fraccion c = fraccion_crear(1, 4);
    Fraccion d = fraccion_crear(1, 4);
    Fraccion suma2 = fraccion_sumar(c, d);
    printf("1/4 + 1/4 = "); fraccion_imprimir(suma2); printf(" (esperado: 1/2)\n\n");

    /* Test multiplicar */
    printf("--- Multiplicacion ---\n");
    Fraccion e = fraccion_crear(2, 3);
    Fraccion f = fraccion_crear(3, 4);
    Fraccion prod = fraccion_multiplicar(e, f);
    printf("2/3 * 3/4 = "); fraccion_imprimir(prod); printf(" (esperado: 1/2)\n");

    Fraccion g = fraccion_crear(5, 7);
    Fraccion h = fraccion_crear(7, 10);
    Fraccion prod2 = fraccion_multiplicar(g, h);
    printf("5/7 * 7/10 = "); fraccion_imprimir(prod2); printf(" (esperado: 1/2)\n");

    return 0;
}
