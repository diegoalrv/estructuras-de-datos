"""
SEMANA 4.2: Clases Item y Conductor (Composición)
===================================================

OBJETIVO:
Implementar items del juego y la composición Personaje+Kart (Conductor).

REQUISITOS:

ITEM:
1. Item: tipo (str), bonus (int), activo (bool)
2. Método activar(): marca como activo y aplica bonus
3. Métodos: __str__()

CONDUCTOR:
Conductor es la composición de Personaje + Kart
1. Conductor: personaje (Personaje), kart (Kart)
2. Método manejar(incremento): delega a kart.acelerar()
3. Método girar(angulo): delega a kart.girar()
4. Método obtener_velocidad(): retorna kart.velocidad
5. Método obtener_posicion(): retorna tupla (kart.posicion_x, kart.posicion_y)

ESTUDIANTE: Completa el código donde dice # TODO
"""


class Item:
    """Representa un item del juego que puede recoger un conductor."""

    def __init__(self, tipo, bonus):
        # TODO: Inicializa atributos
        # tipo, bonus, activo=False
        pass

    def activar(self):
        # TODO: Marca como activo (True)
        pass

    def __str__(self):
        # TODO: Retorna string como: "🎁 {tipo} | Bonus: +{bonus}"
        # Ej: "🎁 Turbo | Bonus: +50"
        pass


class Conductor:
    """Representa un conductor (composición de Personaje + Kart)."""

    def __init__(self, personaje, kart):
        # TODO: Asigna personaje y kart
        # Además: items = []
        pass

    def manejar(self, incremento):
        # TODO: Acelera el kart (delega a self.kart.acelerar(incremento))
        # Retorna la nueva velocidad
        pass

    def girar(self, angulo):
        # TODO: Gira el kart (delega a self.kart.girar(angulo))
        # Retorna la nueva dirección
        pass

    def recoger_item(self, item):
        # TODO: Agrega item a self.items y lo activa
        # item.activar()
        pass

    def obtener_velocidad(self):
        # TODO: Retorna self.kart.velocidad
        pass

    def obtener_posicion(self):
        # TODO: Retorna tupla (self.kart.posicion_x, self.kart.posicion_y)
        pass

    def __str__(self):
        return f"🏎️ {self.personaje.nombre} | V: {self.obtener_velocidad()} km/h | Items: {len(self.items)}"


# PRUEBAS
if __name__ == "__main__":
    # TODO: Descomenta para validar
    # from kart import Kart
    # from personaje import Personaje
    #
    # mario = Personaje("Mario", "Guerrero", 100, 100, 50, 50)
    # mario_kart = Kart("Mario", 200, "Rojo")
    # conductor = Conductor(mario, mario_kart)
    #
    # # Prueba manejar
    # conductor.manejar(50)
    # assert conductor.obtener_velocidad() == 50
    # print(f"✓ Velocidad: {conductor.obtener_velocidad()}")
    #
    # # Prueba girar
    # conductor.girar(45)
    # assert conductor.kart.direccion == 45
    # print(f"✓ Dirección: {conductor.kart.direccion}")
    #
    # # Prueba items
    # turbo = Item("Turbo", 50)
    # conductor.recoger_item(turbo)
    # assert len(conductor.items) == 1
    # assert turbo.activo == True
    # print(f"✓ Item recogido: {turbo}")
    #
    # print("✅ Conductor y Item funcionan!")
    pass
