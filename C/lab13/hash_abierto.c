/*
 * Estructuras de Datos - EIN423-B
 * Laboratorio 13: Hashing con Sondeo Abierto - IMPLEMENTACIÓN
 *
 * Alumno: ___________________________________
 * Sección: _________________________________
 */

#include "hash_abierto.h"

/**
 * TODO: Implementar tha_crear
 * Crea una tabla hash vacía de tamaño m.
 * Inicializa todas las celdas como VACIO.
 * Hint: Asigna memoria para la tabla y sus celdas. Inicializa estado=VACIO para todas.
 */
TablaHashAbierta* tha_crear(int m) {
    // TODO: Implementar
    return NULL;
}

/**
 * TODO: Implementar tha_sondeo_lineal
 * Calcula (clave % m + i) % m
 * Hint: Si el resultado es negativo (C permite esto), suma m para hacerlo positivo
 */
int tha_sondeo_lineal(int clave, int i, int m) {
    // TODO: Implementar
    return 0;
}

/**
 * TODO: Implementar tha_sondeo_cuadratico
 * Calcula (clave % m + i*i) % m
 * Hint: Cuidado con los módulos negativos en C
 */
int tha_sondeo_cuadratico(int clave, int i, int m) {
    // TODO: Implementar
    return 0;
}

/**
 * TODO: Implementar tha_doble_hash
 * h1(k) = k % m
 * h2(k) = 7 - (k % 7)
 * Retorna (h1 + i*h2) % m
 * Hint: Ambas funciones hash deben combinarse correctamente
 */
int tha_doble_hash(int clave, int i, int m) {
    // TODO: Implementar
    return 0;
}

/**
 * TODO: Implementar tha_insertar
 * Inserta clave-valor probando sondeos i=0, 1, 2, ...
 * Inserta en primera celda VACIO o ELIMINADO encontrada.
 * Retorna número de intentos realizados.
 * Hint: Usa tha_sondeo_lineal. Cuenta los intentos. Si clave ya existe, actualiza.
 */
int tha_insertar(TablaHashAbierta *tha, int clave, int valor) {
    // TODO: Implementar
    return 0;
}

/**
 * TODO: Implementar tha_buscar
 * Busca clave probando sondeos i=0, 1, 2, ...
 * Si VACIO → no existe (corta búsqueda)
 * Si ELIMINADO → continúa sondeo
 * Si OCUPADO y clave==buscada → encontrado
 * Hint: Llena *valor_out solo si encuentra; retorna 1 si éxito, 0 si no
 */
int tha_buscar(const TablaHashAbierta *tha, int clave, int *valor_out) {
    // TODO: Implementar
    return 0;
}

/**
 * TODO: Implementar tha_eliminar
 * Busca la clave y marca su estado como ELIMINADO.
 * NO borra datos de la celda, solo marca estado.
 * Decrementa tha->n.
 * Hint: Usa tha_buscar internamente. Retorna 1 si eliminó, 0 si no existía.
 */
int tha_eliminar(TablaHashAbierta *tha, int clave) {
    // TODO: Implementar
    return 0;
}

/**
 * TODO: Implementar tha_imprimir
 * Imprime la tabla con formato:
 * [índice] clave=valor estado
 * Por ejemplo:
 * [0] clave=10 valor=100 OCUPADO
 * [1] VACIO
 */
void tha_imprimir(const TablaHashAbierta *tha) {
    // TODO: Implementar
}

/**
 * TODO: Implementar tha_destruir
 * Libera memoria del array tabla y la estructura.
 * Hint: free(tha->tabla); free(tha);
 */
void tha_destruir(TablaHashAbierta *tha) {
    // TODO: Implementar
}
