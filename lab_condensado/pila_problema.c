/*
 * ============================================================================
 * CURSO:      Estructuras de Datos (EIN423-B)
 * UNIVERSIDAD: Universidad Técnica Federico Santa María
 * TEMA:       Pila (Stack) — LIFO
 * ESTUDIANTE: [Tu nombre aquí]
 * ============================================================================
 *
 * ENUNCIADO:
 * ----------
 * Implementa una Pila (Stack) usando un arreglo estático de tamaño MAX=100.
 * La pila sigue el principio LIFO (Last In, First Out).
 *
 * 1) Pila pila_crear()
 *    - Retorna una pila vacía (tope = 0).
 *
 * 2) void pila_push(Pila *p, int valor)
 *    - Apila un valor. Si la pila está llena, imprime error.
 *
 * 3) int pila_pop(Pila *p)
 *    - Desapila y retorna el valor del tope. Si está vacía, retorna -1.
 *
 * 4) int pila_peek(Pila *p)
 *    - Retorna el valor del tope SIN desapilar. Si está vacía, retorna -1.
 *
 * 5) int pila_esta_vacia(Pila *p)
 *    - Retorna 1 si el tope es 0, 0 en caso contrario.
 *
 * 6) int pila_esta_llena(Pila *p)
 *    - Retorna 1 si el tope es MAX, 0 en caso contrario.
 *
 * APLICACION: int parentesis_balanceados(const char *expr)
 *    - Usa la pila para verificar si los paréntesis (), [], {} están balanceados.
 *    - Retorna 1 si están balanceados, 0 si no.
 *    - Algoritmo:
 *      a) Recorrer cada carácter de la expresión.
 *      b) Si es '(', '[' o '{': apilar.
 *      c) Si es ')', ']' o '}': desapilar y verificar que coincida.
 *      d) Al final, la pila debe estar vacía.
 *
 * SALIDA ESPERADA:
 *   push 10,20,30 → peek=30
 *   pop → 30, pop → 20, pop → 10
 *   "(a+b)" → balanceado
 *   "(()" → NO balanceado
 *   "{[()]}" → balanceado
 * ============================================================================
 */

#include <stdio.h>
#include <string.h>

#define MAX_PILA 100

/* ---------- ESTRUCTURA ---------- */

typedef struct {
    int elementos[MAX_PILA];
    int tope;
} Pila;

/* ---------- FUNCIONES A IMPLEMENTAR ---------- */

Pila pila_crear(void) {
    /* TODO: Inicializar pila vacía con tope = 0 */
    Pila p;
    p.tope = 0;
    return p;
}

void pila_push(Pila *p, int valor) {
    /* TODO: Si la pila está llena, imprimir error y retornar.
     * Si no: p->elementos[p->tope] = valor; p->tope++; */
}

int pila_pop(Pila *p) {
    /* TODO: Si vacía, retorna -1.
     * Si no: p->tope--; retorna p->elementos[p->tope]; */
    return -1;
}

int pila_peek(Pila *p) {
    /* TODO: Si vacía, retorna -1.
     * Si no: retorna p->elementos[p->tope - 1]; */
    return -1;
}

int pila_esta_vacia(Pila *p) {
    /* TODO: Retorna 1 si tope == 0, 0 si no */
    return 1;
}

int pila_esta_llena(Pila *p) {
    /* TODO: Retorna 1 si tope == MAX_PILA, 0 si no */
    return 0;
}

int parentesis_balanceados(const char *expr) {
    /* TODO: Usar una pila para verificar paréntesis balanceados.
     * Hint: recorrer cada char de expr.
     * Hint: si es '(' '[' '{' → push el carácter.
     * Hint: si es ')' ']' '}' → pop y verificar que coincida.
     * Hint: al final, pila debe estar vacía.
     * Retorna 1 si balanceados, 0 si no. */
    return 0;
}

/* ---------- PROGRAMA PRINCIPAL (NO MODIFICAR) ---------- */

int main(void) {
    printf("=== PILA (STACK) ===\n\n");

    /* Test básico */
    printf("--- Operaciones basicas ---\n");
    Pila p = pila_crear();
    printf("Pila vacia? %d (esperado: 1)\n", pila_esta_vacia(&p));

    pila_push(&p, 10);
    pila_push(&p, 20);
    pila_push(&p, 30);
    printf("Peek: %d (esperado: 30)\n", pila_peek(&p));
    printf("Pila vacia? %d (esperado: 0)\n\n", pila_esta_vacia(&p));

    printf("--- Pop ---\n");
    printf("Pop: %d (esperado: 30)\n", pila_pop(&p));
    printf("Pop: %d (esperado: 20)\n", pila_pop(&p));
    printf("Pop: %d (esperado: 10)\n", pila_pop(&p));
    printf("Pila vacia? %d (esperado: 1)\n", pila_esta_vacia(&p));
    printf("Pop en vacia: %d (esperado: -1)\n\n", pila_pop(&p));

    /* Test paréntesis balanceados */
    printf("--- Parentesis balanceados ---\n");
    printf("\"(a+b)\"     → %d (esperado: 1)\n", parentesis_balanceados("(a+b)"));
    printf("\"(()\"       → %d (esperado: 0)\n", parentesis_balanceados("(()"));
    printf("\"{[()]}\"    → %d (esperado: 1)\n", parentesis_balanceados("{[()]}"));
    printf("\"([)]\"      → %d (esperado: 0)\n", parentesis_balanceados("([)]"));
    printf("\"\"          → %d (esperado: 1)\n", parentesis_balanceados(""));
    printf("\"{[(a+b)*c]}\" → %d (esperado: 1)\n", parentesis_balanceados("{[(a+b)*c]}"));

    return 0;
}
