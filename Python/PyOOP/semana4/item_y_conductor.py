"""
SEMANA 4.2: Clase Item - Elementos de Juego
============================================

OBJETIVO:
Implementar los items que pueden recoger los personajes durante la carrera.

REQUISITOS:
1. Item: tipo (str), bonus (int), activo (bool)

2. Método activar():
   - Marca el item como activo
   - En un juego real, aplicaría el bonus al personaje

3. Métodos: __str__()

ITEMS EN MARIO KART:
- Turbo: +velocidad temporal
- Escudo: Protección contra ataques
- Bomba: Daño a contrincantes
- Super Salto: Acelerar en salto

COMPOSICIÓN:
- Personaje CONTIENE una lista de items (items = [])
- Los items se agregan con personaje.recoger_item(item)
- Los items se activan cuando se recogen

NOTA:
- La clase Conductor fue eliminada porque Personaje ya contiene el kart
- Esto simplifica la arquitectura y evita redundancia
- Los métodos que estaban en Conductor ahora se llaman directamente en Personaje/Kart

ESTUDIANTE: Completa el código donde dice # TODO
"""


class Item:
    """Representa un item del juego que puede recoger un personaje."""

    def __init__(self, tipo, bonus):
        """
        Inicializa un item.

        Args:
            tipo (str): Tipo de item (ej: "Turbo", "Escudo", "Bomba")
            bonus (int): Valor del bonus (ej: 50 para velocidad)
        """
        # TODO: Asigna los atributos
        # - tipo, bonus
        # - activo = False (se activa al recoger)
        pass

    def activar(self):
        """
        Activa el item.
        En un juego real, aplicaría el bonus al personaje que lo recogió.
        """
        # TODO: Marca el item como activo
        # self.activo = True
        pass

    def __str__(self):
        """Representación del item."""
        return f"🎁 {self.tipo} | Bonus: +{self.bonus}"


# ============================================================================
# EXTENSIÓN: Métodos helpers para Personaje (agregados a clase Personaje)
# ============================================================================
# Estos métodos se agregan a la clase Personaje para trabajar con items:
#
# def recoger_item(self, item):
#     """Recoge un item y lo activa."""
#     self.items.append(item)
#     item.activar()
#
# def listar_items(self):
#     """Lista todos los items que tiene el personaje."""
#     if not self.items:
#         print(f"  {self.nombre} no tiene items")
#     else:
#         print(f"  Items de {self.nombre}:")
#         for item in self.items:
#             print(f"    - {item}")


# ============================================================================
# PRUEBAS
# ============================================================================

if __name__ == "__main__":
    from semana1.personaje import Personaje
    from semana3.karts_especializados import KartLigero

    # Crea personaje
    toad = Personaje("Toad", "Ligero", 90, 70)
    toad_kart = KartLigero("Toad Kart")
    toad.asignar_kart(toad_kart)
    toad.items = []  # Inicializa lista de items

    # Crea items
    turbo = Item("Turbo", 50)
    escudo = Item("Escudo", 100)

    print("=== ITEMS ===")
    print(f"Turbo creado: {turbo}")
    print(f"Escudo creado: {escudo}")

    # Recoge items (usando append directo en este ejemplo)
    toad.items.append(turbo)
    turbo.activar()

    assert len(toad.items) == 1
    assert turbo.activo == True
    print(f"\n✓ {toad.nombre} recogió: {turbo}")

    print("\n✅ Items funcionan correctamente!")
