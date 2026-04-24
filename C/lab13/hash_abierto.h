/*
 * Estructuras de Datos - EIN423-B
 * Laboratorio 13: Hashing con Sondeo Abierto
 *
 * Alumno: ___________________________________
 * Sección: _________________________________
 *
 * Descripción:
 * Implementación de tabla hash con direccionamiento abierto (open addressing).
 * Soporta tres métodos de sondeo: lineal, cuadrático y doble hashing.
 */

#ifndef HASH_ABIERTO_H
#define HASH_ABIERTO_H

#include <stdio.h>
#include <stdlib.h>

/**
 * Estados posibles de una celda en la tabla hash.
 * VACIO:     celda nunca ha sido usada
 * OCUPADO:   celda contiene un par clave-valor
 * ELIMINADO: celda fue ocupada pero fue eliminada (necesaria para sondeo abierto)
 */
typedef enum {
    VACIO,
    OCUPADO,
    ELIMINADO
} EstadoCelda;

/**
 * Estructura de una celda individual en la tabla hash.
 */
typedef struct {
    int clave;           /**< Clave almacenada */
    int valor;           /**< Valor asociado a la clave */
    EstadoCelda estado;  /**< Estado actual de la celda */
} Celda;

/**
 * Estructura de la tabla hash con direccionamiento abierto.
 */
typedef struct {
    Celda *tabla;  /**< Array dinámico de celdas */
    int m;         /**< Tamaño de la tabla (debe ser primo) */
    int n;         /**< Número de elementos actualmente ocupados */
} TablaHashAbierta;

/**
 * Crea una nueva tabla hash vacía.
 *
 * @param m Tamaño de la tabla (debe ser primo para mejor distribución)
 * @return Puntero a la nueva tabla, o NULL si falla la asignación
 */
TablaHashAbierta* tha_crear(int m);

/**
 * Calcula el índice usando sondeo LINEAL.
 * Fórmula: (h(k) + i) mod m, donde h(k) = k mod m
 *
 * @param clave Clave a hashear
 * @param i Número de intento (0, 1, 2, ...)
 * @param m Tamaño de la tabla
 * @return Índice en el rango [0, m-1]
 */
int tha_sondeo_lineal(int clave, int i, int m);

/**
 * Calcula el índice usando sondeo CUADRÁTICO.
 * Fórmula: (h(k) + i²) mod m, donde h(k) = k mod m
 *
 * @param clave Clave a hashear
 * @param i Número de intento (0, 1, 2, ...)
 * @param m Tamaño de la tabla
 * @return Índice en el rango [0, m-1]
 */
int tha_sondeo_cuadratico(int clave, int i, int m);

/**
 * Calcula el índice usando DOBLE HASHING.
 * Fórmula: (h1(k) + i·h2(k)) mod m
 * donde h1(k) = k mod m, h2(k) = 7 - (k mod 7)
 *
 * @param clave Clave a hashear
 * @param i Número de intento (0, 1, 2, ...)
 * @param m Tamaño de la tabla
 * @return Índice en el rango [0, m-1]
 */
int tha_doble_hash(int clave, int i, int m);

/**
 * Inserta un par clave-valor en la tabla usando sondeo lineal.
 * Si la clave ya existe, actualiza su valor.
 *
 * @param tha Tabla hash a modificar
 * @param clave Clave a insertar
 * @param valor Valor asociado
 * @return Número de sondeos (intentos) necesarios para insertar
 */
int tha_insertar(TablaHashAbierta *tha, int clave, int valor);

/**
 * Busca una clave en la tabla.
 *
 * @param tha Tabla hash a consultar
 * @param clave Clave a buscar
 * @param valor_out Puntero donde almacenar el valor si se encuentra
 * @return 1 si se encontró la clave, 0 si no existe
 */
int tha_buscar(const TablaHashAbierta *tha, int clave, int *valor_out);

/**
 * Elimina una clave de la tabla (marca su celda como ELIMINADO).
 *
 * @param tha Tabla hash a modificar
 * @param clave Clave a eliminar
 * @return 1 si se eliminó la clave, 0 si no existía
 */
int tha_eliminar(TablaHashAbierta *tha, int clave);

/**
 * Imprime el contenido de la tabla hash en formato legible.
 * Muestra cada celda con su índice, clave, valor y estado.
 *
 * @param tha Tabla hash a imprimir
 */
void tha_imprimir(const TablaHashAbierta *tha);

/**
 * Libera la memoria ocupada por la tabla hash.
 *
 * @param tha Tabla hash a destruir
 */
void tha_destruir(TablaHashAbierta *tha);

#endif
