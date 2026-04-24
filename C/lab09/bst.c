/*
 * Estructuras de Datos — EIN423-B
 * Universidad Técnica Federico Santa María
 * Laboratorio 09: Árbol Binario de Búsqueda (BST)
 *
 * Estudiante: [Nombre Completo]
 * Fecha: [Fecha de entrega]
 */

#include "bst.h"

/**
 * Inserta una clave en el BST manteniendo la propiedad BST
 */
NodoBST* bst_insertar(NodoBST *raiz, int clave) {
    /* TODO: Implementar inserción en BST
     * Hint: Si raiz==NULL, crear nuevo nodo.
     *       Si clave < raiz->clave, insertar en subárbol izquierdo.
     *       Si clave > raiz->clave, insertar en subárbol derecho.
     *       Si clave == raiz->clave, duplicado (ignorar o actualizar).
     */
    return NULL;
}

/**
 * Busca una clave en el árbol
 */
NodoBST* bst_buscar(NodoBST *raiz, int clave) {
    /* TODO: Implementar búsqueda en BST
     * Hint: Si raiz==NULL, retornar NULL.
     *       Si clave == raiz->clave, retornar raiz.
     *       Si clave < raiz->clave, buscar en subárbol izquierdo.
     *       Si clave > raiz->clave, buscar en subárbol derecho.
     */
    return NULL;
}

/**
 * Imprime el árbol en recorrido inorden
 */
void bst_inorden(const NodoBST *raiz) {
    /* TODO: Implementar recorrido inorden
     * Hint: Procesar izquierda, luego nodo, luego derecha.
     *       Usar printf("%d ", raiz->clave) para cada nodo.
     */
}

/**
 * Imprime el árbol en recorrido preorden
 */
void bst_preorden(const NodoBST *raiz) {
    /* TODO: Implementar recorrido preorden
     * Hint: Procesar nodo, luego izquierda, luego derecha.
     */
}

/**
 * Imprime el árbol en recorrido postorden
 */
void bst_postorden(const NodoBST *raiz) {
    /* TODO: Implementar recorrido postorden
     * Hint: Procesar izquierda, luego derecha, luego nodo.
     */
}

/**
 * Calcula la altura del árbol
 */
int bst_altura(const NodoBST *raiz) {
    /* TODO: Implementar cálculo de altura
     * Hint: Si raiz==NULL, retornar -1.
     *       Si no, retornar 1 + max(altura(izq), altura(der)).
     */
    return -1;
}

/**
 * Cuenta el número total de nodos
 */
int bst_contar_nodos(const NodoBST *raiz) {
    /* TODO: Implementar conteo de nodos
     * Hint: Si raiz==NULL, retornar 0.
     *       Si no, retornar 1 + contar(izq) + contar(der).
     */
    return 0;
}

/**
 * Busca el valor mínimo
 */
int bst_buscar_min(const NodoBST *raiz) {
    /* TODO: Implementar búsqueda del mínimo
     * Hint: El mínimo siempre está en el hijo izquierdo más profundo.
     *       Recorrer raiz->izq hasta encontrar nodo sin hijo izquierdo.
     */
    return 0;
}

/**
 * Busca el valor máximo
 */
int bst_buscar_max(const NodoBST *raiz) {
    /* TODO: Implementar búsqueda del máximo
     * Hint: El máximo siempre está en el hijo derecho más profundo.
     *       Recorrer raiz->der hasta encontrar nodo sin hijo derecho.
     */
    return 0;
}

/**
 * Elimina una clave del árbol
 */
NodoBST* bst_eliminar(NodoBST *raiz, int clave) {
    /* TODO: Implementar eliminación en BST
     * Casos:
     * 1. Nodo hoja: liberar memoria y retornar NULL.
     * 2. Nodo con un hijo: reemplazar nodo por su hijo.
     * 3. Nodo con dos hijos: usar sucesor inorden (mínimo del subárbol derecho),
     *    copiar su clave, y eliminar el sucesor del subárbol derecho.
     * Hint: El sucesor inorden es el mínimo del subárbol derecho.
     *       Copia su clave a este nodo, luego elimina el sucesor del subárbol derecho.
     */
    return NULL;
}

/**
 * Libera toda la memoria del árbol
 */
void bst_destruir(NodoBST *raiz) {
    /* TODO: Implementar destrucción del árbol
     * Hint: Postorden: destruir izquierda, derecha, luego liberar raiz.
     */
}
