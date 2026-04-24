/*
 * ============================================================================
 * CURSO:      Estructuras de Datos (EIN423-B)
 * UNIVERSIDAD: Universidad Técnica Federico Santa María
 * TEMA:       Estructuras de Datos — struct Fraccion — SOLUCION
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num;
    int den;
} Fraccion;

/* ---------- SOLUCIONES ---------- */

int mcd(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b != 0) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

Fraccion fraccion_crear(int num, int den) {
    Fraccion f;
    
    // f.num = num;
    // f.den = den;

    if (den == 0) {
        printf("Error: denominador no puede ser 0\n");
        f.num = 0;
        f.den = 1;
        return f;
    }
    if (den < 0) {
        num = -num;
        den = -den;
    }
    int g = mcd(num, den);
    f.num = num / g;
    f.den = den / g;
    return f;
}

Fraccion fraccion_sumar(Fraccion a, Fraccion b) {
    int nuevo_num = a.num * b.den + b.num * a.den;
    int nuevo_den = a.den * b.den;
    return fraccion_crear(nuevo_num, nuevo_den);
}

Fraccion fraccion_multiplicar(Fraccion a, Fraccion b) {
    int nuevo_num = a.num * b.num;
    int nuevo_den = a.den * b.den;
    return fraccion_crear(nuevo_num, nuevo_den);
}

void fraccion_imprimir(Fraccion f) {
    printf("%d/%d", f.num, f.den);
}

/* ---------- PROGRAMA PRINCIPAL ---------- */

int main(void) {
    printf("=== STRUCT FRACCION ===\n\n");

    printf("--- Crear y simplificar ---\n");
    Fraccion f1 = fraccion_crear(4, 6);
    printf("Crear 4/6 = "); fraccion_imprimir(f1); printf(" (esperado: 2/3)\n");

    Fraccion f2 = fraccion_crear(6, 9);
    printf("Crear 6/9 = "); fraccion_imprimir(f2); printf(" (esperado: 2/3)\n");

    Fraccion f3 = fraccion_crear(3, -4);
    printf("Crear 3/-4 = "); fraccion_imprimir(f3); printf(" (esperado: -3/4)\n\n");

    printf("--- Suma ---\n");
    Fraccion a = fraccion_crear(1, 2);
    Fraccion b = fraccion_crear(1, 3);
    Fraccion suma = fraccion_sumar(a, b);
    printf("1/2 + 1/3 = "); fraccion_imprimir(suma); printf(" (esperado: 5/6)\n");

    Fraccion c = fraccion_crear(1, 4);
    Fraccion d = fraccion_crear(1, 4);
    Fraccion suma2 = fraccion_sumar(c, d);
    printf("1/4 + 1/4 = "); fraccion_imprimir(suma2); printf(" (esperado: 1/2)\n\n");

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
