# Laboratorio 9 — Árbol Binario de Búsqueda (BST)

**Curso:** EIN423-B · Estructuras de Datos
**Duración:** 90 minutos
**Horario:** 08:30 – 10:00

## Objetivos del laboratorio
- Entender la estructura y propiedades del Árbol Binario de Búsqueda (BST)
- Implementar operaciones básicas: inserción, búsqueda y recorrido inorden
- Comprender la relación entre altura del árbol y complejidad de operaciones
- Visualizar cómo un BST mantiene datos ordenados

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

Un **Árbol Binario de Búsqueda (BST)** es una estructura de datos que organiza información de manera jerárquica para permitir búsquedas eficientes.

**Propiedad fundamental:**
- Para cada nodo, todos los valores en el **subárbol izquierdo** son **menores** que el nodo
- Todos los valores en el **subárbol derecho** son **mayores** que el nodo

Esta propiedad permite búsqueda en O(h) donde h es la altura del árbol. Si el árbol está balanceado, h = O(log n) y las operaciones son muy rápidas.

```
       50
      /  \
    30    70
   / \    / \
  20 40  60 80
```

En este árbol, el inorden (izquierda → nodo → derecha) produce: 20, 30, 40, 50, 60, 70, 80 (¡ordenado!)

---

# 2. Concepto y código guiado (08:40 – 09:10)

## Estructura del Nodo

```c
typedef struct NodoBST {
    int clave;
    struct NodoBST *izq, *der;
} NodoBST;
```

## Crear un nodo nuevo

```c
NodoBST* crear_nodo(int clave) {
    NodoBST *nuevo = (NodoBST*) malloc(sizeof(NodoBST));
    nuevo->clave = clave;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    return nuevo;
}
```

## Insertar en BST

```c
NodoBST* bst_insertar(NodoBST *raiz, int clave) {
    if (raiz == NULL) {
        return crear_nodo(clave);
    }

    if (clave < raiz->clave) {
        raiz->izq = bst_insertar(raiz->izq, clave);
    } else if (clave > raiz->clave) {
        raiz->der = bst_insertar(raiz->der, clave);
    }
    // Si clave == raiz->clave, no insertamos (sin duplicados)

    return raiz;
}
```

## Buscar en BST

```c
NodoBST* bst_buscar(NodoBST *raiz, int clave) {
    if (raiz == NULL) {
        return NULL;
    }

    if (clave == raiz->clave) {
        return raiz;
    } else if (clave < raiz->clave) {
        return bst_buscar(raiz->izq, clave);
    } else {
        return bst_buscar(raiz->der, clave);
    }
}
```

## Recorridos: Inorden (devuelve datos ordenados)

```c
void bst_inorden(NodoBST *raiz) {
    if (raiz == NULL) return;

    bst_inorden(raiz->izq);        // Visitar subárbol izquierdo
    printf("%d ", raiz->clave);    // Visitar nodo (aquí está ordenado)
    bst_inorden(raiz->der);        // Visitar subárbol derecho
}
```

## Recorrido Preorden

```c
void bst_preorden(NodoBST *raiz) {
    if (raiz == NULL) return;

    printf("%d ", raiz->clave);    // Visitar nodo PRIMERO
    bst_preorden(raiz->izq);       // Subárbol izquierdo
    bst_preorden(raiz->der);       // Subárbol derecho
}
```

## Recorrido Postorden

```c
void bst_postorden(NodoBST *raiz) {
    if (raiz == NULL) return;

    bst_postorden(raiz->izq);      // Subárbol izquierdo
    bst_postorden(raiz->der);      // Subárbol derecho
    printf("%d ", raiz->clave);    // Visitar nodo ÚLTIMO
}
```

## Ejemplo completo ejecutable

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct NodoBST {
    int clave;
    struct NodoBST *izq, *der;
} NodoBST;

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

void bst_inorden(NodoBST *raiz) {
    if (raiz == NULL) return;
    bst_inorden(raiz->izq);
    printf("%d ", raiz->clave);
    bst_inorden(raiz->der);
}

void bst_preorden(NodoBST *raiz) {
    if (raiz == NULL) return;
    printf("%d ", raiz->clave);
    bst_preorden(raiz->izq);
    bst_preorden(raiz->der);
}

void bst_postorden(NodoBST *raiz) {
    if (raiz == NULL) return;
    bst_postorden(raiz->izq);
    bst_postorden(raiz->der);
    printf("%d ", raiz->clave);
}

int main() {
    NodoBST *arbol = NULL;

    // Insertar: 50, 30, 70, 20, 40, 60, 80
    int valores[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++) {
        arbol = bst_insertar(arbol, valores[i]);
    }

    printf("Inorden:   ");
    bst_inorden(arbol);
    printf("\n");

    printf("Preorden:  ");
    bst_preorden(arbol);
    printf("\n");

    printf("Postorden: ");
    bst_postorden(arbol);
    printf("\n");

    return 0;
}
```

**Salida esperada:**
```
Inorden:   20 30 40 50 60 70 80
Preorden:  50 30 20 40 70 60 80
Postorden: 20 40 30 60 80 70 50
```

---

# 3. Ejercicios (09:10 – 09:55)

## Ejercicio 1 — Construcción e impresión de BST (★☆☆)

Construye un BST insertando los valores: 50, 30, 70, 20, 40, 60, 80.

Implementa las funciones `bst_insertar`, `bst_inorden`, `bst_preorden` y `bst_postorden` (pueden usar el código guiado).

Imprime los tres recorridos.

**Bonus:** Dibuja manualmente el árbol resultante en papel.

## Ejercicio 2 — Operaciones de análisis del árbol (★★☆)

Amplía el código del ejercicio 1 con las siguientes funciones:

1. `int altura(NodoBST *raiz)` — Retorna la altura del árbol (NULL = -1, hoja = 0)
2. `int contar_nodos(NodoBST *raiz)` — Cuenta el número total de nodos
3. `int buscar_min(NodoBST *raiz)` — Retorna el valor mínimo (siempre está en el extremo izquierdo)
4. `int buscar_max(NodoBST *raiz)` — Retorna el valor máximo (siempre está en el extremo derecho)
5. `void destruir(NodoBST *raiz)` — Libera toda la memoria del árbol

Prueba: Usa el mismo árbol del ejercicio 1. Imprime altura, número de nodos, mín, máx. Luego destruye el árbol.

## Ejercicio 3 — Eliminación en BST (★★★)

Implementa `NodoBST* bst_eliminar(NodoBST *raiz, int clave)` que elimina un nodo. Hay 3 casos:

1. **Nodo hoja:** Solo eliminarlo (retornar NULL)
2. **Nodo con un hijo:** Reemplazarlo por su hijo
3. **Nodo con dos hijos:** Reemplazarlo por el **sucesor inorden** (el mínimo del subárbol derecho), luego eliminar el sucesor

Prueba: Sobre el árbol del ejercicio 1, elimina algunos nodos (una hoja, un nodo con un hijo, un nodo con dos hijos). Verifica con inorden que el árbol sigue siendo un BST válido (datos ordenados).

---

# 4. Cierre (09:55 – 10:00)

El Árbol Binario de Búsqueda es la estructura fundamental para búsqueda eficiente: O(h), donde h es la altura.

**Pregunta importante:** ¿Qué pasa si insertas valores en orden creciente (1, 2, 3, 4, 5)? ¿Cuál es la altura? ¿Y la complejidad?

**Próximo laboratorio:** Descubriremos por qué los BST desbalanceados son un problema y cómo los **Árboles AVL** lo resuelven garantizando altura O(log n) siempre.

---

*EIN423-B · Departamento de Informática · UTFSM*
