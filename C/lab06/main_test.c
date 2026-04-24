/*
 * ============================================================================
 * CURSO:      Estructuras de Datos (EIN423-B)
 * UNIVERSIDAD: Universidad Técnica Federico Santa María
 * LAB:        06 - Lista Doblemente Enlazada
 * ESTUDIANTE: [Nombre del estudiante]
 * FECHA:      Marzo 2026
 * ============================================================================
 */

#include "lista_doble.h"

int main(void)
{
    printf("=== PRUEBAS LAB 06: Lista Doblemente Enlazada ===\n\n");

    /* Crear lista vacía */
    ListaDoble *lista = listad_crear();
    printf("1. Lista vacía creada.\n");
    printf("   ¿Está vacía? %d (esperado: 1)\n\n", listad_esta_vacia(lista));

    /* Prueba: push_back 1, 2, 3, 4, 5 */
    printf("2. Prueba push_back(1), push_back(2), ..., push_back(5):\n");
    listad_push_back(lista, 1);
    listad_push_back(lista, 2);
    listad_push_back(lista, 3);
    listad_push_back(lista, 4);
    listad_push_back(lista, 5);
    printf("   Adelante: ");
    listad_imprimir_adelante(lista);
    printf("   Atrás:    ");
    listad_imprimir_atras(lista);
    printf("\n");

    /* Prueba: insertar_ordenado en lista nueva */
    printf("3. Prueba insertar_ordenado en lista nueva:\n");
    ListaDoble *lista2 = listad_crear();
    printf("   Insertando: 5, 3, 1, 4, 2 (debe quedar ordenada: 1,2,3,4,5)\n");
    listad_insertar_ordenado(lista2, 5);
    listad_insertar_ordenado(lista2, 3);
    listad_insertar_ordenado(lista2, 1);
    listad_insertar_ordenado(lista2, 4);
    listad_insertar_ordenado(lista2, 2);
    printf("   Resultado:  ");
    listad_imprimir_adelante(lista2);
    printf("\n");

    /* Prueba: pop_back 3 veces en lista2 */
    printf("4. Prueba pop_back 3 veces en lista2:\n");
    int val = listad_pop_back(lista2);
    printf("   Pop 1: %d (esperado: 5)\n", val);
    val = listad_pop_back(lista2);
    printf("   Pop 2: %d (esperado: 4)\n", val);
    val = listad_pop_back(lista2);
    printf("   Pop 3: %d (esperado: 3)\n", val);
    printf("   Resultado: ");
    listad_imprimir_adelante(lista2);
    printf("\n");

    /* Prueba: deque (push_front, push_back, pop_front, pop_back) */
    printf("5. Prueba deque (push_front/push_back, pop_front/pop_back):\n");
    ListaDoble *deque = listad_crear();
    printf("   Push_front 'a' (valor=10):     ");
    listad_push_front(deque, 10);
    listad_imprimir_adelante(deque);
    printf("   Push_back  'b' (valor=20):     ");
    listad_push_back(deque, 20);
    listad_imprimir_adelante(deque);
    printf("   Pop_front (esperado 10):   %d\n", listad_pop_front(deque));
    printf("   Pop_back (esperado 20):    %d\n", listad_pop_back(deque));
    printf("   ¿Está vacía? %d (esperado: 1)\n\n", listad_esta_vacia(deque));

    /* Prueba: eliminar */
    printf("6. Prueba eliminar en lista original:\n");
    printf("   Antes:    ");
    listad_imprimir_adelante(lista);
    int eliminado = listad_eliminar(lista, 3);
    printf("   ¿Eliminado 3? %d (esperado: 1)\n", eliminado);
    printf("   Después:  ");
    listad_imprimir_adelante(lista);
    printf("\n");

    /* Limpiar */
    listad_destruir(lista);
    listad_destruir(lista2);
    listad_destruir(deque);
    printf("7. Listas destruidas.\n");
    printf("\n=== FIN DE PRUEBAS ===\n");

    return 0;
}
