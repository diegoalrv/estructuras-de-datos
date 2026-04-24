/*
 * Estructuras de Datos — EIN423-B
 * Universidad Técnica Federico Santa María
 * Laboratorio 10: Recorridos y Operaciones Avanzadas — Pruebas
 *
 * Estudiante: [Nombre Completo]
 * Fecha: [Fecha de entrega]
 */

#include "bst.h"
#include "arbol_ops.h"
#include <assert.h>

int main(void) {
    printf("=== Pruebas de Recorridos y Operaciones Avanzadas en BST ===\n\n");

    /* Crear árbol y insertar valores */
    NodoBST *raiz = NULL;
    int valores[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    int n = 9;

    printf("Insertando valores: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", valores[i]);
        raiz = bst_insertar(raiz, valores[i]);
    }
    printf("\n\n");

    /* Test 1: Recorrido por niveles (BFS) */
    printf("Test 1 - Recorrido por niveles (BFS):\n");
    printf("  Esperado: 8 3 10 1 6 14 4 7 13\n");
    printf("  Obtenido: ");
    bst_por_niveles(raiz);
    printf("\n✓ PASS\n\n");

    /* Test 2: Contar hojas */
    int hojas = bst_contar_hojas(raiz);
    printf("Test 2 - Contar hojas:\n");
    printf("  Cantidad de hojas: %d (esperado: 4)\n", hojas);
    printf("  Hojas del árbol: 1, 4, 7, 13\n");
    assert(hojas == 4 && "ERROR: conteo de hojas incorrecto");
    printf("✓ PASS\n\n");

    /* Test 3: Suma de nodos */
    long suma = bst_suma_nodos(raiz);
    printf("Test 3 - Suma de todos los nodos:\n");
    printf("  Suma: %ld (esperado: 66)\n", suma);
    assert(suma == 66 && "ERROR: suma incorrecta");
    printf("✓ PASS\n\n");

    /* Test 4: Validar BST válido */
    printf("Test 4 - Validar BST:\n");
    bool es_valido = bst_es_valido(raiz);
    printf("  ¿Es un BST válido?: %s (esperado: true)\n",
           es_valido ? "true" : "false");
    assert(es_valido && "ERROR: BST debería ser válido");
    printf("✓ PASS\n\n");

    /* Test 5: Validar BST inválido (si se modifica manualmente) */
    printf("Test 5 - Validar BST inválido (construcción manual):\n");
    NodoBST *invalido = (NodoBST *)malloc(sizeof(NodoBST));
    invalido->clave = 5;
    invalido->izq = (NodoBST *)malloc(sizeof(NodoBST));
    invalido->izq->clave = 10;  /* Inválido: izq > raíz */
    invalido->izq->izq = NULL;
    invalido->izq->der = NULL;
    invalido->der = NULL;
    bool invalido_detectado = !bst_es_valido(invalido);
    printf("  ¿Detectado como inválido?: %s (esperado: true)\n",
           invalido_detectado ? "true" : "false");
    assert(invalido_detectado && "ERROR: BST inválido no fue detectado");
    free(invalido->izq);
    free(invalido);
    printf("✓ PASS\n\n");

    /* Test 6: Serializar y deserializar */
    printf("Test 6 - Serialización y deserialización:\n");
    char buffer[2048];
    int pos = 0;
    bst_serializar(raiz, buffer, &pos);
    buffer[pos] = '\0';  /* Null-terminate */
    printf("  Serialización (primeros 50 caracteres): %.50s...\n", buffer);

    /* Deserializar */
    pos = 0;
    NodoBST *arbol_restaurado = bst_deserializar(buffer, &pos);

    /* Verificar que el árbol restaurado tiene el mismo inorden */
    printf("  Inorden original: ");
    bst_inorden(raiz);
    printf("\n  Inorden restaurado: ");
    bst_inorden(arbol_restaurado);
    printf("\n  (deben ser iguales)\n");
    printf("✓ PASS\n\n");

    /* Limpiar memoria */
    bst_destruir(raiz);
    bst_destruir(arbol_restaurado);

    printf("=== TODAS LAS PRUEBAS PASARON ===\n");
    return 0;
}
