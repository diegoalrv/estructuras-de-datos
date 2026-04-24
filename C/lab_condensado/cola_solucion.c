/*
 * ============================================================================
 * CURSO:      Estructuras de Datos (EIN423-B)
 * UNIVERSIDAD: Universidad Técnica Federico Santa María
 * TEMA:       Cola (Queue) — FIFO — SOLUCION
 * ============================================================================
 */

#include <stdio.h>

#define MAX_COLA 100

typedef struct {
    int elementos[MAX_COLA];
    int frente;
    int final;
    int cantidad;
} Cola;

/* ---------- SOLUCIONES ---------- */

Cola cola_crear(void) {
    Cola c;
    c.frente = 0;
    c.final = 0;
    c.cantidad = 0;
    return c;
}

void cola_enqueue(Cola *c, int valor) {
    if (c->cantidad == MAX_COLA) {
        printf("Error: cola llena\n");
        return;
    }
    c->elementos[c->final] = valor;
    c->final = (c->final + 1) % MAX_COLA;
    c->cantidad++;
}

int cola_dequeue(Cola *c) {
    if (c->cantidad == 0) return -1;
    int val = c->elementos[c->frente];
    c->frente = (c->frente + 1) % MAX_COLA;
    c->cantidad--;
    return val;
}

int cola_frente(Cola *c) {
    if (c->cantidad == 0) return -1;
    return c->elementos[c->frente];
}

int cola_esta_vacia(Cola *c) {
    return c->cantidad == 0;
}

int cola_esta_llena(Cola *c) {
    return c->cantidad == MAX_COLA;
}

/* ---------- PROGRAMA PRINCIPAL ---------- */

int main(void) {
    printf("=== COLA (QUEUE) ===\n\n");

    printf("--- Operaciones basicas ---\n");
    Cola c = cola_crear();
    printf("Cola vacia? %d (esperado: 1)\n", cola_esta_vacia(&c));

    cola_enqueue(&c, 10);
    cola_enqueue(&c, 20);
    cola_enqueue(&c, 30);
    printf("Frente: %d (esperado: 10)\n", cola_frente(&c));
    printf("Cola vacia? %d (esperado: 0)\n\n", cola_esta_vacia(&c));

    printf("--- Dequeue ---\n");
    printf("Dequeue: %d (esperado: 10)\n", cola_dequeue(&c));
    printf("Dequeue: %d (esperado: 20)\n", cola_dequeue(&c));
    printf("Frente ahora: %d (esperado: 30)\n", cola_frente(&c));
    printf("Dequeue: %d (esperado: 30)\n", cola_dequeue(&c));
    printf("Cola vacia? %d (esperado: 1)\n", cola_esta_vacia(&c));
    printf("Dequeue en vacia: %d (esperado: -1)\n\n", cola_dequeue(&c));

    printf("--- Simulacion: Cola de atencion ---\n");
    Cola atencion = cola_crear();
    int num_clientes = 8;
    printf("Encolando %d clientes...\n", num_clientes);
    for (int i = 1; i <= num_clientes; i++) {
        cola_enqueue(&atencion, i);
    }

    printf("Atendiendo:\n");
    int turno = 1;
    while (!cola_esta_vacia(&atencion)) {
        int cliente = cola_dequeue(&atencion);
        printf("  Turno %d: Cliente %d\n", turno, cliente);
        turno++;
    }
    printf("Todos los clientes atendidos.\n");

    return 0;
}
