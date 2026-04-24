/*
 * ============================================================================
 * CURSO:      Estructuras de Datos (EIN423-B)
 * UNIVERSIDAD: Universidad Técnica Federico Santa María
 * LAB:        07 - Pila (Stack)
 * ESTUDIANTE: [Nombre del estudiante]
 * FECHA:      Marzo 2026
 * ============================================================================
 */

#include "pila.h"

Pila* pila_crear(void)
{
    /* TODO: Asignar memoria para una nueva Pila.
     * Inicializar tope=NULL y tamanio=0.
     * Retornar el puntero a la nueva pila. */

    return NULL;
}

void pila_push(Pila *p, int valor)
{
    /* TODO: Crear un nuevo nodo con el valor.
     * El tope es la 'cabeza' — insertar al frente es O(1).
     * nuevo->siguiente = p->tope, luego p->tope = nuevo.
     * Incrementar p->tamanio. */
}

int pila_pop(Pila *p)
{
    /* TODO: Si la pila está vacía, imprime "Error: pila vacía" y aborta.
     * Guarda el dato del tope (p->tope->dato).
     * Avanza p->tope = p->tope->siguiente.
     * Libera el nodo antiguo.
     * Decrementa tamanio y retorna el dato. */

    return -1;
}

int pila_peek(const Pila *p)
{
    /* TODO: Si la pila está vacía, imprime "Error: pila vacía" y aborta.
     * Retorna p->tope->dato. */

    return -1;
}

int pila_esta_vacia(const Pila *p)
{
    /* TODO: Retorna 1 si tamanio==0, 0 en otro caso. */
    return 1;
}

int pila_tamanio(const Pila *p)
{
    /* TODO: Retorna p->tamanio. */
    return -1;
}

void pila_destruir(Pila *p)
{
    /* TODO: Libera todos los nodos recorriendo desde el tope.
     * Guarda siguiente antes de liberar cada nodo.
     * Luego libera el puntero a la pila p. */
}

int balanceada(const char *expresion)
{
    /* TODO: Verifica que paréntesis/corchetes/llaves estén balanceados.
     * Haz push de cada '(', '[', '{' encontrado.
     * Al encontrar un cierre ')', ']' o '}':
     *   - Si la pila está vacía, retorna 0 (desequilibrado).
     *   - Si pila_peek() no es el par correspondiente, retorna 0.
     *   - Si es el par, haz pop.
     * Al final, si la pila NO está vacía, retorna 0.
     * Si todo es correcto, retorna 1.
     * Ignora caracteres que no sean paréntesis/corchetes/llaves. */

    return 0;
}

int evaluar_postfija(const char *expr)
{
    /* TODO: Evalúa una expresión en notación RPN.
     * Tokeniza la expresión usando strtok(expr, " ").
     * Para cada token:
     *   - Si es un número (dígitos): haz push a la pila.
     *   - Si es un operador (+,-,*,/): pop b, pop a, push(a op b).
     * Al final, retorna el único elemento en la pila (el resultado).
     * Nota: Asume entrada válida (no hay manejo de errores requerido). */

    return 0;
}
