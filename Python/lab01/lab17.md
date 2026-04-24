# Laboratorio 17 — Introducción a Programación Orientada a Objetos en Python

**Curso:** EIN423-B · Estructuras de Datos  
**Duración:** 90 minutos  
**Horario:** 08:30 – 10:00

## Objetivos del laboratorio

- Comprender la diferencia entre clases y objetos
- Dominar la definición de atributos y métodos
- Implementar constructores (`__init__`) y el parámetro `self`
- Aplicar encapsulamiento básico con atributos privados
- Implementar métodos especiales (`__str__`, `__repr__`, `__eq__`)
- Practicar validación de datos en métodos
- Prepararse para estructuras de datos complejas en C

---

## Estructura de la clase

| Hora | Actividad |
|------|-----------|
| 08:30 – 08:40 | Introducción y motivación |
| 08:40 – 09:10 | Conceptos fundamentales + código guiado |
| 09:10 – 09:55 | Ejercicios prácticos |
| 09:55 – 10:00 | Cierre y próximas aplicaciones |

---

# 1. Introducción (08:30 – 08:40)

## ¿Por qué OOP?

La **Programación Orientada a Objetos (OOP)** es un paradigma que organiza el código en torno a **objetos**: entidades que contienen tanto datos (atributos) como operaciones (métodos).

### Ventajas principales:

1. **Reutilización**: Define una clase una vez, crea múltiples instancias
2. **Modularidad**: Agrupa datos relacionados con sus operaciones
3. **Mantenibilidad**: Cambios locales sin romper código externo
4. **Preparación para C avanzado**: Entender estructuras y funciones relacionadas

### Comparación: Procedural vs OOP

```python
# PROCEDURAL: datos y funciones separadas
edades = [25, 30, 22]
nombres = ["Alice", "Bob", "Charlie"]

def mostrar_persona(nombre, edad):
    print(f"{nombre} tiene {edad} años")

# OOP: datos y funciones juntos
class Persona:
    def __init__(self, nombre, edad):
        self.nombre = nombre
        self.edad = edad
    
    def mostrar_info(self):
        print(f"{self.nombre} tiene {self.edad} años")

alice = Persona("Alice", 25)
alice.mostrar_info()
```

---

# 2. Conceptos Fundamentales (08:40 – 09:10)

## 2.1 Clase vs Objeto

### Clase: El Plano

Una **clase** es una plantilla o esquema que define:
- Qué atributos tendrán los objetos (datos)
- Qué métodos podrán ejecutar (acciones)

```python
class Auto:
    pass  # Plantilla vacía
```

### Objeto: La Instancia

Un **objeto** es una instancia específica de una clase con datos reales.

```python
auto1 = Auto()  # Objeto 1
auto2 = Auto()  # Objeto 2
```

**Analógía**: Una clase es como el plano de una casa. Los objetos son casas reales construidas según ese plano.

---

## 2.2 Atributos

Los **atributos** son variables que pertenecen al objeto. Se definen y acceden mediante `self`.

```python
class Persona:
    def __init__(self, nombre, edad):
        self.nombre = nombre      # Atributo 1
        self.edad = edad          # Atributo 2
        self.saldo = 0            # Atributo 3

alice = Persona("Alice", 25)
print(alice.nombre)     # Alice
print(alice.edad)       # 25
```

**Nota**: El método especial `__init__` es el **constructor** y se ejecuta automáticamente al crear un objeto.

---

## 2.3 Métodos

Los **métodos** son funciones que pertenecen a la clase. Siempre reciben `self` como primer parámetro.

```python
class Persona:
    def __init__(self, nombre):
        self.nombre = nombre
    
    def saludar(self):                    # Método sin parámetros (además de self)
        return f"Hola, soy {self.nombre}"
    
    def cambiar_nombre(self, nuevo_nombre):  # Método con parámetros
        self.nombre = nuevo_nombre

alice = Persona("Alice")
print(alice.saludar())               # Hola, soy Alice
alice.cambiar_nombre("Alicia")
print(alice.saludar())               # Hola, soy Alicia
```

---

## 2.4 El parámetro `self`

`self` es una **referencia al objeto actual**. Permite que los métodos accedan a los atributos del objeto.

```python
class Contador:
    def __init__(self):
        self.valor = 0
    
    def incrementar(self):
        self.valor += 1  # self.valor accede al atributo del objeto actual
    
    def obtener(self):
        return self.valor

c = Contador()
c.incrementar()
c.incrementar()
print(c.obtener())  # 2
```

**Clave**: `self.valor` en `c.incrementar()` significa "el atributo `valor` del objeto `c`".

---

## 2.5 Encapsulamiento Básico

El **encapsulamiento** protege los datos de cambios no autorizados. Python usa convenciones:

- **Público**: `nombre`
- **Privado por convención**: `_nombre` (un guion bajo)
- **Privado (name mangling)**: `__nombre` (dos guiones bajos)

```python
class Banco:
    def __init__(self, titular):
        self.titular = titular          # Público
        self._saldo = 0                 # Privado por convención
    
    def depositar(self, cantidad):
        if cantidad > 0:
            self._saldo += cantidad
        else:
            raise ValueError("Cantidad debe ser positiva")
    
    def obtener_saldo(self):
        return self._saldo

banco = Banco("Juan")
banco.depositar(1000)
print(banco.obtener_saldo())    # 1000
# banco._saldo = -999  # Técnicamente posible pero ¡MALA PRÁCTICA!
```

---

## 2.6 Métodos Especiales

Los métodos especiales (dunder methods) cumplen roles específicos:

### `__str__`: Representación legible

```python
class Persona:
    def __init__(self, nombre, edad):
        self.nombre = nombre
        self.edad = edad
    
    def __str__(self):
        return f"{self.nombre} ({self.edad} años)"

alice = Persona("Alice", 25)
print(alice)  # Alice (25 años)
```

### `__repr__`: Representación para desarrolladores

```python
class Persona:
    def __repr__(self):
        return f"Persona(nombre='{self.nombre}', edad={self.edad})"

print(repr(alice))  # Persona(nombre='Alice', edad=25)
```

### `__eq__`: Comparación de igualdad

```python
class Persona:
    def __init__(self, nombre, edad):
        self.nombre = nombre
        self.edad = edad
    
    def __eq__(self, otro):
        if not isinstance(otro, Persona):
            return False
        return self.nombre == otro.nombre and self.edad == otro.edad

alice1 = Persona("Alice", 25)
alice2 = Persona("Alice", 25)
print(alice1 == alice2)  # True (si tienen mismo nombre y edad)
```

---

## 2.7 Constructor y Validación

El constructor es el lugar ideal para validar datos iniciales:

```python
class Producto:
    def __init__(self, nombre, precio, stock):
        if not nombre or len(nombre) == 0:
            raise ValueError("El nombre no puede estar vacío")
        if precio < 0:
            raise ValueError("El precio no puede ser negativo")
        if stock < 0:
            raise ValueError("El stock no puede ser negativo")
        
        self.nombre = nombre
        self.precio = precio
        self.stock = stock

# Uso correcto
p1 = Producto("Laptop", 999.99, 5)

# Generará error
p2 = Producto("Mouse", -10, 20)  # ValueError
```

---

# 3. Ejercicios Prácticos (09:10 – 09:55)

## Ejercicio 1: Clase `Cuenta` (★☆☆)

Implementa una clase `Cuenta` con:
- **Atributos**: `titular` (str), `_saldo` (float)
- **Métodos**:
  - `__init__(titular, saldo_inicial)`: Constructor con validación
  - `depositar(cantidad)`: Aumenta el saldo (validar cantidad > 0)
  - `retirar(cantidad)`: Disminuye el saldo (validar cantidad > 0 y <= saldo)
  - `obtener_saldo()`: Retorna el saldo
  - `__str__()`: Retorna `"Cuenta de [titular]: $[saldo]"`

### Ejemplo de uso:
```python
cuenta = Cuenta("Juan", 1000)
cuenta.depositar(500)
print(cuenta.obtener_saldo())  # 1500
cuenta.retirar(200)
print(cuenta)  # Cuenta de Juan: $1300.0
```

---

## Ejercicio 2: Clase `Estudiante` (★★☆)

Implementa una clase `Estudiante` con:
- **Atributos**: `nombre`, `carrera`, `_calificaciones` (lista)
- **Métodos**:
  - `__init__(nombre, carrera)`: Constructor
  - `agregar_calificacion(nota)`: Añade nota (validar 1.0-7.0)
  - `promedio()`: Calcula el promedio de calificaciones
  - `aprobo()`: Retorna True si promedio >= 4.0
  - `__str__()`: Retorna nombre, carrera y promedio
  - `__eq__(otro)`: Compara por nombre y carrera

### Ejemplo de uso:
```python
est = Estudiante("Maria", "Ingeniería en Computación")
est.agregar_calificacion(6.5)
est.agregar_calificacion(7.0)
est.agregar_calificacion(5.5)
print(est.promedio())  # 6.333...
print(est)             # Maria (Ingeniería en Computación) - Promedio: 6.33
print(est.aprobo())    # True
```

---

## Ejercicio 3: Clase `Inventario` (★★★)

Implementa una clase `Inventario` que administra productos:
- **Atributos**: `_productos` (diccionario con producto: cantidad)
- **Métodos**:
  - `__init__()`: Constructor que inicializa inventario vacío
  - `agregar_producto(nombre, cantidad)`: Añade producto (validar cantidad > 0)
  - `quitar_producto(nombre, cantidad)`: Reduce cantidad (validar cantidad disponible)
  - `obtener_cantidad(nombre)`: Retorna cantidad de un producto
  - `productos_disponibles()`: Retorna lista de productos en stock
  - `vaciar()`: Vacía todo el inventario
  - `__str__()`: Muestra resumen del inventario
  - `__len__()`: Retorna cantidad total de unidades

### Ejemplo de uso:
```python
inv = Inventario()
inv.agregar_producto("Laptop", 5)
inv.agregar_producto("Mouse", 20)
print(len(inv))  # 25
print(inv.obtener_cantidad("Laptop"))  # 5
inv.quitar_producto("Mouse", 3)
print(len(inv))  # 22
print(inv)
# Inventario: Laptop (5), Mouse (17)
```

---

## Ejercicio 4: Clase `Fecha` (★★★)

Implementa una clase `Fecha` para representar fechas:
- **Atributos**: `dia`, `mes`, `anno` (validados en constructor)
- **Métodos**:
  - `__init__(dia, mes, anno)`: Valida rango válido
  - `es_bisiesto()`: Retorna True si el año es bisiesto
  - `dias_en_mes()`: Retorna cuántos días tiene el mes
  - `es_valida()`: Valida la fecha completa
  - `__str__()`: Formato "DD/MM/AAAA"
  - `__eq__(otra)`: Compara dos fechas
  - `__lt__(otra)`: Retorna True si es anterior a otra fecha

### Ejemplo de uso:
```python
f1 = Fecha(15, 3, 2024)
f2 = Fecha(20, 3, 2024)
print(f1)  # 15/03/2024
print(f1 < f2)  # True
print(f1 == f2)  # False

# Validación
f3 = Fecha(30, 2, 2024)  # ValueError: Febrero no tiene 30 días
```

---

# 4. Buenas Prácticas y Errores Comunes

## ✅ Buenas Prácticas

1. **Nombres claros**: Usa PascalCase para clases (`Persona`), snake_case para atributos/métodos (`mi_atributo`)
2. **Inicializa en `__init__`**: Todos los atributos deben inicializarse en el constructor
3. **Documenta con docstrings**:
   ```python
   def depositar(self, cantidad):
       """Deposita una cantidad en la cuenta.
       
       Args:
           cantidad (float): Monto a depositar (debe ser > 0)
       
       Raises:
           ValueError: Si cantidad <= 0
       """
   ```
4. **Valida siempre**: Especialmente en `__init__` y métodos que modifican estado
5. **Usa encapsulamiento**: Atributos privados, acceso controlado via métodos

## ❌ Errores Comunes

| Error | Correcto |
|-------|----------|
| `def saludar():` (sin self) | `def saludar(self):` |
| `p = Persona` (sin paréntesis) | `p = Persona()` |
| `self.edad = -5` (sin validación) | Validar en setter o método |
| Mezclar público y privado | Ser consistente con convenciones |
| No documentar métodos | Usar docstrings |

---

# 5. Puente hacia Estructuras de Datos en C

Los conceptos de OOP preparan el camino para estructuras complejas en C:

| Concepto OOP | Equivalente en C |
|--------------|-----------------|
| Clase | `struct` |
| Atributos | Campos de la estructura |
| Métodos | Funciones que reciben puntero a struct |
| Constructor `__init__` | Función `nuevo_*()` que aloca memoria |
| Encapsulamiento | Documentación de uso privado/público |

**Ejemplo**: Una clase `Nodo` en OOP se transforma en C así:

```python
# Python OOP
class Nodo:
    def __init__(self, valor):
        self.valor = valor
        self.siguiente = None
```

```c
// C equivalente
typedef struct Nodo {
    int valor;
    struct Nodo* siguiente;
} Nodo;

Nodo* nuevo_nodo(int valor) {
    Nodo* n = malloc(sizeof(Nodo));
    n->valor = valor;
    n->siguiente = NULL;
    return n;
}
```

---

# Resumen

En este laboratorio aprendiste:

✓ La diferencia entre clases y objetos  
✓ Atributos, métodos y constructores  
✓ El rol crucial de `self`  
✓ Encapsulamiento básico  
✓ Métodos especiales para controlimpresión y comparación  
✓ Validación de datos  
✓ Cómo OOP prepara para estructuras en C

**Próximo paso**: Herencia, polimorfismo y luego estructuras de datos avanzadas en C.

---

## Recursos Adicionales

- **Documentación oficial**: https://docs.python.org/3/tutorial/classes.html
- **Ejercicios extra**: Ver archivos `ejercicio_1.py`, `ejercicio_2.py`, etc.
