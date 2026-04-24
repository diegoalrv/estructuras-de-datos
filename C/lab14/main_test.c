/*
 * Estructuras de Datos - EIN423-B
 * Laboratorio 14: Grafos - PRUEBAS
 *
 * Pruebas unitarias para validar implementación de grafos y BFS.
 */

#include "grafo.h"
#include <assert.h>

#define VERDE  "\x1b[32m"
#define ROJO   "\x1b[31m"
#define RESET  "\x1b[0m"

void test_crear_grafo() {
    printf("\n=== TEST 1: Crear Grafo ===\n");

    Grafo *g = grafo_crear(6, 0);  // 6 vértices, no dirigido
    assert(g != NULL);
    assert(g->V == 6);
    assert(g->E == 0);
    assert(g->dirigido == 0);

    printf("✓ Grafo creado: %d vértices, %d aristas\n", g->V, g->E);

    printf(VERDE "✓ TEST 1 PASÓ\n" RESET);
    grafo_destruir(g);
}

void test_agregar_aristas() {
    printf("\n=== TEST 2: Agregar Aristas ===\n");

    Grafo *g = grafo_crear(6, 0);  // 0-1-2-3-4-5

    // Aristas: 0-1, 0-2, 1-3, 1-4, 2-4, 3-5, 4-5
    grafo_agregar_arista(g, 0, 1);
    grafo_agregar_arista(g, 0, 2);
    grafo_agregar_arista(g, 1, 3);
    grafo_agregar_arista(g, 1, 4);
    grafo_agregar_arista(g, 2, 4);
    grafo_agregar_arista(g, 3, 5);
    grafo_agregar_arista(g, 4, 5);

    assert(g->E == 7);
    printf("✓ 7 aristas agregadas (no dirigido = 14 direcciones)\n");

    printf("\nRepresentación en lista de adyacencia:\n");
    grafo_imprimir(g);

    printf(VERDE "✓ TEST 2 PASÓ\n" RESET);
    grafo_destruir(g);
}

void test_grado() {
    printf("\n=== TEST 3: Grado de Vértices ===\n");

    Grafo *g = grafo_crear(6, 0);

    grafo_agregar_arista(g, 0, 1);
    grafo_agregar_arista(g, 0, 2);
    grafo_agregar_arista(g, 1, 3);
    grafo_agregar_arista(g, 1, 4);
    grafo_agregar_arista(g, 2, 4);
    grafo_agregar_arista(g, 3, 5);
    grafo_agregar_arista(g, 4, 5);

    assert(grafo_grado(g, 0) == 2);  // vecinos: 1, 2
    printf("✓ grafo_grado(0) = %d (esperado 2)\n", grafo_grado(g, 0));

    assert(grafo_grado(g, 1) == 3);  // vecinos: 0, 3, 4
    printf("✓ grafo_grado(1) = %d (esperado 3)\n", grafo_grado(g, 1));

    assert(grafo_grado(g, 5) == 2);  // vecinos: 3, 4
    printf("✓ grafo_grado(5) = %d (esperado 2)\n", grafo_grado(g, 5));

    printf(VERDE "✓ TEST 3 PASÓ\n" RESET);
    grafo_destruir(g);
}

void test_bfs() {
    printf("\n=== TEST 4: BFS desde Vértice 0 ===\n");

    Grafo *g = grafo_crear(6, 0);

    grafo_agregar_arista(g, 0, 1);
    grafo_agregar_arista(g, 0, 2);
    grafo_agregar_arista(g, 1, 3);
    grafo_agregar_arista(g, 1, 4);
    grafo_agregar_arista(g, 2, 4);
    grafo_agregar_arista(g, 3, 5);
    grafo_agregar_arista(g, 4, 5);

    int distancias[6];
    int padres[6];

    grafo_bfs(g, 0, distancias, padres);

    printf("Distancias desde 0:\n");
    for (int i = 0; i < 6; i++) {
        printf("  V%d: %d\n", i, distancias[i]);
    }

    assert(distancias[0] == 0);
    assert(distancias[1] == 1);
    assert(distancias[2] == 1);
    assert(distancias[3] == 2);
    assert(distancias[4] == 2);
    assert(distancias[5] == 3);

    printf("✓ Distancias correctas: [0, 1, 1, 2, 2, 3]\n");

    printf(VERDE "✓ TEST 4 PASÓ\n" RESET);
    grafo_destruir(g);
}

void test_caminos() {
    printf("\n=== TEST 5: Imprimir Caminos ===\n");

    Grafo *g = grafo_crear(6, 0);

    grafo_agregar_arista(g, 0, 1);
    grafo_agregar_arista(g, 0, 2);
    grafo_agregar_arista(g, 1, 3);
    grafo_agregar_arista(g, 1, 4);
    grafo_agregar_arista(g, 2, 4);
    grafo_agregar_arista(g, 3, 5);
    grafo_agregar_arista(g, 4, 5);

    int distancias[6];
    int padres[6];

    grafo_bfs(g, 0, distancias, padres);

    printf("\nCaminos más cortos desde 0:\n");

    printf("Camino 0→5 (distancia %d): ", distancias[5]);
    grafo_imprimir_camino(padres, 0, 5);
    printf("\n");

    printf("Camino 0→4 (distancia %d): ", distancias[4]);
    grafo_imprimir_camino(padres, 0, 4);
    printf("\n");

    printf("Camino 0→3 (distancia %d): ", distancias[3]);
    grafo_imprimir_camino(padres, 0, 3);
    printf("\n");

    printf(VERDE "✓ TEST 5 PASÓ\n" RESET);
    grafo_destruir(g);
}

void test_bfs_desde_vertice_intermedio() {
    printf("\n=== TEST 6: BFS desde Vértice Intermedio ===\n");

    Grafo *g = grafo_crear(6, 0);

    grafo_agregar_arista(g, 0, 1);
    grafo_agregar_arista(g, 0, 2);
    grafo_agregar_arista(g, 1, 3);
    grafo_agregar_arista(g, 1, 4);
    grafo_agregar_arista(g, 2, 4);
    grafo_agregar_arista(g, 3, 5);
    grafo_agregar_arista(g, 4, 5);

    int distancias[6];
    int padres[6];

    grafo_bfs(g, 3, distancias, padres);

    printf("Distancias desde 3:\n");
    for (int i = 0; i < 6; i++) {
        printf("  V%d: %d\n", i, distancias[i]);
    }

    assert(distancias[3] == 0);
    assert(distancias[5] == 1);
    assert(distancias[1] == 1);
    assert(distancias[0] == 2);

    printf("✓ Distancias desde vértice 3 correctas\n");

    printf(VERDE "✓ TEST 6 PASÓ\n" RESET);
    grafo_destruir(g);
}

int main() {
    printf("╔════════════════════════════════════════════════════════╗\n");
    printf("║       Estructuras de Datos - Lab 14: Grafos - BFS      ║\n");
    printf("║  EIN423-B - UTFSM                                       ║\n");
    printf("╚════════════════════════════════════════════════════════╝\n");

    test_crear_grafo();
    test_agregar_aristas();
    test_grado();
    test_bfs();
    test_caminos();
    test_bfs_desde_vertice_intermedio();

    printf("\n╔════════════════════════════════════════════════════════╗\n");
    printf("║" VERDE "              TODOS LOS TESTS PASARON ✓              " RESET "║\n");
    printf("╚════════════════════════════════════════════════════════╝\n\n");

    return 0;
}
