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

int main(void)
{
    printf("=== PRUEBAS LAB 07: Pila (Stack) ===\n\n");

    /* Prueba 1: push y pop básicos (LIFO) */
    printf("1. Prueba push 1..5, luego pop todos (LIFO):\n");
    Pila *pila = pila_crear();
    printf("   Operaciones: push(1), push(2), push(3), push(4), push(5)\n");
    pila_push(pila, 1);
    pila_push(pila, 2);
    pila_push(pila, 3);
    pila_push(pila, 4);
    pila_push(pila, 5);
    printf("   Tamaño: %d (esperado: 5)\n", pila_tamanio(pila));

    printf("   Pop: ");
    printf("%d ", pila_pop(pila));  /* 5 */
    printf("%d ", pila_pop(pila));  /* 4 */
    printf("%d ", pila_pop(pila));  /* 3 */
    printf("%d ", pila_pop(pila));  /* 2 */
    printf("%d ", pila_pop(pila));  /* 1 */
    printf("(esperado: 5 4 3 2 1)\n");
    printf("   ¿Está vacía? %d (esperado: 1)\n\n", pila_esta_vacia(pila));

    pila_destruir(pila);

    /* Prueba 2: balanceada - casos correctos */
    printf("2. Prueba balanceada - casos correctos:\n");
    printf("   \"({[]})\"    : %d (esperado: 1)\n", balanceada("({[]})"));
    printf("   \"[[[]]]\"    : %d (esperado: 1)\n", balanceada("[[[]]]"));
    printf("   \"()\"        : %d (esperado: 1)\n", balanceada("()"));
    printf("   \"({})\"      : %d (esperado: 1)\n\n", balanceada("({})"));

    /* Prueba 3: balanceada - casos incorrectos */
    printf("3. Prueba balanceada - casos incorrectos:\n");
    printf("   \"({)}\"      : %d (esperado: 0)\n", balanceada("({)}"));
    printf("   \"(((\"       : %d (esperado: 0)\n", balanceada("((("));
    printf("   \")\"         : %d (esperado: 0)\n", balanceada(")"));
    printf("   \"([)]\"      : %d (esperado: 0)\n\n", balanceada("([)]"));

    /* Prueba 4: evaluar_postfija - casos sencillos */
    printf("4. Prueba evaluar_postfija - casos sencillos:\n");
    int res1 = evaluar_postfija("3 4 +");
    printf("   \"3 4 +\"     = %d (esperado: 7)\n", res1);

    int res2 = evaluar_postfija("10 2 -");
    printf("   \"10 2 -\"    = %d (esperado: 8)\n", res2);

    int res3 = evaluar_postfija("5 3 *");
    printf("   \"5 3 *\"     = %d (esperado: 15)\n", res3);

    int res4 = evaluar_postfija("20 4 /");
    printf("   \"20 4 /\"    = %d (esperado: 5)\n\n", res4);

    /* Prueba 5: evaluar_postfija - caso complejo */
    printf("5. Prueba evaluar_postfija - caso complejo:\n");
    printf("   \"5 1 2 + 4 * + 3 -\"\n");
    printf("   Pasos: 5 | 1 2 + (3) | 3 4 * (12) | 5 12 + (17) | 17 3 - (14)\n");
    int res5 = evaluar_postfija("5 1 2 + 4 * + 3 -");
    printf("   Resultado: %d (esperado: 14)\n\n", res5);

    printf("=== FIN DE PRUEBAS ===\n");

    return 0;
}
