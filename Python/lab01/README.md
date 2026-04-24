# Laboratorio 17: Introducción a Programación Orientada a Objetos en Python

Bienvenido al Laboratorio 17, donde aprenderás los fundamentos de la **Programación Orientada a Objetos (OOP)** en Python. Este laboratorio es el puente entre Python puro y las estructuras de datos complejas que implementaremos en C.

## 📚 Contenidos del Laboratorio

### Archivos principales:

1. **lab17.md** — Guía completa del laboratorio con:
   - Conceptos teóricos detallados
   - Ejemplos de código
   - Explicación de buenas prácticas
   - 4 ejercicios progresivos

2. **ejemplo_basico.py** — Ejemplos funcionales:
   - Clase `Persona` (atributos y métodos básicos)
   - Clase `Auto` (encapsulamiento)
   - Clase `Contador` (métodos especiales)
   - Clase `Temperatura` (validación)

3. **ejercicio_1_template.py** — Template para la clase `Cuenta`
4. **ejercicio_2_template.py** — Template para la clase `Estudiante`
5. **ejercicio_3_template.py** — Template para la clase `Inventario`
6. **ejercicio_4_template.py** — Template para la clase `Fecha`

## 🚀 Cómo usar este laboratorio

### Paso 1: Revisa los ejemplos

```bash
python ejemplo_basico.py
```

Este archivo contiene clases completas y funcionales. Estúdialas para entender la sintaxis y estructura.

### Paso 2: Implementa los ejercicios

Cada archivo de template (`ejercicio_N_template.py`) contiene:
- La estructura de la clase con comentarios `# TODO`
- Las pruebas al final (descomenta para verificar)

Proceso para cada ejercicio:

```bash
# 1. Abre el archivo en tu editor favorito
nano ejercicio_1_template.py

# 2. Implementa los métodos (reemplaza # TODO por código real)
# 3. Descomenta las pruebas al final del archivo
# 4. Ejecuta para verificar tu implementación
python ejercicio_1_template.py

# 5. Si todas las pruebas pasan, ¡felicidades!
```

## 📋 Ejercicios

### Ejercicio 1: Clase `Cuenta` (Básico)
**Tiempo estimado:** 15-20 minutos

Implementa una clase `Cuenta` para administrar una cuenta bancaria.

**Conceptos**: Atributos, métodos, constructor, validación básica

```python
cuenta = Cuenta("Juan", 1000)
cuenta.depositar(500)
print(cuenta.obtener_saldo())  # 1500
```

---

### Ejercicio 2: Clase `Estudiante` (Intermedio)
**Tiempo estimado:** 20-25 minutos

Implementa una clase `Estudiante` que maneje calificaciones.

**Conceptos**: Listas como atributos, cálculos, métodos especiales (`__eq__`, `__str__`)

```python
est = Estudiante("Maria", "Ingeniería")
est.agregar_calificacion(6.5)
est.agregar_calificacion(7.0)
print(est.promedio())  # 6.75
```

---

### Ejercicio 3: Clase `Inventario` (Intermedio)
**Tiempo estimado:** 20-25 minutos

Implementa una clase `Inventario` que gestiona múltiples productos.

**Conceptos**: Diccionarios como atributos, `__len__`, operaciones complejas

```python
inv = Inventario()
inv.agregar_producto("Laptop", 5)
inv.agregar_producto("Mouse", 20)
print(len(inv))  # 25 (total de unidades)
```

---

### Ejercicio 4: Clase `Fecha` (Avanzado)
**Tiempo estimado:** 30-35 minutos

Implementa una clase `Fecha` con validación compleja.

**Conceptos**: Validación compleja, años bisiestos, comparaciones (`__lt__`, `__eq__`)

```python
f1 = Fecha(15, 3, 2024)
f2 = Fecha(20, 3, 2024)
print(f1 < f2)  # True
print(f1)  # 15/03/2024
```

## 🎯 Objetivos de aprendizaje

Al completar este laboratorio, deberías ser capaz de:

- [ ] Entender la diferencia entre clases y objetos
- [ ] Definir atributos y métodos en una clase
- [ ] Usar `self` correctamente en métodos
- [ ] Implementar constructores (`__init__`)
- [ ] Validar datos en métodos
- [ ] Usar encapsulamiento básico (atributos privados)
- [ ] Implementar métodos especiales (`__str__`, `__eq__`, `__lt__`)
- [ ] Trabajar con listas y diccionarios como atributos
- [ ] Aplicar OOP a problemas del mundo real

## 💡 Tips y trucos

### Tip 1: Entender `self`
`self` siempre se refiere al objeto actual. En `cuenta.depositar(100)`, dentro del método `self` será `cuenta`.

### Tip 2: Nombra tus atributos claramente
- Público: `saldo`, `nombre`, `edad`
- Privado: `_saldo`, `_dni`, `_password`
- No uses nombres genéricos como `x`, `datos`, `resultado`

### Tip 3: Documenta con docstrings
```python
def depositar(self, cantidad):
    """Deposita dinero en la cuenta.
    
    Args:
        cantidad (float): Monto a depositar
    
    Raises:
        ValueError: Si cantidad <= 0
    """
```

### Tip 4: Valida en el constructor
La mayoría de validaciones deben estar en `__init__` para garantizar que los objetos siempre están en estado válido.

### Tip 5: Usa métodos especiales
`__str__` para representación legible, `__eq__` para comparación, `__lt__` para ordenamiento.

## ⚠️ Errores comunes

| Error | Solución |
|-------|----------|
| `def saludar():` (sin self) | Siempre incluye `self` como primer parámetro |
| `p = Persona` (sin `()`) | Siempre usa `()` para crear instancias: `Persona()` |
| Modificar `_atributo` desde fuera | Usa métodos públicos para acceder/modificar |
| Olvidar inicializar en `__init__` | Todos los atributos deben inicializarse en el constructor |
| No validar entrada | Valida siempre, especialmente en `__init__` y métodos setter |

## 🔗 Conexión con C

Los conceptos de OOP en Python se traducen a C así:

| Python | C |
|--------|---|
| Clase | `struct` |
| Atributo | Campo de la estructura |
| Método | Función que recibe puntero a struct |
| Constructor `__init__` | Función `nuevo_*()` que aloca memoria |
| Encapsulamiento | Documentación y archivos `.h` |

Ejemplo:
```python
# Python
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

## 📚 Recursos adicionales

- [Documentación oficial de Python - Clases](https://docs.python.org/3/tutorial/classes.html)
- [Real Python - OOP in Python](https://realpython.com/python3-object-oriented-programming/)
- [Ejercicios en LeetCode](https://leetcode.com/problems/) (busca "OOP Python")

## ✅ Checklist para completar el laboratorio

- [ ] Leí completamente lab17.md
- [ ] Ejecuté y entendí ejemplo_basico.py
- [ ] Implementé y pasé todas las pruebas del Ejercicio 1 (Cuenta)
- [ ] Implementé y pasé todas las pruebas del Ejercicio 2 (Estudiante)
- [ ] Implementé y pasé todas las pruebas del Ejercicio 3 (Inventario)
- [ ] Implementé y pasé todas las pruebas del Ejercicio 4 (Fecha)
- [ ] Entiendo cómo OOP en Python se relaciona con C
- [ ] Puedo explicar qué es `self` y por qué es importante
- [ ] Puedo usar correctamente métodos especiales como `__str__` y `__eq__`

## 🤝 Necesitas ayuda?

Si tienes dudas:

1. **Revisa los ejemplos** en `ejemplo_basico.py`
2. **Lee la documentación** en `lab17.md`
3. **Descomenta las pruebas** en los templates para ver qué se espera
4. **Ejecuta paso a paso** y verifica cada método

¡Buen laboratorio! 🚀
