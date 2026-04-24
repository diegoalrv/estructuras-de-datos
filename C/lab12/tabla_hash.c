/*
 * Estructuras de Datos — EIN423-B
 * Universidad Técnica Federico Santa María
 * Laboratorio 12: Tabla Hash con Encadenamiento
 *
 * Estudiante: [Nombre Completo]
 * Fecha: [Fecha de entrega]
 */

#include "tabla_hash.h"

/**
 * Función hash para enteros (implementada)
 * Usa técnica djb2 adaptada para enteros
 */
unsigned int hash_entero(int clave, int m) {
    /* Usar valor absoluto y modular para obtener índice */
    unsigned int h = (unsigned int)clave;
    if (clave < 0) {
        h = (unsigned int)(-clave);
    }
    return h % m;
}

/**
 * Crea una nueva tabla hash
 */
TablaHash* th_crear(int m) {
    TablaHash *th = (TablaHash *)malloc(sizeof(TablaHash));
    if (th == NULL) {
        fprintf(stderr, "Error: no hay memoria\n");
        exit(EXIT_FAILURE);
    }

    th->tabla = (NodoHash **)calloc(m, sizeof(NodoHash *));
    if (th->tabla == NULL) {
        fprintf(stderr, "Error: no hay memoria\n");
        exit(EXIT_FAILURE);
    }

    th->m = m;
    th->n = 0;

    return th;
}

/**
 * Inserta un par clave-valor en la tabla
 */
void th_insertar(TablaHash *th, int clave, int valor) {
    /* TODO: Implementar inserción con manejo de colisiones
     * Pasos:
     * 1. Calcular hash_idx = clave % th->m (manejar negativos)
     * 2. Recorrer lista en tabla[hash_idx] buscando clave
     * 3. Si encontramos clave existente: actualizar su valor
     * 4. Si no encontramos: crear nuevo nodo e insertar al frente
     * 5. Si se insertó nuevo: incrementar th->n
     * 6. Si factor_carga > 0.7: llamar th_rehash (rehashing automático)
     *
     * Hint: Usar hash_entero(clave, th->m) para calcular índice.
     *       Insertar nuevo nodo al frente de la cadena es O(1).
     */
}

/**
 * Busca una clave en la tabla
 */
int th_buscar(const TablaHash *th, int clave, int *valor_out) {
    /* TODO: Implementar búsqueda
     * Pasos:
     * 1. Calcular hash_idx = hash_entero(clave, th->m)
     * 2. Recorrer lista en tabla[hash_idx]
     * 3. Si encontramos nodo con clave coincidente:
     *    - Copiar valor en *valor_out
     *    - Retornar 1
     * 4. Si llegamos a NULL sin encontrar: retornar 0
     *
     * Hint: Usar strcmp para comparar claves (si fueran strings)
     *       Aquí comparamos enteros directamente.
     */
    return 0;
}

/**
 * Elimina una clave de la tabla
 */
int th_eliminar(TablaHash *th, int clave) {
    /* TODO: Implementar eliminación
     * Pasos:
     * 1. Calcular hash_idx = hash_entero(clave, th->m)
     * 2. Recorrer lista en tabla[hash_idx]
     * 3. Si encontramos nodo con clave:
     *    - Desenlazarlo de la lista
     *    - Liberar su memoria
     *    - Decrementar th->n
     *    - Retornar 1
     * 4. Si no encontramos: retornar 0
     *
     * Hint: Mantener puntero al nodo anterior para desenlazar correctamente.
     */
    return 0;
}

/**
 * Calcula el factor de carga
 */
double th_factor_carga(const TablaHash *th) {
    /* TODO: Implementar cálculo de factor de carga
     * Hint: retornar (double)th->n / th->m;
     */
    return 0.0;
}

/**
 * Imprime el contenido de la tabla
 */
void th_imprimir(const TablaHash *th) {
    printf("=== Tabla Hash (m=%d, n=%d, carga=%.2f) ===\n",
           th->m, th->n, th_factor_carga(th));

    for (int i = 0; i < th->m; i++) {
        printf("Slot %2d: ", i);

        if (th->tabla[i] == NULL) {
            printf("(vacío)\n");
        } else {
            NodoHash *nodo = th->tabla[i];
            while (nodo != NULL) {
                printf("[%d → %d] ", nodo->clave, nodo->valor);
                nodo = nodo->siguiente;
            }
            printf("\n");
        }
    }
    printf("\n");
}

/**
 * Realiza rehashing de la tabla
 */
void th_rehash(TablaHash *th) {
    /* TODO: Implementar rehashing
     * Pasos:
     * 1. Guardar referencias a tabla y m antiguos
     * 2. Crear nueva tabla con tamaño 2 * m_antiguo
     * 3. Reinsert cada elemento de las listas antiguas en la nueva tabla
     * 4. Liberar la tabla antigua
     *
     * Hint: Usar malloc/calloc para nueva tabla.
     *       Iterar sobre todos los slots de la tabla antigua.
     *       Para cada nodo en cada lista, calcular nuevo hash_idx con nuevo m.
     *       Insertar nodo al frente de la lista en el nuevo slot.
     *       No crear nuevos nodos: reutilizar los existentes.
     */
}

/**
 * Libera la memoria de la tabla
 */
void th_destruir(TablaHash *th) {
    if (th == NULL) {
        return;
    }

    for (int i = 0; i < th->m; i++) {
        NodoHash *nodo = th->tabla[i];
        while (nodo != NULL) {
            NodoHash *temp = nodo;
            nodo = nodo->siguiente;
            free(temp);
        }
    }

    free(th->tabla);
    free(th);
}
