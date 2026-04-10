/*
 * ============================================================================
 * CURSO:      Estructuras de Datos (EIN423-B)
 * UNIVERSIDAD: Universidad Técnica Federico Santa María
 * TEMA:       Lista Doblemente Enlazada
 * ESTUDIANTE: [Tu nombre aquí]
 * ============================================================================
 *
 * ENUNCIADO:
 * ----------
 * Implementa una lista doblemente enlazada con punteros cabeza y cola.
 * Cada nodo tiene punteros 'anterior' y 'siguiente'.
 * El puntero 'cola' permite push_back en O(1).
 *
 * 1) ListaDoble listad_crear()
 *    - Retorna lista vacía (cabeza=NULL, cola=NULL, tamanio=0).
 *
 * 2) void listad_push_front(ListaDoble *l, int valor)
 *    - Inserta al inicio. Actualiza cabeza y, si vacía, también cola.
 *
 * 3) void listad_push_back(ListaDoble *l, int valor)
 *    - Inserta al final en O(1). Actualiza cola y, si vacía, también cabeza.
 *
 * 4) int listad_pop_front(ListaDoble *l)
 *    - Elimina del inicio. Retorna valor o -1 si vacía.
 *
 * 5) int listad_pop_back(ListaDoble *l)
 *    - Elimina del final. Retorna valor o -1 si vacía.
 *
 * 6) void listad_insertar_ordenado(ListaDoble *l, int valor)
 *    - Inserta manteniendo orden ascendente.
 *
 * 7) int listad_eliminar(ListaDoble *l, int valor)
 *    - Elimina primera ocurrencia. Retorna 1 si eliminó, 0 si no.
 *
 * 8) void listad_imprimir_adelante(ListaDoble *l)
 *    - Imprime de cabeza a cola: [1] <-> [2] <-> [3] <-> NULL
 *
 * 9) void listad_imprimir_atras(ListaDoble *l)
 *    - Imprime de cola a cabeza: [3] <-> [2] <-> [1] <-> NULL
 *
 * 10) void listad_destruir(ListaDoble *l)
 *     - Libera todos los nodos.
 *
 * SALIDA ESPERADA:
 *   push_back(1,2,3,4,5): [1] <-> [2] <-> [3] <-> [4] <-> [5] <-> NULL
 *   insertar_ordenado(5,3,1,4,2): [1] <-> [2] <-> [3] <-> [4] <-> [5] <-> NULL
 *   pop_back x3: queda [1] <-> [2] <-> NULL
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/* ---------- ESTRUCTURAS ---------- */

typedef struct NodoD {
    int dato;
    struct NodoD *anterior;
    struct NodoD *siguiente;
} NodoD;

typedef struct {
    NodoD *cabeza;
    NodoD *cola;
    int tamanio;
} ListaDoble;

/* ---------- FUNCIONES A IMPLEMENTAR ---------- */

ListaDoble listad_crear(void) {
    /* TODO: Inicializar lista vacía
     * Hint: cabeza=NULL, cola=NULL, tamanio=0 */
    ListaDoble l = {NULL, NULL, 0};
    return l;
}

void listad_push_front(ListaDoble *l, int valor) {
    /* TODO: Crear nodo. nuevo->anterior=NULL, nuevo->siguiente=cabeza.
     * Si hay cabeza: cabeza->anterior=nuevo. Si no: cola=nuevo.
     * cabeza=nuevo. tamanio++. */
}

void listad_push_back(ListaDoble *l, int valor) {
    /* TODO: Crear nodo. nuevo->siguiente=NULL, nuevo->anterior=cola.
     * Si hay cola: cola->siguiente=nuevo. Si no: cabeza=nuevo.
     * cola=nuevo. tamanio++. */
}

int listad_pop_front(ListaDoble *l) {
    /* TODO: Si vacía retorna -1.
     * Guarda dato, avanza cabeza. Si nueva cabeza existe: cabeza->anterior=NULL.
     * Si no: cola=NULL. Libera nodo. tamanio--. */
    return -1;
}

int listad_pop_back(ListaDoble *l) {
    /* TODO: Si vacía retorna -1.
     * Guarda dato, retrocede cola. Si nueva cola existe: cola->siguiente=NULL.
     * Si no: cabeza=NULL. Libera nodo. tamanio--. */
    return -1;
}

void listad_insertar_ordenado(ListaDoble *l, int valor) {
    /* TODO: Si vacía o valor <= cabeza->dato: push_front.
     * Si valor >= cola->dato: push_back.
     * Si no: recorrer hasta encontrar nodo con dato >= valor, insertar antes. */
}

int listad_eliminar(ListaDoble *l, int valor) {
    /* TODO: Buscar nodo con el valor.
     * Si es cabeza: pop_front. Si es cola: pop_back.
     * Si está en medio: desenlazar actualizando anterior->siguiente y siguiente->anterior.
     * Liberar nodo. tamanio--. Retorna 1 si eliminó, 0 si no encontró. */
    return 0;
}

void listad_imprimir_adelante(ListaDoble *l) {
    /* TODO: Recorrer desde cabeza imprimiendo [dato] <-> ... <-> NULL */
    printf("[lista vacia]\n");
}

void listad_imprimir_atras(ListaDoble *l) {
    /* TODO: Recorrer desde cola hacia atrás imprimiendo [dato] <-> ... <-> NULL */
    printf("[lista vacia]\n");
}

void listad_destruir(ListaDoble *l) {
    /* TODO: Liberar todos los nodos desde cabeza.
     * Hint: guardar siguiente antes de free.
     * Poner cabeza=cola=NULL, tamanio=0. */
}

/* ---------- PROGRAMA PRINCIPAL (NO MODIFICAR) ---------- */

int main(void) {
    printf("=== LISTA DOBLEMENTE ENLAZADA ===\n\n");

    /* Test push_back */
    printf("--- push_back 1,2,3,4,5 ---\n");
    ListaDoble l = listad_crear();
    for (int i = 1; i <= 5; i++) listad_push_back(&l, i);
    printf("Adelante: "); listad_imprimir_adelante(&l);
    printf("Atras:    "); listad_imprimir_atras(&l);
    printf("Tamanio: %d (esperado: 5)\n\n", l.tamanio);

    /* Test insertar ordenado */
    printf("--- insertar_ordenado: 5,3,1,4,2 ---\n");
    ListaDoble l2 = listad_crear();
    listad_insertar_ordenado(&l2, 5);
    listad_insertar_ordenado(&l2, 3);
    listad_insertar_ordenado(&l2, 1);
    listad_insertar_ordenado(&l2, 4);
    listad_insertar_ordenado(&l2, 2);
    printf("Resultado: "); listad_imprimir_adelante(&l2);
    printf("Tamanio: %d (esperado: 5)\n\n", l2.tamanio);

    /* Test pop_back */
    printf("--- pop_back x3 en lista ordenada ---\n");
    printf("pop_back: %d (esperado: 5)\n", listad_pop_back(&l2));
    printf("pop_back: %d (esperado: 4)\n", listad_pop_back(&l2));
    printf("pop_back: %d (esperado: 3)\n", listad_pop_back(&l2));
    printf("Resultado: "); listad_imprimir_adelante(&l2);
    printf("Tamanio: %d (esperado: 2)\n\n", l2.tamanio);

    /* Test eliminar */
    printf("--- eliminar 3 en lista original ---\n");
    printf("Antes:   "); listad_imprimir_adelante(&l);
    int ok = listad_eliminar(&l, 3);
    printf("Eliminar 3: %d (esperado: 1)\n", ok);
    printf("Despues: "); listad_imprimir_adelante(&l);
    printf("Tamanio: %d (esperado: 4)\n\n", l.tamanio);

    /* Test pop_front */
    printf("--- pop_front ---\n");
    printf("pop_front: %d (esperado: 1)\n", listad_pop_front(&l));
    printf("Resultado: "); listad_imprimir_adelante(&l);

    listad_destruir(&l);
    listad_destruir(&l2);
    printf("\nListas destruidas.\n");

    return 0;
}
