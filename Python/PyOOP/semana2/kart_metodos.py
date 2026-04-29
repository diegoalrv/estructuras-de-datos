"""
SEMANA 2: Métodos de Instancia + Lógica Interna
===============================================

OBJETIVO:
Agregar métodos que controlen el movimiento y comportamiento del kart.

REQUISITOS:
1. Implementar método `acelerar(incremento)`:
   - Aumenta self.velocidad en incremento
   - PERO: nunca puede superar self.velocidad_max
   - Retorna la nueva velocidad

2. Implementar método `frenar(decremento)`:
   - Disminuye self.velocidad en decremento
   - PERO: nunca puede ser menor a 0
   - Retorna la nueva velocidad

3. Implementar método `girar(angulo)`:
   - Suma `angulo` a self.direccion (inicializa en 0)
   - La dirección debe estar entre 0 y 360 grados (usa % para normalizar)
   - Retorna la nueva dirección

4. Implementar método `actualizar_posicion()`:
   - Calcula nueva posicion_x y posicion_y basada en velocidad y direccion
   - Usa trigonometría: import math
   - posicion_x += velocidad * math.cos(math.radians(direccion))
   - posicion_y += velocidad * math.sin(math.radians(direccion))
   - NO retorna nada, solo modifica self.posicion_x y self.posicion_y

ESTUDIANTE: Completa el código donde dice # TODO
"""

import math


class Kart:
    """Representa un kart con métodos de movimiento."""

    def __init__(self, nombre, velocidad_max, color):
        self.nombre = nombre
        self.velocidad_max = velocidad_max
        self.color = color
        self.posicion_x = 0.0
        self.posicion_y = 0.0
        self.velocidad = 0.0
        self.turbo_disponible = True
        # TODO: Inicializa self.direccion = 0

    def __str__(self):
        return f"🏎️ {self.nombre} | V.max: {self.velocidad_max} km/h | Color: {self.color}"

    def acelerar(self, incremento):
        # TODO: Implementa la lógica
        # - Aumenta self.velocidad en incremento
        # - Pero no superar self.velocidad_max
        # - Retorna la nueva velocidad
        pass

    def frenar(self, decremento):
        # TODO: Implementa la lógica
        # - Disminuye self.velocidad en decremento
        # - Pero no ir bajo 0
        # - Retorna la nueva velocidad
        pass

    def girar(self, angulo):
        # TODO: Implementa la lógica
        # - Suma angulo a self.direccion
        # - Normaliza a rango 0-360 usando % (módulo)
        # - Retorna la nueva dirección
        pass

    def actualizar_posicion(self):
        # TODO: Implementa la lógica
        # - Calcula nueva posición usando trigonometría
        # - posicion_x += velocidad * math.cos(math.radians(direccion))
        # - posicion_y += velocidad * math.sin(math.radians(direccion))
        # - NO retorna nada
        pass


# ============================================================================
# PRUEBAS - Descomenta estas líneas para validar tu código
# ============================================================================

if __name__ == "__main__":
    # TODO: Descomenta y ejecuta para validar
    # kart = Kart("Bowser", 210, "Verde")

    # # Prueba acelerar
    # assert kart.acelerar(10) == 10
    # assert kart.acelerar(20) == 30
    # assert kart.acelerar(200) == 210  # No supera max
    # print(f"✓ Velocidad: {kart.velocidad}")

    # # Prueba frenar
    # assert kart.frenar(10) == 200
    # assert kart.frenar(300) == 0  # No va bajo 0
    # print(f"✓ Velocidad después frenar: {kart.velocidad}")

    # # Prueba girar
    # assert kart.girar(45) == 45
    # assert kart.girar(90) == 135
    # assert kart.girar(300) == 435 % 360  # Normaliza a 75
    # print(f"✓ Dirección: {kart.direccion}")

    # # Prueba actualizar_posición
    # kart.velocidad = 10
    # kart.direccion = 0  # Hacia la derecha
    # kart.actualizar_posicion()
    # print(f"✓ Nueva posición: ({kart.posicion_x}, {kart.posicion_y})")

    # print("✅ ¡Todas las pruebas pasaron!")
    pass
