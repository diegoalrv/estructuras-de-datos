/*
 * ============================================================================
 * CURSO:      Estructuras de Datos (EIN423-B)
 * UNIVERSIDAD: Universidad Técnica Federico Santa María
 * TEMA:       Lista Enlazada Simple
 * ESTUDIANTE: [Tu nombre aquí]
 * ============================================================================
 *
 * ENUNCIADO:
 * ----------
 * Implementa una lista enlazada simple con las siguientes operaciones:
 *
 * 1) Lista lista_crear()
 *    - Retorna una lista vacía (cabeza=NULL, tamanio=0).
 *
 * 2) void lista_push_front(Lista *l, int valor)
 *    - Crea un nuevo nodo y lo inserta al inicio de la lista.
 *
 * 3) void lista_push_back(Lista *l, int valor)
 *    - Crea un nuevo nodo y lo inserta al final (recorre hasta el último).
 *
 * 4) int lista_pop_front(Lista *l)
 *    - Elimina el primer nodo y retorna su valor. Retorna -1 si está vacía.
 *
 * 5) int lista_buscar(Lista *l, int valor)
 *    - Retorna el índice (0-based) de la primera ocurrencia, o -1.
 *
 * 6) int lista_obtener(Lista *l, int idx)
 *    - Retorna el valor en el índice dado, o -1 si es inválido.
 *
 * 7) int lista_eliminar(Lista *l, int valor)
 *    - Elimina la primera ocurrencia del valor. Retorna 1 si eliminó, 0 si no.
 *
 * 8) void lista_invertir(Lista *l)
 *    - Invierte la lista in-place usando 3 punteros (anterior, actual, siguiente).
 *
 * 9) void lista_imprimir(Lista *l)
 *    - Imprime en formato: [1] -> [2] -> [3] -> NULL
 *
 * 10) void lista_destruir(Lista *l)
 *     - Libera todos los nodos de la lista.
 *
 * SALIDA ESPERADA:
 *   push_front/push_back: [1] -> [2] -> [3] -> [4] -> [5] -> NULL
 *   buscar(3)=2, obtener(1)=2
 *   pop_front → 1, eliminar(3) → éxito
 *   invertir: [5] -> [4] -> [2] -> NULL
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/* ---------- ESTRUCTURAS ---------- */

typedef struct Nodo {
    int dato;
    struct Nodo *siguiente;
} Nodo;

typedef struct {
    Nodo *cabeza;
    int tamanio;
} Lista;

/* ---------- FUNCIONES A IMPLEMENTAR ---------- */

Lista lista_crear(void) {
    /* TODO: Inicializar lista vacía
     * Hint: cabeza = NULL, tamanio = 0 */
    Lista l = {NULL, 0};
    return l;
}

void lista_push_front(Lista *l, int valor) {
    /* TODO: Crear nuevo nodo, apuntarlo a la cabeza actual, actualizar cabeza
     * Hint: Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
     * Hint: nuevo->dato = valor; nuevo->siguiente = l->cabeza;
     * Hint: l->cabeza = nuevo; l->tamanio++; */
}

void lista_push_back(Lista *l, int valor) {
    /* TODO: Si lista vacía, es como push_front.
     * Si no, recorrer hasta el último nodo y enlazar el nuevo.
     * Hint: Nodo *actual = l->cabeza;
     * Hint: while(actual->siguiente != NULL) actual = actual->siguiente;
     * Hint: actual->siguiente = nuevo; */
}

int lista_pop_front(Lista *l) {
    /* TODO: Si vacía retorna -1.
     * Guarda dato de cabeza, avanza cabeza, libera nodo antiguo.
     * Hint: Nodo *temp = l->cabeza; int val = temp->dato;
     * Hint: l->cabeza = temp->siguiente; free(temp); l->tamanio--; */
    return -1;
}

int lista_buscar(Lista *l, int valor) {
    /* TODO: Recorrer contando índice, retornar cuando encuentre, -1 si no.
     * Hint: int idx = 0; Nodo *act = l->cabeza;
     * Hint: while(act) { if(act->dato==valor) return idx; act=act->siguiente; idx++; } */
    return -1;
}

int lista_obtener(Lista *l, int idx) {
    /* TODO: Validar 0 <= idx < tamanio. Recorrer idx pasos y retornar dato.
     * Hint: Nodo *act = l->cabeza; for(int i=0; i<idx; i++) act=act->siguiente; */
    return -1;
}

int lista_eliminar(Lista *l, int valor) {
    /* TODO: Buscar nodo con el valor. Desenlazar y liberar.
     * Hint: caso especial si es la cabeza.
     * Hint: si no, usar puntero 'anterior' para desenlazar. */
    return 0;
}

void lista_invertir(Lista *l) {
    /* TODO: Usar 3 punteros: anterior=NULL, actual=cabeza, siguiente.
     * En cada paso: siguiente=actual->siguiente, actual->siguiente=anterior,
     * anterior=actual, actual=siguiente.
     * Al final: l->cabeza = anterior. */
}

void lista_imprimir(Lista *l) {
    /* TODO: Recorrer e imprimir cada nodo en formato [dato] -> ... -> NULL
     * Hint: Nodo *act = l->cabeza;
     * Hint: while(act) { printf("[%d] -> ", act->dato); act=act->siguiente; }
     * Hint: printf("NULL\n"); */
    printf("[lista vacia]\n");
}

void lista_destruir(Lista *l) {
    /* TODO: Liberar todos los nodos.
     * Hint: Nodo *act = l->cabeza;
     * Hint: while(act) { Nodo *tmp=act; act=act->siguiente; free(tmp); }
     * Hint: l->cabeza=NULL; l->tamanio=0; */
}

/* ---------- PROGRAMA PRINCIPAL (NO MODIFICAR) ---------- */

int main(void) {
    printf("=== LISTA ENLAZADA SIMPLE ===\n\n");

    Lista l = lista_crear();

    /* Insertar */
    printf("--- Insertar ---\n");
    lista_push_front(&l, 3);
    lista_push_front(&l, 2);
    lista_push_front(&l, 1);
    lista_push_back(&l, 4);
    lista_push_back(&l, 5);
    printf("Despues de push_front(3,2,1) y push_back(4,5):\n");
    lista_imprimir(&l);
    printf("Tamanio: %d (esperado: 5)\n\n", l.tamanio);

    /* Buscar y obtener */
    printf("--- Buscar y Obtener ---\n");
    printf("Buscar 3:  indice %d (esperado: 2)\n", lista_buscar(&l, 3));
    printf("Buscar 99: indice %d (esperado: -1)\n", lista_buscar(&l, 99));
    printf("Obtener[0]: %d (esperado: 1)\n", lista_obtener(&l, 0));
    printf("Obtener[4]: %d (esperado: 5)\n\n", lista_obtener(&l, 4));

    /* Pop front */
    printf("--- Pop front ---\n");
    int val = lista_pop_front(&l);
    printf("pop_front: %d (esperado: 1)\n", val);
    lista_imprimir(&l);
    printf("Tamanio: %d (esperado: 4)\n\n", l.tamanio);

    /* Eliminar */
    printf("--- Eliminar ---\n");
    int ok = lista_eliminar(&l, 3);
    printf("Eliminar 3: %d (esperado: 1)\n", ok);
    lista_imprimir(&l);
    printf("Tamanio: %d (esperado: 3)\n\n", l.tamanio);

    /* Invertir */
    printf("--- Invertir ---\n");
    printf("Antes:   "); lista_imprimir(&l);
    lista_invertir(&l);
    printf("Despues: "); lista_imprimir(&l);

    /* Destruir */
    lista_destruir(&l);
    printf("\nLista destruida.\n");

    return 0;
}
