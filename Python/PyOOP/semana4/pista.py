"""
SEMANA 4.1: Clase Pista (Racetrack)
===================================

OBJETIVO:
Implementar la pista de carreras como contenedor de vehículos.

REQUISITOS:
1. Pista: nombre, ancho, largo, conductores (lista)
2. Método add_conductor(personaje): Agrega personaje a la pista
3. Método remover_conductor(personaje): Quita personaje de la pista
4. Método actualizar_conductores(): Actualiza posición de todos los conductores
5. Método verificar_ganador(): Retorna primer conductor que cruza meta (largo)
6. Validar que posicion_x no salga de rango [0, ancho]

ESTUDIANTE: Completa el código donde dice # TODO
"""


class Pista:
    """Representa la pista de carreras donde compiten los conductores."""

    def __init__(self, nombre, ancho, largo):
        # TODO: Inicializa atributos
        # nombre, ancho, largo, conductores=[]
        pass

    def add_conductor(self, personaje):
        # TODO: Agrega un personaje a la lista de conductores
        # Verifica que personaje tenga un kart asignado
        pass

    def remover_conductor(self, personaje):
        # TODO: Remueve un personaje de la lista de conductores
        pass

    def actualizar_conductores(self):
        # TODO: Itera sobre todos los conductores
        # Para cada uno: personaje.kart.actualizar_posicion()
        # Pero primero valida que posicion_x esté en rango [0, self.ancho]
        # Si sale del rango, ajusta a límite más cercano (max con 0, min con ancho)
        pass

    def verificar_ganador(self):
        # TODO: Busca el primer conductor cuya posicion_y >= self.largo
        # Retorna ese personaje, o None si no hay ganador aún
        pass

    def __str__(self):
        return f"🏁 Pista: {self.nombre} | {self.ancho}x{self.largo} | Conductores: {len(self.conductores)}"


# PRUEBAS
if __name__ == "__main__":
    # TODO: Descomenta para validar
    # from kart import Kart
    # from personaje import Personaje
    #
    # pista = Pista("Mario Circuit", 100, 500)
    #
    # mario = Personaje("Mario", "Guerrero", 100, 100, 50, 50)
    # mario.kart = Kart("Mario Kart", 200, "Rojo")
    #
    # pista.add_conductor(mario)
    # assert len(pista.conductores) == 1
    #
    # mario.kart.velocidad = 50
    # mario.kart.actualizar_posicion()  # Debe mover el kart
    #
    # print(f"✓ {mario.nombre} en posición: ({mario.kart.posicion_x}, {mario.kart.posicion_y})")
    # print("✅ Pista funciona!")
    pass
