# Laboratorio 2 — Recursividad

**Curso:** EIN423-B · Estructuras de Datos
**Duración:** 90 minutos
**Horario:** 08:30 – 10:00

## Objetivos del laboratorio
- Comprender el concepto fundamental de recursividad: caso base y caso recursivo
- Comparar soluciones iterativas vs recursivas
- Analizar la pila de llamadas (call stack) en procesos recursivos
- Implementar funciones recursivas eficientes
- Identificar problemas donde la recursión es la solución natural

---

# Estructura de la clase

| Hora | Actividad |
|------|-----------|
| 08:30 – 08:40 | Introducción: ¿Qué es recursividad? |
| 08:40 – 09:10 | Concepto y código guiado |
| 09:10 – 09:55 | Ejercicios |
| 09:55 – 10:00 | Cierre |

---

# 1. Introducción (08:30 – 08:40)

La **recursividad** es una técnica donde una función **se llama a sí misma** para resolver un problema más pequeño.

**Las dos reglas fundamentales:**

1. **Caso base:** Una condición donde la función **NO se llama a sí misma** y retorna un valor directo. Sin caso base, tenemos **recursión infinita**.

2. **Caso recursivo:** La función se llama a sí misma con un problema **más pequeño** que el original.

**¿Por qué recursividad?**
- Algunos problemas son naturalmente recursivos: factoriales, búsqueda en árboles, recorridos de grafos.
- El código es más conciso y a menudo más legible que la versión iterativa.
- En estructura de datos (árboles, grafos), la recursividad es casi inevitable.

**Nota importante:** Cada llamada recursiva usa espacio en la **pila de llamadas (call stack)**. Si la recursión es muy profunda, podemos causar **stack overflow**.

---

# 2. Concepto y código guiado (08:40 – 09:10)

## Factorial: iterativo vs recursivo

**Versión iterativa:**
```c
#include <stdio.h>

// Iterativo: factorial(5) = 5 * 4 * 3 * 2 * 1 = 120
int factorial_iterativo(int n) {
    int resultado = 1;
    for (int i = 2; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

int main() {
    printf("factorial_iterativo(5) = %d\n", factorial_iterativo(5));  // 120
    return 0;
}
```

**Versión recursiva:**
```c
#include <stdio.h>

// Recursivo: factorial(n) = n * factorial(n-1)
// Caso base: factorial(0) = 1 o factorial(1) = 1
int factorial_recursivo(int n) {
    if (n <= 1) {
        return 1;  // CASO BASE
    }
    return n * factorial_recursivo(n - 1);  // CASO RECURSIVO
}

int main() {
    printf("factorial_recursivo(5) = %d\n", factorial_recursivo(5));  // 120
    return 0;
}
```

**¿Cómo funciona `factorial_recursivo(5)`?**

```
factorial_recursivo(5)
  = 5 * factorial_recursivo(4)
    = 5 * (4 * factorial_recursivo(3))
      = 5 * (4 * (3 * factorial_recursivo(2)))
        = 5 * (4 * (3 * (2 * factorial_recursivo(1))))
          = 5 * (4 * (3 * (2 * 1)))  ← CASO BASE
        = 5 * (4 * (3 * 2))
      = 5 * (4 * 6)
    = 5 * 24
  = 120
```

## Fibonacci: O(2^n) vs O(n)

**Fibonacci ingenuo (LENTO - exponencial):**
```c
#include <stdio.h>

// fibonacci(n) = fibonacci(n-1) + fibonacci(n-2)
// fibonacci(5) calcula fibonacci(4) y fibonacci(3)
// fibonacci(4) calcula fibonacci(3) y fibonacci(2)
// ¡fibonacci(3) se calcula múltiples veces! → exponencial O(2^n)
int fibonacci_naive(int n) {
    if (n <= 1) {
        return n;  // CASO BASE: fib(0)=0, fib(1)=1
    }
    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);  // CASO RECURSIVO
}

int main() {
    printf("fibonacci_naive(10) = %d\n", fibonacci_naive(10));  // 55
    // Pero esto es MUY LENTO para n > 40
    return 0;
}
```

**Por qué es lento:**
- `fibonacci_naive(5)` llama a `fibonacci_naive(4)` y `fibonacci_naive(3)`
- `fibonacci_naive(4)` llama a `fibonacci_naive(3)` y `fibonacci_naive(2)`
- Note que `fibonacci_naive(3)` se calcula **dos veces**
- En general, `fibonacci_naive(n)` hace ~2^n llamadas

**Fibonacci iterativo (RÁPIDO - lineal):**
```c
#include <stdio.h>

int fibonacci_iterativo(int n) {
    if (n <= 1) return n;

    int a = 0, b = 1;
    for (int i = 2; i <= n; i++) {
        int tmp = a + b;
        a = b;
        b = tmp;
    }
    return b;
}

int main() {
    printf("fibonacci_iterativo(10) = %d\n", fibonacci_iterativo(10));  // 55
    // Esto es instant para n < 100
    return 0;
}
```

## Recursividad con traza: visualizar la pila

```c
#include <stdio.h>

int nivel_profundidad = 0;

int factorial_con_traza(int n) {
    // Imprime la entrada
    for (int i = 0; i < nivel_profundidad; i++) printf("  ");
    printf("→ factorial(%d)\n", n);

    nivel_profundidad++;

    if (n <= 1) {
        // Caso base
        for (int i = 0; i < nivel_profundidad - 1; i++) printf("  ");
        printf("← factorial(%d) retorna 1 (caso base)\n", n);
        nivel_profundidad--;
        return 1;
    }

    int resultado = n * factorial_con_traza(n - 1);

    // Imprime la salida
    nivel_profundidad--;
    for (int i = 0; i < nivel_profundidad; i++) printf("  ");
    printf("← factorial(%d) retorna %d\n", n, resultado);

    return resultado;
}

int main() {
    printf("Traza de factorial_con_traza(4):\n");
    printf("Resultado: %d\n", factorial_con_traza(4));
    return 0;
}

/* Salida:
Traza de factorial_con_traza(4):
→ factorial(4)
  → factorial(3)
    → factorial(2)
      → factorial(1)
        ← factorial(1) retorna 1 (caso base)
      ← factorial(2) retorna 2
    ← factorial(3) retorna 6
  ← factorial(4) retorna 24
Resultado: 24
*/
```

## Búsqueda binaria recursiva

```c
#include <stdio.h>

// Busca el valor 'objetivo' en arr[izq..der]
// Retorna el índice si encuentra, -1 si no
int busqueda_binaria(int *arr, int izq, int der, int objetivo) {
    if (izq > der) {
        return -1;  // CASO BASE: no encontrado
    }

    int mid = izq + (der - izq) / 2;
    int valor_mid = arr[mid];

    if (valor_mid == objetivo) {
        return mid;  // CASO BASE: encontrado
    } else if (valor_mid < objetivo) {
        // Busca en la mitad derecha
        return busqueda_binaria(arr, mid + 1, der, objetivo);
    } else {
        // Busca en la mitad izquierda
        return busqueda_binaria(arr, izq, mid - 1, objetivo);
    }
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 67, 78};
    int n = 11;

    printf("Arreglo: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    int objetivo = 23;
    int resultado = busqueda_binaria(arr, 0, n - 1, objetivo);

    if (resultado != -1) {
        printf("Encontrado %d en índice %d\n", objetivo, resultado);
    } else {
        printf("%d no encontrado\n", objetivo);
    }

    return 0;
}
```

---

# 3. Ejercicios (09:10 – 09:55)

## Ejercicio 1 — Factorial y Fibonacci (★☆☆)

Implementa dos funciones recursivas:

1. `int factorial(int n)` — retorna n!
2. `int fibonacci(int n)` — retorna el n-ésimo número de Fibonacci

En el `main`, calcula e imprime ambas para n = 0, 1, 2, ..., 10.

**Salida esperada:**
```
n=0: factorial=1, fibonacci=0
n=1: factorial=1, fibonacci=1
n=2: factorial=2, fibonacci=1
n=3: factorial=6, fibonacci=2
...
n=10: factorial=3628800, fibonacci=55
```

**Pistas:**
- Para factorial: caso base es n ≤ 1 → retorna 1
- Para Fibonacci: caso base es n ≤ 1 → retorna n
- Usa `printf` con un bucle para mostrar ambos
- **Advertencia:** No calcules fibonacci para n > 40, ¡será muy lento!

---

## Ejercicio 2 — Búsqueda binaria recursiva (★★☆)

Implementa:
```c
int busqueda_binaria(int *arr, int izq, int der, int objetivo)
```

que realiza búsqueda binaria de forma recursiva. En el `main`:
1. Crea un arreglo ordenado de 20 números
2. Busca 5 valores diferentes (algunos presentes, otros no)
3. Imprime el índice si se encuentra, o "no encontrado"

**Ejemplo:**
```c
int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39};
// Busca 15 → índice 7
// Busca 20 → no encontrado
```

**Pistas:**
- El caso base es cuando `izq > der` (no encontrado) o cuando encuentras el valor
- Para el caso recursivo, compara con el elemento del medio (`mid = (izq + der) / 2`)
- Si el objetivo es menor, busca en la mitad izquierda; si es mayor, en la derecha

---

## Ejercicio 3 — Torres de Hanói (★★★)

Las **Torres de Hanói** es un clásico juego recursivo. Tienes 3 varillas (origen, auxiliar, destino) y n discos de tamaños diferentes. El objetivo es mover todos los discos de origen a destino con estas reglas:
- Solo puedes mover un disco a la vez
- Nunca puedes poner un disco grande sobre uno pequeño

Implementa:
```c
void hanoi(int n, char origen, char destino, char auxiliar)
```

que imprime cada movimiento (p. ej., "Mover disco 1 de A a C"). Además:
1. **Cuenta el número total de movimientos** y verifica que = 2^n - 1
2. Imprime todos los movimientos para n = 1, 2, 3, 4

**Ejemplo para n=2:**
```
Mover disco 1 de A a B
Mover disco 2 de A a C
Mover disco 1 de B a C
Total de movimientos: 3 (= 2^2 - 1)
```

**Pistas:**
- La idea recursiva: para mover n discos de origen a destino usando auxiliar:
  1. Mueve n-1 discos de origen a auxiliar (usando destino como temporal)
  2. Mueve el disco n de origen a destino
  3. Mueve n-1 discos de auxiliar a destino (usando origen como temporal)
- El caso base es n = 1: simplemente mueve el disco

**Código parcial:**
```c
int movimientos = 0;

void hanoi(int n, char origen, char destino, char auxiliar) {
    if (n == 1) {
        printf("Mover disco 1 de %c a %c\n", origen, destino);
        movimientos++;
        return;
    }

    // Mover n-1 discos de origen a auxiliar
    // Mover disco n de origen a destino
    // Mover n-1 discos de auxiliar a destino
}
```

---

# Cierre (09:55 – 10:00)

La recursividad es una **herramienta poderosa** cuando:
- El problema tiene estructura recursiva natural (factorial, Fibonacci, Torres de Hanói)
- Necesitas recorrer estructuras anidadas (árboles, grafos, directorios)

**Lecciones importantes:**
1. **Siempre necesitas un caso base** para evitar recursión infinita
2. **La recursión usa pila (call stack)** — demasiada profundidad causa stack overflow
3. **A veces la iteración es más eficiente** — Fibonacci iterativo es mucho más rápido que el recursivo

En los próximos laboratorios veremos árboles y grafos, donde la recursividad será **esencial**. También aprenderemos a optimizar recursión con técnicas como **memoización** y **programación dinámica**.

---

*EIN423-B · Departamento de Informática · UTFSM*
