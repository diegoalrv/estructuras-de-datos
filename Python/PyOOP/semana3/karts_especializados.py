"""
SEMANA 3.2: Subclases KartPesado y KartLigero
==============================================

OBJETIVO:
Implementar especialización de karts mediante herencia.

REQUISITOS:
1. KartPesado(VehiculoBase): velocidad_max=150, acelera más (x1.2)
2. KartLigero(VehiculoBase): velocidad_max=220, acelera menos (x0.8)
3. Usar super().__init__() para llamar constructor padre
4. Override método acelerar() para diferentes comportamientos

ESTUDIANTE: Completa el código donde dice # TODO
"""

# TODO: Importa VehiculoBase de vehiculo_base.py
# from vehiculo_base import VehiculoBase


class KartPesado:
    # TODO: class KartPesado(VehiculoBase):
    pass

    def __init__(self, nombre):
        # TODO: super().__init__(nombre, velocidad_max=150)
        pass

    def acelerar(self, incremento):
        # TODO: Acelera más: incremento * 1.2
        # self.velocidad = min(self.velocidad + (incremento * 1.2), self.velocidad_max)
        # return self.velocidad
        pass


class KartLigero:
    # TODO: class KartLigero(VehiculoBase):
    pass

    def __init__(self, nombre):
        # TODO: super().__init__(nombre, velocidad_max=220)
        pass

    def acelerar(self, incremento):
        # TODO: Acelera menos: incremento * 0.8
        # self.velocidad = min(self.velocidad + (incremento * 0.8), self.velocidad_max)
        # return self.velocidad
        pass


# PRUEBAS
if __name__ == "__main__":
    # TODO: Descomenta para validar
    # pesado = KartPesado("Bowser")
    # ligero = KartLigero("Toad")
    #
    # pesado.acelerar(100)
    # ligero.acelerar(100)
    #
    # print(f"Pesado: {pesado.velocidad} / {pesado.velocidad_max}")
    # print(f"Ligero: {ligero.velocidad} / {ligero.velocidad_max}")
    # print("✅ Herencia funciona!")
    pass
