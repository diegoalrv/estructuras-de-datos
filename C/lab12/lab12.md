# Laboratorio 12 — Hashing con Encadenamiento

**Curso:** EIN423-B · Estructuras de Datos
**Duración:** 90 minutos
**Horario:** 08:30 – 10:00

## Objetivos del laboratorio
- Entender el concepto de función hash y colisiones
- Implementar tablas hash con encadenamiento (separate chaining)
- Comprender el factor de carga y el rehashing
- Construir un diccionario clave-valor con O(1) promedio

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

Una **Tabla Hash** mapea claves a índices en un array mediante una **función hash**. En lugar de buscar linealmente (O(n)), hacemos hash(clave) → índice en O(1).

**Colisiones:** Cuando dos claves mapean al mismo índice. Se resuelven con **encadenamiento**: cada celda es una lista enlazada.

```
Función hash: h(k) = k % m  (m = tamaño tabla)

Tabla con m=5:
  [0] → 5 → 10
  [1] → 1 → 6 → 11
  [2] → 2 → 7
  [3] → 3 → 8 → 13
  [4] → 4 → 9 → 14
```

**Factor de carga:** α = n/m (promedio de elementos por celda).
- Si α ≤ 0.75: búsqueda eficiente O(1) promedio
- Si α > 0.75: rehashear con tabla más grande

---

# 2. Concepto y código guiado (08:40 – 09:10)

## Estructura de datos

```c
typedef struct Nodo {
    int clave;
    char valor[100];
    struct Nodo *siguiente;
} Nodo;

typedef struct {
    Nodo **tabla;
    int m;      // Tamaño de la tabla
    int n;      // Cantidad de elementos insertados
} TablaHash;
```

## Función hash para enteros

```c
int hash_entero(int clave, int m) {
    return clave % m;
}
```

## Función hash para strings (djb2)

```c
unsigned int hash_string(const char *str, int m) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }

    return hash % m;
}
```

## Crear tabla hash

```c
TablaHash* th_crear(int tamaño) {
    TablaHash *th = (TablaHash*) malloc(sizeof(TablaHash));
    th->tabla = (Nodo**) calloc(tamaño, sizeof(Nodo*));
    th->m = tamaño;
    th->n = 0;
    return th;
}
```

## Insertar elemento

```c
void th_insertar(TablaHash *th, int clave, const char *valor) {
    int indice = hash_entero(clave, th->m);

    // Buscar si ya existe
    Nodo *actual = th->tabla[indice];
    while (actual != NULL) {
        if (actual->clave == clave) {
            strcpy(actual->valor, valor);  // Actualizar
            return;
        }
        actual = actual->siguiente;
    }

    // Insertar al principio de la cadena
    Nodo *nuevo = (Nodo*) malloc(sizeof(Nodo));
    nuevo->clave = clave;
    strcpy(nuevo->valor, valor);
    nuevo->siguiente = th->tabla[indice];
    th->tabla[indice] = nuevo;
    th->n++;
}
```

## Buscar elemento

```c
char* th_buscar(TablaHash *th, int clave) {
    int indice = hash_entero(clave, th->m);

    Nodo *actual = th->tabla[indice];
    while (actual != NULL) {
        if (actual->clave == clave) {
            return actual->valor;
        }
        actual = actual->siguiente;
    }

    return NULL;  // No encontrado
}
```

## Imprimir tabla hash

```c
void th_imprimir(TablaHash *th) {
    for (int i = 0; i < th->m; i++) {
        printf("[%d] → ", i);
        Nodo *actual = th->tabla[i];
        while (actual != NULL) {
            printf("(%d:%s) → ", actual->clave, actual->valor);
            actual = actual->siguiente;
        }
        printf("NULL\n");
    }
    printf("Factor de carga: %.2f (n=%d, m=%d)\n", 
           (float)th->n / th->m, th->n, th->m);
}
```

## Destruir tabla hash

```c
void th_destruir(TablaHash *th) {
    for (int i = 0; i < th->m; i++) {
        Nodo *actual = th->tabla[i];
        while (actual != NULL) {
            Nodo *temp = actual;
            actual = actual->siguiente;
            free(temp);
        }
    }
    free(th->tabla);
    free(th);
}
```

## Ejemplo completo ejecutable

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo {
    int clave;
    char valor[100];
    struct Nodo *siguiente;
} Nodo;

typedef struct {
    Nodo **tabla;
    int m;
    int n;
} TablaHash;

int hash_entero(int clave, int m) {
    return clave % m;
}

TablaHash* th_crear(int tamaño) {
    TablaHash *th = (TablaHash*) malloc(sizeof(TablaHash));
    th->tabla = (Nodo**) calloc(tamaño, sizeof(Nodo*));
    th->m = tamaño;
    th->n = 0;
    return th;
}

void th_insertar(TablaHash *th, int clave, const char *valor) {
    int indice = hash_entero(clave, th->m);

    Nodo *actual = th->tabla[indice];
    while (actual != NULL) {
        if (actual->clave == clave) {
            strcpy(actual->valor, valor);
            return;
        }
        actual = actual->siguiente;
    }

    Nodo *nuevo = (Nodo*) malloc(sizeof(Nodo));
    nuevo->clave = clave;
    strcpy(nuevo->valor, valor);
    nuevo->siguiente = th->tabla[indice];
    th->tabla[indice] = nuevo;
    th->n++;
}

char* th_buscar(TablaHash *th, int clave) {
    int indice = hash_entero(clave, th->m);

    Nodo *actual = th->tabla[indice];
    while (actual != NULL) {
        if (actual->clave == clave) {
            return actual->valor;
        }
        actual = actual->siguiente;
    }

    return NULL;
}

void th_imprimir(TablaHash *th) {
    for (int i = 0; i < th->m; i++) {
        printf("[%d] → ", i);
        Nodo *actual = th->tabla[i];
        while (actual != NULL) {
            printf("(%d:%s) → ", actual->clave, actual->valor);
            actual = actual->siguiente;
        }
        printf("NULL\n");
    }
    printf("Factor de carga: %.2f (n=%d, m=%d)\n", 
           (float)th->n / th->m, th->n, th->m);
}

void th_destruir(TablaHash *th) {
    for (int i = 0; i < th->m; i++) {
        Nodo *actual = th->tabla[i];
        while (actual != NULL) {
            Nodo *temp = actual;
            actual = actual->siguiente;
            free(temp);
        }
    }
    free(th->tabla);
    free(th);
}

int main() {
    TablaHash *tabla = th_crear(5);

    th_insertar(tabla, 1, "uno");
    th_insertar(tabla, 2, "dos");
    th_insertar(tabla, 11, "once");
    th_insertar(tabla, 12, "doce");

    printf("--- Tabla Hash (m=5) ---\n");
    th_imprimir(tabla);

    printf("\nBúsquedas:\n");
    printf("Clave 1: %s\n", th_buscar(tabla, 1));
    printf("Clave 11: %s\n", th_buscar(tabla, 11));
    printf("Clave 99: %s\n", th_buscar(tabla, 99) ? "Encontrado" : "No encontrado");

    th_destruir(tabla);
    return 0;
}
```

**Salida esperada:**
```
--- Tabla Hash (m=5) ---
[0] → NULL
[1] → (12:doce) → (2:dos) → NULL
[2] → NULL
[3] → NULL
[4] → (11:once) → (1:uno) → NULL
Factor de carga: 0.80 (n=4, m=5)

Búsquedas:
Clave 1: uno
Clave 11: once
Clave 99: No encontrado
```

---

# 3. Ejercicios (09:10 – 09:55)

## Ejercicio 1 — Tabla hash básica con encadenamiento (★☆☆)

Implementa tabla hash con claves enteras y valores string.

Inserta: (1,"uno"), (2,"dos"), (11,"once"), (12,"doce") en una tabla de tamaño m=5.

Imprime la estructura de la tabla (mostrando las cadenas en cada índice).

Busca algunas claves y verifica resultados.

## Ejercicio 2 — Diccionario string→string con hash djb2 (★★☆)

Implementa tabla hash que mapee strings a strings (p. ej., word→definition).

Usa función hash djb2 para keys string.

Inserta 10 pares palabra-definición, luego busca algunos.

Para tablas de tamaño m=5, 10, 20, 50, 100 con 100 elementos insertados,
calcula el factor de carga y el largo promedio de cadena en cada celda.

## Ejercicio 3 — Rehashing dinámico (★★★)

Implementa `th_rehash(TablaHash *th)` que:

1. Duplica el tamaño de la tabla (m' = 2*m)
2. Reinserta todos los elementos (rehashea cada uno con el nuevo tamaño)
3. Libera la tabla vieja

Modifica `th_insertar` para llamar a `th_rehash` cuando α > 0.75.

Prueba: Inserta 100 elementos y monitorea cómo la tabla crece de m=8 → 16 → 32 → 64 → 128.

---

# 4. Cierre (09:55 – 10:00)

Las tablas hash ofrecen O(1) promedio para búsqueda, inserción y eliminación, mejor que árboles AVL O(log n).

**Trade-off:** Espacio extra (tabla puede estar vacía) vs velocidad.

**Próximo laboratorio:** Sondeo abierto (open addressing) — alternativa sin punteros, mejor uso de caché.

---

*EIN423-B · Departamento de Informática · UTFSM*
