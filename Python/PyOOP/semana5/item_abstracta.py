"""
SEMANA 5.2-5.4: Clases Abstractas - ItemBase y VehiculoBase ABC
================================================================

OBJETIVO:
Implementar clases abstractas con @abstractmethod para definir contratos.

REQUISITOS:

ItemBase (clase abstracta):
1. from abc import ABC, abstractmethod
2. ItemBase(ABC): clase abstracta base para todos los items
3. @abstractmethod def activar(self): pass
4. @abstractmethod def __str__(self): pass
5. No se puede instanciar ItemBase directamente
6. Las subclases (Turbo, Escudo) DEBEN implementar estos métodos

Turbo (subclase de ItemBase):
1. Hereda de ItemBase
2. Implementa activar(): aumenta velocidad
3. Implementa __str__()

Escudo (subclase de ItemBase):
1. Hereda de ItemBase
2. Implementa activar(): protege de daño
3. Implementa __str__()

ABSTRACCIÓN:
- ItemBase define QUÉ debe hacer (contrato)
- Las subclases definen CÓMO lo hace (implementación)
- Fuerza a las subclases a implementar los métodos abstractos

ESTUDIANTE: Completa el código donde dice # TODO
"""

from abc import ABC, abstractmethod


# TODO: class ItemBase(ABC):
class ItemBase:
    """Clase abstracta base para todos los items."""

    def __init__(self, nombre, bonus):
        self.nombre = nombre
        self.bonus = bonus
        self.activo = False

    # TODO: @abstractmethod
    def activar(self):
        # TODO: Este método DEBE ser implementado en las subclases
        pass

    # TODO: @abstractmethod
    def __str__(self):
        # TODO: Este método DEBE ser implementado en las subclases
        pass


class Turbo(ItemBase):
    """Item Turbo que aumenta la velocidad."""

    def __init__(self):
        # TODO: super().__init__("Turbo", 50)
        pass

    def activar(self):
        # TODO: Implementa lógica del turbo
        # self.activo = True
        # return f"¡{self.nombre} activado! +{self.bonus} km/h"
        pass

    def __str__(self):
        # TODO: Retorna string como: "🚀 Turbo | Bonus: +{self.bonus}"
        pass


class Escudo(ItemBase):
    """Item Escudo que protege de daño."""

    def __init__(self):
        # TODO: super().__init__("Escudo", 100)
        pass

    def activar(self):
        # TODO: Implementa lógica del escudo
        # self.activo = True
        # return f"¡{self.nombre} activado! Protegido por {self.bonus} puntos"
        pass

    def __str__(self):
        # TODO: Retorna string como: "🛡️ Escudo | Bonus: +{self.bonus}"
        pass


class Moneda(ItemBase):
    """Item Moneda que da puntos."""

    def __init__(self):
        # TODO: super().__init__("Moneda", 10)
        pass

    def activar(self):
        # TODO: Implementa lógica de la moneda
        # self.activo = True
        # return f"¡{self.nombre} recogida! +{self.bonus} puntos"
        pass

    def __str__(self):
        # TODO: Retorna string como: "🪙 Moneda | Bonus: +{self.bonus}"
        pass


# PRUEBAS
if __name__ == "__main__":
    # TODO: Descomenta para validar
    # # Esto DEBE fallar: no se puede instanciar una clase abstracta
    # try:
    #     item = ItemBase("Item Genérico", 0)
    #     print("❌ ItemBase no debe instanciarse")
    # except TypeError:
    #     print("✓ ItemBase es abstracta (no se puede instanciar)")
    #
    # # Esto SÍ funciona: instanciar subclases concretas
    # turbo = Turbo()
    # escudo = Escudo()
    # moneda = Moneda()
    #
    # print(f"\n{turbo}")
    # print(f"Activación: {turbo.activar()}")
    #
    # print(f"\n{escudo}")
    # print(f"Activación: {escudo.activar()}")
    #
    # print(f"\n{moneda}")
    # print(f"Activación: {moneda.activar()}")
    #
    # # Polimorfismo: lista heterogénea de items
    # items = [turbo, escudo, moneda]
    # print("\n🎁 Items en la carrera:")
    # for item in items:
    #     print(f"  {item} -> {item.activar()}")
    #
    # print("\n✅ ¡Clases abstractas funcionan!")
    pass
