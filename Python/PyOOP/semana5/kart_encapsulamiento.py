"""
SEMANA 5.1: Encapsulamiento - Velocidad Privada con @property
==============================================================

OBJETIVO:
Encapsular el atributo velocidad como privado (__velocidad) con @property y @setter.

REQUISITOS:
1. Cambiar self.velocidad a self.__velocidad (privado)
2. Crear @property velocidad que retorna self.__velocidad
3. Crear @velocidad.setter que:
   - Acepta el nuevo valor
   - Valida que no sea negativo
   - Valida que no supere self.velocidad_max
   - Solo entonces asigna self.__velocidad = valor
4. Métodos acelerar(), frenar() ahora usan self.velocidad (que llama al @property)
5. IMPORTANTE: No se puede modificar directamente kart.velocidad = 100
   - Solo se puede mediante: kart.velocidad = 100 (que usa el @setter)

ENCAPSULAMIENTO:
- El atributo interno es __velocidad (privado, "name mangling")
- No se puede acceder directo: kart.__velocidad (lanza error)
- Se accede mediante kart.velocidad (que usa @property)
- La lógica de validación está centralizada en el @setter

ESTUDIANTE: Completa el código donde dice # TODO
"""

import math


class Kart:
    """Kart con velocidad encapsulada."""

    def __init__(self, nombre, velocidad_max, color):
        self.nombre = nombre
        self.velocidad_max = velocidad_max
        self.color = color
        self.posicion_x = 0.0
        self.posicion_y = 0.0
        # TODO: Usar __velocidad privado en lugar de velocidad
        # self.__velocidad = 0.0
        self.direccion = 0

    @property
    def velocidad(self):
        # TODO: Retorna el valor de self.__velocidad
        # Esta es la forma "segura" de leer velocidad
        pass

    @velocidad.setter
    def velocidad(self, valor):
        # TODO: Valida y asigna la velocidad
        # - Si valor < 0, asigna 0
        # - Si valor > self.velocidad_max, asigna self.velocidad_max
        # - Si no, asigna valor
        # Luego: self.__velocidad = valor_validado
        pass

    def acelerar(self, incremento):
        # TODO: Aumenta velocidad sin superar max
        # self.velocidad += incremento  # Usa el @setter automáticamente!
        # Retorna la nueva velocidad
        pass

    def frenar(self, decremento):
        # TODO: Disminuye velocidad sin ir bajo 0
        # self.velocidad -= decremento
        # Retorna la nueva velocidad
        pass

    def girar(self, angulo):
        # TODO: Cambia dirección (normaliza 0-360)
        # self.direccion = (self.direccion + angulo) % 360
        # Retorna la nueva dirección
        pass

    def actualizar_posicion(self):
        # TODO: Calcula nueva posición
        # self.posicion_x += self.velocidad * math.cos(math.radians(self.direccion))
        # self.posicion_y += self.velocidad * math.sin(math.radians(self.direccion))
        pass

    def __str__(self):
        return f"🏎️ {self.nombre} | V: {self.velocidad}/{self.velocidad_max} km/h | Color: {self.color}"


# PRUEBAS
if __name__ == "__main__":
    # TODO: Descomenta para validar
    # kart = Kart("Mario", 200, "Rojo")
    #
    # # Prueba @property y @setter
    # kart.velocidad = 50
    # assert kart.velocidad == 50
    # print(f"✓ Velocidad: {kart.velocidad}")
    #
    # # Prueba validación: no va bajo 0
    # kart.velocidad = -50
    # assert kart.velocidad == 0
    # print(f"✓ No puede ser negativo: {kart.velocidad}")
    #
    # # Prueba validación: no supera max
    # kart.velocidad = 300
    # assert kart.velocidad == 200
    # print(f"✓ No supera max: {kart.velocidad}")
    #
    # # Prueba que no se puede acceder directo a __velocidad
    # try:
    #     print(kart.__velocidad)  # Esto debe fallar
    #     print("❌ No funcionó el encapsulamiento")
    # except AttributeError:
    #     print("✓ __velocidad es privado (no se puede acceder directo)")
    #
    # print("✅ ¡Encapsulamiento funciona!")
    pass
