# Laboratorio 0 — Introducción a la Programación en C

## Objetivos del laboratorio

- Compilar y ejecutar programas simples en C
- Comprender la estructura básica de un programa en C (`#include`, `main`, `return`)
- Manejar los tipos de datos primitivos: `int`, `float`, `double`, `char`
- Usar `printf` y `scanf` para entrada y salida estándar
- Escribir estructuras condicionales con `if / else if / else`
- Implementar ciclos con `for`, `while` y `do-while`
- Definir y llamar funciones con y sin retorno de valor

---

# 1. Introducción

C es un lenguaje de **bajo nivel controlado**: nos obliga a pensar en cómo funciona el computador (memoria, tipos, tamaño de datos), pero sin la complejidad del ensamblador. Es el lenguaje base de sistemas operativos, compiladores y prácticamente todas las estructuras de datos que estudiaremos este semestre.

**¿Por qué aprender C antes de estructuras de datos?**

- En C, el programador controla explícitamente la memoria.
- Los punteros (próximo lab) son la clave para listas enlazadas, árboles y grafos.
- Entender C nos permite comprender *qué hace realmente* un lenguaje de más alto nivel como Python o Java por debajo.

Hoy daremos los primeros pasos: escribir, compilar y ejecutar programas en C, y practicar sus bloques fundamentales.

---

# 2. Conceptos y código guiado

## 2.1 Estructura mínima de un programa en C

```c
#include <stdio.h>   // Librería de entrada/salida estándar

int main() {
    printf("Hola, mundo!\n");
    return 0;        // 0 = éxito
}
```

**Elementos clave:**
- `#include <stdio.h>` — importa funciones como `printf` y `scanf`.
- `int main()` — punto de entrada del programa; retorna un entero.
- `return 0;` — indica que el programa terminó sin errores.
- `\n` — carácter de nueva línea.

## 2.2 Tipos de datos primitivos

| Tipo     | Tamaño típico | Descripción              | Ejemplo           |
|----------|---------------|--------------------------|-------------------|
| `int`    | 4 bytes       | Entero con signo         | `int x = 42;`     |
| `float`  | 4 bytes       | Real de precisión simple | `float f = 3.14f;`|
| `double` | 8 bytes       | Real de doble precisión  | `double d = 3.14;`|
| `char`   | 1 byte        | Carácter ASCII           | `char c = 'A';`   |

```c
#include <stdio.h>

int main() {
    int    entero  = 100;
    float  real_f  = 3.14f;
    double real_d  = 2.718281828;
    char   letra   = 'C';

    printf("int:    %d\n",  entero);
    printf("float:  %.2f\n", real_f);
    printf("double: %.9f\n", real_d);
    printf("char:   %c  (ASCII: %d)\n", letra, letra);

    return 0;
}
```

## 2.3 Entrada con `scanf`

```c
#include <stdio.h>

int main() {
    int edad;
    printf("Ingresa tu edad: ");
    scanf("%d", &edad);           // & es "dirección de" — más detalles en Lab 1
    printf("Tienes %d años.\n", edad);
    return 0;
}
```

**Especificadores de formato frecuentes:**

| Especificador | Tipo     |
|---------------|----------|
| `%d`          | `int`    |
| `%f`          | `float`  |
| `%lf`         | `double` (en `scanf`) |
| `%c`          | `char`   |
| `%s`          | cadena de texto |

---

# 3. Actividades prácticas (09:05 – 09:55)

## Actividad 1 — Hola, mundo personalizado (★☆☆)

**Archivo:** `act1_hola_mundo.c`

Modifica el clásico "Hola, mundo" para que:
1. Imprima en líneas separadas tu nombre, carrera y año de ingreso.
2. Use al menos una variable `char[]` para almacenar el nombre.

**Salida esperada (ejemplo):**
```
Nombre : Diego
Carrera: Ingeniería Civil Informática
Año    : 2023
```

**Pistas:**
- Declara `char nombre[] = "Diego";` para guardar texto.
- Usa `%s` en `printf` para imprimir cadenas.

---

## Actividad 2 — Variables y tipos de datos (★☆☆)

**Archivo:** `act2_variables.c`

Declara las siguientes variables, asígnales un valor y calcula los resultados indicados:

1. Dos enteros `a` y `b`. Imprime su suma, resta, producto, cociente y resto.
2. Un `double` con el radio de un círculo. Calcula e imprime el **área** y el **perímetro** usando `π ≈ 3.14159265`.
3. Un `char` con una letra minúscula. Imprime el carácter y su equivalente en mayúscula (suma 32 a su valor ASCII para ir de mayúscula a minúscula; réstalo para el inverso).

**Salida esperada (con `a=10`, `b=3`, `radio=5.0`, `letra='a'`):**
```
a=10, b=3
Suma     : 13
Resta    : 7
Producto : 30
Cociente : 3
Resto    : 1
Radio=5.00, Area=78.54, Perimetro=31.42
Letra minuscula: a  →  Mayuscula: A
```

---

## Actividad 3 — Entrada/salida interactiva (★★☆)

**Archivo:** `act3_io.c`

Escribe un programa que:
1. Pida al usuario que ingrese **dos números reales** (`double`).
2. Imprima la **suma**, **diferencia**, **producto** y **cociente** (con 4 decimales).
3. Verifique que el divisor no sea cero antes de calcular el cociente; de lo contrario imprime `"División no definida"`.

**Ejemplo de ejecución:**
```
Ingresa el primer número : 7.5
Ingresa el segundo número: 2.5
Suma      : 10.0000
Diferencia: 5.0000
Producto  : 18.7500
Cociente  : 3.0000
```

---

## Actividad 4 — Condicionales: calculadora de notas (★★☆)

**Archivo:** `act4_condicionales.c`

Escribe un programa que:
1. Lea una nota entre 1.0 y 7.0 (tipo `double`).
2. Clasifique la nota según la siguiente tabla e imprima el mensaje correspondiente:

| Rango         | Mensaje             |
|---------------|---------------------|
| 6.0 – 7.0     | `Excelente`         |
| 5.0 – 5.9     | `Bueno`             |
| 4.0 – 4.9     | `Suficiente`        |
| 3.0 – 3.9     | `Insuficiente`      |
| 1.0 – 2.9     | `Reprobado`         |
| Fuera de rango| `Nota inválida`     |

3. Indique además si el alumno **aprobó o reprobó** (nota mínima de aprobación: 4.0).

**Ejemplo:**
```
Ingresa la nota: 5.5
Clasificación: Bueno
Estado: Aprobado
```

---

## Actividad 5 — Ciclos: tablas y series (★★☆)

**Archivo:** `act5_ciclos.c`

Implementa tres secciones en el mismo programa:

1. **Tabla de multiplicar** — Usando un `for`, imprime la tabla del número que ingrese el usuario (del 1 al 10).
2. **Cuenta regresiva** — Usando un `while`, imprime los números desde N hasta 1 y al final imprime `"¡Despegue!"`. El valor de N lo ingresa el usuario.
3. **Suma de dígitos** — Usando un `do-while`, suma los dígitos de un número entero positivo ingresado por el usuario (ej.: `1234 → 1+2+3+4 = 10`).

**Ejemplo de salida (tabla del 3, cuenta desde 5, número 1234):**
```
--- Tabla del 3 ---
3 x 1 = 3
3 x 2 = 6
...
3 x 10 = 30

--- Cuenta regresiva desde 5 ---
5 4 3 2 1 ¡Despegue!

--- Suma de dígitos de 1234 ---
Suma: 10
```

---

## Actividad 6 — Funciones: conversiones y utilidades (★★★)

**Archivo:** `act6_funciones.c`

Implementa las siguientes funciones **antes** de `main` y úsalas dentro de `main`:

```c
// Convierte grados Celsius a Fahrenheit
double celsius_a_fahrenheit(double celsius);

// Retorna el valor absoluto de un entero (sin usar abs() de stdlib)
int valor_absoluto(int n);

// Retorna 1 si n es primo, 0 si no lo es
int es_primo(int n);

// Imprime los primeros n números de la serie Fibonacci
void fibonacci(int n);
```

**Comportamiento esperado en `main`:**
1. Pide temperatura en Celsius e imprime en Fahrenheit.
2. Pide un entero e imprime su valor absoluto.
3. Pide un entero e informa si es primo o no.
4. Pide cuántos términos de Fibonacci imprimir y los muestra.

**Ejemplo:**
```
Temperatura en Celsius: -40
En Fahrenheit: -40.00

Entero: -17
Valor absoluto: 17

Número: 7
7 es primo

Términos Fibonacci: 8
0 1 1 2 3 5 8 13
```

---

# 4. Cierre (09:55 – 10:00)

En este laboratorio sentamos las bases de C:

- Todo programa comienza en `main` y usa `#include` para acceder a librerías.
- C es **fuertemente tipado**: cada variable debe declararse con su tipo antes de usarse.
- `printf`/`scanf` manejan la E/S con especificadores de formato (`%d`, `%f`, `%c`, `%s`).
- Las estructuras de control (`if/else`, `for`, `while`, `do-while`) funcionan igual que en otros lenguajes, pero sin recolector de basura ni excepciones automáticas.
- Las funciones en C se declaran con tipo de retorno, nombre y parámetros tipados.

En el **Laboratorio 1** daremos el salto fundamental: los **punteros**, que permiten acceder y modificar memoria directamente. Sin ellos, no podemos construir ninguna estructura de datos dinámica.

---

*EIN423-B · Departamento de Informática · UTFSM*
