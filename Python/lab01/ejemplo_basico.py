"""
ejemplo_basico.py
Ejemplos básicos de definición de clases en Python
"""

# ============================================================================
# Ejemplo 1: Clase muy simple - Persona
# ============================================================================

class Persona:
    """Representa una persona con nombre y edad."""

    def __init__(self, nombre, edad):
        """Constructor de la clase Persona.

        Args:
            nombre (str): Nombre de la persona
            edad (int): Edad de la persona
        """
        self.nombre = nombre
        self.edad = edad

    def saludar(self):
        """Retorna un saludo personalizado."""
        return f"Hola, soy {self.nombre}"

    def cumplir_años(self):
        """Incrementa la edad en 1."""
        self.edad += 1
        return f"{self.nombre} ahora tiene {self.edad} años"

    def __str__(self):
        """Representación en string de la Persona."""
        return f"{self.nombre} ({self.edad} años)"


# Pruebas del Ejemplo 1
if __name__ == "__main__":
    # Crear objetos
    alice = Persona("Alice", 25)
    bob = Persona("Bob", 30)

    # Usar métodos
    print(alice.saludar())      # Hola, soy Alice
    print(alice.cumplir_años()) # Alice ahora tiene 26 años
    print(alice)                # Alice (26 años)
    print(bob)                  # Bob (30 años)
    print()


# ============================================================================
# Ejemplo 2: Clase Auto con encapsulamiento básico
# ============================================================================

class Auto:
    """Representa un automóvil con marca, modelo y velocidad."""

    def __init__(self, marca, modelo):
        """Constructor.

        Args:
            marca (str): Marca del auto
            modelo (str): Modelo del auto
        """
        self.marca = marca
        self.modelo = modelo
        self._velocidad = 0  # Atributo privado (por convención)

    def acelerar(self, incremento=10):
        """Aumenta la velocidad.

        Args:
            incremento (int): Cuánto aumentar (por defecto 10)
        """
        self._velocidad += incremento
        print(f"Acelerando... Velocidad: {self._velocidad} km/h")

    def frenar(self, decremento=10):
        """Disminuye la velocidad.

        Args:
            decremento (int): Cuánto disminuir (por defecto 10)
        """
        self._velocidad = max(0, self._velocidad - decremento)
        print(f"Frenando... Velocidad: {self._velocidad} km/h")

    def obtener_velocidad(self):
        """Retorna la velocidad actual (mejor que acceder directo)."""
        return self._velocidad

    def __str__(self):
        """Representación del auto."""
        return f"{self.marca} {self.modelo} ({self._velocidad} km/h)"


# Pruebas del Ejemplo 2
if __name__ == "__main__":
    auto = Auto("Toyota", "Corolla")
    print(auto)         # Toyota Corolla (0 km/h)
    auto.acelerar(20)   # Acelerando... Velocidad: 20 km/h
    auto.acelerar(30)   # Acelerando... Velocidad: 50 km/h
    auto.frenar(15)     # Frenando... Velocidad: 35 km/h
    print(auto)         # Toyota Corolla (35 km/h)
    print()


# ============================================================================
# Ejemplo 3: Clase Contador con método especial __call__
# ============================================================================

class Contador:
    """Un contador que puede incrementarse y decrementarse."""

    def __init__(self, inicial=0):
        """Constructor.

        Args:
            inicial (int): Valor inicial del contador
        """
        self._valor = inicial

    def incrementar(self):
        """Incrementa en 1."""
        self._valor += 1

    def decrementar(self):
        """Decrementa en 1."""
        self._valor -= 1

    def reset(self):
        """Reinicia el contador a 0."""
        self._valor = 0

    def obtener(self):
        """Retorna el valor actual."""
        return self._valor

    def __str__(self):
        """Representación del contador."""
        return f"Contador: {self._valor}"

    def __eq__(self, otro):
        """Compara dos contadores por su valor."""
        if not isinstance(otro, Contador):
            return False
        return self._valor == otro._valor


# Pruebas del Ejemplo 3
if __name__ == "__main__":
    c1 = Contador(5)
    c2 = Contador(5)
    c3 = Contador(10)

    print(c1)           # Contador: 5
    print(c1 == c2)     # True (mismo valor)
    print(c1 == c3)     # False (diferente valor)

    c1.incrementar()
    c1.incrementar()
    print(c1)           # Contador: 7

    c1.reset()
    print(c1)           # Contador: 0
    print()


# ============================================================================
# Ejemplo 4: Clase Temperatura con validación
# ============================================================================

class Temperatura:
    """Representa una temperatura en grados Celsius."""

    def __init__(self, celsius):
        """Constructor con validación.

        Args:
            celsius (float): Temperatura en grados Celsius

        Raises:
            ValueError: Si la temperatura es menor a -273.15 (cero absoluto)
        """
        if celsius < -273.15:
            raise ValueError("Temperatura menor al cero absoluto (-273.15°C)")
        self._celsius = celsius

    def convertir_fahrenheit(self):
        """Convierte a Fahrenheit."""
        return (self._celsius * 9/5) + 32

    def convertir_kelvin(self):
        """Convierte a Kelvin."""
        return self._celsius + 273.15

    def es_agua_congelada(self):
        """Retorna True si es 0°C (agua congelada)."""
        return abs(self._celsius - 0) < 0.01  # Con margen de error

    def es_agua_hirviendo(self):
        """Retorna True si es 100°C (agua hirviendo)."""
        return abs(self._celsius - 100) < 0.01

    def __str__(self):
        """Representación de la temperatura."""
        f = self.convertir_fahrenheit()
        return f"{self._celsius}°C ({f:.1f}°F)"

    def __lt__(self, otra):
        """Compara si esta temperatura es menor que otra."""
        if not isinstance(otra, Temperatura):
            return NotImplemented
        return self._celsius < otra._celsius


# Pruebas del Ejemplo 4
if __name__ == "__main__":
    t1 = Temperatura(0)
    t2 = Temperatura(100)
    t3 = Temperatura(25)

    print(t1)                       # 0.0°C (32.0°F)
    print(t2)                       # 100°C (212.0°F)
    print(t3)                       # 25°C (77.0°F)

    print(f"¿0°C es agua congelada? {t1.es_agua_congelada()}")      # True
    print(f"¿100°C es agua hirviendo? {t2.es_agua_hirviendo()}")    # True
    print(f"¿25°C < 0°C? {t3 < t1}")                                # False
    print(f"¿0°C < 100°C? {t1 < t2}")                               # True

    # Esto causaría un error (cero absoluto)
    try:
        t_invalida = Temperatura(-300)
    except ValueError as e:
        print(f"Error: {e}")
