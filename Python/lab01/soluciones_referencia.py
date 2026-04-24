"""
soluciones_referencia.py
Soluciones de referencia para todos los ejercicios del Laboratorio 17

NOTA: Usa este archivo solo para verificar tu trabajo o si estás atascado.
Intenta resolver primero por tu cuenta.
"""


# ============================================================================
# EJERCICIO 1: Clase Cuenta
# ============================================================================

class Cuenta:
    """Representa una cuenta bancaria con saldo."""

    def __init__(self, titular, saldo_inicial):
        """Constructor de la clase Cuenta.

        Args:
            titular (str): Nombre del titular
            saldo_inicial (float): Saldo inicial (debe ser >= 0)

        Raises:
            ValueError: Si saldo_inicial es negativo o titular está vacío
        """
        if not titular or len(titular) == 0:
            raise ValueError("El titular no puede estar vacío")
        if saldo_inicial < 0:
            raise ValueError("El saldo inicial no puede ser negativo")

        self.titular = titular
        self._saldo = saldo_inicial

    def depositar(self, cantidad):
        """Deposita una cantidad en la cuenta.

        Args:
            cantidad (float): Monto a depositar

        Raises:
            ValueError: Si cantidad <= 0
        """
        if cantidad <= 0:
            raise ValueError("La cantidad a depositar debe ser positiva")
        self._saldo += cantidad

    def retirar(self, cantidad):
        """Retira una cantidad de la cuenta.

        Args:
            cantidad (float): Monto a retirar

        Raises:
            ValueError: Si cantidad <= 0 o cantidad > saldo
        """
        if cantidad <= 0:
            raise ValueError("La cantidad a retirar debe ser positiva")
        if cantidad > self._saldo:
            raise ValueError("Saldo insuficiente para realizar el retiro")
        self._saldo -= cantidad

    def obtener_saldo(self):
        """Retorna el saldo actual."""
        return self._saldo

    def __str__(self):
        """Representación en string de la cuenta."""
        return f"Cuenta de {self.titular}: ${self._saldo:.2f}"


# ============================================================================
# EJERCICIO 2: Clase Estudiante
# ============================================================================

class Estudiante:
    """Representa un estudiante con calificaciones."""

    def __init__(self, nombre, carrera):
        """Constructor de la clase Estudiante."""
        self.nombre = nombre
        self.carrera = carrera
        self._calificaciones = []

    def agregar_calificacion(self, nota):
        """Añade una calificación a la lista.

        Args:
            nota (float): Calificación a agregar (debe estar entre 1.0 y 7.0)

        Raises:
            ValueError: Si nota < 1.0 o nota > 7.0
        """
        if nota < 1.0 or nota > 7.0:
            raise ValueError("La calificación debe estar entre 1.0 y 7.0")
        self._calificaciones.append(nota)

    def promedio(self):
        """Calcula el promedio de calificaciones."""
        if len(self._calificaciones) == 0:
            return 0.0
        return sum(self._calificaciones) / len(self._calificaciones)

    def aprobo(self):
        """Indica si el estudiante aprobó (promedio >= 4.0)."""
        return self.promedio() >= 4.0

    def __str__(self):
        """Representación en string del estudiante."""
        return f"{self.nombre} ({self.carrera}) - Promedio: {self.promedio():.2f}"

    def __eq__(self, otro):
        """Compara dos estudiantes por nombre y carrera."""
        if not isinstance(otro, Estudiante):
            return False
        return self.nombre == otro.nombre and self.carrera == otro.carrera


# ============================================================================
# EJERCICIO 3: Clase Inventario
# ============================================================================

class Inventario:
    """Administra un inventario de productos."""

    def __init__(self):
        """Constructor de la clase Inventario."""
        self._productos = {}

    def agregar_producto(self, nombre, cantidad):
        """Añade o actualiza un producto en el inventario.

        Args:
            nombre (str): Nombre del producto
            cantidad (int): Cantidad a agregar (debe ser > 0)

        Raises:
            ValueError: Si cantidad <= 0
        """
        if cantidad <= 0:
            raise ValueError("La cantidad debe ser positiva")

        if nombre in self._productos:
            self._productos[nombre] += cantidad
        else:
            self._productos[nombre] = cantidad

    def quitar_producto(self, nombre, cantidad):
        """Reduce la cantidad de un producto.

        Args:
            nombre (str): Nombre del producto
            cantidad (int): Cantidad a quitar

        Raises:
            ValueError: Si cantidad <= 0
            KeyError: Si el producto no existe
            ValueError: Si cantidad > cantidad disponible
        """
        if cantidad <= 0:
            raise ValueError("La cantidad debe ser positiva")

        if nombre not in self._productos:
            raise KeyError(f"El producto '{nombre}' no existe en el inventario")

        if cantidad > self._productos[nombre]:
            raise ValueError(f"No hay suficiente cantidad de '{nombre}'")

        self._productos[nombre] -= cantidad
        if self._productos[nombre] == 0:
            del self._productos[nombre]

    def obtener_cantidad(self, nombre):
        """Retorna la cantidad de un producto."""
        return self._productos.get(nombre, 0)

    def productos_disponibles(self):
        """Retorna una lista de productos en stock."""
        return list(self._productos.keys())

    def vaciar(self):
        """Vacía completamente el inventario."""
        self._productos.clear()

    def __len__(self):
        """Retorna la cantidad total de unidades."""
        return sum(self._productos.values())

    def __str__(self):
        """Representación en string del inventario."""
        if len(self._productos) == 0:
            return "Inventario: vacío"

        items = [f"{nombre} ({cantidad})" for nombre, cantidad in self._productos.items()]
        return f"Inventario: {', '.join(items)}"


# ============================================================================
# EJERCICIO 4: Clase Fecha
# ============================================================================

class Fecha:
    """Representa una fecha completa con validación."""

    def __init__(self, dia, mes, anno):
        """Constructor de la clase Fecha.

        Args:
            dia (int): Día de la fecha (1-31)
            mes (int): Mes de la fecha (1-12)
            anno (int): Año de la fecha (>= 1)

        Raises:
            ValueError: Si la fecha no es válida
        """
        self.dia = dia
        self.mes = mes
        self.anno = anno

        if not self.es_valida():
            raise ValueError("Fecha inválida")

    def es_bisiesto(self):
        """Determina si el año es bisiesto."""
        return (self.anno % 4 == 0 and self.anno % 100 != 0) or (self.anno % 400 == 0)

    def dias_en_mes(self):
        """Retorna cuántos días tiene el mes."""
        if self.mes in [1, 3, 5, 7, 8, 10, 12]:
            return 31
        elif self.mes in [4, 6, 9, 11]:
            return 30
        elif self.mes == 2:
            return 29 if self.es_bisiesto() else 28
        else:
            return 0  # mes inválido

    def es_valida(self):
        """Valida que la fecha sea correcta."""
        if self.anno < 1:
            return False
        if self.mes < 1 or self.mes > 12:
            return False
        if self.dia < 1 or self.dia > self.dias_en_mes():
            return False
        return True

    def __str__(self):
        """Representación en string de la fecha."""
        return f"{self.dia:02d}/{self.mes:02d}/{self.anno:04d}"

    def __eq__(self, otra):
        """Compara si dos fechas son iguales."""
        if not isinstance(otra, Fecha):
            return False
        return (
            self.dia == otra.dia
            and self.mes == otra.mes
            and self.anno == otra.anno
        )

    def __lt__(self, otra):
        """Compara si esta fecha es anterior a otra."""
        if not isinstance(otra, Fecha):
            return NotImplemented

        if self.anno != otra.anno:
            return self.anno < otra.anno
        if self.mes != otra.mes:
            return self.mes < otra.mes
        return self.dia < otra.dia


# ============================================================================
# PRUEBAS COMPLETAS
# ============================================================================

if __name__ == "__main__":
    print("=" * 70)
    print("SOLUCIONES DE REFERENCIA - LABORATORIO 17")
    print("=" * 70)
    print()

    # EJERCICIO 1
    print("EJERCICIO 1: Clase Cuenta")
    print("-" * 70)
    cuenta = Cuenta("Juan", 1000)
    print(f"Cuenta creada: {cuenta}")
    cuenta.depositar(500)
    print(f"Después de depositar 500: {cuenta}")
    cuenta.retirar(200)
    print(f"Después de retirar 200: {cuenta}")
    print()

    # EJERCICIO 2
    print("EJERCICIO 2: Clase Estudiante")
    print("-" * 70)
    est = Estudiante("Maria", "Ingeniería en Computación")
    est.agregar_calificacion(6.5)
    est.agregar_calificacion(7.0)
    est.agregar_calificacion(5.5)
    print(f"{est}")
    print(f"¿Aprobó? {est.aprobo()}")
    print()

    # EJERCICIO 3
    print("EJERCICIO 3: Clase Inventario")
    print("-" * 70)
    inv = Inventario()
    inv.agregar_producto("Laptop", 5)
    inv.agregar_producto("Mouse", 20)
    inv.agregar_producto("Teclado", 15)
    print(f"{inv}")
    print(f"Total de unidades: {len(inv)}")
    inv.quitar_producto("Mouse", 3)
    print(f"Después de quitar 3 Mouse: {inv}")
    print(f"Total de unidades: {len(inv)}")
    print()

    # EJERCICIO 4
    print("EJERCICIO 4: Clase Fecha")
    print("-" * 70)
    f1 = Fecha(15, 3, 2024)
    f2 = Fecha(20, 3, 2024)
    f3 = Fecha(29, 2, 2024)
    print(f"Fecha 1: {f1}")
    print(f"Fecha 2: {f2}")
    print(f"Fecha 3: {f3}")
    print(f"¿{f1} < {f2}? {f1 < f2}")
    print(f"¿{f1} == {f2}? {f1 == f2}")
    print(f"¿2024 es bisiesto? {f1.es_bisiesto()}")
    print()

    print("=" * 70)
    print("Todas las soluciones ejecutadas correctamente ✓")
    print("=" * 70)
