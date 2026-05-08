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

CONCEPTO DE HERENCIA:
- VehiculoBase es la clase BASE (padre)
- Las subclases heredan todos sus atributos y métodos
- Las subclases pueden OVERRIDE (sobrescribir) métodos para comportamiento diferente
- Usar super().__init__() en subclases para llamar al constructor del padre

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
        """
        Aumenta la velocidad sin exceder el máximo.

        Args:
            incremento (float): Cantidad a aumentar en velocidad

        Returns:
            float: Nueva velocidad
        """
        # TODO: Aumenta velocidad sin superar max
        # self.velocidad = min(self.velocidad + incremento, self.velocidad_max)
        # return self.velocidad
        pass

    def frenar(self, decremento):
        """
        Disminuye la velocidad sin ir por debajo de 0.

        Args:
            decremento (float): Cantidad a disminuir en velocidad

        Returns:
            float: Nueva velocidad
        """
        # TODO: Disminuye velocidad sin ir bajo 0
        # self.velocidad = max(self.velocidad - decremento, 0)
        # return self.velocidad
        pass

    def girar(self, angulo):
        """
        Cambia la dirección del vehículo.

        Args:
            angulo (float): Ángulo en grados

        Returns:
            float: Nueva dirección normalizada (0-360)
        """
        # TODO: Cambia dirección (normaliza 0-360)
        # self.direccion = (self.direccion + angulo) % 360
        # return self.direccion
        pass

    def actualizar_posicion(self):
        """
        Actualiza la posición basada en velocidad y dirección.
        Usa trigonometría para movimiento en 2D.
        """
        # TODO: Calcula nueva posición con trigonometría
        # self.posicion_x += self.velocidad * math.cos(math.radians(self.direccion))
        # self.posicion_y += self.velocidad * math.sin(math.radians(self.direccion))
        pass

    def __str__(self):
        return (f"🏎️ {self.nombre} | V.max: {self.velocidad_max} km/h | "
                f"V.actual: {self.velocidad} | Posición: ({self.posicion_x:.1f}, {self.posicion_y:.1f})")


# PRUEBAS
if __name__ == "__main__":
    # TODO: Descomenta para validar
    # vehiculo = VehiculoBase("KartBase", 200)
    # print(vehiculo)
    # vehiculo.acelerar(50)
    # assert vehiculo.velocidad == 50
    # vehiculo.girar(90)
    # assert vehiculo.direccion == 90
    # vehiculo.actualizar_posicion()
    # print(f"Nueva posición: ({vehiculo.posicion_x:.2f}, {vehiculo.posicion_y:.2f})")
    # print("✅ VehiculoBase funciona!")
    pass
