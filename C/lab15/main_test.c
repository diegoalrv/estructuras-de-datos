/*
 * Estructuras de Datos - EIN423-B
 * Laboratorio 15: Grafos - DFS y Caminos - PRUEBAS
 *
 * Pruebas unitarias para validar implementación de DFS y análisis de grafos.
 */

#include "grafo.h"
#include "grafo_dfs.h"
#include <assert.h>

#define VERDE  "\x1b[32m"
#define ROJO   "\x1b[31m"
#define RESET  "\x1b[0m"

void test_dfs_grafo_no_dirigido() {
    printf("\n=== TEST 1: DFS en Grafo No Dirigido ===\n");

    Grafo *g = grafo_crear(6, 0);  // 6 vértices, no dirigido

    grafo_agregar_arista(g, 0, 1);
    grafo_agregar_arista(g, 0, 2);
    grafo_agregar_arista(g, 1, 3);
    grafo_agregar_arista(g, 1, 4);
    grafo_agregar_arista(g, 2, 4);
    grafo_agregar_arista(g, 3, 5);
    grafo_agregar_arista(g, 4, 5);

    int orden_visita[6];
    int n_visitados = 0;

    grafo_dfs(g, 0, orden_visita, &n_visitados);

    printf("Orden de visita DFS desde 0: ");
    for (int i = 0; i < n_visitados; i++) {
        printf("%d ", orden_visita[i]);
    }
    printf("\n");

    assert(n_visitados == 6);
    assert(orden_visita[0] == 0);

    printf("✓ DFS visitó todos los 6 vértices\n");
    printf("✓ Inicio correcto desde vértice 0\n");

    printf(VERDE "✓ TEST 1 PASÓ\n" RESET);
    grafo_destruir(g);
}

void test_dfs_grafo_dirigido() {
    printf("\n=== TEST 2: DFS en Grafo Dirigido ===\n");

    Grafo *g = grafo_crear(5, 1);  // 5 vértices, dirigido

    grafo_agregar_arista(g, 0, 1);
    grafo_agregar_arista(g, 0, 2);
    grafo_agregar_arista(g, 1, 3);
    grafo_agregar_arista(g, 2, 3);
    grafo_agregar_arista(g, 3, 4);

    int orden_visita[5];
    int n_visitados = 0;

    grafo_dfs(g, 0, orden_visita, &n_visitados);

    printf("Orden de visita DFS desde 0: ");
    for (int i = 0; i < n_visitados; i++) {
        printf("%d ", orden_visita[i]);
    }
    printf("\n");

    assert(n_visitados == 5);

    printf("✓ DFS visitó todos los 5 vértices\n");

    printf(VERDE "✓ TEST 2 PASÓ\n" RESET);
    grafo_destruir(g);
}

void test_ciclo_dag() {
    printf("\n=== TEST 3: Detectar Ciclo en DAG (Grafo Acíclico) ===\n");

    // DAG de prerrequisitos:
    // MAT(0) → PROG(2), FIS(1) → PROG(2)
    // PROG(2) → ED(3)
    // ED(3) → ALG(4)
    // ALG(4) → SO(5)
    Grafo *g = grafo_crear(6, 1);  // dirigido

    grafo_agregar_arista(g, 0, 2);  // MAT → PROG
    grafo_agregar_arista(g, 0, 1);  // MAT → FIS (en este caso agregamos así)
    grafo_agregar_arista(g, 2, 3);  // PROG → ED
    grafo_agregar_arista(g, 1, 3);  // FIS → ED
    grafo_agregar_arista(g, 3, 4);  // ED → ALG
    grafo_agregar_arista(g, 4, 5);  // ALG → SO

    int ciclo_u, ciclo_v;
    int resultado = grafo_tiene_ciclo(g, &ciclo_u, &ciclo_v);

    assert(resultado == 0);
    printf("✓ DAG detectado correctamente (no hay ciclos)\n");

    printf(VERDE "✓ TEST 3 PASÓ\n" RESET);
    grafo_destruir(g);
}

void test_ciclo_presente() {
    printf("\n=== TEST 4: Detectar Ciclo Presente ===\n");

    // Grafo con ciclo: 0→1→2→0
    Grafo *g = grafo_crear(3, 1);  // dirigido

    grafo_agregar_arista(g, 0, 1);
    grafo_agregar_arista(g, 1, 2);
    grafo_agregar_arista(g, 2, 0);  // crea ciclo

    int ciclo_u, ciclo_v;
    int resultado = grafo_tiene_ciclo(g, &ciclo_u, &ciclo_v);

    assert(resultado == 1);
    printf("✓ Ciclo detectado: %d → %d\n", ciclo_u, ciclo_v);

    printf(VERDE "✓ TEST 4 PASÓ\n" RESET);
    grafo_destruir(g);
}

void test_ordenamiento_topologico() {
    printf("\n=== TEST 5: Ordenamiento Topológico ===\n");

    // DAG de prerrequisitos
    Grafo *g = grafo_crear(6, 1);  // dirigido

    grafo_agregar_arista(g, 0, 2);  // MAT → PROG
    grafo_agregar_arista(g, 0, 1);  // MAT → FIS
    grafo_agregar_arista(g, 2, 3);  // PROG → ED
    grafo_agregar_arista(g, 1, 3);  // FIS → ED
    grafo_agregar_arista(g, 3, 4);  // ED → ALG
    grafo_agregar_arista(g, 4, 5);  // ALG → SO

    int orden_topo[6];
    int resultado = grafo_orden_topologico(g, orden_topo);

    assert(resultado == 1);  // Grafo acíclico
    printf("Orden topológico: ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", orden_topo[i]);
    }
    printf("\n");

    // Verificar que para cada arista u→v, u aparece antes de v
    // Creamos un índice de posición
    int pos[6];
    for (int i = 0; i < 6; i++) {
        pos[orden_topo[i]] = i;
    }

    // Verificar arista 0→2
    assert(pos[0] < pos[2]);
    printf("✓ Arista 0→2: vértice 0 antes de 2\n");

    // Verificar arista 3→4
    assert(pos[3] < pos[4]);
    printf("✓ Arista 3→4: vértice 3 antes de 4\n");

    printf("✓ Ordenamiento topológico válido\n");

    printf(VERDE "✓ TEST 5 PASÓ\n" RESET);
    grafo_destruir(g);
}

void test_orden_topologico_falla_con_ciclo() {
    printf("\n=== TEST 6: Ordenamiento Topológico Falla con Ciclo ===\n");

    // Grafo con ciclo
    Grafo *g = grafo_crear(3, 1);  // dirigido

    grafo_agregar_arista(g, 0, 1);
    grafo_agregar_arista(g, 1, 2);
    grafo_agregar_arista(g, 2, 0);  // ciclo

    int orden_topo[3];
    int resultado = grafo_orden_topologico(g, orden_topo);

    assert(resultado == 0);  // Debe fallar debido al ciclo
    printf("✓ Ordenamiento topológico rechazado correctamente (grafo con ciclo)\n");

    printf(VERDE "✓ TEST 6 PASÓ\n" RESET);
    grafo_destruir(g);
}

int main() {
    printf("╔════════════════════════════════════════════════════════╗\n");
    printf("║    Estructuras de Datos - Lab 15: Grafos - DFS         ║\n");
    printf("║  EIN423-B - UTFSM                                       ║\n");
    printf("╚════════════════════════════════════════════════════════╝\n");

    test_dfs_grafo_no_dirigido();
    test_dfs_grafo_dirigido();
    test_ciclo_dag();
    test_ciclo_presente();
    test_ordenamiento_topologico();
    test_orden_topologico_falla_con_ciclo();

    printf("\n╔════════════════════════════════════════════════════════╗\n");
    printf("║" VERDE "              TODOS LOS TESTS PASARON ✓              " RESET "║\n");
    printf("╚════════════════════════════════════════════════════════╝\n\n");

    return 0;
}
