/*
 * ============================================================================
 * CURSO:      Estructuras de Datos (EIN423-B)
 * UNIVERSIDAD: Universidad Técnica Federico Santa María
 * TEMA:       Lista Doblemente Enlazada — SOLUCION
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

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

/* ---------- SOLUCIONES ---------- */

ListaDoble listad_crear(void) {
    ListaDoble l;
    l.cabeza = NULL;
    l.cola = NULL;
    l.tamanio = 0;
    return l;
}

void listad_push_front(ListaDoble *l, int valor) {
    NodoD *nuevo = (NodoD *)malloc(sizeof(NodoD));
    if (!nuevo) { fprintf(stderr, "Error: malloc\n"); return; }
    nuevo->dato = valor;
    nuevo->anterior = NULL;
    nuevo->siguiente = l->cabeza;

    if (l->cabeza != NULL)
        l->cabeza->anterior = nuevo;
    else
        l->cola = nuevo;

    l->cabeza = nuevo;
    l->tamanio++;
}

void listad_push_back(ListaDoble *l, int valor) {
    NodoD *nuevo = (NodoD *)malloc(sizeof(NodoD));
    if (!nuevo) { fprintf(stderr, "Error: malloc\n"); return; }
    nuevo->dato = valor;
    nuevo->siguiente = NULL;
    nuevo->anterior = l->cola;

    if (l->cola != NULL)
        l->cola->siguiente = nuevo;
    else
        l->cabeza = nuevo;

    l->cola = nuevo;
    l->tamanio++;
}

int listad_pop_front(ListaDoble *l) {
    if (l->cabeza == NULL) return -1;
    NodoD *temp = l->cabeza;
    int val = temp->dato;
    l->cabeza = temp->siguiente;

    if (l->cabeza != NULL)
        l->cabeza->anterior = NULL;
    else
        l->cola = NULL;

    free(temp);
    l->tamanio--;
    return val;
}

int listad_pop_back(ListaDoble *l) {
    if (l->cola == NULL) return -1;
    NodoD *temp = l->cola;
    int val = temp->dato;
    l->cola = temp->anterior;

    if (l->cola != NULL)
        l->cola->siguiente = NULL;
    else
        l->cabeza = NULL;

    free(temp);
    l->tamanio--;
    return val;
}

void listad_insertar_ordenado(ListaDoble *l, int valor) {
    /* Lista vacía o valor <= cabeza */
    if (l->cabeza == NULL || valor <= l->cabeza->dato) {
        listad_push_front(l, valor);
        return;
    }
    /* Valor >= cola */
    if (valor >= l->cola->dato) {
        listad_push_back(l, valor);
        return;
    }
    /* Buscar posición en el medio */
    NodoD *actual = l->cabeza->siguiente;
    while (actual != NULL && actual->dato < valor)
        actual = actual->siguiente;

    /* Insertar antes de 'actual' */
    NodoD *nuevo = (NodoD *)malloc(sizeof(NodoD));
    if (!nuevo) { fprintf(stderr, "Error: malloc\n"); return; }
    nuevo->dato = valor;
    nuevo->siguiente = actual;
    nuevo->anterior = actual->anterior;
    actual->anterior->siguiente = nuevo;
    actual->anterior = nuevo;
    l->tamanio++;
}

int listad_eliminar(ListaDoble *l, int valor) {
    if (l->cabeza == NULL) return 0;

    /* Buscar el nodo */
    NodoD *actual = l->cabeza;
    while (actual != NULL && actual->dato != valor)
        actual = actual->siguiente;

    if (actual == NULL) return 0; /* No encontrado */

    /* Es la cabeza */
    if (actual == l->cabeza) {
        listad_pop_front(l);
        return 1;
    }
    /* Es la cola */
    if (actual == l->cola) {
        listad_pop_back(l);
        return 1;
    }
    /* Está en el medio */
    actual->anterior->siguiente = actual->siguiente;
    actual->siguiente->anterior = actual->anterior;
    free(actual);
    l->tamanio--;
    return 1;
}

void listad_imprimir_adelante(ListaDoble *l) {
    NodoD *actual = l->cabeza;
    while (actual != NULL) {
        printf("[%d] <-> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

void listad_imprimir_atras(ListaDoble *l) {
    NodoD *actual = l->cola;
    while (actual != NULL) {
        printf("[%d] <-> ", actual->dato);
        actual = actual->anterior;
    }
    printf("NULL\n");
}

void listad_destruir(ListaDoble *l) {
    NodoD *actual = l->cabeza;
    while (actual != NULL) {
        NodoD *tmp = actual;
        actual = actual->siguiente;
        free(tmp);
    }
    l->cabeza = NULL;
    l->cola = NULL;
    l->tamanio = 0;
}

/* ---------- PROGRAMA PRINCIPAL ---------- */

int main(void) {
    printf("=== LISTA DOBLEMENTE ENLAZADA ===\n\n");

    printf("--- push_back 1,2,3,4,5 ---\n");
    ListaDoble l = listad_crear();
    for (int i = 1; i <= 5; i++) listad_push_back(&l, i);
    printf("Adelante: "); listad_imprimir_adelante(&l);
    printf("Atras:    "); listad_imprimir_atras(&l);
    printf("Tamanio: %d (esperado: 5)\n\n", l.tamanio);

    printf("--- insertar_ordenado: 5,3,1,4,2 ---\n");
    ListaDoble l2 = listad_crear();
    listad_insertar_ordenado(&l2, 5);
    listad_insertar_ordenado(&l2, 3);
    listad_insertar_ordenado(&l2, 1);
    listad_insertar_ordenado(&l2, 4);
    listad_insertar_ordenado(&l2, 2);
    printf("Resultado: "); listad_imprimir_adelante(&l2);
    printf("Tamanio: %d (esperado: 5)\n\n", l2.tamanio);

    printf("--- pop_back x3 en lista ordenada ---\n");
    printf("pop_back: %d (esperado: 5)\n", listad_pop_back(&l2));
    printf("pop_back: %d (esperado: 4)\n", listad_pop_back(&l2));
    printf("pop_back: %d (esperado: 3)\n", listad_pop_back(&l2));
    printf("Resultado: "); listad_imprimir_adelante(&l2);
    printf("Tamanio: %d (esperado: 2)\n\n", l2.tamanio);

    printf("--- eliminar 3 en lista original ---\n");
    printf("Antes:   "); listad_imprimir_adelante(&l);
    int ok = listad_eliminar(&l, 3);
    printf("Eliminar 3: %d (esperado: 1)\n", ok);
    printf("Despues: "); listad_imprimir_adelante(&l);
    printf("Tamanio: %d (esperado: 4)\n\n", l.tamanio);

    printf("--- pop_front ---\n");
    printf("pop_front: %d (esperado: 1)\n", listad_pop_front(&l));
    printf("Resultado: "); listad_imprimir_adelante(&l);

    listad_destruir(&l);
    listad_destruir(&l2);
    printf("\nListas destruidas.\n");

    return 0;
}
