/*
 * ============================================================================
 * CURSO:      Estructuras de Datos (EIN423-B)
 * UNIVERSIDAD: Universidad Técnica Federico Santa María
 * LAB:        05 - Lista Enlazada Simple
 * ESTUDIANTE: [Nombre del estudiante]
 * FECHA:      Marzo 2026
 * ============================================================================
 */

#include "lista_simple.h"

Lista* lista_crear(void)
{
    /* TODO: Asignar memoria para una nueva Lista.
     * Inicializar cabeza=NULL y tamanio=0.
     * Retornar el puntero a la nueva lista. */

    return NULL;  /* Reemplazar con implementación */
}

void lista_push_front(Lista *l, int valor)
{
    /* TODO: Crea un nuevo nodo con el valor.
     * El nuevo nodo apunta a l->cabeza (que puede ser NULL).
     * Luego, l->cabeza = nuevo nodo.
     * Incrementar l->tamanio. */
}

void lista_push_back(Lista *l, int valor)
{
    /* TODO: Si la lista está vacía, es como push_front.
     * Si no, recorre hasta el último nodo (donde nodo->siguiente == NULL).
     * Enlaza ese nodo con el nuevo nodo.
     * Incrementar l->tamanio. */
}

int lista_pop_front(Lista *l)
{
    /* TODO: Si la lista está vacía, retorna -1.
     * Guarda el dato del primer nodo (l->cabeza->dato).
     * Avanza l->cabeza al siguiente nodo (l->cabeza = l->cabeza->siguiente).
     * Libera el nodo antiguo.
     * Decrementa l->tamanio y retorna el dato guardado. */

    return -1;  /* Reemplazar con implementación */
}

void lista_imprimir(const Lista *l)
{
    /* TODO: Imprime un '[', luego cada dato separado por espacios,
     * luego un ']' y salto de línea.
     * Ejemplo: [1 2 3 4 5]
     * Si está vacía: [] */
}

int lista_tamanio(const Lista *l)
{
    /* TODO: Retorna l->tamanio. */
    return -1;
}

int lista_buscar(const Lista *l, int valor)
{
    /* TODO: Recorre la lista contando el índice (comenzando en 0).
     * Si encuentra el valor, retorna el índice.
     * Si llega al final sin encontrar, retorna -1. */

    return -1;
}

int lista_obtener(const Lista *l, int idx)
{
    /* TODO: Recorre idx pasos desde la cabeza.
     * Si idx es válido (0 <= idx < tamanio), retorna el dato.
     * Si idx es inválido, retorna -1. */

    return -1;
}

int lista_eliminar(Lista *l, int valor)
{
    /* TODO: Recorre la lista buscando el primer nodo con ese valor.
     * Si encuentra, lo desenlaza (nodo_anterior->siguiente = nodo->siguiente).
     * Libera el nodo, decrementa tamanio y retorna 1.
     * Si no encuentra, retorna 0. */

    return 0;
}

void lista_invertir(Lista *l)
{
    /* TODO: Invierte la lista in-place.
     * Usa tres punteros: anterior=NULL, actual=l->cabeza, siguiente.
     * En cada paso, redirige actual->siguiente = anterior.
     * Luego, anterior=actual, actual=siguiente.
     * Al final, l->cabeza = anterior. */
}

void lista_destruir(Lista *l)
{
    /* TODO: Libera todos los nodos recorriendo desde la cabeza.
     * Guarda siguiente antes de liberar.
     * Luego libera el puntero a la lista l. */
}

int lista_esta_vacia(const Lista *l)
{
    /* TODO: Retorna 1 si tamanio==0, 0 en otro caso. */
    return 1;
}
