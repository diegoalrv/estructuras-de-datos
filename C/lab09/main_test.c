/*
 * Estructuras de Datos — EIN423-B
 * Universidad Técnica Federico Santa María
 * Laboratorio 09: Árbol Binario de Búsqueda (BST) — Pruebas
 *
 * Estudiante: [Nombre Completo]
 * Fecha: [Fecha de entrega]
 */

#include "bst.h"
#include <assert.h>

int main(void) {
    printf("=== Pruebas de Árbol Binario de Búsqueda (BST) ===\n\n");

    /* Crear un árbol e insertar valores */
    NodoBST *raiz = NULL;
    int valores[] = {50, 30, 70, 20, 40, 60, 80};
    int n = 7;

    printf("Insertando en orden: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", valores[i]);
        raiz = bst_insertar(raiz, valores[i]);
    }
    printf("\n\n");

    /* Test 1: Recorrido inorden (debe estar ordenado) */
    printf("Test 1 - Inorden (debe mostrar: 20 30 40 50 60 70 80): ");
    bst_inorden(raiz);
    printf("\n");

    /* Test 2: Recorrido preorden */
    printf("Test 2 - Preorden (debe mostrar: 50 30 20 40 70 60 80): ");
    bst_preorden(raiz);
    printf("\n");

    /* Test 3: Recorrido postorden */
    printf("Test 3 - Postorden (debe mostrar: 20 40 30 60 80 70 50): ");
    bst_postorden(raiz);
    printf("\n\n");

    /* Test 4: Altura */
    int alt = bst_altura(raiz);
    printf("Test 4 - Altura del árbol: %d (esperado: 2)\n", alt);
    assert(alt == 2 && "ERROR: altura incorrecta");
    printf("✓ PASS\n\n");

    /* Test 5: Contar nodos */
    int cnt = bst_contar_nodos(raiz);
    printf("Test 5 - Número de nodos: %d (esperado: 7)\n", cnt);
    assert(cnt == 7 && "ERROR: conteo incorrecto");
    printf("✓ PASS\n\n");

    /* Test 6: Buscar mínimo y máximo */
    int minimo = bst_buscar_min(raiz);
    int maximo = bst_buscar_max(raiz);
    printf("Test 6 - Mínimo: %d (esperado: 20), Máximo: %d (esperado: 80)\n",
           minimo, maximo);
    assert(minimo == 20 && maximo == 80 && "ERROR: min/max incorrecto");
    printf("✓ PASS\n\n");

    /* Test 7: Buscar claves existentes */
    NodoBST *encontrado = bst_buscar(raiz, 40);
    printf("Test 7 - Buscar(40): %s\n",
           (encontrado != NULL && encontrado->clave == 40) ? "Encontrado" : "NO encontrado");
    assert(encontrado != NULL && encontrado->clave == 40 && "ERROR: búsqueda fallida");
    printf("✓ PASS\n\n");

    /* Test 8: Buscar clave inexistente */
    encontrado = bst_buscar(raiz, 99);
    printf("Test 8 - Buscar(99): %s (esperado: no encontrado)\n",
           (encontrado == NULL) ? "No encontrado" : "Encontrado (ERROR)");
    assert(encontrado == NULL && "ERROR: debería no encontrarse");
    printf("✓ PASS\n\n");

    /* Test 9: Eliminar nodo con dos hijos */
    printf("Test 9 - Eliminar 30 (caso: dos hijos)\n");
    printf("  Antes: ");
    bst_inorden(raiz);
    printf("\n");
    raiz = bst_eliminar(raiz, 30);
    printf("  Después: ");
    bst_inorden(raiz);
    printf(" (esperado: 20 40 50 60 70 80)\n");
    printf("✓ PASS\n\n");

    /* Test 10: Eliminar nodo hoja */
    printf("Test 10 - Eliminar 20 (caso: nodo hoja)\n");
    printf("  Antes: ");
    bst_inorden(raiz);
    printf("\n");
    raiz = bst_eliminar(raiz, 20);
    printf("  Después: ");
    bst_inorden(raiz);
    printf(" (esperado: 40 50 60 70 80)\n");
    printf("✓ PASS\n\n");

    /* Limpiar memoria */
    bst_destruir(raiz);

    printf("=== TODAS LAS PRUEBAS PASARON ===\n");
    return 0;
}
