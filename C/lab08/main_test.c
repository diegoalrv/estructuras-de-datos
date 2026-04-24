/*
 * ============================================================================
 * CURSO:      Estructuras de Datos (EIN423-B)
 * UNIVERSIDAD: Universidad Técnica Federico Santa María
 * LAB:        08 - Cola (Queue) y Cola de Prioridad
 * ESTUDIANTE: [Nombre del estudiante]
 * FECHA:      Marzo 2026
 * ============================================================================
 */

#include "cola.h"
#include "cola_prioridad.h"

int main(void)
{
    printf("=== PRUEBAS LAB 08: Cola y Cola de Prioridad ===\n\n");

    /* ========== Pruebas de Cola (FIFO) ========== */
    printf("1. Prueba Cola - FIFO (First In First Out):\n");
    Cola *cola = cola_crear();
    printf("   Operaciones: enqueue 1..5\n");
    cola_enqueue(cola, 1);
    cola_enqueue(cola, 2);
    cola_enqueue(cola, 3);
    cola_enqueue(cola, 4);
    cola_enqueue(cola, 5);
    printf("   Tamaño: %d (esperado: 5)\n", cola_tamanio(cola));

    printf("   Frente actual: %d (esperado: 1)\n", cola_frente(cola));

    printf("   Dequeue todos: ");
    printf("%d ", cola_dequeue(cola));  /* 1 */
    printf("%d ", cola_dequeue(cola));  /* 2 */
    printf("%d ", cola_dequeue(cola));  /* 3 */
    printf("%d ", cola_dequeue(cola));  /* 4 */
    printf("%d ", cola_dequeue(cola));  /* 5 */
    printf("(esperado: 1 2 3 4 5)\n");
    printf("   ¿Está vacía? %d (esperado: 1)\n\n", cola_esta_vacia(cola));

    cola_destruir(cola);

    /* ========== Pruebas de Cola de Prioridad (Min-Heap) ========== */
    printf("2. Prueba Cola de Prioridad - Min-Heap:\n");
    ColaPrioridad *cp = cp_crear();
    printf("   ¿Está vacía? %d (esperado: 1)\n", cp_esta_vacia(cp));
    printf("   Insertando elementos con sus prioridades:\n");

    printf("     Insertar (valor=10, prioridad=3)\n");
    cp_insertar(cp, 10, 3);

    printf("     Insertar (valor=20, prioridad=1)\n");
    cp_insertar(cp, 20, 1);

    printf("     Insertar (valor=30, prioridad=2)\n");
    cp_insertar(cp, 30, 2);

    printf("     Insertar (valor=5, prioridad=5)\n");
    cp_insertar(cp, 5, 5);

    printf("     Insertar (valor=15, prioridad=1)\n");
    cp_insertar(cp, 15, 1);

    printf("\n   Verificando mínimo (sin extraer): ");
    ElementoHeap min1 = cp_ver_minimo(cp);
    printf("valor=%d, prioridad=%d\n", min1.valor, min1.prioridad);
    printf("   (Esperado: prioridad=1, puede ser valor=20 o valor=15)\n\n");

    printf("   Extrayendo elementos en orden de prioridad:\n");
    ElementoHeap elem1 = cp_extraer_minimo(cp);
    printf("     1º extraído: valor=%d, prioridad=%d (esperado: prioridad=1)\n",
           elem1.valor, elem1.prioridad);

    ElementoHeap elem2 = cp_extraer_minimo(cp);
    printf("     2º extraído: valor=%d, prioridad=%d (esperado: prioridad=1)\n",
           elem2.valor, elem2.prioridad);

    ElementoHeap elem3 = cp_extraer_minimo(cp);
    printf("     3º extraído: valor=%d, prioridad=%d (esperado: prioridad=2)\n",
           elem3.valor, elem3.prioridad);

    ElementoHeap elem4 = cp_extraer_minimo(cp);
    printf("     4º extraído: valor=%d, prioridad=%d (esperado: prioridad=3)\n",
           elem4.valor, elem4.prioridad);

    ElementoHeap elem5 = cp_extraer_minimo(cp);
    printf("     5º extraído: valor=%d, prioridad=%d (esperado: prioridad=5)\n",
           elem5.valor, elem5.prioridad);

    printf("\n   ¿Está vacía? %d (esperado: 1)\n\n", cp_esta_vacia(cp));

    cp_destruir(cp);

    printf("=== FIN DE PRUEBAS ===\n");

    return 0;
}
