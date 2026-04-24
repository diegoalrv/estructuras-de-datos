/*
 * ============================================================================
 * CURSO:      Estructuras de Datos (EIN423-B)
 * UNIVERSIDAD: Universidad Técnica Federico Santa María
 * TEMA:       Lista Enlazada Simple — SOLUCION
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo *siguiente;
} Nodo;

typedef struct {
    Nodo *cabeza;
    int tamanio;
} Lista;

/* ---------- SOLUCIONES ---------- */

Lista lista_crear(void) {
    Lista l;
    l.cabeza = NULL;
    l.tamanio = 0;
    return l;
}

void lista_push_front(Lista *l, int valor) {
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    if (!nuevo) { fprintf(stderr, "Error: malloc\n"); return; }
    nuevo->dato = valor;
    nuevo->siguiente = l->cabeza;
    l->cabeza = nuevo;
    l->tamanio++;
}

void lista_push_back(Lista *l, int valor) {
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    if (!nuevo) { fprintf(stderr, "Error: malloc\n"); return; }
    nuevo->dato = valor;
    nuevo->siguiente = NULL;

    if (l->cabeza == NULL) {
        l->cabeza = nuevo;
    } else {
        Nodo *actual = l->cabeza;
        while (actual->siguiente != NULL)
            actual = actual->siguiente;
        actual->siguiente = nuevo;
    }
    l->tamanio++;
}

int lista_pop_front(Lista *l) {
    if (l->cabeza == NULL) return -1;
    Nodo *temp = l->cabeza;
    int val = temp->dato;
    l->cabeza = temp->siguiente;
    free(temp);
    l->tamanio--;
    return val;
}

int lista_buscar(Lista *l, int valor) {
    int idx = 0;
    Nodo *actual = l->cabeza;
    while (actual != NULL) {
        if (actual->dato == valor) return idx;
        actual = actual->siguiente;
        idx++;
    }
    return -1;
}

int lista_obtener(Lista *l, int idx) {
    if (idx < 0 || idx >= l->tamanio) return -1;
    Nodo *actual = l->cabeza;
    for (int i = 0; i < idx; i++)
        actual = actual->siguiente;
    return actual->dato;
}

int lista_eliminar(Lista *l, int valor) {
    if (l->cabeza == NULL) return 0;

    /* Caso especial: es la cabeza */
    if (l->cabeza->dato == valor) {
        Nodo *temp = l->cabeza;
        l->cabeza = temp->siguiente;
        free(temp);
        l->tamanio--;
        return 1;
    }

    /* Buscar en el resto */
    Nodo *anterior = l->cabeza;
    Nodo *actual = l->cabeza->siguiente;
    while (actual != NULL) {
        if (actual->dato == valor) {
            anterior->siguiente = actual->siguiente;
            free(actual);
            l->tamanio--;
            return 1;
        }
        anterior = actual;
        actual = actual->siguiente;
    }
    return 0;
}

void lista_invertir(Lista *l) {
    Nodo *anterior = NULL;
    Nodo *actual = l->cabeza;
    Nodo *siguiente = NULL;
    while (actual != NULL) {
        siguiente = actual->siguiente;
        actual->siguiente = anterior;
        anterior = actual;
        actual = siguiente;
    }
    l->cabeza = anterior;
}

void lista_imprimir(Lista *l) {
    Nodo *actual = l->cabeza;
    while (actual != NULL) {
        printf("[%d] -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

void lista_destruir(Lista *l) {
    Nodo *actual = l->cabeza;
    while (actual != NULL) {
        Nodo *tmp = actual;
        actual = actual->siguiente;
        free(tmp);
    }
    l->cabeza = NULL;
    l->tamanio = 0;
}

/* ---------- PROGRAMA PRINCIPAL ---------- */

int main(void) {
    printf("=== LISTA ENLAZADA SIMPLE ===\n\n");

    Lista l = lista_crear();

    printf("--- Insertar ---\n");
    lista_push_front(&l, 3);
    lista_push_front(&l, 2);
    lista_push_front(&l, 1);
    lista_push_back(&l, 4);
    lista_push_back(&l, 5);
    printf("Despues de push_front(3,2,1) y push_back(4,5):\n");
    lista_imprimir(&l);
    printf("Tamanio: %d (esperado: 5)\n\n", l.tamanio);

    printf("--- Buscar y Obtener ---\n");
    printf("Buscar 3:  indice %d (esperado: 2)\n", lista_buscar(&l, 3));
    printf("Buscar 99: indice %d (esperado: -1)\n", lista_buscar(&l, 99));
    printf("Obtener[0]: %d (esperado: 1)\n", lista_obtener(&l, 0));
    printf("Obtener[4]: %d (esperado: 5)\n\n", lista_obtener(&l, 4));

    printf("--- Pop front ---\n");
    int val = lista_pop_front(&l);
    printf("pop_front: %d (esperado: 1)\n", val);
    lista_imprimir(&l);
    printf("Tamanio: %d (esperado: 4)\n\n", l.tamanio);

    printf("--- Eliminar ---\n");
    int ok = lista_eliminar(&l, 3);
    printf("Eliminar 3: %d (esperado: 1)\n", ok);
    lista_imprimir(&l);
    printf("Tamanio: %d (esperado: 3)\n\n", l.tamanio);

    printf("--- Invertir ---\n");
    printf("Antes:   "); lista_imprimir(&l);
    lista_invertir(&l);
    printf("Despues: "); lista_imprimir(&l);

    lista_destruir(&l);
    printf("\nLista destruida.\n");

    return 0;
}
