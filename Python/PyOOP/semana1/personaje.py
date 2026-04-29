"""
SEMANA 1.2: Crear la Clase Personaje
====================================

OBJETIVO:
Crear una clase que represente al jugador que controla un kart.

REQUISITOS:
1. Crear clase `Personaje` con método `__init__`
2. Atributos obligatorios:
   - nombre (str)
   - clase_rpg (str) - ej: "Guerrero", "Mago", "Ladrón"
   - hp (int) - vida inicial
   - hp_max (int) - vida máxima
   - energia (int) - energía inicial
   - energia_max (int) - energía máxima
   - kart (objeto Kart o None) - inicial None (no tiene kart aún)

3. Implementar `__str__()` que retorne:
   👤 {nombre} | Clase: {clase_rpg} | HP: {hp}/{hp_max} | Energía: {energia}/{energia_max}

ESTUDIANTE: Completa el código donde dice # TODO
"""


class Personaje:
    """Representa un personaje RPG que controla un Kart."""

    def __init__(self, nombre, clase_rpg, hp, hp_max, energia, energia_max):
        # TODO: Asigna todos los atributos usando self.atributo = valor
        # Recuerda: kart=None (inicialmente sin kart)
        pass

    def __str__(self):
        # TODO: Retorna un string formateado con el patrón:
        # "👤 {nombre} | Clase: {clase_rpg} | HP: {hp}/{hp_max} | Energía: {energia}/{energia_max}"
        pass


# ============================================================================
# PRUEBAS - Descomenta estas líneas para validar tu código
# ============================================================================

if __name__ == "__main__":
    # TODO: Crea una instancia llamada alderete
    # alderete = Personaje("Aldric", "Guerrero", 100, 100, 50, 50)
    # print(alderete)
    # # Debe imprimir: 👤 Aldric | Clase: Guerrero | HP: 100/100 | Energía: 50/50

    # TODO: Verifica los atributos
    # assert alderete.nombre == "Aldric"
    # assert alderete.clase_rpg == "Guerrero"
    # assert alderete.hp == 100
    # assert alderete.hp_max == 100
    # assert alderete.energia == 50
    # assert alderete.energia_max == 50
    # assert alderete.kart == None

    # print("✅ ¡Todas las pruebas pasaron!")
    pass
