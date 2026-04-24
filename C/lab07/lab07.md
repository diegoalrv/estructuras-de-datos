# Laboratorio 7 — Pila (Stack)

**Curso:** EIN423-B · Estructuras de Datos
**Duración:** 90 minutos
**Horario:** 08:30 – 10:00

## Objetivos del laboratorio
- Implementar el TDA Pila usando lista enlazada
- Comprender y aplicar el principio LIFO (Last In, First Out)
- Resolver problemas clásicos: paréntesis balanceados, notación postfija
- Entender por qué las pilas son fundamentales en recursión y compiladores

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

Una **pila (stack)** es una estructura **LIFO** (Last In, First Out): el último elemento insertado es el primero en salir.

**Visualización:**
```
tope →  [ 5 ]  ← último en entrar, primero en salir
        [ 3 ]
        [ 1 ]  ← primer en entrar
        [   ]
```

**Aplicaciones reales:**
- **Call stack:** Cada llamada a función entra en la pila; al retornar, sale
- **Paréntesis balanceados:** Compiladores verifican que { [ ( se cierren correctamente
- **Notación postfija (RPN):** "3 4 +" = 7 (evaluador de calculadora)
- **Undo/Redo:** Cada acción entra; deshacer saca del tope

---

# 2. Concepto y código guiado (08:40 – 09:10)

## Estructura de Pila

Usaremos una lista enlazada (dinámica, sin límite de tamaño):

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo {
    int dato;
    struct Nodo *siguiente;
} Nodo;

typedef struct {
    Nodo *tope;
    int tamanio;
} Pila;
```

## Diagrama: LIFO

```
Operación:    push(5)  push(3)  push(1)   pop()    pop()
Estado:       [5]      [5]      [5]       [5]      [5]
              [ ]      [3]      [3]       [3]      [ ]
              [ ]      [ ]      [1]       [1]
                                (tope)
```

Nota: `push` agrega al tope (push_front), `pop` extrae del tope (pop_front).

## Crear pila

```c
Pila crear_pila(void) {
    Pila pila;
    pila.tope = NULL;
    pila.tamanio = 0;
    return pila;
}
```

## push: Insertar al tope

```c
void push(Pila *pila, int valor) {
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    if (nuevo == NULL) {
        fprintf(stderr, "Error: No se pudo asignar memoria\n");
        return;
    }

    nuevo->dato = valor;
    nuevo->siguiente = pila->tope;
    pila->tope = nuevo;
    pila->tamanio++;

    printf("push(%d): ", valor);
}
```

## pop: Eliminar del tope

```c
int pop(Pila *pila) {
    if (pila->tope == NULL) {
        fprintf(stderr, "Error: Pila vacía\n");
        return -1;
    }

    Nodo *temp = pila->tope;
    int valor = temp->dato;
    pila->tope = temp->siguiente;
    free(temp);
    pila->tamanio--;

    return valor;
}
```

## peek: Ver el tope sin eliminar

```c
int peek(Pila *pila) {
    if (pila->tope == NULL) {
        fprintf(stderr, "Error: Pila vacía\n");
        return -1;
    }
    return pila->tope->dato;
}
```

## Esta vacía

```c
int esta_vacia(Pila *pila) {
    return pila->tope == NULL;
}
```

## Obtener tamaño

```c
int obtener_tamanio(Pila *pila) {
    return pila->tamanio;
}
```

## Destruir pila

```c
void destruir_pila(Pila *pila) {
    while (!esta_vacia(pila)) {
        pop(pila);
    }
    pila->tamanio = 0;
}
```

## Aplicación 1: Invertir una cadena

```c
void invertir_cadena(const char *original, char *invertida) {
    Pila pila = crear_pila();

    // Meter cada carácter en la pila
    for (int i = 0; original[i] != '\0'; i++) {
        push(&pila, (int)original[i]);
    }

    // Sacar en orden inverso
    int i = 0;
    while (!esta_vacia(&pila)) {
        invertida[i++] = (char)pop(&pila);
    }
    invertida[i] = '\0';

    destruir_pila(&pila);
}
```

**Ejemplo:**
```
invertir_cadena("HELLO", resultado);
// resultado = "OLLEH"
```

---

# 3. Ejercicios (09:10 – 09:55)

## Ejercicio 1 — TDA Pila Completo (★☆☆)

Implementa un programa que:
1. Crea una pila vacía
2. Hace `push` de los números 1, 2, 3, 4, 5 (en ese orden)
3. Imprime el tamaño (debe ser 5)
4. Verifica que `peek()` retorna 5 (el tope)
5. Hace `pop` 5 veces e imprime cada valor (debe ser 5, 4, 3, 2, 1)
6. Verifica que `esta_vacia()` retorna verdadero

**Funciones requeridas:**
```c
Pila crear_pila(void);
void push(Pila *pila, int valor);
int pop(Pila *pila);
int peek(Pila *pila);
int esta_vacia(Pila *pila);
int obtener_tamanio(Pila *pila);
void destruir_pila(Pila *pila);
```

**Salida esperada:**
```
Tamaño inicial: 0
push(1) push(2) push(3) push(4) push(5)
Tamaño final: 5
Tope (peek): 5
pop(): 5, pop(): 4, pop(): 3, pop(): 2, pop(): 1
Pila vacía: 1
```

---

## Ejercicio 2 — Paréntesis Balanceados (★★☆)

Implementa `int esta_balanceada(const char *expresion)` que verifica si una expresión tiene paréntesis, corchetes y llaves **balanceados**.

**Reglas:**
- `{`, `[`, `(` abren
- `}`, `]`, `)` cierran el tipo correspondiente
- La expresión es válida si cada cierre corresponde al último abierto

**Algoritmo:**
1. Recorrer carácter por carácter
2. Si es abierto `{`, `[`, `(` → hacer push
3. Si es cerrado `}`, `]`, `)`:
   - Si pila vacía → inválido
   - Si tope no coincide con tipo → inválido
   - Si coincide → hacer pop
4. Al final, si pila vacía → válido

**Ejemplo:**
```
"({[]})"      → válido
({            → push ( y {
[]}           → push [, pop ] (coincide [), pop } (coincide {), pop ) (coincide ()

"({)}"        → inválido
({            → push ( y {
)             → coincide (, pero abierto está {, no ( → inválido

"[[[]]]"      → válido
"((("         → inválido (no se cierran)
""            → válido (vacío)
```

**Prueba en main:**
```c
printf("%d\n", esta_balanceada("({[]})"));    // 1
printf("%d\n", esta_balanceada("({})"));      // 1
printf("%d\n", esta_balanceada("({)"));       // 0
printf("%d\n", esta_balanceada("[[["));       // 0
printf("%d\n", esta_balanceada(""));          // 1
printf("%d\n", esta_balanceada("()[]{}"));    // 1
```

---

## Ejercicio 3 — Evaluador de Notación Postfija (★★★)

Implementa `int evaluar_postfija(const char *expresion)` que evalúa una expresión en **notación postfija** (RPN).

**Notación postfija vs infiija:**
```
Infiija:      3 + 4 * 2         (normal, operador en medio)
Postfija:     3 4 2 * +         (operador al final)

Evaluación:
- push(3)              Pila: [3]
- push(4)              Pila: [3, 4]
- push(2)              Pila: [3, 4, 2]
- pop 2, pop 4, 4*2=8, push(8)    Pila: [3, 8]
- pop 8, pop 3, 3+8=11, push(11)  Pila: [11]
- Resultado: 11
```

**Algoritmo:**
1. Parsear la expresión separada por espacios
2. Si es número → push
3. Si es operador (+, -, *, /):
   - pop dos valores (B es el tope, A es el siguiente)
   - calcular A op B
   - push resultado
4. Al final, el tope es el resultado

**Expresiones para probar:**
```
"3 4 +"                          → 7 (3+4)
"5 1 2 + 4 * + 3 -"              → 14
"15 7 1 1 + - / 3 * 2 1 1 + + -" → 5

Verificación de la última:
15 7 1 1 + - / 3 * 2 1 1 + + -
15 7 2 - / 3 * 2 2 + -       (1+1=2)
15 5 / 3 * 2 2 + -           (7-2=5)
3 3 * 2 2 + -                (15/5=3)
9 2 2 + -                     (3*3=9)
9 4 -                         (2+2=4)
5                             (9-4=5)
```

**Manejo de errores:**
- Divisiones por cero
- Operandos insuficientes
- Operadores inválidos

**En main:**
```c
printf("%d\n", evaluar_postfija("3 4 +"));              // 7
printf("%d\n", evaluar_postfija("10 5 -"));             // 5
printf("%d\n", evaluar_postfija("3 4 * 2 /"));          // 6
printf("%d\n", evaluar_postfija("5 1 2 + 4 * + 3 -")); // 14
```

---

# Cierre (09:55 – 10:00)

La **pila es el corazón** de muchos algoritmos fundamentales:

- **Recursión:** El call stack es una pila. Cada llamada entra; al retornar, sale
- **Compiladores:** Parsean expresiones y verifican balance de paréntesis con pilas
- **Evaluación de expresiones:** RPN es más fácil de evaluar que infiija
- **DFS (Depth-First Search):** Usa pilas para exploración

**Próximo laboratorio:** Cola (Queue) FIFO y Cola de Prioridad.

---

*EIN423-B · Departamento de Informática · UTFSM*
