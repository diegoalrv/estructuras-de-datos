/*
 * Estructuras de Datos — EIN423-B
 * Universidad Técnica Federico Santa María
 * Laboratorio 10: Implementación Completa de BST
 *
 * Este archivo contiene la implementación completa de todas las funciones BST.
 * Los estudiantes deben implementar las funciones en arbol_ops.c
 */

#include "bst.h"
#include <limits.h>

NodoBST* bst_insertar(NodoBST *raiz, int clave) {
    if (raiz == NULL) {
        NodoBST *nuevo = (NodoBST *)malloc(sizeof(NodoBST));
        if (nuevo == NULL) {
            fprintf(stderr, "Error: no hay memoria\n");
            exit(EXIT_FAILURE);
        }
        nuevo->clave = clave;
        nuevo->izq = NULL;
        nuevo->der = NULL;
        return nuevo;
    }

    if (clave < raiz->clave) {
        raiz->izq = bst_insertar(raiz->izq, clave);
    } else if (clave > raiz->clave) {
        raiz->der = bst_insertar(raiz->der, clave);
    }
    /* Si clave == raiz->clave, no hacer nada (duplicados se ignoran) */

    return raiz;
}

NodoBST* bst_buscar(NodoBST *raiz, int clave) {
    if (raiz == NULL) {
        return NULL;
    }

    if (clave == raiz->clave) {
        return raiz;
    } else if (clave < raiz->clave) {
        return bst_buscar(raiz->izq, clave);
    } else {
        return bst_buscar(raiz->der, clave);
    }
}

void bst_inorden(const NodoBST *raiz) {
    if (raiz == NULL) {
        return;
    }

    bst_inorden(raiz->izq);
    printf("%d ", raiz->clave);
    bst_inorden(raiz->der);
}

void bst_preorden(const NodoBST *raiz) {
    if (raiz == NULL) {
        return;
    }

    printf("%d ", raiz->clave);
    bst_preorden(raiz->izq);
    bst_preorden(raiz->der);
}

void bst_postorden(const NodoBST *raiz) {
    if (raiz == NULL) {
        return;
    }

    bst_postorden(raiz->izq);
    bst_postorden(raiz->der);
    printf("%d ", raiz->clave);
}

int bst_altura(const NodoBST *raiz) {
    if (raiz == NULL) {
        return -1;
    }

    int alt_izq = bst_altura(raiz->izq);
    int alt_der = bst_altura(raiz->der);

    int max_alt = (alt_izq > alt_der) ? alt_izq : alt_der;
    return 1 + max_alt;
}

int bst_contar_nodos(const NodoBST *raiz) {
    if (raiz == NULL) {
        return 0;
    }

    return 1 + bst_contar_nodos(raiz->izq) + bst_contar_nodos(raiz->der);
}

int bst_buscar_min(const NodoBST *raiz) {
    if (raiz->izq == NULL) {
        return raiz->clave;
    }
    return bst_buscar_min(raiz->izq);
}

int bst_buscar_max(const NodoBST *raiz) {
    if (raiz->der == NULL) {
        return raiz->clave;
    }
    return bst_buscar_max(raiz->der);
}

NodoBST* bst_eliminar(NodoBST *raiz, int clave) {
    if (raiz == NULL) {
        return NULL;
    }

    if (clave < raiz->clave) {
        raiz->izq = bst_eliminar(raiz->izq, clave);
    } else if (clave > raiz->clave) {
        raiz->der = bst_eliminar(raiz->der, clave);
    } else {
        /* Encontramos el nodo a eliminar */

        /* Caso 1: Nodo hoja */
        if (raiz->izq == NULL && raiz->der == NULL) {
            free(raiz);
            return NULL;
        }

        /* Caso 2: Nodo con un hijo */
        if (raiz->izq == NULL) {
            NodoBST *temp = raiz->der;
            free(raiz);
            return temp;
        }
        if (raiz->der == NULL) {
            NodoBST *temp = raiz->izq;
            free(raiz);
            return temp;
        }

        /* Caso 3: Nodo con dos hijos */
        /* Encontrar el sucesor inorden (mínimo del subárbol derecho) */
        int sucesor = bst_buscar_min(raiz->der);
        raiz->clave = sucesor;
        /* Eliminar el sucesor del subárbol derecho */
        raiz->der = bst_eliminar(raiz->der, sucesor);
    }

    return raiz;
}

void bst_destruir(NodoBST *raiz) {
    if (raiz == NULL) {
        return;
    }

    bst_destruir(raiz->izq);
    bst_destruir(raiz->der);
    free(raiz);
}
