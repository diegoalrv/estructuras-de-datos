/*
 * ============================================================================
 * CURSO:      Estructuras de Datos (EIN423-B)
 * UNIVERSIDAD: Universidad Técnica Federico Santa María
 * TEMA:       Pila (Stack) — LIFO — SOLUCION
 * ============================================================================
 */

#include <stdio.h>
#include <string.h>

#define MAX_PILA 100

typedef struct {
    int elementos[MAX_PILA];
    int tope;
} Pila;

/* ---------- SOLUCIONES ---------- */

Pila pila_crear(void) {
    Pila p;
    p.tope = 0;
    return p;
}

void pila_push(Pila *p, int valor) {
    if (p->tope == MAX_PILA) {
        printf("Error: pila llena\n");
        return;
    }
    p->elementos[p->tope] = valor;
    p->tope++;
}

int pila_pop(Pila *p) {
    if (p->tope == 0) return -1;
    p->tope--;
    return p->elementos[p->tope];
}

int pila_peek(Pila *p) {
    if (p->tope == 0) return -1;
    return p->elementos[p->tope - 1];
}

int pila_esta_vacia(Pila *p) {
    return p->tope == 0;
}

int pila_esta_llena(Pila *p) {
    return p->tope == MAX_PILA;
}

int parentesis_balanceados(const char *expr) {
    Pila p = pila_crear();
    int len = strlen(expr);

    for (int i = 0; i < len; i++) {
        char c = expr[i];

        if (c == '(' || c == '[' || c == '{') {
            pila_push(&p, c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (pila_esta_vacia(&p)) return 0;

            int tope = pila_pop(&p);
            if (c == ')' && tope != '(') return 0;
            if (c == ']' && tope != '[') return 0;
            if (c == '}' && tope != '{') return 0;
        }
    }

    return pila_esta_vacia(&p);
}

/* ---------- PROGRAMA PRINCIPAL ---------- */

int main(void) {
    printf("=== PILA (STACK) ===\n\n");

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

    printf("--- Parentesis balanceados ---\n");
    printf("\"(a+b)\"     -> %d (esperado: 1)\n", parentesis_balanceados("(a+b)"));
    printf("\"(()\"       -> %d (esperado: 0)\n", parentesis_balanceados("(()"));
    printf("\"{[()]}\"    -> %d (esperado: 1)\n", parentesis_balanceados("{[()]}"));
    printf("\"([)]\"      -> %d (esperado: 0)\n", parentesis_balanceados("([)]"));
    printf("\"\"          -> %d (esperado: 1)\n", parentesis_balanceados(""));
    printf("\"{[(a+b)*c]}\" -> %d (esperado: 1)\n", parentesis_balanceados("{[(a+b)*c]}"));

    return 0;
}
