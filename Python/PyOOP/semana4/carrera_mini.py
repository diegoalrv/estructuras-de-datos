"""
SEMANA 4.3: Mini-carrera con Polimorfismo
==========================================

OBJETIVO:
Demostrar polimorfismo: distintos tipos de Kart aceleran diferente.

REQUISITOS:
1. Usar KartPesado (acelera x1.2) y KartLigero (acelera x0.8)
2. En un loop de carrera, acelerar ambos karts con el mismo incremento
3. Mostrar que aceleran diferente (polimorfismo en acelerar())
4. Simular una carrera corta (50 ciclos)

POLIMORFISMO:
- acelerar() es override en KartPesado y KartLigero
- Se llama a acelerar(50) en ambos pero el comportamiento es diferente
- Esto es polimorfismo: misma interfaz, distinto comportamiento

ESTUDIANTE: Completa el código donde dice # TODO
"""


class Carrera:
    """Simula una mini-carrera para demostrar polimorfismo."""

    def __init__(self, nombre):
        # TODO: Inicializa
        # nombre, conductores=[]
        pass

    def agregar_conductor(self, conductor):
        # TODO: Agrega conductor a la lista de conductores
        pass

    def simular_vuelta(self, incremento):
        # TODO: Para cada conductor en self.conductores:
        #   - Llamar a conductor.manejar(incremento)
        #   - Imprimir velocidad actual
        # POLIMORFISMO: aunque llames manejar() con el mismo incremento,
        # KartPesado y KartLigero aceleran diferente
        pass

    def correr(self, vueltas, incremento):
        # TODO: Ejecuta simular_vuelta() vueltas veces
        # Muestra progresión de velocidades
        for vuelta in range(vueltas):
            print(f"\n🏁 Vuelta {vuelta + 1}")
            self.simular_vuelta(incremento)

    def mostrar_ganador(self):
        # TODO: Encuentra el conductor más rápido (mayor velocidad)
        # Retorna ese conductor
        pass


# PRUEBAS
if __name__ == "__main__":
    # TODO: Descomenta para validar
    # from kart_metodos import Kart  # O la versión especializada
    # from personaje import Personaje
    # from item_y_conductor import Conductor
    #
    # # Crea conductores con karts especializados
    # bowser = Personaje("Bowser", "Guerrero", 150, 150, 80, 80)
    # bowser.kart = KartPesado("Bowser Pesado")  # Acelera x1.2
    #
    # toad = Personaje("Toad", "Mago", 80, 80, 100, 100)
    # toad.kart = KartLigero("Toad Ligero")  # Acelera x0.8
    #
    # conductor_bowser = Conductor(bowser, bowser.kart)
    # conductor_toad = Conductor(toad, toad.kart)
    #
    # # Crea carrera
    # carrera = Carrera("Mini-Carrera Polimórfica")
    # carrera.agregar_conductor(conductor_bowser)
    # carrera.agregar_conductor(conductor_toad)
    #
    # # Simula 5 vueltas
    # carrera.correr(5, 50)
    #
    # # Muestra ganador
    # ganador = carrera.mostrar_ganador()
    # print(f"\n🏆 ¡Ganador: {ganador.personaje.nombre} con {ganador.obtener_velocidad()} km/h!")
    # print("✅ ¡Polimorfismo demostrado!")
    pass
