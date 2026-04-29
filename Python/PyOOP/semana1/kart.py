–"""
SEMANA 1.1: Crear la Clase Kart
================================

OBJETIVO:
Crear una clase que represente un kart de carreras con sus características básicas.

REQUISITOS:
1. Crear clase `Kart` con método `__init__`
2. Atributos obligatorios:
   - nombre (str)
   - velocidad_max (float) - en km/h
   - color (str)
   - posicion_x (float) - coordenada inicial 0.0
   - posicion_y (float) - coordenada inicial 0.0
   - velocidad (float) - inicial 0.0
   - turbo_disponible (bool) - inicial True
   - direccion: (float) - ángulo en grados, inicial 0.0

3. Implementar `__str__()` que retorne:
   🏎️ {nombre} | V.max: {velocidad_max} km/h | Color: {color}

ESTUDIANTE: Completa el código donde dice # TODO
"""


class Kart:
    """Representa un kart de carreras en Mario Kart."""

    def __init__(self, nombre, velocidad_max, color):
        # TODO: Asigna todos los atributos usando self.atributo = valor
        # Recuerda: posicion_x=0.0, posicion_y=0.0, velocidad=0.0, turbo_disponible=True
        pass

    def __str__(self):
        # TODO: Retorna un string formateado con el patrón:
        # "🏎️ {nombre} | V.max: {velocidad_max} km/h | Color: {color}"
        pass


# ============================================================================
# PRUEBAS - Descomenta estas líneas para validar tu código
# ============================================================================

if __name__ == "__main__":
    # TODO: Crea una instancia llamada mario_kart
    # mario_kart = Kart("Mario", 180, "Rojo")
    # print(mario_kart)
    # # Debe imprimir: 🏎️ Mario | V.max: 180.0 km/h | Color: Rojo

    # TODO: Verifica los atributos con assert
    # assert mario_kart.nombre == "Mario"
    # assert mario_kart.velocidad_max == 180
    # assert mario_kart.color == "Rojo"
    # assert mario_kart.posicion_x == 0.0
    # assert mario_kart.posicion_y == 0.0
    # assert mario_kart.velocidad == 0.0
    # assert mario_kart.turbo_disponible == True

    # print("✅ ¡Todas las pruebas pasaron!")
    pass
