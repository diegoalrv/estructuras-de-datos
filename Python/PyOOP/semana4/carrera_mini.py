"""
SEMANA 4.3: Clase Carrera - Simulación con Polimorfismo
=======================================================

OBJETIVO:
Demostrar polimorfismo: personajes con diferentes tipos de karts
aceleran de manera diferente en la misma carrera.

REQUISITOS:
1. Carrera: nombre, pista, vueltas

2. Método simular_vuelta(incremento):
   - Todos los personajes aceleran
   - Pero aceleran diferente según su tipo de kart (POLIMORFISMO)

3. Método correr(vueltas, incremento):
   - Simula múltiples vueltas
   - Muestra progresión

4. Método obtener_ganador():
   - Retorna el personaje más rápido

POLIMORFISMO EN ACCIÓN:
Cuando llamas personaje.kart.acelerar(50) a varios personajes:
- KartPesado: +60 km/h (50 × 1.2)
- KartMedio: +50 km/h (50 × 1.0)
- KartLigero: +40 km/h (50 × 0.8)

Sin if/else, sin verificar tipo, sin complejidad extra.
¡Polimorfismo en acción!

ESTUDIANTE: Completa el código donde dice # TODO
"""


class Carrera:
    """Simula una carrera con polimorfismo."""

    def __init__(self, nombre, pista):
        """
        Inicializa la carrera.

        Args:
            nombre (str): Nombre de la carrera
            pista (Pista): Objeto Pista donde ocurre la carrera
        """
        # TODO: Asigna los atributos
        # - nombre, pista
        # - vueltas = 0 (contador de vueltas)
        pass

    def simular_vuelta(self, incremento):
        """
        Simula una vuelta: todos los personajes aceleran.

        POLIMORFISMO:
        Todos usan el mismo método con el mismo argumento,
        pero se comportan diferente según el tipo de kart.

        Args:
            incremento (float): Incremento base de aceleración
        """
        # TODO: Para cada personaje en self.pista.personajes:
        # - Llama personaje.kart.acelerar(incremento)
        # - Imprime la velocidad resultante
        pass

    def correr(self, vueltas, incremento):
        """
        Ejecuta la carrera durante varias vueltas.

        Args:
            vueltas (int): Número de vueltas a simular
            incremento (float): Incremento base por vuelta
        """
        # TODO: Simula la carrera
        # - Imprime encabezado con nombre, pista, vueltas
        # - Para cada vuelta, llama simular_vuelta(incremento)
        # - Mantén actualizado self.vueltas
        pass

    def obtener_ganador(self):
        """
        Obtiene el personaje más rápido (mayor velocidad).

        Returns:
            Personaje: El personaje con mayor velocidad
        """
        # TODO: Retorna el personaje con mayor velocidad
        # Usa max() con key=lambda
        pass

    def mostrar_estadisticas(self):
        """Muestra estadísticas de la carrera."""
        # TODO: Muestra estadísticas finales
        # - Vueltas completadas
        # - Lista de personajes ordenados por velocidad (descendente)
        # - Medallas para top 3 (🥇🥈🥉)
        # - Ganador destacado con su velocidad
        pass


# ============================================================================
# PRUEBAS
# ============================================================================

if __name__ == "__main__":
    from semana1.personaje import Personaje
    from semana3.karts_especializados import KartPesado, KartMedio, KartLigero
    from pista import Pista

    print("\n" + "="*70)
    print("DEMOSTRANDO POLIMORFISMO EN MARIO KART")
    print("="*70)
    print("\nMismo incremento de aceleración (50 km/h), diferente resultado:")
    print("  🏋️  KartPesado:   50 × 1.2 = 60 km/h")
    print("  🎮 KartMedio:    50 × 1.0 = 50 km/h")
    print("  ⚡ KartLigero:   50 × 0.8 = 40 km/h")
    print("="*70)

    # Crea pista
    pista = Pista("Mario Circuit", 100, 500)

    # Crea personajes con diferentes karts
    bowser = Personaje("Bowser", "Pesado", 90, 85)
    bowser.asignar_kart(KartPesado("Bowser Kart"))
    bowser.items = []

    mario = Personaje("Mario", "Medio", 80, 75)
    mario.asignar_kart(KartMedio("Mario Kart"))
    mario.items = []

    toad = Personaje("Toad", "Ligero", 70, 75)
    toad.asignar_kart(KartLigero("Toad Kart"))
    toad.items = []

    # Agrega a pista
    pista.add_personaje(bowser)
    pista.add_personaje(mario)
    pista.add_personaje(toad)

    # Crea y ejecuta carrera
    carrera = Carrera("Gran Premio Olímpico", pista)
    carrera.correr(5, 50)

    # Muestra estadísticas
    carrera.mostrar_estadisticas()

    print("\n✅ ¡Polimorfismo demostrado exitosamente!")
