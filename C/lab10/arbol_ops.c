/*
 * Estructuras de Datos — EIN423-B
 * Universidad Técnica Federico Santa María
 * Laboratorio 10: Recorridos y Operaciones Avanzadas en BST
 *
 * Estudiante: [Nombre Completo]
 * Fecha: [Fecha de entrega]
 */

#include "arbol_ops.h"
#include <string.h>
#include <limits.h>
#include <stdio.h>

#define COLA_MAX 1000  /* Tamaño máximo de cola para recorrido por niveles */

/**
 * Recorrido por niveles (BFS)
 */
void bst_por_niveles(const NodoBST *raiz) {
    /* TODO: Implementar recorrido por niveles usando cola
     * Hint: Usa un arreglo como cola circular. Encola la raíz.
     *       Mientras cola no esté vacía: desencola, visita, encola hijos no-NULL.
     */
}

/**
 * Contar hojas
 */
int bst_contar_hojas(const NodoBST *raiz) {
    /* TODO: Implementar conteo de hojas (nodos sin hijos)
     * Hint: Si raiz==NULL, retornar 0.
     *       Si no tiene hijos izq ni der, es una hoja (retornar 1).
     *       Si no, retornar contar_hojas(izq) + contar_hojas(der).
     */
    return 0;
}

/**
 * Suma de todos los nodos
 */
long bst_suma_nodos(const NodoBST *raiz) {
    /* TODO: Implementar suma de todos los valores
     * Hint: Si raiz==NULL, retornar 0.
     *       Si no, retornar raiz->clave + suma(izq) + suma(der).
     */
    return 0;
}

/**
 * Validar que es un BST válido usando rangos min/max
 */
static bool bst_es_valido_rango(const NodoBST *raiz, int min, int max) {
    /* TODO: Implementar validación con rangos
     * Hint: Si raiz==NULL, es válido (retornar true).
     *       Si raiz->clave <= min o raiz->clave >= max, inválido (retornar false).
     *       Si no, validar recursivamente:
     *         - izquierda con rango [min, raiz->clave-1]
     *         - derecha con rango [raiz->clave+1, max]
     */
    return true;
}

bool bst_es_valido(const NodoBST *raiz) {
    return bst_es_valido_rango(raiz, INT_MIN, INT_MAX);
}

/**
 * Serializar árbol a string (preorden)
 */
void bst_serializar(const NodoBST *raiz, char *buffer, int *pos) {
    /* TODO: Implementar serialización en preorden
     * Hint: Si raiz==NULL, escribir '#' en buffer.
     *       Si no, escribir raiz->clave, ',' recursivamente izq, ',' recursivamente der.
     *       Usar sprintf para escribir números: sprintf(buffer + *pos, "%d", raiz->clave)
     *       Actualizar *pos a medida que se escriba.
     */
}

/**
 * Deserializar string a árbol (preorden)
 */
NodoBST* bst_deserializar(const char *str, int *pos) {
    /* TODO: Implementar deserialización desde formato preorden
     * Hint: Parsear token en str[*pos] buscando ',' como separador.
     *       Si token es '#', retornar NULL (y avanzar pos).
     *       Si es número, crear nodo, recurrir para izq y der, retornar nodo.
     *       Usar sscanf o strtol para convertir string a número.
     */
    return NULL;
}
