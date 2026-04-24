# Laboratorio 11 — Árbol AVL

**Curso:** EIN423-B · Estructuras de Datos
**Duración:** 90 minutos
**Horario:** 08:30 – 10:00

## Objetivos del laboratorio
- Entender el problema de degeneración en BST
- Comprender el factor de balance y la invariante AVL
- Implementar las 4 rotaciones: LL, RR, LR, RL
- Construir un árbol AVL con inserción auto-balanceada

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

Un **Árbol AVL** (Adelson-Velsky y Landis) resuelve el problema del BST degenerado. Si insertas 1,2,3,4,5 en orden en un BST, obtienes una lista enlazada (altura = 5, complejidad O(n)).

**Factor de Balance:**
```
FB(nodo) = altura(subárbol_izq) - altura(subárbol_der)
```

**Invariante AVL:** Para cada nodo, |FB| ≤ 1 (el árbol nunca se desbalancea).

**Rotaciones:** Si el balance se viola, aplicamos una de 4 rotaciones:
- **LL** (Left-Left): desbalance izquierdo, rotación derecha
- **RR** (Right-Right): desbalance derecho, rotación izquierda
- **LR** (Left-Right): desbalance izquierdo-derecho, doble rotación
- **RL** (Right-Left): desbalance derecho-izquierdo, doble rotación

El resultado es un árbol con altura h = O(log n) siempre.

---

# 2. Concepto y código guiado (08:40 – 09:10)

## Estructura del Nodo AVL

```c
typedef struct NodoAVL {
    int clave;
    int altura;
    struct NodoAVL *izq, *der;
} NodoAVL;
```

## Altura de un nodo

```c
int altura_nodo(NodoAVL *nodo) {
    if (nodo == NULL) return -1;
    return nodo->altura;
}

void actualizar_altura(NodoAVL *nodo) {
    if (nodo == NULL) return;

    int h_izq = altura_nodo(nodo->izq);
    int h_der = altura_nodo(nodo->der);

    nodo->altura = 1 + (h_izq > h_der ? h_izq : h_der);
}
```

## Factor de balance

```c
int factor_balance(NodoAVL *nodo) {
    if (nodo == NULL) return 0;
    return altura_nodo(nodo->izq) - altura_nodo(nodo->der);
}
```

## Las 4 Rotaciones

### Rotación Derecha (LL)

```c
NodoAVL* rotar_derecha(NodoAVL *y) {
    NodoAVL *x = y->izq;
    NodoAVL *T2 = x->der;

    x->der = y;
    y->izq = T2;

    actualizar_altura(y);
    actualizar_altura(x);

    return x;
}
```

### Rotación Izquierda (RR)

```c
NodoAVL* rotar_izquierda(NodoAVL *x) {
    NodoAVL *y = x->der;
    NodoAVL *T2 = y->izq;

    y->izq = x;
    x->der = T2;

    actualizar_altura(x);
    actualizar_altura(y);

    return y;
}
```

### Rotación Izquierda-Derecha (LR)

```c
NodoAVL* rotar_izq_der(NodoAVL *z) {
    z->izq = rotar_izquierda(z->izq);
    return rotar_derecha(z);
}
```

### Rotación Derecha-Izquierda (RL)

```c
NodoAVL* rotar_der_izq(NodoAVL *z) {
    z->der = rotar_derecha(z->der);
    return rotar_izquierda(z);
}
```

## Crear nodo

```c
NodoAVL* crear_nodo(int clave) {
    NodoAVL *nuevo = (NodoAVL*) malloc(sizeof(NodoAVL));
    nuevo->clave = clave;
    nuevo->altura = 0;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    return nuevo;
}
```

## Validar que un árbol es AVL

```c
int es_avl_valido(NodoAVL *nodo) {
    if (nodo == NULL) return 1;

    int fb = factor_balance(nodo);
    if (fb < -1 || fb > 1) {
        return 0;
    }

    return es_avl_valido(nodo->izq) && es_avl_valido(nodo->der);
}
```

## Inserción AVL (con balanceo automático)

```c
NodoAVL* avl_insertar(NodoAVL *nodo, int clave) {
    if (nodo == NULL) {
        return crear_nodo(clave);
    }

    if (clave < nodo->clave) {
        nodo->izq = avl_insertar(nodo->izq, clave);
    } else if (clave > nodo->clave) {
        nodo->der = avl_insertar(nodo->der, clave);
    } else {
        return nodo;  // Sin duplicados
    }

    actualizar_altura(nodo);
    int fb = factor_balance(nodo);

    // Caso LL
    if (fb > 1 && factor_balance(nodo->izq) >= 0) {
        return rotar_derecha(nodo);
    }

    // Caso RR
    if (fb < -1 && factor_balance(nodo->der) <= 0) {
        return rotar_izquierda(nodo);
    }

    // Caso LR
    if (fb > 1 && factor_balance(nodo->izq) < 0) {
        return rotar_izq_der(nodo);
    }

    // Caso RL
    if (fb < -1 && factor_balance(nodo->der) > 0) {
        return rotar_der_izq(nodo);
    }

    return nodo;
}
```

## Ejemplo completo ejecutable

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct NodoAVL {
    int clave;
    int altura;
    struct NodoAVL *izq, *der;
} NodoAVL;

int altura_nodo(NodoAVL *nodo) {
    return (nodo == NULL) ? -1 : nodo->altura;
}

void actualizar_altura(NodoAVL *nodo) {
    if (nodo == NULL) return;
    int h_izq = altura_nodo(nodo->izq);
    int h_der = altura_nodo(nodo->der);
    nodo->altura = 1 + (h_izq > h_der ? h_izq : h_der);
}

int factor_balance(NodoAVL *nodo) {
    return (nodo == NULL) ? 0 : altura_nodo(nodo->izq) - altura_nodo(nodo->der);
}

NodoAVL* crear_nodo(int clave) {
    NodoAVL *nuevo = (NodoAVL*) malloc(sizeof(NodoAVL));
    nuevo->clave = clave;
    nuevo->altura = 0;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    return nuevo;
}

NodoAVL* rotar_derecha(NodoAVL *y) {
    NodoAVL *x = y->izq;
    NodoAVL *T2 = x->der;
    x->der = y;
    y->izq = T2;
    actualizar_altura(y);
    actualizar_altura(x);
    return x;
}

NodoAVL* rotar_izquierda(NodoAVL *x) {
    NodoAVL *y = x->der;
    NodoAVL *T2 = y->izq;
    y->izq = x;
    x->der = T2;
    actualizar_altura(x);
    actualizar_altura(y);
    return y;
}

NodoAVL* avl_insertar(NodoAVL *nodo, int clave) {
    if (nodo == NULL) {
        return crear_nodo(clave);
    }

    if (clave < nodo->clave) {
        nodo->izq = avl_insertar(nodo->izq, clave);
    } else if (clave > nodo->clave) {
        nodo->der = avl_insertar(nodo->der, clave);
    } else {
        return nodo;
    }

    actualizar_altura(nodo);
    int fb = factor_balance(nodo);

    if (fb > 1 && factor_balance(nodo->izq) >= 0) {
        return rotar_derecha(nodo);
    }

    if (fb < -1 && factor_balance(nodo->der) <= 0) {
        return rotar_izquierda(nodo);
    }

    if (fb > 1 && factor_balance(nodo->izq) < 0) {
        nodo->izq = rotar_izquierda(nodo->izq);
        return rotar_derecha(nodo);
    }

    if (fb < -1 && factor_balance(nodo->der) > 0) {
        nodo->der = rotar_derecha(nodo->der);
        return rotar_izquierda(nodo);
    }

    return nodo;
}

void inorden(NodoAVL *nodo) {
    if (nodo == NULL) return;
    inorden(nodo->izq);
    printf("%d ", nodo->clave);
    inorden(nodo->der);
}

int main() {
    NodoAVL *arbol = NULL;
    int valores[] = {1, 2, 3, 4, 5, 6, 7};

    printf("Insertando: 1 2 3 4 5 6 7\n");
    for (int i = 0; i < 7; i++) {
        arbol = avl_insertar(arbol, valores[i]);
    }

    printf("Inorden: ");
    inorden(arbol);
    printf("\n");

    printf("Altura final: %d\n", altura_nodo(arbol));
    printf("¿Es AVL válido? %s\n", 
        (factor_balance(arbol) >= -1 && factor_balance(arbol) <= 1) ? "Sí" : "No");

    return 0;
}
```

**Salida esperada:**
```
Insertando: 1 2 3 4 5 6 7
Inorden: 1 2 3 4 5 6 7
Altura final: 2
¿Es AVL válido? Sí
```

---

# 3. Ejercicios (09:10 – 09:55)

## Ejercicio 1 — Funciones básicas AVL (★☆☆)

Implementa:
1. `int altura_nodo(NodoAVL *nodo)` — Retorna altura
2. `int factor_balance(NodoAVL *nodo)` — Calcula FB
3. `int es_avl_valido(NodoAVL *nodo)` — Verifica |FB| ≤ 1 para todos los nodos

Inserta 1..7 en orden en un BST normal y un AVL. Compara sus alturas.

## Ejercicio 2 — Las 4 rotaciones (★★☆)

Implementa las 4 funciones de rotación:
1. `rotar_derecha` (LL)
2. `rotar_izquierda` (RR)
3. `rotar_izq_der` (LR)
4. `rotar_der_izq` (RL)

Escribe código que trigger cada tipo de rotación e imprime el árbol resultante.

## Ejercicio 3 — Inserción AVL completa (★★★)

Implementa `avl_insertar(nodo, clave)` que:
1. Inserta como en BST
2. Actualiza alturas
3. Detecta desbalance (|FB| > 1)
4. Aplica la rotación correcta

Prueba: Inserta {1,2,3,4,5,6,7} → verifica altura = 2 y que es AVL válido.
Compara con BST: BST altura = 6, AVL altura = 2.

---

# 4. Cierre (09:55 – 10:00)

El Árbol AVL garantiza O(log n) para todas las operaciones incluso en el peor caso.

**Pregunta:** ¿Cuál es la altura máxima de un AVL con 1 millón de nodos?

**Próximo laboratorio:** Los **Árboles Rojo-Negro** (otra estrategia de balanceo) y luego las **Tablas Hash** (O(1) promedio).

---

*EIN423-B · Departamento de Informática · UTFSM*
