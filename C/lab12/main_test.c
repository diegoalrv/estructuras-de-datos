/*
 * Estructuras de Datos — EIN423-B
 * Universidad Técnica Federico Santa María
 * Laboratorio 12: Tabla Hash con Encadenamiento — Pruebas
 *
 * Estudiante: [Nombre Completo]
 * Fecha: [Fecha de entrega]
 */

#include "tabla_hash.h"
#include <assert.h>

int main(void) {
    printf("=== Pruebas de Tabla Hash con Encadenamiento ===\n\n");

    /* Test 1: Crear tabla y insertar elementos */
    printf("Test 1 - Crear tabla de tamaño 5 e insertar elementos\n");
    TablaHash *th = th_crear(5);

    printf("  Insertando: (1,10), (2,20), (6,60), (11,110), (7,70)\n");
    printf("  Notar colisiones:\n");
    printf("    1 %% 5 = %u\n", hash_entero(1, 5));
    printf("    6 %% 5 = %u\n", hash_entero(6, 5));
    printf("    11 %% 5 = %u\n", hash_entero(11, 5));
    printf("  → Todas en el mismo slot\n\n");

    th_insertar(th, 1, 10);
    th_insertar(th, 2, 20);
    th_insertar(th, 6, 60);
    th_insertar(th, 11, 110);
    th_insertar(th, 7, 70);

    printf("✓ PASS\n\n");

    /* Test 2: Imprimir tabla */
    printf("Test 2 - Visualizar tabla con colisiones\n");
    th_imprimir(th);
    printf("✓ PASS\n\n");

    /* Test 3: Buscar elementos */
    printf("Test 3 - Buscar elementos\n");
    int valor;
    int encontrado = th_buscar(th, 6, &valor);
    printf("  Buscar(6): %s (valor esperado: 60)\n",
           encontrado ? "Encontrado" : "No encontrado");
    if (encontrado) {
        printf("  Valor obtenido: %d\n", valor);
    }
    assert(encontrado && valor == 60 && "ERROR: búsqueda fallida");

    encontrado = th_buscar(th, 99, &valor);
    printf("  Buscar(99): %s (esperado: no encontrado)\n",
           encontrado ? "Encontrado" : "No encontrado");
    assert(!encontrado && "ERROR: clave fantasma encontrada");
    printf("✓ PASS\n\n");

    /* Test 4: Eliminar elemento */
    printf("Test 4 - Eliminar elemento\n");
    printf("  Antes: ");
    th_imprimir(th);

    int eliminado = th_eliminar(th, 6);
    printf("  Eliminar(6): %s\n", eliminado ? "Eliminado" : "No encontrado");
    assert(eliminado && "ERROR: no se pudo eliminar");

    encontrado = th_buscar(th, 6, &valor);
    printf("  Buscar(6) después: %s (esperado: no encontrado)\n",
           encontrado ? "Encontrado" : "No encontrado");
    assert(!encontrado && "ERROR: elemento aún existe después de eliminar");
    printf("✓ PASS\n\n");

    /* Test 5: Factor de carga y rehashing automático */
    printf("Test 5 - Rehashing automático cuando factor_carga > 0.7\n");
    printf("  Tabla actual: m=%d, n=%d, carga=%.2f\n",
           th->m, th->n, th_factor_carga(th));

    printf("  Insertando más elementos hasta que se exceda 0.7 * m...\n");
    printf("  Inserts: ");
    for (int i = 20; i <= 30; i++) {
        printf("%d ", i);
        th_insertar(th, i, i * 100);
    }
    printf("\n\n");

    printf("  Después de inserts: m=%d, n=%d, carga=%.2f\n",
           th->m, th->n, th_factor_carga(th));

    if (th->m > 5) {
        printf("  ¡Rehashing automático activado! Nuevo tamaño: %d\n", th->m);
        printf("✓ PASS\n\n");
    }

    /* Test 6: Verificar que todos los elementos siguen siendo accesibles */
    printf("Test 6 - Verificar accesibilidad de todos los elementos\n");
    printf("  Buscando elementos después de rehashing:\n");

    int elementos_encontrados = 0;
    int claves_esperadas[] = {1, 2, 7, 11, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30};
    int num_claves = 15;

    for (int i = 0; i < num_claves; i++) {
        int clave = claves_esperadas[i];
        if (th_buscar(th, clave, &valor)) {
            elementos_encontrados++;
        } else {
            printf("  ERROR: clave %d no encontrada después de rehashing\n", clave);
        }
    }

    printf("  Encontrados: %d de %d elementos esperados\n",
           elementos_encontrados, num_claves);
    assert(elementos_encontrados == num_claves &&
           "ERROR: algunos elementos se perdieron en rehashing");
    printf("✓ PASS\n\n");

    /* Test 7: Imprimir estado final */
    printf("Test 7 - Estado final de la tabla\n");
    printf("  Tabla hash final:\n");
    th_imprimir(th);
    printf("✓ PASS\n\n");

    /* Limpiar memoria */
    th_destruir(th);

    printf("=== TODAS LAS PRUEBAS PASARON ===\n");
    return 0;
}
