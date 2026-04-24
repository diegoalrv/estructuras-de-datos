/*
 * Estructuras de Datos — EIN423-B
 * Universidad Técnica Federico Santa María
 * Laboratorio 12: Tabla Hash con Encadenamiento
 *
 * Estudiante: [Nombre Completo]
 * Fecha: [Fecha de entrega]
 */

#ifndef TABLA_HASH_H
#define TABLA_HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Nodo para almacenar pares clave-valor en lista enlazada
 */
typedef struct NodoHash {
    int clave;              /**< Clave del elemento */
    int valor;              /**< Valor asociado a la clave */
    struct NodoHash *siguiente;  /**< Siguiente nodo en la cadena de colisiones */
} NodoHash;

/**
 * Tabla Hash con encadenamiento separado
 * Utiliza listas enlazadas para resolver colisiones
 */
typedef struct {
    NodoHash **tabla;   /**< Arreglo de punteros a listas enlazadas */
    int m;              /**< Tamaño de la tabla */
    int n;              /**< Número de elementos insertados */
} TablaHash;

/**
 * Crea una nueva tabla hash de tamaño m
 * @param m Tamaño inicial de la tabla (número de slots)
 * @return Puntero a la tabla hash creada
 */
TablaHash* th_crear(int m);

/**
 * Inserta un par clave-valor en la tabla
 * Si la clave ya existe, actualiza su valor
 * @param th Puntero a la tabla hash
 * @param clave Clave del elemento
 * @param valor Valor a asociar con la clave
 */
void th_insertar(TablaHash *th, int clave, int valor);

/**
 * Busca un valor en la tabla dado su clave
 * @param th Puntero a la tabla hash
 * @param clave Clave a buscar
 * @param valor_out Puntero donde se almacenará el valor encontrado
 * @return 1 si la clave fue encontrada, 0 si no existe
 */
int th_buscar(const TablaHash *th, int clave, int *valor_out);

/**
 * Elimina un par clave-valor de la tabla
 * @param th Puntero a la tabla hash
 * @param clave Clave del elemento a eliminar
 * @return 1 si el elemento fue eliminado, 0 si no existía
 */
int th_eliminar(TablaHash *th, int clave);

/**
 * Calcula el factor de carga de la tabla
 * Factor de carga = n / m (número de elementos / tamaño)
 * @param th Puntero a la tabla hash
 * @return Factor de carga (como double)
 */
double th_factor_carga(const TablaHash *th);

/**
 * Imprime el contenido de la tabla
 * Muestra cada slot con su cadena de colisiones
 * @param th Puntero a la tabla hash
 */
void th_imprimir(const TablaHash *th);

/**
 * Realiza rehashing de la tabla
 * Duplica el tamaño (m) y reinserta todos los elementos
 * Se usa cuando el factor de carga es demasiado alto
 * @param th Puntero a la tabla hash
 */
void th_rehash(TablaHash *th);

/**
 * Libera toda la memoria asociada a la tabla
 * @param th Puntero a la tabla hash
 */
void th_destruir(TablaHash *th);

/**
 * Función hash para enteros (djb2 modificada)
 * Realiza mapeo de clave a índice en [0, m-1]
 * @param clave Clave a hashear
 * @param m Tamaño de la tabla
 * @return Índice en [0, m-1]
 */
unsigned int hash_entero(int clave, int m);

#endif /* TABLA_HASH_H */
