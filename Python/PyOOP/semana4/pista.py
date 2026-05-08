"""
SEMANA 4.1: Clase Pista - Gestión de la Carrera
================================================

OBJETIVO:
Implementar la pista de carreras que contiene y gestiona a los personajes.

REQUISITOS:
1. Pista: nombre, ancho, largo, personajes (lista)

2. Método add_personaje(personaje):
   - Agrega un personaje a la carrera
   - Valida que tenga kart asignado

3. Método remover_personaje(personaje):
   - Quita un personaje de la carrera

4. Método actualizar_conductores():
   - Actualiza posición de todos los personajes
   - Valida límites de la pista

5. Método verificar_ganador():
   - Retorna primer personaje que cruza la meta

6. Método listar_personajes():
   - Muestra el estado de todos los personajes

CONTENEDOR:
- Pista es un contenedor de Personajes
- Cada Personaje tiene asignado un Kart
- La pista gestiona los movimientos de todos

ESTUDIANTE: Completa el código donde dice # TODO
"""


class Pista:
    """Representa la pista de carreras."""

    def __init__(self, nombre, ancho, largo):
        """
        Inicializa la pista.

        Args:
            nombre (str): Nombre de la pista
            ancho (float): Ancho de la pista en metros
            largo (float): Largo de la pista (distancia a meta) en metros
        """
        # TODO: Asigna los atributos
        # - nombre, ancho, largo
        # - personajes = [] (lista vacía de Personajes)
        pass

    def add_personaje(self, personaje):
        """
        Agrega un personaje a la carrera.

        Args:
            personaje (Personaje): Personaje a agregar

        Raises:
            ValueError: Si el personaje no tiene kart asignado
        """
        # TODO: Valida que personaje.kart no sea None
        # Si es None, lanza: ValueError("El personaje debe tener un kart asignado")
        # Si no, agrégalo a self.personajes
        pass

    def remover_personaje(self, personaje):
        """
        Remueve un personaje de la carrera.

        Args:
            personaje (Personaje): Personaje a remover
        """
        # TODO: Usa try/except para remover el personaje
        # Si no está, pasa silenciosamente
        pass

    def actualizar_conductores(self):
        """
        Actualiza la posición de todos los personajes.
        Valida que no salgan de los límites.
        """
        # TODO: Para cada personaje:
        # - Llama personaje.kart.actualizar_posicion()
        # - Valida que posicion_x esté entre 0 y self.ancho
        # - Ajusta si sale del rango
        pass

    def verificar_ganador(self):
        """
        Verifica si algún personaje ha cruzado la meta.
        La meta está en posicion_y >= self.largo.

        Returns:
            Personaje: El primer personaje en cruzar
            None: Si nadie ha cruzado aún
        """
        # TODO: Itera personajes y retorna el primero con posicion_y >= self.largo
        # Si nadie ha cruzado, retorna None
        pass

    def listar_personajes(self):
        """Lista el estado de todos los personajes."""
        # TODO: Imprime información de todos los personajes
        # Formato similar a:
        # 📍 === {nombre_pista} ===
        # Personajes en carrera: {cantidad}
        # Para cada personaje mostrar: nombre, velocidad, posición
        pass

    def __str__(self):
        return f"🏁 Pista: {self.nombre} | {self.ancho}x{self.largo} | Personajes: {len(self.personajes)}"


# ============================================================================
# PRUEBAS
# ============================================================================

if __name__ == "__main__":
    from semana1.personaje import Personaje
    from semana3.karts_especializados import KartPesado

    # Crea pista
    pista = Pista("Mario Circuit", 100, 500)
    print(pista)

    # Crea personaje y le asigna kart
    mario = Personaje("Mario", "Medio", 80, 75)
    mario_kart = KartPesado("Mario Kart")
    mario.asignar_kart(mario_kart)
    mario.items = []  # Inicializa lista de items

    # Agrega a pista
    pista.add_personaje(mario)
    assert len(pista.personajes) == 1
    print(f"✓ {mario.nombre} agregado a la pista")

    # Simula movimiento
    mario.kart.acelerar(50)
    pista.actualizar_conductores()

    x, y = mario.kart.posicion_x, mario.kart.posicion_y
    print(f"✓ {mario.nombre} en posición: ({x:.1f}, {y:.1f})")

    print("\n✅ Pista funciona correctamente!")
