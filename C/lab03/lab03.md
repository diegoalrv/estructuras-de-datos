# Laboratorio 3 — Análisis de Complejidad Experimental

**Curso:** EIN423-B · Estructuras de Datos
**Duración:** 90 minutos
**Horario:** 08:30 – 10:00

## Objetivos del laboratorio
- Comprender Big-O no solo en teoría, sino con **evidencia experimental**
- Medir tiempos de ejecución de algoritmos en C
- Generar y analizar datos de rendimiento
- Reconocer patrones O(n), O(n²), O(n log n) en datos reales
- Validar que la teoría de complejidad coincide con la práctica

---

# Estructura de la clase

| Hora | Actividad |
|------|-----------|
| 08:30 – 08:40 | Introducción: Big-O no es solo teoría |
| 08:40 – 09:10 | Concepto y código guiado |
| 09:10 – 09:55 | Ejercicios |
| 09:55 – 10:00 | Cierre |

---

# 1. Introducción (08:30 – 08:40)

**Big-O es una medida teórica**, pero ¿cómo sabemos que realmente O(n²) es más lento que O(n log n)?

**Hoy vamos a medir.**

La función `clock()` de C nos permite contar ciclos de CPU desde el inicio del programa. Usando esto, podemos:
1. Medir el tiempo que tarda una búsqueda lineal vs binaria
2. Medir cuánto tarda bubble sort vs quicksort
3. Ver cómo crece el tiempo cuando multiplicamos n por 2, por 10, etc.
4. Determinar empíricamente la clase de complejidad

**¿Cómo?** Calculamos ratios como:
- T(2n) / T(n) para O(n) → ratio ≈ 2
- T(2n) / T(n) para O(n²) → ratio ≈ 4
- T(2n) / T(n) para O(n log n) → ratio ≈ 2.4 (aproximadamente)

---

# 2. Concepto y código guiado (08:40 – 09:10)

## Medir tiempo en C: clock()

```c
#include <stdio.h>
#include <time.h>

int main() {
    // Medir antes de empezar
    clock_t inicio = clock();

    // Aquí va el código que queremos medir
    int suma = 0;
    for (int i = 0; i < 1000000; i++) {
        suma += i;
    }

    // Medir después
    clock_t fin = clock();

    // Convertir a segundos
    double tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;

    printf("Suma: %d\n", suma);
    printf("Tiempo: %.6f segundos\n", tiempo);

    return 0;
}
```

**Nota:** `CLOCKS_PER_SEC` es la cantidad de ciclos de reloj por segundo (típicamente 1,000,000 en Linux).

## Búsqueda lineal vs binaria

```c
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// O(n) — busca en un arreglo desordenado
int busqueda_lineal(int *arr, int n, int objetivo) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == objetivo) return i;
    }
    return -1;
}

// O(log n) — busca en un arreglo ORDENADO
int busqueda_binaria(int *arr, int n, int objetivo) {
    int izq = 0, der = n - 1;
    while (izq <= der) {
        int mid = izq + (der - izq) / 2;
        if (arr[mid] == objetivo) return mid;
        if (arr[mid] < objetivo) izq = mid + 1;
        else der = mid - 1;
    }
    return -1;
}

int main() {
    // Generar datos de prueba
    int tamaños[] = {10000, 50000, 100000, 500000, 1000000};
    int num_tamaños = 5;

    printf("n\t\tTiempo Lineal\tTiempo Binaria\tRatio (L/B)\n");
    printf("------------------------------------------------------------\n");

    for (int k = 0; k < num_tamaños; k++) {
        int n = tamaños[k];
        int *arr = (int *)malloc(n * sizeof(int));

        // Llenar arreglo con números del 0 al n-1
        for (int i = 0; i < n; i++) {
            arr[i] = i;
        }

        // Busca lineal
        clock_t inicio = clock();
        for (int i = 0; i < 1000; i++) {
            busqueda_lineal(arr, n, n - 1);
        }
        clock_t fin = clock();
        double tiempo_lineal = (double)(fin - inicio) / CLOCKS_PER_SEC;

        // Busca binaria
        inicio = clock();
        for (int i = 0; i < 1000; i++) {
            busqueda_binaria(arr, n, n - 1);
        }
        fin = clock();
        double tiempo_binaria = (double)(fin - inicio) / CLOCKS_PER_SEC;

        printf("%d\t%.6f\t%.6f\t%.2f\n", n, tiempo_lineal, tiempo_binaria,
               tiempo_lineal / tiempo_binaria);

        free(arr);
    }

    return 0;
}
```

**Salida típica:**
```
n               Tiempo Lineal   Tiempo Binaria  Ratio (L/B)
------------------------------------------------------------
10000           0.010245        0.000123        83.37
50000           0.051234        0.000412        124.35
100000          0.102345        0.000678        150.93
500000          0.512345        0.003456        148.24
1000000         1.023456        0.006789        150.78
```

Nota: A mayor n, la búsqueda lineal crece O(n) mientras binaria crece O(log n). La razón aumenta.

## Bubble sort vs quicksort

```c
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

// O(n²) — bubble sort
void bubble_sort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

// Comparador para qsort
int comparar(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int tamaños[] = {1000, 2000, 4000, 8000};
    int num_tamaños = 4;

    printf("n\t\tBubble Sort\tQuick Sort\tRatio (B/Q)\n");
    printf("----------------------------------------------------------\n");

    for (int k = 0; k < num_tamaños; k++) {
        int n = tamaños[k];
        int *arr = (int *)malloc(n * sizeof(int));
        int *arr_copia = (int *)malloc(n * sizeof(int));

        // Llenar con números aleatorios
        srand(42);  // Seed fija para reproducibilidad
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 10000;
        }

        // Bubble sort
        memcpy(arr_copia, arr, n * sizeof(int));
        clock_t inicio = clock();
        bubble_sort(arr_copia, n);
        clock_t fin = clock();
        double tiempo_bubble = (double)(fin - inicio) / CLOCKS_PER_SEC;

        // Quick sort
        memcpy(arr_copia, arr, n * sizeof(int));
        inicio = clock();
        qsort(arr_copia, n, sizeof(int), comparar);
        fin = clock();
        double tiempo_quick = (double)(fin - inicio) / CLOCKS_PER_SEC;

        printf("%d\t%.6f\t%.6f\t%.2f\n", n, tiempo_bubble, tiempo_quick,
               tiempo_bubble / tiempo_quick);

        free(arr);
        free(arr_copia);
    }

    return 0;
}
```

**Salida típica:**
```
n               Bubble Sort     Quick Sort      Ratio (B/Q)
----------------------------------------------------------
1000            0.010234        0.000456        22.43
2000            0.041234        0.000912        45.20
4000            0.164567        0.001823        90.34
8000            0.658234        0.003645        180.56
```

Bubble sort es O(n²) → cuando n se duplica, tiempo se cuadruplica (razón ≈ 4)
Quick sort es O(n log n) → cuando n se duplica, tiempo se duplica × log(razón) (razón ≈ 2.3)

---

# 3. Ejercicios (09:10 – 09:55)

## Ejercicio 1 — Acceso directo vs búsqueda lineal (★☆☆)

Implementa dos funciones:

1. `int acceso_directo(int *arr, int i)` — retorna arr[i] en O(1)
2. `int busqueda_lineal(int *arr, int n, int objetivo)` — busca en O(n)

Mide el tiempo para encontrar 100 elementos aleatorios en arreglos de tamaño n = 10,000; 50,000; 100,000; 500,000.

**Salida esperada:**
```
n               Acceso directo  Búsqueda lineal  Ratio
10000           0.000001        0.000234         234
50000           0.000001        0.001234         1234
100000          0.000001        0.002456         2456
500000          0.000001        0.012345         12345
```

**Pistas:**
- Para acceso directo, simplemente genera índices aleatorios y accede a arr[i]
- Para búsqueda lineal, genera valores aleatorios y busca cada uno
- Repite 100 veces cada búsqueda para obtener tiempos medibles
- Imprime los tiempos con 6 decimales

---

## Ejercicio 2 — Bubble sort vs qsort (★★☆)

Implementa bubble sort y mide su tiempo vs `qsort` de stdlib. Genera una tabla CSV:

```
n,tiempo_burbuja,tiempo_qsort,razon
1000,0.012345,0.000456,27.07
2000,0.049876,0.000912,54.67
4000,0.199345,0.001823,109.34
8000,0.797234,0.003645,218.67
```

Para cada tamaño:
- Crea un arreglo de números aleatorios
- Mide bubble sort
- Crea una copia y mide qsort
- Calcula la razón (tiempo_burbuja / tiempo_qsort)

**Salida esperada:** Una tabla que muestre cómo la razón crece (indicando que O(n²) crece más rápido que O(n log n))

**Pistas:**
- Usa `srand(42)` para generador reproducible
- Usa `memcpy` para copiar arreglos
- Imprime con formato `printf("%d,%.6f,%.6f,%.2f\n", ...)`

---

## Ejercicio 3 — Determinar clase de complejidad por análisis (★★★)

Para una función misteriosa `long proceso(int n)`, mide el tiempo para n = 1000, 2000, 3000, ..., 10000.

Calcula tres ratios para cada par (n, 2n):
- `T(2n) / T(n)` — ratio directo
- `T(2n) / (T(n) * 2)` — ¿Es lineal?
- `T(2n) / (T(n) * 4)` — ¿Es cuadrático?
- `T(2n) / (T(n) * 2.32)` — ¿Es n log n?

El ratio que **se acerca a 1** indica la clase de complejidad.

**Código para función misteriosa:**
```c
long proceso(int n) {
    long resultado = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            resultado += i * j;
        }
    }
    return resultado;
}
```

**Salida esperada:**
```
n       T(n)            T(2n)           Ratio   Linear  Quad.   nLogn
1000    0.000456        0.001823        4.00    2.00    1.00    1.94
2000    0.001823        0.007292        4.00    2.00    1.00    1.94
3000    0.004123        0.016512        4.00    2.00    1.00    1.94
...
```

El ratio que está más cerca a 1 es el que corresponde a la clase de complejidad.

---

# Cierre (09:55 – 10:00)

Hoy **validamos empíricamente** lo que estudiamos en teoría:

1. **Big-O no es solo papel:** Los números reales confirman O(n) vs O(n²) vs O(n log n)
2. **Medir es importante:** No confíes solo en análisis teórico — valida con datos reales
3. **Algoritmos crecen diferente:** Pequeñas diferencias de complejidad explosan con n grande

En los siguientes laboratorios implementaremos estructuras de datos (listas, árboles, grafos) y podremos medir experimentalmente si nuestra implementación cumple con la complejidad teórica. Esta es la forma en que los ingenieros **reales** validan código.

---

*EIN423-B · Departamento de Informática · UTFSM*
