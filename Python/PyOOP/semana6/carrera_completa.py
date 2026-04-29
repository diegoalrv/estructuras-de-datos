"""
SEMANA 6: Carrera Completa - Integración de Todos los Conceptos
===============================================================

OBJETIVO:
Integración completa: simular una carrera con múltiples conductores,
items, encapsulamiento, herencia, polimorfismo y abstractas.

REQUISITOS:
1. Crear instancias de:
   - Personajes con diferentes clases RPG
   - Karts especializados (KartPesado, KartLigero)
   - Conductores (composición)
   - Items variados (Turbo, Escudo, Moneda)
   - Pista con dimensiones

2. Simular carrera:
   - Múltiples vueltas
   - Cada vuelta: acelerar, girar, recoger items
   - Validar límites de la pista
   - Detectar ganador

3. Demostrar TODOS los conceptos aprendidos:
   - Encapsulamiento: velocidad privada con @property
   - Herencia: KartPesado y KartLigero heredan de VehiculoBase
   - Polimorfismo: aceleran diferente (override de acelerar())
   - Composición: Conductor = Personaje + Kart
   - Abstracción: ItemBase con subclases concretas

COMPORTAMIENTO ESPERADO:
- KartPesado acelera más (x1.2) pero tiene velocidad_max baja
- KartLigero acelera menos (x0.8) pero tiene velocidad_max alta
- Los items afectan el juego (turbo aumenta velocidad, escudo protege)
- La carrera termina cuando alguien cruza la meta (largo de pista)

ESTUDIANTE: Completa el código donde dice # TODO
"""

import math


class CarreraCompleta:
    """Simula una carrera completa con todos los elementos del juego."""

    def __init__(self, nombre_pista, ancho, largo):
        # TODO: Inicializa
        # self.nombre_pista = nombre_pista
        # self.ancho = ancho
        # self.largo = largo
        # self.conductores = []
        # self.ganador = None
        pass

    def agregar_conductor(self, conductor):
        # TODO: Agrega conductor a la lista
        pass

    def simular_vuelta(self, num_vuelta):
        # TODO: Simula una vuelta para todos los conductores
        # Para cada conductor:
        #   - Incrementa velocidad (acelerar con incremento aleatorio 10-50)
        #   - Gira el kart (girar con ángulo aleatorio -10 a 10)
        #   - Actualiza posición
        #   - Valida límites de ancho (si sale, ajusta a límite)
        #   - Imprime estado actual
        pass

    def verificar_ganador(self):
        # TODO: Busca el primer conductor que cruzó la meta (posicion_y >= self.largo)
        # Guarda en self.ganador
        # Retorna True si hay ganador, False si no
        pass

    def correr(self, max_vueltas=100):
        # TODO: Ejecuta la carrera
        # Loop hasta encontrar ganador o alcanzar max_vueltas:
        #   - Simular vuelta
        #   - Verificar ganador
        #   - Si hay ganador, romper loop
        pass

    def mostrar_resultados(self):
        # TODO: Muestra resultados finales
        # Si hay ganador:
        #   - Imprime: "🏆 ¡{nombre} ganó la carrera!"
        #   - Velocidad final, posición, items recolectados
        # Si no hay ganador:
        #   - Imprime: "❌ Nadie cruzó la meta"
        #   - Muestra el más avanzado
        pass


# PRUEBAS - EJERCICIO INTEGRADOR
if __name__ == "__main__":
    # TODO: Descomenta y completa para ejecutar carrera integrada
    #
    # from karts_especializados import KartPesado, KartLigero
    # from personaje import Personaje
    # from item_y_conductor import Conductor, Item
    # import random
    #
    # # Crea pista
    # pista = CarreraCompleta("Luigi Circuit", 200, 1000)
    #
    # # Crea personajes y conductores
    # mario = Personaje("Mario", "Guerrero", 100, 100, 50, 50)
    # mario.kart = KartPesado("Mario Pesado")
    # conductor_mario = Conductor(mario, mario.kart)
    #
    # luigi = Personaje("Luigi", "Ladrón", 90, 90, 70, 70)
    # luigi.kart = KartLigero("Luigi Ligero")
    # conductor_luigi = Conductor(luigi, luigi.kart)
    #
    # bowser = Personaje("Bowser", "Tanque", 150, 150, 30, 30)
    # bowser.kart = KartPesado("Bowser")
    # conductor_bowser = Conductor(bowser, bowser.kart)
    #
    # # Agrega conductores a pista
    # pista.agregar_conductor(conductor_mario)
    # pista.agregar_conductor(conductor_luigi)
    # pista.agregar_conductor(conductor_bowser)
    #
    # # Ejecuta carrera
    # print(f"🏁 INICIANDO CARRERA: {pista.nombre_pista}\n")
    # pista.correr(max_vueltas=50)
    #
    # # Muestra resultados
    # pista.mostrar_resultados()
    #
    # print("\n✅ ¡Carrera completada!")
    # print("✅ ¡Todos los conceptos OOP fueron aplicados!")
    pass
