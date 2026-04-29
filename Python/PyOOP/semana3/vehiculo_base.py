"""
SEMANA 3.1: Clase Base VehiculoBase
===================================

OBJETIVO:
Crear jerarquía de herencia para los karts.

REQUISITOS:
1. Crear clase VehiculoBase con atributos comunes
2. Método __init__ que asigne: nombre, velocidad_max, posicion_x, posicion_y
3. Métodos base: acelerar(), frenar(), girar(), actualizar_posicion()
4. Esta será la clase padre de todos los karts

ESTUDIANTE: Completa el código donde dice # TODO
"""

import math


class VehiculoBase:
    """Clase base para todos los vehículos (Karts)."""

    def __init__(self, nombre, velocidad_max):
        # TODO: Inicializa atributos
        # nombre, velocidad_max, posicion_x=0.0, posicion_y=0.0
        # velocidad=0.0, direccion=0
        pass

    def acelerar(self, incremento):
        # TODO: Aumenta velocidad sin superar max
        pass

    def frenar(self, decremento):
        # TODO: Disminuye velocidad sin ir bajo 0
        pass

    def girar(self, angulo):
        # TODO: Cambia dirección (normaliza 0-360)
        pass

    def actualizar_posicion(self):
        # TODO: Calcula nueva posición con trigonometría
        pass

    def __str__(self):
        return f"Vehículo: {self.nombre} | V.max: {self.velocidad_max}"


# PRUEBAS
if __name__ == "__main__":
    # TODO: Descomenta para validar
    # vehiculo = VehiculoBase("KartBase", 200)
    # print(vehiculo)
    # vehiculo.acelerar(50)
    # assert vehiculo.velocidad == 50
    # print("✅ VehiculoBase funciona!")
    pass
