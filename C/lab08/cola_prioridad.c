/*
 * ============================================================================
 * CURSO:      Estructuras de Datos (EIN423-B)
 * UNIVERSIDAD: Universidad Técnica Federico Santa María
 * LAB:        08 - Cola de Prioridad (Priority Queue)
 * ESTUDIANTE: [Nombre del estudiante]
 * FECHA:      Marzo 2026
 * ============================================================================
 */

#include "cola_prioridad.h"

ColaPrioridad* cp_crear(void)
{
    /* TODO: Asignar memoria para una nueva ColaPrioridad.
     * Inicializar tamanio=0.
     * Retornar el puntero a la nueva cola de prioridad. */

    return NULL;
}

void cp_insertar(ColaPrioridad *cp, int valor, int prioridad)
{
    /* TODO: Verifica que tamanio < MAX_HEAP.
     * Agrega el nuevo elemento al final del arreglo (datos[tamanio]).
     * Incrementa tamanio.
     * Llama a heapify_up(cp, tamanio-1) para reestablecer la propiedad de heap. */
}

ElementoHeap cp_extraer_minimo(ColaPrioridad *cp)
{
    /* TODO: Si la cola está vacía, retorna {-1, -1}.
     * Guarda el elemento raíz (datos[0]) — es el mínimo.
     * Mueve el último elemento a la raíz (datos[0] = datos[tamanio-1]).
     * Decrementa tamanio.
     * Llama a heapify_down(cp, 0) para reestablecer la propiedad de heap.
     * Retorna el elemento guardado. */

    ElementoHeap error = {-1, -1};
    return error;
}

ElementoHeap cp_ver_minimo(const ColaPrioridad *cp)
{
    /* TODO: Si la cola está vacía, retorna {-1, -1}.
     * Retorna datos[0] (el mínimo sin extraerlo). */

    ElementoHeap error = {-1, -1};
    return error;
}

int cp_esta_vacia(const ColaPrioridad *cp)
{
    /* TODO: Retorna 1 si tamanio==0, 0 en otro caso. */
    return 1;
}

void cp_destruir(ColaPrioridad *cp)
{
    /* TODO: Libera el puntero a la cola de prioridad cp.
     * Nota: Los datos están en un arreglo estático, no necesitan liberar individualmente. */
}

void heapify_up(ColaPrioridad *cp, int i)
{
    /* TODO: Reestablece la propiedad de min-heap hacia arriba.
     * Mientras i > 0:
     *   - Calcula índice del padre: padre = (i-1) / 2
     *   - Si datos[i].prioridad < datos[padre].prioridad:
     *     - Intercambia datos[i] y datos[padre]
     *     - Actualiza i = padre
     *   - Si no, termina (la propiedad ya está satisfecha). */
}

void heapify_down(ColaPrioridad *cp, int i)
{
    /* TODO: Reestablece la propiedad de min-heap hacia abajo.
     * Mientras i tiene hijos:
     *   - Calcula índices: izq = 2*i+1, der = 2*i+2
     *   - Encuentra el hijo con menor prioridad (y existe).
     *   - Si datos[i].prioridad > datos[hijo_menor].prioridad:
     *     - Intercambia datos[i] y datos[hijo_menor]
     *     - Actualiza i = hijo_menor
     *   - Si no, termina (la propiedad ya está satisfecha). */
}
