/*
 * Estructuras de Datos - EIN423-B
 * Laboratorio 16: Algoritmos de Ordenamiento - PRUEBAS
 *
 * Pruebas unitarias para validar implementación de algoritmos de ordenamiento.
 */

#include "ordenamiento.h"
#include <assert.h>
#include <time.h>

#define VERDE  "\x1b[32m"
#define ROJO   "\x1b[31m"
#define RESET  "\x1b[0m"

/**
 * Verifica si un array está ordenado correctamente.
 */
static int esta_ordenado(const int *arr, int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            return 0;
        }
    }
    return 1;
}

void test_correctitud_basico() {
    printf("\n=== TEST 1: Correctitud Básica (Array Pequeño) ===\n");

    int original[] = {64, 25, 12, 22, 11};
    int esperado[] = {11, 12, 22, 25, 64};
    int n = 5;

    // Test Bubble Sort
    int arr_bubble[5];
    copiar_array(arr_bubble, original, n);
    burbuja_sort(arr_bubble, n);
    assert(esta_ordenado(arr_bubble, n));
    printf("✓ Bubble Sort: ");
    imprimir_array(arr_bubble, n);

    // Test Selection Sort
    int arr_select[5];
    copiar_array(arr_select, original, n);
    seleccion_sort(arr_select, n);
    assert(esta_ordenado(arr_select, n));
    printf("✓ Selection Sort: ");
    imprimir_array(arr_select, n);

    // Test Insertion Sort
    int arr_insert[5];
    copiar_array(arr_insert, original, n);
    insercion_sort(arr_insert, n);
    assert(esta_ordenado(arr_insert, n));
    printf("✓ Insertion Sort: ");
    imprimir_array(arr_insert, n);

    // Test Merge Sort
    int arr_merge[5];
    copiar_array(arr_merge, original, n);
    merge_sort(arr_merge, n);
    assert(esta_ordenado(arr_merge, n));
    printf("✓ Merge Sort: ");
    imprimir_array(arr_merge, n);

    // Test Quick Sort
    int arr_quick[5];
    copiar_array(arr_quick, original, n);
    quick_sort(arr_quick, n);
    assert(esta_ordenado(arr_quick, n));
    printf("✓ Quick Sort: ");
    imprimir_array(arr_quick, n);

    // Test qsort stdlib
    int arr_qsort[5];
    copiar_array(arr_qsort, original, n);
    qsort(arr_qsort, n, sizeof(int), comparar_int_asc);
    assert(esta_ordenado(arr_qsort, n));
    printf("✓ qsort stdlib: ");
    imprimir_array(arr_qsort, n);

    printf(VERDE "✓ TEST 1 PASÓ\n" RESET);
}

void test_array_ya_ordenado() {
    printf("\n=== TEST 2: Array Ya Ordenado ===\n");

    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    int arr_copy[5];
    copiar_array(arr_copy, arr, n);

    burbuja_sort(arr_copy, n);
    assert(esta_ordenado(arr_copy, n));
    printf("✓ Bubble Sort con array ordenado: ");
    imprimir_array(arr_copy, n);

    printf(VERDE "✓ TEST 2 PASÓ\n" RESET);
}

void test_array_invertido() {
    printf("\n=== TEST 3: Array Invertido ===\n");

    int arr[] = {5, 4, 3, 2, 1};
    int n = 5;

    // Test todos los algoritmos
    int arr_bubble[5], arr_select[5], arr_insert[5], arr_merge[5], arr_quick[5];

    copiar_array(arr_bubble, arr, n);
    burbuja_sort(arr_bubble, n);
    assert(esta_ordenado(arr_bubble, n));
    printf("✓ Bubble Sort: ");
    imprimir_array(arr_bubble, n);

    copiar_array(arr_select, arr, n);
    seleccion_sort(arr_select, n);
    assert(esta_ordenado(arr_select, n));
    printf("✓ Selection Sort: ");
    imprimir_array(arr_select, n);

    copiar_array(arr_insert, arr, n);
    insercion_sort(arr_insert, n);
    assert(esta_ordenado(arr_insert, n));
    printf("✓ Insertion Sort: ");
    imprimir_array(arr_insert, n);

    copiar_array(arr_merge, arr, n);
    merge_sort(arr_merge, n);
    assert(esta_ordenado(arr_merge, n));
    printf("✓ Merge Sort: ");
    imprimir_array(arr_merge, n);

    copiar_array(arr_quick, arr, n);
    quick_sort(arr_quick, n);
    assert(esta_ordenado(arr_quick, n));
    printf("✓ Quick Sort: ");
    imprimir_array(arr_quick, n);

    printf(VERDE "✓ TEST 3 PASÓ\n" RESET);
}

void test_comparativas_comparaciones() {
    printf("\n=== TEST 4: Comparativas de Comparaciones (n=20) ===\n");

    int n = 20;
    int arr_original[20] = {
        64, 34, 25, 12, 22, 11, 90, 88, 45, 50,
        32, 17, 88, 13, 14, 18, 56, 77, 99, 100
    };

    // Array ordenado
    int arr_ord[20];
    copiar_array(arr_ord, arr_original, n);
    qsort(arr_ord, n, sizeof(int), comparar_int_asc);

    printf("\n--- Array YA ORDENADO ---\n");
    long comp_bubble = burbuja_sort(arr_ord, n);
    printf("Bubble: %ld comparaciones\n", comp_bubble);

    copiar_array(arr_ord, arr_original, n);
    qsort(arr_ord, n, sizeof(int), comparar_int_asc);
    long comp_insert = insercion_sort(arr_ord, n);
    printf("Insertion: %ld comparaciones\n", comp_insert);

    copiar_array(arr_ord, arr_original, n);
    qsort(arr_ord, n, sizeof(int), comparar_int_asc);
    long comp_select = seleccion_sort(arr_ord, n);
    printf("Selection: %ld comparaciones\n", comp_select);

    // Array invertido
    printf("\n--- Array INVERTIDO ---\n");
    int arr_inv[20];
    copiar_array(arr_inv, arr_original, n);
    qsort(arr_inv, n, sizeof(int), comparar_int_asc);

    // Invertir
    for (int i = 0; i < n / 2; i++) {
        swap_int(&arr_inv[i], &arr_inv[n - 1 - i]);
    }

    comp_bubble = burbuja_sort(arr_inv, n);
    printf("Bubble: %ld comparaciones\n", comp_bubble);

    copiar_array(arr_inv, arr_original, n);
    qsort(arr_inv, n, sizeof(int), comparar_int_asc);
    for (int i = 0; i < n / 2; i++) {
        swap_int(&arr_inv[i], &arr_inv[n - 1 - i]);
    }
    comp_insert = insercion_sort(arr_inv, n);
    printf("Insertion: %ld comparaciones\n", comp_insert);

    copiar_array(arr_inv, arr_original, n);
    qsort(arr_inv, n, sizeof(int), comparar_int_asc);
    for (int i = 0; i < n / 2; i++) {
        swap_int(&arr_inv[i], &arr_inv[n - 1 - i]);
    }
    comp_select = seleccion_sort(arr_inv, n);
    printf("Selection: %ld comparaciones\n", comp_select);

    printf(VERDE "✓ TEST 4 COMPLETADO\n" RESET);
}

void test_merge_sort_completo() {
    printf("\n=== TEST 5: Merge Sort ===\n");

    int arr[] = {38, 27, 43, 3, 9, 82, 10, 15};
    int n = 8;

    printf("Original: ");
    imprimir_array(arr, n);

    merge_sort(arr, n);
    assert(esta_ordenado(arr, n));

    printf("Ordenado: ");
    imprimir_array(arr, n);

    printf(VERDE "✓ TEST 5 PASÓ\n" RESET);
}

void test_quick_sort_completo() {
    printf("\n=== TEST 6: Quick Sort ===\n");

    int arr[] = {38, 27, 43, 3, 9, 82, 10, 15};
    int n = 8;

    printf("Original: ");
    imprimir_array(arr, n);

    quick_sort(arr, n);
    assert(esta_ordenado(arr, n));

    printf("Ordenado: ");
    imprimir_array(arr, n);

    printf(VERDE "✓ TEST 6 PASÓ\n" RESET);
}

void test_edge_cases() {
    printf("\n=== TEST 7: Edge Cases ===\n");

    // Array de un elemento
    int arr1[] = {42};
    burbuja_sort(arr1, 1);
    assert(arr1[0] == 42);
    printf("✓ Array de 1 elemento\n");

    // Array de dos elementos
    int arr2[] = {2, 1};
    burbuja_sort(arr2, 2);
    assert(arr2[0] == 1 && arr2[1] == 2);
    printf("✓ Array de 2 elementos\n");

    // Array con elementos duplicados
    int arr3[] = {5, 2, 5, 2, 5, 1, 2};
    int n3 = 7;
    merge_sort(arr3, n3);
    assert(esta_ordenado(arr3, n3));
    printf("✓ Array con duplicados: ");
    imprimir_array(arr3, n3);

    printf(VERDE "✓ TEST 7 PASÓ\n" RESET);
}

int main() {
    printf("╔════════════════════════════════════════════════════════╗\n");
    printf("║   Estructuras de Datos - Lab 16: Ordenamiento         ║\n");
    printf("║  EIN423-B - UTFSM                                       ║\n");
    printf("╚════════════════════════════════════════════════════════╝\n");

    test_correctitud_basico();
    test_array_ya_ordenado();
    test_array_invertido();
    test_comparativas_comparaciones();
    test_merge_sort_completo();
    test_quick_sort_completo();
    test_edge_cases();

    printf("\n╔════════════════════════════════════════════════════════╗\n");
    printf("║" VERDE "              TODOS LOS TESTS PASARON ✓              " RESET "║\n");
    printf("╚════════════════════════════════════════════════════════╝\n\n");

    return 0;
}
