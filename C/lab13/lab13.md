# Laboratorio 13 — Hashing con Sondeo Abierto

**Curso:** EIN423-B · Estructuras de Datos  
**Duración:** 90 minutos  
**Horario:** 08:30 – 10:00

## Objetivos del laboratorio
- Entender la diferencia entre hashing con encadenamiento y sondeo abierto
- Implementar una tabla hash con sondeo lineal
- Comprender por qué la marca ELIMINADO es necesaria para mantener la integridad de búsquedas
- Comparar sondeo lineal vs sondeo cuadrático vs doble hashing en términos de colisiones

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

En el laboratorio anterior vimos hashing con encadenamiento, donde cada posición en la tabla apuntaba a una lista enlazada de elementos que colisionaban. Hoy exploraremos **sondeo abierto**: una alternativa donde **todos los datos se almacenan directamente en la tabla**, y cuando hay una colisión, buscamos otra celda vacía usando una función de prueba.

**Ventajas del sondeo abierto:**
- Mejor localidad de caché (menos punteros, datos contiguos)
- Menor overhead de memoria (sin punteros)
- Más sensible al factor de carga

**Desventajas:**
- Más sensible al factor de carga ρ = n/m
- Requiere cuidado especial con eliminaciones

---

# 2. Concepto y código guiado

## Estados de celda

Cada celda en la tabla puede tener tres estados:

```c
typedef enum { VACIO, OCUPADO, ELIMINADO } EstadoCelda;

typedef struct {
    int clave;
    int valor;
    EstadoCelda estado;
} Celda;

typedef struct {
    Celda *tabla;
    int m;   // tamaño de la tabla
    int n;   // cantidad de elementos insertados
} TablaHashAbierta;
```

**¿Por qué necesitamos ELIMINADO?**

Cuando buscamos una clave usando sondeo lineal, paramos cuando encontramos VACIO. Si simplemente marcáramos una celda como VACIO al eliminar, rompemos la cadena de pruebas para elementos insertados después. Por eso usamos ELIMINADO: la búsqueda puede continuar pasando sobre ELIMINADO, pero la inserción puede reutilizar esas celdas.

## Sondeo lineal: h(k, i) = (h(k) + i) mod m

```c
TablaHashAbierta* th_crear(int m) {
    TablaHashAbierta *t = malloc(sizeof(TablaHashAbierta));
    t->tabla = malloc(m * sizeof(Celda));
    t->m = m;
    t->n = 0;
    for (int i = 0; i < m; i++) {
        t->tabla[i].estado = VACIO;
    }
    return t;
}

void th_insertar(TablaHashAbierta *t, int clave, int valor) {
    int h = clave % t->m;  // función hash principal
    int i = 0;
    int j = -1;  // primera celda ELIMINADA que vimos

    while (i < t->m) {
        int pos = (h + i) % t->m;

        if (t->tabla[pos].estado == VACIO) {
            // Insertar aquí (o en la primer ELIMINADA si la vimos)
            int destino = (j != -1) ? j : pos;
            t->tabla[destino].clave = clave;
            t->tabla[destino].valor = valor;
            t->tabla[destino].estado = OCUPADO;
            t->n++;
            return;
        }

        if (t->tabla[pos].estado == ELIMINADO && j == -1) {
            j = pos;  // guardamos la primera celda ELIMINADA
        }

        if (t->tabla[pos].estado == OCUPADO && t->tabla[pos].clave == clave) {
            // Clave ya existe, actualizar valor
            t->tabla[pos].valor = valor;
            return;
        }

        i++;
    }

    // Tabla llena (deberíamos redimensionar)
    printf("Error: tabla hash llena\n");
}

int th_buscar(TablaHashAbierta *t, int clave, int *valor) {
    int h = clave % t->m;
    int i = 0;

    while (i < t->m) {
        int pos = (h + i) % t->m;

        if (t->tabla[pos].estado == VACIO) {
            // No encontrada (VACIO detiene la búsqueda)
            return 0;
        }

        if (t->tabla[pos].estado == OCUPADO && t->tabla[pos].clave == clave) {
            *valor = t->tabla[pos].valor;
            return 1;
        }

        i++;
    }

    return 0;
}

int th_eliminar(TablaHashAbierta *t, int clave) {
    int h = clave % t->m;
    int i = 0;

    while (i < t->m) {
        int pos = (h + i) % t->m;

        if (t->tabla[pos].estado == VACIO) {
            return 0;  // No encontrada
        }

        if (t->tabla[pos].estado == OCUPADO && t->tabla[pos].clave == clave) {
            t->tabla[pos].estado = ELIMINADO;  // Marcamos como ELIMINADO
            t->n--;
            return 1;
        }

        i++;
    }

    return 0;
}

void th_imprimir(TablaHashAbierta *t) {
    printf("\nTabla hash (tamaño=%d, elementos=%d):\n", t->m, t->n);
    for (int i = 0; i < t->m; i++) {
        printf("[%2d] ", i);
        if (t->tabla[i].estado == VACIO) {
            printf("VACIO\n");
        } else if (t->tabla[i].estado == ELIMINADO) {
            printf("ELIMINADO\n");
        } else {
            printf("clave=%d, valor=%d\n", t->tabla[i].clave, t->tabla[i].valor);
        }
    }
}

void th_destruir(TablaHashAbierta *t) {
    free(t->tabla);
    free(t);
}
```

## Sondeo cuadrático: h(k, i) = (h(k) + i²) mod m

Reduce clustering primario pero puede no explorar todas las celdas:

```c
int pos = (h + i*i) % t->m;
```

## Doble hashing: h(k, i) = (h₁(k) + i·h₂(k)) mod m

Menor agrupamiento pero requiere h₂(k) ≠ 0 y mcd(h₂(k), m) = 1:

```c
int h1 = clave % t->m;
int h2 = 7 - (clave % 7);  // Asegurar que h2 ≠ 0 y ≠ múltiplo de m
int pos = (h1 + i * h2) % t->m;
```

---

# 3. Ejercicios

## Ejercicio 1 — Sondeo lineal con tabla de tamaño 11 (★☆☆)

Implementa una tabla hash con sondeo lineal. Inserta las siguientes claves en orden: **10, 22, 31, 4, 15, 28, 17, 88, 59**.

Requisitos:
- Tabla de tamaño m = 11
- Imprime la tabla después de cada inserción mostrando el índice y la clave (o VACIO)
- Cuenta el número total de colisiones (intentos fallidos durante inserción)
- Al final, imprime la tabla completa y el total de colisiones

**Salida esperada (parcial):**
```
Insertando 10: hash(10) % 11 = 10 -> [10] VACIO, insertar aquí
Tabla después de insertar 10: [10 en posición 10]

Insertando 22: hash(22) % 11 = 0 -> [0] VACIO, insertar aquí
Tabla después de insertar 22: [22 en posición 0, 10 en posición 10]

Insertando 31: hash(31) % 11 = 9 -> [9] VACIO, insertar aquí
...

Total de colisiones: X
```

## Ejercicio 2 — Comparación: sondeo lineal vs cuadrático (★★☆)

Implementa tanto sondeo lineal como sondeo cuadrático. Para el mismo conjunto de claves **{10, 22, 31, 4, 15, 28, 17, 88, 59}** y tres tamaños de tabla **m ∈ {11, 17, 23}**, cuenta el número total de probes (intentos durante inserción).

Requisitos:
- Función auxiliar que cuente probes para cada inserción
- Imprime una tabla comparativa:

```
m=11:
  Sondeo Lineal:    X probes totales
  Sondeo Cuadrático: Y probes totales

m=17:
  Sondeo Lineal:    X probes totales
  Sondeo Cuadrático: Y probes totales

m=23:
  Sondeo Lineal:    X probes totales
  Sondeo Cuadrático: Y probes totales
```

¿Cuál método tiene menos colisiones? ¿Qué observas sobre el factor de carga ρ?

## Ejercicio 3 — Doble hashing (★★★)

Implementa doble hashing con h₁(k) = k mod m y h₂(k) = 7 - (k mod 7). Compara los tres métodos (lineal, cuadrático, doble) para las mismas claves y tamaños.

Requisitos:
- Implementa doble hashing completamente
- Asegura que h₂(k) nunca es 0
- Cuenta probes para cada método
- Imprime comparativa:

```
m=11:
  Sondeo Lineal:     X probes
  Sondeo Cuadrático: Y probes
  Doble Hashing:     Z probes

[similar para m=17 y m=23]
```

**Pregunta clave:** ¿Por qué es importante que h₂(k) sea coprimo con m? ¿Qué sucede si h₂(k) = 5 y m = 10?

---

# Cierre

El sondeo abierto evita el overhead de punteros en memoria pero es más sensible al factor de carga. La biblioteca estándar de C++ (unordered_map) usa sondeo abierto por defecto en muchas implementaciones.

**Resumen:**
- **Sondeo lineal:** simple, pero sufre clustering primario
- **Sondeo cuadrático:** mejor que lineal, pero puede no explorar todas las celdas
- **Doble hashing:** mejor distribución, pero más costoso (dos funciones hash)

La marca ELIMINADO es crucial: permite que las búsquedas no se corten prematuramente y que la inserción reutilice espacio.

**Próximo laboratorio:** Grafos — representación y búsqueda en amplitud (BFS).

---

*EIN423-B · Departamento de Informática · UTFSM*
