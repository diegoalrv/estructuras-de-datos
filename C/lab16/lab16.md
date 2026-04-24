# Laboratorio 16 — Algoritmos de Ordenamiento

**Curso:** EIN423-B · Estructuras de Datos  
**Duración:** 90 minutos  
**Horario:** 08:30 – 10:00

## Objetivos del laboratorio
- Implementar algoritmos de ordenamiento clásicos (bubble sort, selection sort, insertion sort)
- Entender merge sort y quick sort (divide y conquista)
- Comparar eficiencia (operaciones y tiempo) entre algoritmos
- Usar qsort de stdlib.h y crear ordenamiento genérico personalizado

---

# Estructura de la clase

| Hora | Actividad |
|------|-----------|
| 08:30 – 08:40 | Introducción |
| 08:40 – 09:10 | Concepto y código guiado |
| 09:10 – 09:55 | Ejercicios |
| 09:55 – 10:00 | Cierre |

---

# 1. Introducción

El **ordenamiento** es una operación fundamental en programación. Casi todo algoritmo rápido requiere datos ordenados (búsqueda binaria, análisis estadístico, etc.).

**Complejidad teórica:**
| Algoritmo | Peor caso | Promedio | Mejor caso | Espacio | Estable |
|-----------|-----------|----------|-----------|---------|---------|
| Bubble Sort | O(n²) | O(n²) | O(n) | O(1) | Sí |
| Selection Sort | O(n²) | O(n²) | O(n²) | O(1) | No |
| Insertion Sort | O(n²) | O(n²) | O(n) | O(1) | Sí |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) | Sí |
| Quick Sort | O(n²) | O(n log n) | O(n log n) | O(log n) | No |

**Ordenamiento es crítico porque:** 
- Búsqueda binaria requiere O(log n) solo si datos están ordenados
- Muchos problemas se simplifican encontrando orden
- Compiladores y sistemas operativos usan ordenamiento constantemente

---

# 2. Concepto y código guiado

## Funciones auxiliares

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void intercambiar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void imprimir_array(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int array_ordenado(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) return 0;
    }
    return 1;
}
```

## Bubble Sort (con optimización)

```c
typedef struct {
    int comparaciones;
    int intercambios;
} Estadisticas;

Estadisticas burbuja(int *arr, int n) {
    Estadisticas stats = {0, 0};
    
    for (int i = 0; i < n - 1; i++) {
        int intercambio = 0;
        for (int j = 0; j < n - i - 1; j++) {
            stats.comparaciones++;
            if (arr[j] > arr[j + 1]) {
                intercambiar(&arr[j], &arr[j + 1]);
                stats.intercambios++;
                intercambio = 1;
            }
        }
        if (!intercambio) break;  // Optimización: ya está ordenado
    }
    return stats;
}
```

## Selection Sort

```c
Estadisticas selection(int *arr, int n) {
    Estadisticas stats = {0, 0};
    
    for (int i = 0; i < n - 1; i++) {
        int minimo = i;
        for (int j = i + 1; j < n; j++) {
            stats.comparaciones++;
            if (arr[j] < arr[minimo]) {
                minimo = j;
            }
        }
        if (minimo != i) {
            intercambiar(&arr[i], &arr[minimo]);
            stats.intercambios++;
        }
    }
    return stats;
}
```

## Insertion Sort

```c
Estadisticas insertion(int *arr, int n) {
    Estadisticas stats = {0, 0};
    
    for (int i = 1; i < n; i++) {
        int clave = arr[i];
        int j = i - 1;
        
        while (j >= 0) {
            stats.comparaciones++;
            if (arr[j] > clave) {
                arr[j + 1] = arr[j];
                stats.intercambios++;
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = clave;
    }
    return stats;
}
```

## Merge Sort

```c
void merge(int *arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));
    
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
    
    free(L);
    free(R);
}

void merge_sort_rec(int *arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort_rec(arr, left, mid);
        merge_sort_rec(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void merge_sort(int *arr, int n) {
    merge_sort_rec(arr, 0, n - 1);
}
```

## Quick Sort

```c
int particionar(int *arr, int low, int high) {
    // Elegir pivot como mediana de (first, middle, last)
    int mid = low + (high - low) / 2;
    if (arr[low] > arr[mid]) intercambiar(&arr[low], &arr[mid]);
    if (arr[mid] > arr[high]) intercambiar(&arr[mid], &arr[high]);
    if (arr[low] > arr[mid]) intercambiar(&arr[low], &arr[mid]);
    
    int pivot = arr[mid];
    intercambiar(&arr[mid], &arr[high]);
    
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            intercambiar(&arr[i], &arr[j]);
        }
    }
    intercambiar(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quick_sort_rec(int *arr, int low, int high) {
    if (low < high) {
        int pi = particionar(arr, low, high);
        quick_sort_rec(arr, low, pi - 1);
        quick_sort_rec(arr, pi + 1, high);
    }
}

void quick_sort(int *arr, int n) {
    quick_sort_rec(arr, 0, n - 1);
}
```

## qsort de stdlib.h

```c
int comparar_int_asc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int comparar_int_desc(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

// Uso: qsort(arr, n, sizeof(int), comparar_int_asc);
```

---

# 3. Ejercicios

## Ejercicio 1 — Comparación de operaciones (★☆☆)

Implementa **bubble sort**, **selection sort** e **insertion sort**. Para cada algoritmo, cuenta:
- Número de comparaciones
- Número de intercambios

Prueba con tres casos de n=20:
1. Array ya ordenado: `[1, 2, 3, ..., 20]`
2. Array invertido: `[20, 19, 18, ..., 1]`
3. Array aleatorio: `[16, 3, 9, ..., 14]` (random)

Requisitos:
- Modifica cada función para retornar `Estadisticas` (comparaciones, intercambios)
- Imprime tabla comparativa

**Salida esperada:**
```
n = 20

Array ya ordenado:
┌─────────────────────┬────────────┬────────────┐
│ Algoritmo           │ Comparaciones │ Intercambios │
├─────────────────────┼────────────┼────────────┤
│ Bubble Sort         │ 19         │ 0          │
│ Selection Sort      │ 190        │ 0          │
│ Insertion Sort      │ 19         │ 0          │
└─────────────────────┴────────────┴────────────┘

Array invertido:
┌─────────────────────┬────────────┬────────────┐
│ Algoritmo           │ Comparaciones │ Intercambios │
├─────────────────────┼────────────┼────────────┤
│ Bubble Sort         │ 190        │ 190        │
│ Selection Sort      │ 190        │ 19         │
│ Insertion Sort      │ 190        │ 190        │
└─────────────────────┴────────────┴────────────┘

Array aleatorio:
┌─────────────────────┬────────────┬────────────┐
│ Algoritmo           │ Comparaciones │ Intercambios │
├─────────────────────┼────────────┼────────────┤
│ Bubble Sort         │ 95         │ 67         │
│ Selection Sort      │ 190        │ 14         │
│ Insertion Sort      │ 112        │ 78         │
└─────────────────────┴────────────┴────────────┘

Análisis:
- Bubble Sort es excelente con datos ya ordenados (optimización activa)
- Selection Sort hace siempre O(n²) comparaciones
- Insertion Sort es mejor con datos parcialmente ordenados
```

## Ejercicio 2 — Comparación de tiempo (★★☆)

Implementa **merge sort** y **quick sort** (con pivote = mediana de 3). Compara tiempo de ejecución con **bubble sort** para tamaños n ∈ {1000, 5000, 10000}.

Requisitos:
- Usa `clock()` para medir tiempo: `t_inicio = clock(); ... t_final = clock(); tiempo_ms = (t_final - t_inicio) * 1000.0 / CLOCKS_PER_SEC;`
- Crea arrays aleatorios para cada tamaño
- Mide tiempo de ordenamiento (no de creación de array)
- Imprime resultados en CSV

**Salida esperada:**
```
n,Bubble Sort (ms),Merge Sort (ms),Quick Sort (ms)
1000,450.25,5.12,4.87
5000,11234.56,32.45,28.76
10000,45123.89,78.34,71.12

Conclusión: Quick Sort y Merge Sort son órdenes de magnitud más rápidos
para datos grandes. Bubble Sort es O(n²), inaceptable para n > 1000.
```

## Ejercicio 3 — Ordenamiento genérico (★★★)

Implementa una función de ordenamiento genérica que coincida con la firma de `qsort`:

```c
void mi_quicksort(void *base, size_t nmemb, size_t size,
                  int (*compar)(const void *, const void *));
```

Prueba ordenando tres tipos de datos diferentes:
1. **int array ascendente**
2. **int array descendente** (con comparador diferente)
3. **struct Estudiante** ordenado por nota (descendente)

Requisitos:
- Implementa quicksort genérico usando aritmética de punteros `void*`
- Usa `memcpy()` para intercambiar elementos
- Crea comparadores para cada tipo
- Valida que cada resultado esté correctamente ordenado

```c
typedef struct {
    char nombre[50];
    float nota;
} Estudiante;

int comparar_estudiante_por_nota(const void *a, const void *b) {
    float nota_a = ((Estudiante*)a)->nota;
    float nota_b = ((Estudiante*)b)->nota;
    if (nota_a < nota_b) return 1;   // Descendente
    if (nota_a > nota_b) return -1;
    return 0;
}
```

**Salida esperada:**
```
Prueba 1: int array ascendente
Antes: 42 17 93 5 28 61 ...
Después: 5 17 28 42 61 93 ...
✓ Correctamente ordenado

Prueba 2: int array descendente
Antes: 42 17 93 5 28 61 ...
Después: 93 61 42 28 17 5 ...
✓ Correctamente ordenado (descendente)

Prueba 3: struct Estudiante por nota (descendente)
Antes:
  Juan: 7.5
  María: 8.9
  Pedro: 6.3
  Ana: 9.1

Después:
  Ana: 9.1
  María: 8.9
  Juan: 7.5
  Pedro: 6.3

✓ Correctamente ordenado por nota (descendente)
```

---

# Cierre

**Has recorrido todo el programa del curso:**

1. **Fundamentos:** Punteros, memoria, tipos de datos abstractos (TDA)
2. **Análisis:** Complejidad asintótica, Big-O
3. **Estructuras lineales:** Listas, pilas, colas
4. **Estructuras jerárquicas:** Árboles, árboles binarios de búsqueda
5. **Búsqueda rápida:** Hashing, tablas hash
6. **Grafos:** Representación, BFS, DFS, ciclos, ordenamiento topológico
7. **Ordenamiento:** Algoritmos clásicos y comparación de eficiencia

**Cada una de estas estructuras aparece en los sistemas que construirás como ingeniero:**
- **Listas y árboles:** Administración de memoria, compiladores
- **Hashing:** Cachés, compiladores, bases de datos
- **Grafos:** Redes sociales, navegación, compiladores
- **Ordenamiento:** Búsqueda, análisis de datos, sistemas operativos

**Consejo final:** Implementa estas estructuras desde cero en proyectos reales. No solo uses librerías — entender cómo funcionan internamente hace mejores ingenieros.

---

*EIN423-B · Departamento de Informática · UTFSM*
