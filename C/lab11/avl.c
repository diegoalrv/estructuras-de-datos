/*
 * Estructuras de Datos — EIN423-B
 * Universidad Técnica Federico Santa María
 * Laboratorio 11: Árbol AVL (Auto-balanceado)
 *
 * Estudiante: [Nombre Completo]
 * Fecha: [Fecha de entrega]
 */

#include "avl.h"

/* === Funciones auxiliares (ya implementadas) === */

int avl_altura_nodo(const NodoAVL *n) {
    if (n == NULL) {
        return -1;
    }
    return n->altura;
}

int avl_factor_balance(const NodoAVL *n) {
    if (n == NULL) {
        return 0;
    }
    return avl_altura_nodo(n->izq) - avl_altura_nodo(n->der);
}

void avl_actualizar_altura(NodoAVL *n) {
    if (n == NULL) {
        return;
    }
    int alt_izq = avl_altura_nodo(n->izq);
    int alt_der = avl_altura_nodo(n->der);
    n->altura = 1 + ((alt_izq > alt_der) ? alt_izq : alt_der);
}

/* === Rotaciones (TODO) === */

NodoAVL* avl_rotar_derecha(NodoAVL *y) {
    /* TODO: Implementar rotación a la derecha
     * Pasos:
     * 1. x = y->izq
     * 2. y->izq = x->der
     * 3. x->der = y
     * 4. Actualizar altura de y luego x
     * 5. Retornar x (nueva raíz del subárbol)
     * Hint:
     *     y              x
     *    / \    →      / \
     *   x   T3        T1   y
     *  / \                / \
     * T1  T2            T2   T3
     */
    return NULL;
}

NodoAVL* avl_rotar_izquierda(NodoAVL *x) {
    /* TODO: Implementar rotación a la izquierda
     * Pasos:
     * 1. y = x->der
     * 2. x->der = y->izq
     * 3. y->izq = x
     * 4. Actualizar altura de x luego y
     * 5. Retornar y (nueva raíz del subárbol)
     * Hint:
     *   x              y
     *  / \    →      / \
     * T1  y         x   T4
     *    / \       / \
     *   T2  T4   T1   T2
     */
    return NULL;
}

/* === Inserción con auto-balanceo === */

NodoAVL* avl_insertar(NodoAVL *raiz, int clave) {
    /* TODO: Implementar inserción con auto-balanceo
     * Pasos:
     * 1. Inserta como BST normal (recursión)
     * 2. Actualiza altura del nodo actual
     * 3. Calcula factor_balance
     * 4. Si |FB| > 1, aplicar rotaciones según caso:
     *    - Caso LL: FB > 1 y clave < raiz->izq->clave → rotar_derecha
     *    - Caso LR: FB > 1 y clave > raiz->izq->clave → rotar_izquierda(izq), rotar_derecha(raiz)
     *    - Caso RR: FB < -1 y clave > raiz->der->clave → rotar_izquierda
     *    - Caso RL: FB < -1 y clave < raiz->der->clave → rotar_derecha(der), rotar_izquierda(raiz)
     * 5. Retornar nueva raíz del subárbol
     *
     * Hint: Si clave == raiz->clave, duplicado (ignorar).
     */
    return NULL;
}

/* === Validación === */

int avl_es_valido(const NodoAVL *raiz) {
    if (raiz == NULL) {
        return 1;
    }

    /* Verificar factor de balance */
    int fb = avl_factor_balance(raiz);
    if (fb < -1 || fb > 1) {
        return 0;
    }

    /* Verificar recursivamente subárboles */
    return avl_es_valido(raiz->izq) && avl_es_valido(raiz->der);
}

/* === Recorridos === */

void avl_inorden(const NodoAVL *raiz) {
    if (raiz == NULL) {
        return;
    }
    avl_inorden(raiz->izq);
    printf("%d ", raiz->clave);
    avl_inorden(raiz->der);
}

void avl_imprimir_estructura(const NodoAVL *raiz, int nivel) {
    if (raiz == NULL) {
        return;
    }

    /* Imprimir subárbol derecho primero (invertido) */
    avl_imprimir_estructura(raiz->der, nivel + 1);

    /* Imprimir indentación y nodo actual */
    for (int i = 0; i < nivel; i++) {
        printf("    ");
    }
    printf("[%d, h=%d, fb=%d]\n", raiz->clave, raiz->altura, avl_factor_balance(raiz));

    /* Imprimir subárbol izquierdo */
    avl_imprimir_estructura(raiz->izq, nivel + 1);
}

/* === Limpieza === */

void avl_destruir(NodoAVL *raiz) {
    if (raiz == NULL) {
        return;
    }
    avl_destruir(raiz->izq);
    avl_destruir(raiz->der);
    free(raiz);
}
