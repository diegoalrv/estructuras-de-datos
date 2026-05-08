"""
SEMANA 1: Clase Personaje - Conductor de Mario Kart
====================================================

OBJETIVO:
Crear la clase Personaje que representa al conductor/jugador en Mario Kart.

REQUISITOS:
1. Atributos del personaje:
   - nombre (str): Nombre del personaje
   - tipo_peso (str): "Ligero", "Medio" o "Pesado"
   - aceleracion (int): Capacidad de aceleración (0-100)
   - agarre (int): Control en curvas (0-100)
   - kart (Kart o None): Kart asignado, inicialmente None

2. Método __str__() que retorne:
   🏎️ {nombre} ({tipo_peso}) | Aceleración: {aceleracion} | Agarre: {agarre} | Kart: {kart.nombre if kart else "Sin kart"}

3. Método asignar_kart(kart): Asigna un kart al personaje

NOTAS:
- El Personaje CONTIENE un Kart (composición)
- El Kart se asigna después de la creación del Personaje
- Un mismo Personaje podría cambiar de Kart durante el juego

ESTUDIANTE: Completa el código donde dice # TODO
"""


class Personaje:
    """Representa un personaje jugable de Mario Kart."""

    def __init__(self, nombre, tipo_peso, aceleracion, agarre):
        """
        Inicializa un personaje.

        Args:
            nombre (str): Nombre del personaje
            tipo_peso (str): "Ligero", "Medio" o "Pesado"
            aceleracion (int): Capacidad de aceleración (0-100)
            agarre (int): Control en curvas (0-100)
        """
        # TODO: Asigna los atributos
        # - nombre, tipo_peso, aceleracion, agarre
        # - kart = None (se asigna después)
        # - items = [] (lista de items que recoge durante la carrera)
        pass

    def asignar_kart(self, kart):
        """
        Asigna un kart a este personaje.

        Args:
            kart (Kart): Instancia de Kart a asignar
        """
        # TODO: Asigna self.kart = kart
        pass

    def recoger_item(self, item):
        """
        Recoge un item durante la carrera.

        Args:
            item (Item): Item a recoger
        """
        # TODO: Agrega item a self.items y lo activa
        # - self.items.append(item)
        # - item.activar()
        pass

    def __str__(self):
        """Representación del personaje."""
        # TODO: Retorna un string con el formato:
        # 🏎️ {nombre} ({tipo_peso}) | Aceleración: {aceleracion} | Agarre: {agarre} | Kart: {kart.nombre if kart else "Sin kart"}
        #
        # Ejemplo:
        # 🏎️ Mario (Medio) | Aceleración: 80 | Agarre: 75 | Kart: Mario Kart
        pass


# ============================================================================
# PRUEBAS
# ============================================================================

if __name__ == "__main__":
    # TODO: Descomenta para validar
    # mario = Personaje("Mario", "Medio", 80, 75)
    # print(mario)
    # # Debe imprimir: 🏎️ Mario (Medio) | Aceleración: 80 | Agarre: 75 | Kart: Sin kart
    #
    # assert mario.nombre == "Mario"
    # assert mario.tipo_peso == "Medio"
    # assert mario.kart == None
    #
    # # Después se asigna un kart (semana 2)
    # # mario.asignar_kart(kart)
    #
    # print("✅ Personaje creado correctamente!")
    pass
