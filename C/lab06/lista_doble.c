/*
 * ============================================================================
 * CURSO:      Estructuras de Datos (EIN423-B)
 * UNIVERSIDAD: Universidad Técnica Federico Santa María
 * LAB:        06 - Lista Doblemente Enlazada
 * ESTUDIANTE: [Nombre del estudiante]
 * FECHA:      Marzo 2026
 * ============================================================================
 */

#include "lista_doble.h"

ListaDoble* listad_crear(void)
{
    /* TODO: Asignar memoria para una nueva ListaDoble.
     * Inicializar cabeza=NULL, cola=NULL y tamanio=0.
     * Retornar el puntero a la nueva lista. */

    return NULL;
}

void listad_push_front(ListaDoble *l, int valor)
{
    /* TODO: Crea un nuevo nodo con el valor.
     * Si la lista está vacía: nuevo->anterior=NULL, nuevo->siguiente=NULL, cabeza=cola=nuevo.
     * Si no: nuevo->anterior=NULL, nuevo->siguiente=cabeza, cabeza->anterior=nuevo, cabeza=nuevo.
     * Incrementar tamanio. */
}

void listad_push_back(ListaDoble *l, int valor)
{
    /* TODO: Crea un nuevo nodo con el valor.
     * Si la lista está vacía: cabeza=cola=nuevo, nuevos punteros NULL.
     * Si no: nuevo->siguiente=NULL, nuevo->anterior=cola, cola->siguiente=nuevo, cola=nuevo.
     * Incrementar tamanio. O(1) gracias al puntero cola. */
}

int listad_pop_front(ListaDoble *l)
{
    /* TODO: Si está vacía, retorna -1.
     * Guarda el dato del primer nodo.
     * Si solo hay 1 nodo: cabeza=cola=NULL.
     * Si hay más: cabeza=cabeza->siguiente, cabeza->anterior=NULL.
     * Libera el nodo antiguo, decrementa tamanio y retorna el dato. */

    return -1;
}

int listad_pop_back(ListaDoble *l)
{
    /* TODO: Si está vacía, retorna -1.
     * Guarda el dato del último nodo.
     * Si solo hay 1 nodo: cabeza=cola=NULL.
     * Si hay más: cola=cola->anterior, cola->siguiente=NULL.
     * Libera el nodo antiguo, decrementa tamanio y retorna el dato. */

    return -1;
}

void listad_imprimir_adelante(const ListaDoble *l)
{
    /* TODO: Imprime '[', recorre desde cabeza, imprime cada dato con espacios, luego ']' y salto de línea.
     * Ejemplo: [1 2 3 4 5] */
}

void listad_imprimir_atras(const ListaDoble *l)
{
    /* TODO: Imprime '[', recorre desde cola hacia atrás, imprime cada dato con espacios, luego ']' y salto de línea.
     * Ejemplo: [5 4 3 2 1] */
}

int listad_eliminar(ListaDoble *l, int valor)
{
    /* TODO: Recorre la lista buscando el valor.
     * Si encuentra: desenlaza el nodo (usa anterior y siguiente para actualizar vecinos).
     * Libera el nodo, decrementa tamanio y retorna 1.
     * Si no encuentra, retorna 0. */

    return 0;
}

void listad_insertar_ordenado(ListaDoble *l, int valor)
{
    /* TODO: Inserta un nuevo nodo manteniendo orden ascendente.
     * Recorre desde cabeza hasta encontrar el primer nodo con dato >= valor.
     * Inserta antes de ese nodo (o al final si no encuentra ninguno).
     * Actualiza anterior y siguiente correctamente.
     * Incrementa tamanio. */
}

void listad_destruir(ListaDoble *l)
{
    /* TODO: Libera todos los nodos recorriendo desde cabeza.
     * Guarda siguiente antes de liberar cada nodo.
     * Luego libera el puntero a la lista l. */
}

int listad_esta_vacia(const ListaDoble *l)
{
    /* TODO: Retorna 1 si tamanio==0, 0 en otro caso. */
    return 1;
}
