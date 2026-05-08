"""
SEMANA 2: Clase Kart - Vehículo Base con Métodos de Movimiento
==============================================================

OBJETIVO:
Crear la clase base Kart que será heredada por KartPesado, KartMedio, KartLigero.

REQUISITOS:
1. Atributos del kart:
   - nombre (str): Nombre del kart
   - velocidad_max (int): Velocidad máxima en km/h
   - color (str): Color del kart
   - posicion_x, posicion_y (float): Posición en la pista
   - velocidad (float): Velocidad actual
   - direccion (float): Dirección en grados (0-360)
   - turbo_disponible (bool): Si tiene turbo disponible

2. Método acelerar(incremento):
   - Aumenta velocidad sin exceder velocidad_max
   - Retorna nueva velocidad

3. Método frenar(decremento):
   - Disminuye velocidad sin ir bajo 0
   - Retorna nueva velocidad

4. Método girar(angulo):
   - Suma angulo a direccion
   - Normaliza dirección a rango 0-360
   - Retorna nueva dirección

5. Método actualizar_posicion():
   - Usa trigonometría para mover según velocidad y dirección
   - No retorna nada

6. Método usar_turbo():
   - Si está disponible: multiplica velocidad por 1.5
   - Marca turbo como no disponible
   - Retorna bool indicando si se usó

NOTAS:
- Esta es la CLASE BASE
- KartPesado, Medio, Ligero heredarán de esta clase
- Estos herederos solo reescribirán el método acelerar()

ESTUDIANTE: Completa el código donde dice # TODO
"""

import math


class Kart:
    """Clase base para todos los karts en Mario Kart."""

    def __init__(self, nombre, velocidad_max, color):
        """
        Inicializa un kart.

        Args:
            nombre (str): Nombre del kart
            velocidad_max (int): Velocidad máxima
            color (str): Color del kart
        """
        # TODO: Asigna los atributos
        # - nombre, velocidad_max, color
        # - posicion_x = 0.0, posicion_y = 0.0
        # - velocidad = 0.0
        # - direccion = 0.0
        # - turbo_disponible = True
        pass

    def acelerar(self, incremento):
        """
        Acelera el kart hasta velocidad_max.

        Args:
            incremento (float): Cantidad a acelerar

        Returns:
            float: Nueva velocidad
        """
        # TODO: Acelera sin exceder velocidad_max
        # self.velocidad = min(self.velocidad + incremento, self.velocidad_max)
        # return self.velocidad
        pass

    def frenar(self, decremento):
        """
        Frena el kart hasta 0.

        Args:
            decremento (float): Cantidad a frenar

        Returns:
            float: Nueva velocidad
        """
        # TODO: Frena sin ir bajo 0
        # self.velocidad = max(self.velocidad - decremento, 0)
        # return self.velocidad
        pass

    def girar(self, angulo):
        """
        Cambia la dirección del kart.

        Args:
            angulo (float): Ángulo en grados a girar

        Returns:
            float: Nueva dirección normalizada (0-360)
        """
        # TODO: Suma el ángulo y normaliza a rango 0-360 usando modulo
        # self.direccion = (self.direccion + angulo) % 360
        # return self.direccion
        pass

    def actualizar_posicion(self):
        """
        Actualiza la posición del kart basada en velocidad y dirección.
        Usa trigonometría para calcular movimiento en 2D.
        """
        # TODO: Usa trigonometría para actualizar posición
        # self.posicion_x += self.velocidad * math.cos(math.radians(self.direccion))
        # self.posicion_y += self.velocidad * math.sin(math.radians(self.direccion))
        pass

    def usar_turbo(self):
        """
        Usa el turbo disponible para boost de velocidad.

        Returns:
            bool: True si se usó turbo, False si no estaba disponible
        """
        # TODO: Si turbo_disponible es True:
        # - Multiplica velocidad por 1.5
        # - Marca turbo_disponible como False
        # - Retorna True
        # Si no: retorna False
        pass

    def __str__(self):
        return f"🏎️ {self.nombre} | V.máx: {self.velocidad_max} km/h | Color: {self.color}"


# ============================================================================
# PRUEBAS
# ============================================================================

if __name__ == "__main__":
    kart = Kart("Mario Kart", 200, "Rojo")
    print(kart)

    # Prueba acelerar
    assert kart.acelerar(50) == 50
    assert kart.acelerar(75) == 125
    assert kart.acelerar(100) == 200  # No supera max
    print(f"✓ Velocidad: {kart.velocidad} km/h")

    # Prueba frenar
    assert kart.frenar(50) == 150
    assert kart.frenar(200) == 0  # No va bajo 0
    print(f"✓ Frenado: {kart.velocidad} km/h")

    # Prueba girar
    kart.velocidad = 10
    assert kart.girar(45) == 45
    assert kart.girar(90) == 135
    assert kart.girar(300) == 75  # (135 + 300) % 360
    print(f"✓ Dirección: {kart.direccion}°")

    # Prueba actualizar_posicion
    kart.velocidad = 10
    kart.direccion = 0  # Hacia la derecha
    kart.actualizar_posicion()
    print(f"✓ Nueva posición: ({kart.posicion_x:.2f}, {kart.posicion_y:.2f})")

    # Prueba turbo
    kart.velocidad = 100
    assert kart.usar_turbo() == True
    assert kart.velocidad == 150  # 100 * 1.5
    assert kart.usar_turbo() == False  # Ya no hay turbo
    print(f"✓ Turbo usado: {kart.velocidad} km/h")

    print("\n✅ Kart base funciona correctamente!")
