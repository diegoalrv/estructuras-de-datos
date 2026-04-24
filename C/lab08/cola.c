/*
 * ============================================================================
 * CURSO:      Estructuras de Datos (EIN423-B)
 * UNIVERSIDAD: Universidad Técnica Federico Santa María
 * LAB:        08 - Cola (Queue)
 * ESTUDIANTE: [Nombre del estudiante]
 * FECHA:      Marzo 2026
 * ============================================================================
 */

#include "cola.h"

Cola* cola_crear(void)
{
    /* TODO: Asignar memoria para una nueva Cola.
     * Inicializar frente=NULL, fondo=NULL y tamanio=0.
     * Retornar el puntero a la nueva cola. */

    return NULL;
}

void cola_enqueue(Cola *c, int valor)
{
    /* TODO: Crear un nuevo nodo con el valor.
     * Si la cola está vacía: frente=fondo=nuevo, nuevo->siguiente=NULL.
     * Si no: nuevo->siguiente=NULL, fondo->siguiente=nuevo, fondo=nuevo.
     * Incrementar tamanio.
     * Esta operación es O(1) gracias al puntero fondo. */
}

int cola_dequeue(Cola *c)
{
    /* TODO: Si la cola está vacía, retorna -1.
     * Guarda el dato del frente (c->frente->dato).
     * Si solo hay 1 nodo: frente=fondo=NULL.
     * Si hay más: frente=frente->siguiente.
     * Libera el nodo antiguo.
     * Decrementa tamanio y retorna el dato.
     * Esta operación es O(1). */

    return -1;
}

int cola_frente(const Cola *c)
{
    /* TODO: Si la cola está vacía, retorna -1.
     * Retorna c->frente->dato. */

    return -1;
}

int cola_esta_vacia(const Cola *c)
{
    /* TODO: Retorna 1 si tamanio==0, 0 en otro caso. */
    return 1;
}

int cola_tamanio(const Cola *c)
{
    /* TODO: Retorna c->tamanio. */
    return -1;
}

void cola_destruir(Cola *c)
{
    /* TODO: Libera todos los nodos recorriendo desde frente.
     * Guarda siguiente antes de liberar cada nodo.
     * Luego libera el puntero a la cola c. */
}
