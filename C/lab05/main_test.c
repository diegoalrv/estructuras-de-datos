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

int main(void)
{
    printf("=== PRUEBAS LAB 05: Lista Enlazada Simple ===\n\n");

    /* Crear lista vacía */
    Lista *lista = lista_crear();
    printf("1. Lista vacía creada.\n");
    printf("   ¿Está vacía? %d (esperado: 1)\n", lista_esta_vacia(lista));
    printf("   Tamaño: %d (esperado: 0)\n\n", lista_tamanio(lista));

    /* Prueba: push_front con 3, 2, 1 (debe quedar [1, 2, 3]) */
    printf("2. Prueba push_front(3), push_front(2), push_front(1):\n");
    lista_push_front(lista, 3);
    lista_push_front(lista, 2);
    lista_push_front(lista, 1);
    printf("   Lista: ");
    lista_imprimir(lista);
    printf("   Tamaño: %d (esperado: 3)\n\n", lista_tamanio(lista));

    /* Prueba: push_back con 4, 5 (debe quedar [1, 2, 3, 4, 5]) */
    printf("3. Prueba push_back(4), push_back(5):\n");
    lista_push_back(lista, 4);
    lista_push_back(lista, 5);
    printf("   Lista: ");
    lista_imprimir(lista);
    printf("   Tamaño: %d (esperado: 5)\n\n", lista_tamanio(lista));

    /* Prueba: buscar */
    printf("4. Prueba buscar:\n");
    printf("   Buscar 3: índice %d (esperado: 2)\n", lista_buscar(lista, 3));
    printf("   Buscar 5: índice %d (esperado: 4)\n", lista_buscar(lista, 5));
    printf("   Buscar 99: índice %d (esperado: -1)\n\n", lista_buscar(lista, 99));

    /* Prueba: obtener */
    printf("5. Prueba obtener:\n");
    printf("   Obtener índice 0: %d (esperado: 1)\n", lista_obtener(lista, 0));
    printf("   Obtener índice 2: %d (esperado: 3)\n", lista_obtener(lista, 2));
    printf("   Obtener índice 4: %d (esperado: 5)\n", lista_obtener(lista, 4));
    printf("   Obtener índice 10: %d (esperado: -1)\n\n", lista_obtener(lista, 10));

    /* Prueba: pop_front */
    printf("6. Prueba pop_front:\n");
    int valor = lista_pop_front(lista);
    printf("   Sacado: %d (esperado: 1)\n", valor);
    printf("   Lista: ");
    lista_imprimir(lista);
    printf("   Tamaño: %d (esperado: 4)\n\n", lista_tamanio(lista));

    /* Prueba: eliminar */
    printf("7. Prueba eliminar(3):\n");
    int eliminado = lista_eliminar(lista, 3);
    printf("   ¿Eliminado? %d (esperado: 1)\n", eliminado);
    printf("   Lista: ");
    lista_imprimir(lista);
    printf("   Tamaño: %d (esperado: 3)\n\n", lista_tamanio(lista));

    /* Prueba: invertir */
    printf("8. Prueba invertir:\n");
    lista_invertir(lista);
    printf("   Lista invertida: ");
    lista_imprimir(lista);
    printf("   Tamaño: %d (esperado: 3)\n\n", lista_tamanio(lista));

    /* Limpiar */
    lista_destruir(lista);
    printf("9. Lista destruida.\n");
    printf("\n=== FIN DE PRUEBAS ===\n");

    return 0;
}
