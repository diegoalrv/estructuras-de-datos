/*
 * Estructuras de Datos — EIN423-B
 * Universidad Técnica Federico Santa María
 * Laboratorio 11: Árbol AVL — Pruebas
 *
 * Estudiante: [Nombre Completo]
 * Fecha: [Fecha de entrega]
 */

#include "avl.h"
#include <assert.h>

int main(void) {
    printf("=== Pruebas de Árbol AVL (Auto-balanceado) ===\n\n");

    /* Test 1: Comparar BST degenerado vs AVL balanceado con secuencia 1,2,3 */
    printf("Test 1 - Insertar 1, 2, 3 (secuencia degenerada)\n");
    printf("  En BST normal: forma una cadena (altura 2) ← degenerado\n");
    printf("  En AVL: debe auto-balancearse (altura 1) ← equilibrado\n");
    NodoAVL *avl = NULL;
    avl = avl_insertar(avl, 1);
    avl = avl_insertar(avl, 2);
    avl = avl_insertar(avl, 3);

    int altura_avl = avl_altura_nodo(avl);
    printf("  Altura del AVL: %d (esperado: 1)\n", altura_avl);
    assert(altura_avl == 1 && "ERROR: altura incorrecta para AVL");

    printf("  Inorden: ");
    avl_inorden(avl);
    printf(" (esperado: 1 2 3)\n");
    printf("  ¿Es AVL válido?: %s\n", avl_es_valido(avl) ? "Sí" : "No");
    assert(avl_es_valido(avl) && "ERROR: AVL debería ser válido");
    printf("✓ PASS\n\n");

    avl_destruir(avl);

    /* Test 2: Insertar 1..7 y verificar balanceo */
    printf("Test 2 - Insertar 1..7 en AVL\n");
    avl = NULL;
    for (int i = 1; i <= 7; i++) {
        avl = avl_insertar(avl, i);
    }

    altura_avl = avl_altura_nodo(avl);
    printf("  Altura del AVL: %d (esperado: 2)\n", altura_avl);
    assert(altura_avl == 2 && "ERROR: altura incorrecta");

    printf("  ¿Es AVL válido?: %s\n", avl_es_valido(avl) ? "Sí" : "No");
    assert(avl_es_valido(avl) && "ERROR: AVL debería ser válido");
    printf("✓ PASS\n\n");

    avl_destruir(avl);

    /* Test 3: Insertar secuencia: 10,20,30,40,50,25 */
    printf("Test 3 - Insertar 10,20,30,40,50,25 (con rotaciones LR y RR)\n");
    avl = NULL;
    int valores[] = {10, 20, 30, 40, 50, 25};
    printf("  Insertando en orden: ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", valores[i]);
        avl = avl_insertar(avl, valores[i]);
    }
    printf("\n");

    printf("  Inorden: ");
    avl_inorden(avl);
    printf(" (debe estar ordenado)\n");

    printf("  ¿Es AVL válido?: %s\n", avl_es_valido(avl) ? "Sí" : "No");
    assert(avl_es_valido(avl) && "ERROR: AVL debería ser válido");
    printf("✓ PASS\n\n");

    /* Mostrar estructura del árbol */
    printf("  Estructura del árbol (visualización):\n");
    avl_imprimir_estructura(avl, 0);
    printf("\n");

    avl_destruir(avl);

    /* Test 4: Árbol más grande */
    printf("Test 4 - Insertar valores aleatorios: 5,2,8,1,3,7,10,6,4,9\n");
    avl = NULL;
    int valores2[] = {5, 2, 8, 1, 3, 7, 10, 6, 4, 9};
    for (int i = 0; i < 10; i++) {
        avl = avl_insertar(avl, valores2[i]);
    }

    printf("  Inorden: ");
    avl_inorden(avl);
    printf(" (debe estar: 1 2 3 4 5 6 7 8 9 10)\n");

    printf("  ¿Es AVL válido?: %s\n", avl_es_valido(avl) ? "Sí" : "No");
    assert(avl_es_valido(avl) && "ERROR: AVL debería ser válido");

    altura_avl = avl_altura_nodo(avl);
    printf("  Altura: %d\n", altura_avl);
    printf("✓ PASS\n\n");

    printf("  Estructura del árbol:\n");
    avl_imprimir_estructura(avl, 0);

    avl_destruir(avl);

    printf("=== TODAS LAS PRUEBAS PASARON ===\n");
    return 0;
}
