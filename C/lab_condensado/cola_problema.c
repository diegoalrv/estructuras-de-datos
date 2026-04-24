/*
 * ============================================================================
 * CURSO:      Estructuras de Datos (EIN423-B)
 * UNIVERSIDAD: Universidad Técnica Federico Santa María
 * TEMA:       Cola (Queue) — FIFO
 * ESTUDIANTE: [Tu nombre aquí]
 * ============================================================================
 *
 * ENUNCIADO:
 * ----------
 * Implementa una Cola (Queue) usando un arreglo circular de tamaño MAX=100.
 * La cola sigue el principio FIFO (First In, First Out).
 *
 * Un arreglo circular usa dos índices: 'frente' y 'final'.
 * - enqueue: inserta en 'final', luego final = (final + 1) % MAX
 * - dequeue: extrae de 'frente', luego frente = (frente + 1) % MAX
 * - El campo 'cantidad' lleva la cuenta de elementos.
 *
 * 1) Cola cola_crear()
 *    - Retorna cola vacía (frente=0, final=0, cantidad=0).
 *
 * 2) void cola_enqueue(Cola *c, int valor)
 *    - Encola un valor. Si está llena, imprime error.
 *
 * 3) int cola_dequeue(Cola *c)
 *    - Desencola y retorna el valor del frente. Si está vacía, retorna -1.
 *
 * 4) int cola_frente(Cola *c)
 *    - Retorna el valor del frente SIN desencolar. Si vacía, retorna -1.
 *
 * 5) int cola_esta_vacia(Cola *c)
 *    - Retorna 1 si cantidad == 0, 0 si no.
 *
 * 6) int cola_esta_llena(Cola *c)
 *    - Retorna 1 si cantidad == MAX, 0 si no.
 *
 * APLICACION: Simular una cola de atención con N clientes.
 *    - Encolar clientes 1..N
 *    - Desencolar y "atender" cada uno, imprimiendo el orden de atención.
 *
 * SALIDA ESPERADA:
 *   enqueue 10,20,30 → frente=10
 *   dequeue → 10, dequeue → 20
 *   Simulación: Atendiendo cliente 1, 2, 3, ..., 8
 * ============================================================================
 */

#include <stdio.h>

#define MAX_COLA 100

/* ---------- ESTRUCTURA ---------- */

typedef struct {
    int elementos[MAX_COLA];
    int frente;
    int final;
    int cantidad;
} Cola;

/* ---------- FUNCIONES A IMPLEMENTAR ---------- */

Cola cola_crear(void) {
    /* TODO: Inicializar cola vacía
     * Hint: frente=0, final=0, cantidad=0 */
    Cola c;
    c.frente = 0;
    c.final = 0;
    c.cantidad = 0;
    return c;
}

void cola_enqueue(Cola *c, int valor) {
    /* TODO: Si llena, imprimir error y retornar.
     * Si no: c->elementos[c->final] = valor;
     *        c->final = (c->final + 1) % MAX_COLA;
     *        c->cantidad++; */
}

int cola_dequeue(Cola *c) {
    /* TODO: Si vacía, retorna -1.
     * Si no: int val = c->elementos[c->frente];
     *        c->frente = (c->frente + 1) % MAX_COLA;
     *        c->cantidad--;
     *        retorna val; */
    return -1;
}

int cola_frente(Cola *c) {
    /* TODO: Si vacía, retorna -1.
     * Si no: retorna c->elementos[c->frente]; */
    return -1;
}

int cola_esta_vacia(Cola *c) {
    /* TODO: Retorna 1 si cantidad == 0, 0 si no */
    return 1;
}

int cola_esta_llena(Cola *c) {
    /* TODO: Retorna 1 si cantidad == MAX_COLA, 0 si no */
    return 0;
}

/* ---------- PROGRAMA PRINCIPAL (NO MODIFICAR) ---------- */

int main(void) {
    printf("=== COLA (QUEUE) ===\n\n");

    /* Test básico */
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

    /* Simulación de atención */
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
