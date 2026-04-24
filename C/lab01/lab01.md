# Laboratorio 1 — Introducción a C y Punteros Básicos

## Objetivos del laboratorio
- Comprender el concepto de dirección de memoria y variables
- Dominar los operadores `&` (dirección) y `*` (desreferencia)
- Implementar funciones que modifican variables mediante punteros
- Usar aritmética de punteros para recorrer arreglos
- Reconocer por qué los punteros son fundamentales en estructuras de datos dinámicas

---

# 1. Introducción

En C, los punteros son **la piedra angular de todas las estructuras de datos dinámicas**. Sin ellos, no podemos:
- Crear listas enlazadas
- Implementar árboles
- Manejar memoria dinámica con `malloc` y `free`
- Pasar variables por referencia para modificarlas

**¿El problema?** Las variables normales (como `int x = 5`) viven en la **pila (stack)**, con una **dirección de memoria fija**. Si quiero que dos funciones compartan y modifiquen el mismo dato, necesito un puntero.

**La solución:** Los punteros son simplemente **variables que almacenan direcciones de memoria**. Con ellos, podemos:
1. Acceder a la dirección donde vive un dato (`&x`)
2. Modificar el dato a través de esa dirección (`*p = 10`)
3. Pasar direcciones a funciones (sin copiar datos)

Hoy practicaremos con arreglos simples, funciones de intercambio, y aritmética de punteros.

---

# 2. Concepto y código guiado

## El operador & (dirección) y * (desreferencia)

```c
#include <stdio.h>

int main() {
    int x = 5;                    // Variable: valor = 5
    int *p = &x;                  // Puntero p apunta a dirección de x

    printf("Valor de x: %d\n", x);           // Imprime: 5
    printf("Dirección de x: %p\n", (void*)p); // Imprime: 0x7fff5fbff8ac (o similar)
    printf("Valor vía puntero: %d\n", *p);   // Imprime: 5

    // Modificar x a través del puntero
    *p = 10;
    printf("Nuevo valor de x: %d\n", x);     // Imprime: 10

    return 0;
}
```

**Explicación:**
- `int x = 5;` — Crea variable `x` en memoria (con dirección, p. ej., `0x1000`)
- `int *p = &x;` — `p` ahora contiene la dirección de `x`. El `&` significa "dame la dirección de"
- `*p` — El `*` significa "dame el valor al que apunta p" (desreferencia)
- `*p = 10;` — Modifica el valor en la dirección que apunta `p`, es decir, modifica `x`

## El problema sin punteros: función swap fallida

```c
#include <stdio.h>

// INCORRECTO: int a y int b son COPIAS locales
void swap_mal(int a, int b) {
    int tmp = a;
    a = b;
    b = tmp;
    // Aquí a y b se intercambian, pero son copias locales
    // La función retorna sin modificar las variables originales
}

int main() {
    int x = 5, y = 10;
    printf("Antes: x=%d, y=%d\n", x, y);

    swap_mal(x, y);
    printf("Después (MAL): x=%d, y=%d\n", x, y);
    // Imprime: x=5, y=10 — ¡No funcionó!

    return 0;
}
```

## La solución: swap con punteros

```c
#include <stdio.h>

// CORRECTO: recibimos punteros a las variables originales
void swap(int *a, int *b) {
    int tmp = *a;    // tmp = valor original de a
    *a = *b;         // a apunta ahora al valor de b
    *b = tmp;        // b apunta ahora al valor original de a
}

int main() {
    int x = 5, y = 10;
    printf("Antes: x=%d, y=%d\n", x, y);

    swap(&x, &y);  // Pasamos direcciones, no valores
    printf("Después (CORRECTO): x=%d, y=%d\n", x, y);
    // Imprime: x=10, y=5 — ¡Funcionó!

    return 0;
}
```

## Aritmética de punteros: recorrer arreglos

Los punteros pueden sumar enteros para "saltar" a elementos en arreglos.

```c
#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int *p = arr;  // p apunta al primer elemento (arr == &arr[0])

    // Forma 1: con *p y +
    printf("arr[0] = %d (vía *p: %d)\n", arr[0], *p);       // 10, 10
    printf("arr[1] = %d (vía *(p+1): %d)\n", arr[1], *(p+1)); // 20, 20
    printf("arr[2] = %d (vía *(p+2): %d)\n", arr[2], *(p+2)); // 30, 30

    // Forma 2: iterar con punteros
    printf("\nIterando con puntero:\n");
    for (int i = 0; i < 5; i++) {
        printf("*(p+%d) = %d\n", i, *(p + i));
    }

    // Forma 3: incrementar puntero
    printf("\nUsando p++ para iterar:\n");
    int *q = arr;
    for (int i = 0; i < 5; i++) {
        printf("%d ", *q);
        q++;  // q apunta al siguiente elemento
    }
    printf("\n");

    return 0;
}
```

**Nota importante:** `*(p+2)` es **exactamente lo mismo** que `arr[2]`. El compilador de C traduce `arr[i]` internamente a `*(arr + i)`.

## Ejemplo integrado: procesar arreglo con punteros

```c
#include <stdio.h>

// Función que suma todos los elementos de un arreglo usando punteros
int suma_arreglo(int *arr, int n) {
    int suma = 0;
    for (int *p = arr; p < arr + n; p++) {
        suma += *p;  // Suma el valor al que apunta p
    }
    return suma;
}

// Función que encuentra el máximo usando punteros
int maximo_arreglo(int *arr, int n) {
    int max = *arr;  // El primero es el máximo inicial
    for (int *p = arr + 1; p < arr + n; p++) {
        if (*p > max) {
            max = *p;
        }
    }
    return max;
}

int main() {
    int numeros[] = {15, 3, 42, 8, 27, 12};
    int n = 6;

    printf("Arreglo: ");
    for (int i = 0; i < n; i++) printf("%d ", numeros[i]);
    printf("\n");

    printf("Suma: %d\n", suma_arreglo(numeros, n));      // 107
    printf("Máximo: %d\n", maximo_arreglo(numeros, n));  // 42

    return 0;
}
```

---

# 3. Ejercicios (09:10 – 09:55)

## Ejercicio 1 — Intercambio con punteros (★☆☆)

Implementa una función `void swap(int *a, int *b)` que intercambie los valores de dos enteros. En el `main`, lee dos enteros desde la entrada estándar y muestra el resultado antes y después del intercambio.

**Entrada:**
```
5 10
```

**Salida esperada:**
```
Antes: a=5, b=10
Después: a=10, b=5
```

**Pistas:**
- Usa `scanf` para leer dos enteros
- Llama a `swap` pasando direcciones con `&`
- Usa una variable temporal para guardar un valor durante el intercambio

---

## Ejercicio 2 — Estadísticas de arreglo (★★☆)

Implementa la función:
```c
void estadisticas(int *arr, int n, int *max, int *min, double *prom)
```

Esta función recibe un arreglo de `n` enteros y **devuelve** (mediante punteros de salida) el máximo, mínimo y promedio.

**Ejemplo en main:**
```c
int arr[] = {10, 25, 15, 30, 5};
int maximo, minimo;
double promedio;

estadisticas(arr, 5, &maximo, &minimo, &promedio);

printf("Máximo: %d\n", maximo);       // 30
printf("Mínimo: %d\n", minimo);       // 5
printf("Promedio: %.2f\n", promedio); // 17.00
```

**Pistas:**
- El primer argumento es un puntero al arreglo (entrada)
- Los tres últimos son punteros a variables donde guardarás los resultados (salida)
- Usa `*max = valor` para guardar a través del puntero
- Para el promedio, suma todos y divide entre `n` (cuidado con tipos)

---

## Ejercicio 3 — Invertir arreglo in-place (★★★)

Implementa la función:
```c
void invertir(int *arr, int n)
```

que **invierte el arreglo en el mismo lugar** (in-place) usando **solo aritmética de punteros**, sin indexación con `[]`.

**Ejemplo:**
```c
int arr[] = {1, 2, 3, 4, 5};
invertir(arr, 5);
// arr ahora es {5, 4, 3, 2, 1}
```

**Pistas:**
- Usa dos punteros: uno desde el inicio (`arr`) y otro desde el final (`arr + n - 1`)
- En cada iteración, intercambia los valores apuntados
- Detente cuando los punteros se crucen (izquierda >= derecha)
- NO uses indexación `arr[i]`, solo punteros y aritmética

**Código parcial:**
```c
void invertir(int *arr, int n) {
    int *izq = arr;
    int *der = arr + n - 1;

    while (izq < der) {
        // Aquí haz el swap de *izq y *der
        // Luego avanza los punteros
    }
}
```

---

# Cierre (09:55 – 10:00)

Hoy aprendimos que los **punteros permiten acceso directo a memoria**. Esto es esencial porque:

1. **Modificar datos en funciones:** Sin punteros, las funciones solo ven copias de variables.
2. **Aritmética de punteros:** Podemos recorrer y procesar arreglos de forma elegante.
3. **Paso de parámetros eficiente:** Pasamos direcciones (8 bytes) en lugar de copiar arreglos enormes.

En el próximo laboratorio estudiaremos **recursividad**, que también usa punteros para manejar la pila de llamadas. Más adelante veremos cómo los punteros son absolutamente críticos para listas enlazadas, árboles y otras estructuras dinámicas.

---

*EIN423-B · Departamento de Informática · UTFSM*
