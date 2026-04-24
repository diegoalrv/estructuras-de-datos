/*
 * Estructuras de Datos — EIN423-B
 * Universidad Técnica Federico Santa María
 * Laboratorio 10: Recorridos y Operaciones Avanzadas en BST
 *
 * Estudiante: [Nombre Completo]
 * Fecha: [Fecha de entrega]
 */

#ifndef ARBOL_OPS_H
#define ARBOL_OPS_H

#include "bst.h"
#include <stdbool.h>

/**
 * Realiza recorrido por niveles (BFS) del árbol usando una cola interna
 * Imprime los nodos nivel por nivel (anchura primero)
 * @param raiz Puntero a la raíz del árbol
 */
void bst_por_niveles(const NodoBST *raiz);

/**
 * Cuenta el número de hojas (nodos sin hijos) en el árbol
 * @param raiz Puntero a la raíz del árbol
 * @return Número de hojas
 */
int bst_contar_hojas(const NodoBST *raiz);

/**
 * Calcula la suma de todas las claves en el árbol
 * @param raiz Puntero a la raíz del árbol
 * @return Suma de todos los nodos
 */
long bst_suma_nodos(const NodoBST *raiz);

/**
 * Verifica si el árbol mantiene la propiedad BST válida
 * Utiliza rangos de min/max para validar recursivamente
 * @param raiz Puntero a la raíz del árbol
 * @return true si es un BST válido, false en caso contrario
 */
bool bst_es_valido(const NodoBST *raiz);

/**
 * Serializa el árbol en una representación de string
 * Formato: preorden con '#' para NULL, valores separados por ','
 * Ejemplo: árbol con raíz 4, hijo izq 2, hijo der 6 → "4,2,#,#,6,#,#"
 * @param raiz Puntero a la raíz del árbol
 * @param buffer Buffer de salida para la serialización
 * @param pos Puntero a la posición actual en buffer (se incrementa durante escritura)
 */
void bst_serializar(const NodoBST *raiz, char *buffer, int *pos);

/**
 * Deserializa una representación de string en un árbol
 * Lee desde el formato de serialización generado por bst_serializar
 * @param str String con los datos serializados
 * @param pos Puntero a la posición actual de lectura (se incrementa durante lectura)
 * @return Puntero a la raíz del árbol reconstruido, o NULL si la serialización estaba vacía
 */
NodoBST* bst_deserializar(const char *str, int *pos);

#endif /* ARBOL_OPS_H */
