/*
 * Estructuras de Datos - EIN423-B
 * Laboratorio 16: Algoritmos de Ordenamiento - IMPLEMENTACIÓN
 *
 * Alumno: ___________________________________
 * Sección: _________________________________
 */

#include "ordenamiento.h"

/**
 * Implementación de swap_int (COMPLETA, no es TODO)
 */
void swap_int(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * Implementación de copiar_array (COMPLETA, no es TODO)
 */
void copiar_array(int *dst, const int *src, int n) {
    for (int i = 0; i < n; i++) {
        dst[i] = src[i];
    }
}

/**
 * Implementación de imprimir_array (COMPLETA, no es TODO)
 */
void imprimir_array(const int *arr, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        if (i > 0) printf(", ");
        printf("%d", arr[i]);
    }
    printf("]\n");
}

/**
 * Implementación de comparar_int_asc (COMPLETA, no es TODO)
 */
int comparar_int_asc(const void *a, const void *b) {
    int val_a = *(int *)a;
    int val_b = *(int *)b;
    return val_a - val_b;
}

/**
 * TODO: Implementar burbuja_sort
 * Compara elementos adyacentes e intercambia si están en orden incorrecto.
 * Optimización: si una pasada no realiza intercambios, el array ya está ordenado.
 * Hint: Dos bucles anidados. Mantener variable 'intercambios' que cuente o boolean.
 *       Retornar número de comparaciones realizadas.
 */
long burbuja_sort(int *arr, int n) {
    // TODO: Implementar
    return 0;
}

/**
 * TODO: Implementar seleccion_sort
 * Para cada posición i, encuentra el mínimo en arr[i..n-1] y lo intercambia.
 * Hint: Bucle externo i=0..n-2. Para cada i, encontrar índice del mínimo en [i, n-1].
 *       Intercambiar arr[i] con arr[min_idx]. Contar comparaciones.
 */
long seleccion_sort(int *arr, int n) {
    // TODO: Implementar
    return 0;
}

/**
 * TODO: Implementar insercion_sort
 * Inserta cada elemento en su posición correcta en la parte ya ordenada.
 * Hint: Bucle i=1..n-1. clave=arr[i]. Desplazar elementos >= clave hacia la derecha.
 *       Insertar clave en su posición. Contar comparaciones durante desplazamiento.
 */
long insercion_sort(int *arr, int n) {
    // TODO: Implementar
    return 0;
}

/**
 * Función auxiliar para merge_sort: mezcla dos mitades ordenadas.
 */
static void merge(int *arr, int izq, int mid, int der) {
    int n1 = mid - izq + 1;
    int n2 = der - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = arr[izq + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = izq;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }

    free(L);
    free(R);
}

/**
 * Función auxiliar recursiva para merge_sort.
 */
static void merge_sort_rec(int *arr, int izq, int der) {
    if (izq < der) {
        int mid = izq + (der - izq) / 2;
        merge_sort_rec(arr, izq, mid);
        merge_sort_rec(arr, mid + 1, der);
        merge(arr, izq, mid, der);
    }
}

/**
 * TODO: Implementar merge_sort
 * Divide el array en mitades, ordena recursivamente, luego mezcla.
 * Hint: Inicializar con merge_sort_rec(arr, 0, n-1)
 */
void merge_sort(int *arr, int n) {
    // TODO: Implementar
}

/**
 * Función auxiliar para quick_sort: partición.
 * Retorna posición del pivote después de particionar.
 */
static int particionar(int *arr, int izq, int der) {
    // Seleccionar pivote como mediana de arr[izq], arr[(izq+der)/2], arr[der]
    int mid = izq + (der - izq) / 2;
    if (arr[izq] > arr[mid]) swap_int(&arr[izq], &arr[mid]);
    if (arr[izq] > arr[der]) swap_int(&arr[izq], &arr[der]);
    if (arr[mid] > arr[der]) swap_int(&arr[mid], &arr[der]);

    // arr[mid] es la mediana, úsalo como pivote
    swap_int(&arr[mid], &arr[der]);
    int pivote = arr[der];

    int i = izq - 1;
    for (int j = izq; j < der; j++) {
        if (arr[j] < pivote) {
            i++;
            swap_int(&arr[i], &arr[j]);
        }
    }
    swap_int(&arr[i + 1], &arr[der]);
    return i + 1;
}

/**
 * Función auxiliar recursiva para quick_sort.
 */
static void quick_sort_rec(int *arr, int izq, int der) {
    if (izq < der) {
        int pi = particionar(arr, izq, der);
        quick_sort_rec(arr, izq, pi - 1);
        quick_sort_rec(arr, pi + 1, der);
    }
}

/**
 * TODO: Implementar quick_sort
 * Partición usando pivote (mediana de 3), luego recursión en ambas mitades.
 * Hint: Llamar quick_sort_rec(arr, 0, n-1)
 */
void quick_sort(int *arr, int n) {
    // TODO: Implementar
}

/**
 * TODO: Implementar mi_quicksort
 * Quick sort genérico compatible con firma de qsort.
 * Hint: Base es void*, nmemb es cantidad de elementos, size es tamaño de cada uno.
 *       Convertir base a int* (asumiendo que compar es para int).
 *       Usar quick_sort_rec pero adaptado para void* y tamaño variable.
 *       Usar memcpy para intercambios en lugar de swap_int.
 */
void mi_quicksort(void *base, size_t nmemb, size_t size,
                  int (*compar)(const void*, const void*)) {
    // TODO: Implementar
}
