# Laboratorio 10 — Recorridos y Operaciones Avanzadas en Árboles

**Curso:** EIN423-B · Estructuras de Datos
**Duración:** 90 minutos
**Horario:** 08:30 – 10:00

## Objetivos del laboratorio
- Dominar los 4 recorridos principales de árboles: inorden, preorden, postorden y por niveles (BFS)
- Implementar operaciones avanzadas como contar hojas, validar BST y serialización
- Comprender el uso de colas en recorrido BFS
- Practicar serialización y deserialización de estructuras de árbol

---

# Estructura de la clase

| Hora | Actividad |
|------|-----------|
| 08:30 – 08:40 | Introducción |
| 08:40 – 09:10 | Concepto y código guiado |
| 09:10 – 09:55 | Ejercicios |
| 09:55 – 10:00 | Cierre |

---

# 1. Introducción (08:30 – 08:40)

Los **recorridos de árboles** son algoritmos fundamentales para procesar todos los nodos. Los tres recorridos recursivos ya conocidos (inorden, preorden, postorden) visitan nodos en profundidad. El recorrido **por niveles (BFS)** es diferente: visita nodos capa por capa desde la raíz.

```
       8
      / \
     3   10
    / \    \
   1   6    14
      / \   /
     4   7 13

Preorden:      8 3 1 6 4 7 10 14 13
Inorden:       1 3 4 6 7 8 10 13 14
Postorden:     1 4 7 6 3 13 14 10 8
Por niveles:   8 3 10 1 6 14 4 7 13
```

Las operaciones avanzadas como contar hojas, validar BST y serializar son aplicaciones prácticas de estos recorridos.

---

# 2. Concepto y código guiado (08:40 – 09:10)

## Estructura del Nodo

```c
typedef struct NodoBST {
    int clave;
    struct NodoBST *izq, *der;
} NodoBST;
```

## Los 3 Recorridos Recursivos

```c
void inorden(NodoBST *raiz) {
    if (raiz == NULL) return;
    inorden(raiz->izq);
    printf("%d ", raiz->clave);
    inorden(raiz->der);
}

void preorden(NodoBST *raiz) {
    if (raiz == NULL) return;
    printf("%d ", raiz->clave);
    preorden(raiz->izq);
    preorden(raiz->der);
}

void postorden(NodoBST *raiz) {
    if (raiz == NULL) return;
    postorden(raiz->izq);
    postorden(raiz->der);
    printf("%d ", raiz->clave);
}
```

## Recorrido por Niveles (BFS) usando Cola

```c
// Cola simple con array
typedef struct {
    NodoBST* nodos[1000];
    int inicio, fin;
} Cola;

void encolar(Cola *c, NodoBST *nodo) {
    if (nodo != NULL) {
        c->nodos[c->fin++] = nodo;
    }
}

NodoBST* desencolar(Cola *c) {
    if (c->inicio >= c->fin) return NULL;
    return c->nodos[c->inicio++];
}

void por_niveles(NodoBST *raiz) {
    if (raiz == NULL) return;

    Cola cola;
    cola.inicio = 0;
    cola.fin = 0;

    encolar(&cola, raiz);

    while (cola.inicio < cola.fin) {
        NodoBST *nodo = desencolar(&cola);
        printf("%d ", nodo->clave);
        encolar(&cola, nodo->izq);
        encolar(&cola, nodo->der);
    }
}
```

## Contar Hojas

```c
int contar_hojas(NodoBST *raiz) {
    if (raiz == NULL) return 0;

    // Hoja: nodo sin hijos
    if (raiz->izq == NULL && raiz->der == NULL) {
        return 1;
    }

    return contar_hojas(raiz->izq) + contar_hojas(raiz->der);
}
```

## Sumar todos los nodos

```c
int sumar_nodos(NodoBST *raiz) {
    if (raiz == NULL) return 0;

    return raiz->clave + sumar_nodos(raiz->izq) + sumar_nodos(raiz->der);
}
```

## Validar que es un BST válido (con rangos min/max)

```c
int es_bst_valido_rango(NodoBST *raiz, int minimo, int maximo) {
    if (raiz == NULL) return 1;

    if (raiz->clave <= minimo || raiz->clave >= maximo) {
        return 0;
    }

    return es_bst_valido_rango(raiz->izq, minimo, raiz->clave) &&
           es_bst_valido_rango(raiz->der, raiz->clave, maximo);
}

int es_bst_valido(NodoBST *raiz) {
    return es_bst_valido_rango(raiz, INT_MIN, INT_MAX);
}
```

## Ejemplo completo ejecutable

```c
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct NodoBST {
    int clave;
    struct NodoBST *izq, *der;
} NodoBST;

typedef struct {
    NodoBST* nodos[1000];
    int inicio, fin;
} Cola;

NodoBST* crear_nodo(int clave) {
    NodoBST *nuevo = (NodoBST*) malloc(sizeof(NodoBST));
    nuevo->clave = clave;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    return nuevo;
}

NodoBST* bst_insertar(NodoBST *raiz, int clave) {
    if (raiz == NULL) {
        return crear_nodo(clave);
    }
    if (clave < raiz->clave) {
        raiz->izq = bst_insertar(raiz->izq, clave);
    } else if (clave > raiz->clave) {
        raiz->der = bst_insertar(raiz->der, clave);
    }
    return raiz;
}

void inorden(NodoBST *raiz) {
    if (raiz == NULL) return;
    inorden(raiz->izq);
    printf("%d ", raiz->clave);
    inorden(raiz->der);
}

void preorden(NodoBST *raiz) {
    if (raiz == NULL) return;
    printf("%d ", raiz->clave);
    preorden(raiz->izq);
    preorden(raiz->der);
}

void postorden(NodoBST *raiz) {
    if (raiz == NULL) return;
    postorden(raiz->izq);
    postorden(raiz->der);
    printf("%d ", raiz->clave);
}

void encolar(Cola *c, NodoBST *nodo) {
    if (nodo != NULL) {
        c->nodos[c->fin++] = nodo;
    }
}

NodoBST* desencolar(Cola *c) {
    if (c->inicio >= c->fin) return NULL;
    return c->nodos[c->inicio++];
}

void por_niveles(NodoBST *raiz) {
    if (raiz == NULL) return;
    Cola cola;
    cola.inicio = 0;
    cola.fin = 0;
    encolar(&cola, raiz);
    while (cola.inicio < cola.fin) {
        NodoBST *nodo = desencolar(&cola);
        printf("%d ", nodo->clave);
        encolar(&cola, nodo->izq);
        encolar(&cola, nodo->der);
    }
}

int contar_hojas(NodoBST *raiz) {
    if (raiz == NULL) return 0;
    if (raiz->izq == NULL && raiz->der == NULL) return 1;
    return contar_hojas(raiz->izq) + contar_hojas(raiz->der);
}

int es_bst_valido_rango(NodoBST *raiz, int minimo, int maximo) {
    if (raiz == NULL) return 1;
    if (raiz->clave <= minimo || raiz->clave >= maximo) return 0;
    return es_bst_valido_rango(raiz->izq, minimo, raiz->clave) &&
           es_bst_valido_rango(raiz->der, raiz->clave, maximo);
}

int es_bst_valido(NodoBST *raiz) {
    return es_bst_valido_rango(raiz, INT_MIN, INT_MAX);
}

int main() {
    NodoBST *arbol = NULL;
    int valores[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};

    for (int i = 0; i < 9; i++) {
        arbol = bst_insertar(arbol, valores[i]);
    }

    printf("Inorden:      ");
    inorden(arbol);
    printf("\n");

    printf("Preorden:     ");
    preorden(arbol);
    printf("\n");

    printf("Postorden:    ");
    postorden(arbol);
    printf("\n");

    printf("Por niveles:  ");
    por_niveles(arbol);
    printf("\n");

    printf("Hojas: %d\n", contar_hojas(arbol));
    printf("¿Es BST válido? %s\n", es_bst_valido(arbol) ? "Sí" : "No");

    return 0;
}
```

**Salida esperada:**
```
Inorden:      1 3 4 6 7 8 10 13 14
Preorden:     8 3 1 6 4 7 10 14 13
Postorden:    1 4 7 6 3 13 14 10 8
Por niveles:  8 3 10 1 6 14 4 7 13
Hojas: 4
¿Es BST válido? Sí
```

---

# 3. Ejercicios (09:10 – 09:55)

## Ejercicio 1 — Los 4 recorridos (★☆☆)

Implementa las funciones: `inorden`, `preorden`, `postorden` y `por_niveles` (con cola array).

Construye el árbol del ejemplo: insertar {8, 3, 10, 1, 6, 14, 4, 7, 13}

Imprime todos los 4 recorridos y verifica que coinciden con los esperados.

## Ejercicio 2 — Validación y análisis avanzado (★★☆)

Implementa:

1. `int contar_hojas(NodoBST *raiz)` — Cuenta solo los nodos sin hijos
2. `int sumar_nodos(NodoBST *raiz)` — Suma todos los valores
3. `int es_bst_valido(NodoBST *raiz)` — Verifica que el árbol cumple propiedad BST usando rangos min/max

Crea dos árboles: uno BST válido y otro inválido (p. ej., construyendo manualmente). Prueba las funciones en ambos.

## Ejercicio 3 — Serialización y deserialización (★★★)

Implementa:

1. `char* serializar(NodoBST *raiz)` — Convierte el árbol a string en formato preorden con `#` para NULL
   - Ejemplo: árbol {8,3,1,#,#,6,4,#,#,7,#,#,10,#,14,13,#,#,#} → "8,3,1,#,#,6,4,#,#,7,#,#,10,#,14,13,#,#,#"

2. `NodoBST* deserializar(char *str)` — Reconstruye el árbol desde ese string

Prueba: Serializa el árbol del ejercicio 1, luego deserializa. Verifica que `inorden(original) == inorden(reconstruido)`.

---

# 4. Cierre (09:55 – 10:00)

Los recorridos de árboles son fundamentales: aparecen en compiladores (AST), sistemas de archivos, y bases de datos.

**Key insight:** BFS (por niveles) es diferente a DFS (profundidad); cada uno es útil según la aplicación.

**Próximo laboratorio:** El problema de la degeneración (insertar 1,2,3,4,5 crea una lista) y cómo **Árboles AVL** lo resuelven mediante rotaciones.

---

*EIN423-B · Departamento de Informática · UTFSM*
