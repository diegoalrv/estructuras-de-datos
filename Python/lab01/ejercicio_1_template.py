"""
ejercicio_1_template.py
Ejercicio 1: Implementar la clase Cuenta

Requisitos:
- Atributos: titular (str), _saldo (float)
- Métodos: __init__, depositar, retirar, obtener_saldo, __str__
- Validaciones: cantidad > 0, saldo suficiente para retiros
"""


class Cuenta:
    """Representa una cuenta bancaria con saldo."""

    def __init__(self, titular, saldo_inicial):
        """Constructor de la clase Cuenta.

        Args:
            titular (str): Nombre del titular
            saldo_inicial (float): Saldo inicial (debe ser >= 0)

        Raises:
            ValueError: Si saldo_inicial es negativo
            ValueError: Si titular está vacío
        """
        # TODO: Validar que titular no esté vacío
        # TODO: Validar que saldo_inicial >= 0
        # TODO: Asignar self.titular y self._saldo
        if len(titular) == 0:
            raise ValueError("El titular no puede estar vacío.")
        if saldo_inicial < 0:
            raise ValueError("El saldo inicial no puede ser negativo.")
        pass

    def depositar(self, cantidad):
        """Deposita una cantidad en la cuenta.

        Args:
            cantidad (float): Monto a depositar

        Raises:
            ValueError: Si cantidad <= 0
        """
        # TODO: Validar que cantidad > 0
        # TODO: Aumentar self._saldo
        pass

    def retirar(self, cantidad):
        """Retira una cantidad de la cuenta.

        Args:
            cantidad (float): Monto a retirar

        Raises:
            ValueError: Si cantidad <= 0
            ValueError: Si cantidad > saldo actual
        """
        # TODO: Validar que cantidad > 0
        # TODO: Validar que cantidad <= self._saldo
        # TODO: Disminuir self._saldo
        pass

    def obtener_saldo(self):
        """Retorna el saldo actual.

        Returns:
            float: Saldo actual
        """
        # TODO: Retornar self._saldo
        pass

    def __str__(self):
        """Representación en string de la cuenta.

        Returns:
            str: Formato "Cuenta de [titular]: $[saldo]"
        """
        # TODO: Retornar string con formato
        pass


# ============================================================================
# PRUEBAS (descomenta para verificar tu implementación)
# ============================================================================

if __name__ == "__main__":
    print("=== Pruebas Ejercicio 1: Clase Cuenta ===\n")

    # Prueba 1: Crear cuenta
    print("Prueba 1: Crear cuenta")
    cuenta = Cuenta("Juan", 1000)
    print(f"Saldo inicial: ${cuenta.obtener_saldo()}")  # 1000.0
    print(cuenta)  # Cuenta de Juan: $1000.0
    print()

    # Prueba 2: Depositar
    print("Prueba 2: Depositar")
    cuenta.depositar(500)
    print(f"Después de depositar 500: ${cuenta.obtener_saldo()}")  # 1500.0
    print()

    # Prueba 3: Retirar
    print("Prueba 3: Retirar")
    cuenta.retirar(200)
    print(f"Después de retirar 200: ${cuenta.obtener_saldo()}")  # 1300.0
    print(cuenta)  # Cuenta de Juan: $1300.0
    print()

    # Prueba 4: Validaciones
    print("Prueba 4: Validaciones")
    try:
        cuenta2 = Cuenta("", 0)  # Error: titular vacío
    except ValueError as e:
        print(f"Error esperado: {e}")

    try:
        cuenta.depositar(-100)  # Error: cantidad negativa
    except ValueError as e:
        print(f"Error esperado: {e}")

    try:
        cuenta.retirar(10000)  # Error: saldo insuficiente
    except ValueError as e:
        print(f"Error esperado: {e}")
