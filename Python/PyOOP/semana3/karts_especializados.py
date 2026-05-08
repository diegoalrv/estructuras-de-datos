"""
SEMANA 3: Karts Especializados - Herencia y Polimorfismo
=======================================================

OBJETIVO:
Crear subclases de Kart que heredan su funcionalidad base pero tienen
comportamientos diferentes en la aceleración (polimorfismo).

REQUISITOS:
1. KartPesado(Kart):
   - velocidad_max = 150 km/h
   - Acelera más fuerte (multiplicador 1.2)

2. KartMedio(Kart):
   - velocidad_max = 185 km/h
   - Acelera normal (multiplicador 1.0)

3. KartLigero(Kart):
   - velocidad_max = 220 km/h
   - Acelera más débil (multiplicador 0.8)

HERENCIA:
- Cada clase hereda de Kart usando: class KartPesado(Kart):
- Usan super().__init__() para llamar al constructor del padre
- Solo reescriben el método acelerar() con diferente comportamiento
- Heredan todos los demás métodos (frenar, girar, actualizar_posicion, usar_turbo)

POLIMORFISMO:
- Aunque todos sean instancias de Kart, se comportan diferente
- acelerar(50) da resultados distintos según el tipo
- Se llama de la misma forma pero con diferente resultado

ESTUDIANTE: Completa el código donde dice # TODO
"""

from semana2.kart_metodos import Kart


class KartPesado(Kart):
    """
    Kart pesado: Lento pero con gran aceleración.
    Ideal para personajes como Bowser, Donkey Kong.
    - Velocidad máxima: 150 km/h
    - Aceleración: x1.2 (50 → +60 km/h)
    """

    def __init__(self, nombre):
        """
        Inicializa un kart pesado.

        Args:
            nombre (str): Nombre del kart
        """
        # TODO: Usa super().__init__() para inicializar con:
        # - nombre: el parámetro
        # - velocidad_max: 150
        # - color: "Verde"
        pass

    def acelerar(self, incremento):
        """
        El kart pesado acelera más fuerte.

        Args:
            incremento (float): Incremento base

        Returns:
            float: Nueva velocidad
        """
        # TODO: El kart pesado multiplica el incremento por 1.2
        # self.velocidad = min(self.velocidad + (incremento * 1.2), self.velocidad_max)
        # return self.velocidad
        pass

    def __str__(self):
        return f"🏋️ {self.nombre} (Pesado) | V.máx: {self.velocidad_max} km/h | Color: {self.color}"


class KartMedio(Kart):
    """
    Kart medio: Balance entre velocidad y aceleración.
    Ideal para personajes como Mario, Luigi.
    - Velocidad máxima: 185 km/h
    - Aceleración: x1.0 (50 → +50 km/h)
    """

    def __init__(self, nombre):
        """
        Inicializa un kart medio.

        Args:
            nombre (str): Nombre del kart
        """
        # TODO: Usa super().__init__() para inicializar con:
        # - nombre: el parámetro
        # - velocidad_max: 185
        # - color: "Amarillo"
        pass

    def acelerar(self, incremento):
        """
        El kart medio acelera normal.

        Args:
            incremento (float): Incremento base

        Returns:
            float: Nueva velocidad
        """
        # TODO: El kart medio acelera sin multiplicador (x1.0)
        # self.velocidad = min(self.velocidad + incremento, self.velocidad_max)
        # return self.velocidad
        pass

    def __str__(self):
        return f"🎮 {self.nombre} (Medio) | V.máx: {self.velocidad_max} km/h | Color: {self.color}"


class KartLigero(Kart):
    """
    Kart ligero: Rápido pero con aceleración débil.
    Ideal para personajes como Toad, Peach.
    - Velocidad máxima: 220 km/h
    - Aceleración: x0.8 (50 → +40 km/h)
    """

    def __init__(self, nombre):
        """
        Inicializa un kart ligero.

        Args:
            nombre (str): Nombre del kart
        """
        # TODO: Usa super().__init__() para inicializar con:
        # - nombre: el parámetro
        # - velocidad_max: 220
        # - color: "Azul"
        pass

    def acelerar(self, incremento):
        """
        El kart ligero acelera más débil.

        Args:
            incremento (float): Incremento base

        Returns:
            float: Nueva velocidad
        """
        # TODO: El kart ligero multiplica el incremento por 0.8
        # self.velocidad = min(self.velocidad + (incremento * 0.8), self.velocidad_max)
        # return self.velocidad
        pass

    def __str__(self):
        return f"⚡ {self.nombre} (Ligero) | V.máx: {self.velocidad_max} km/h | Color: {self.color}"


# ============================================================================
# PRUEBAS
# ============================================================================

if __name__ == "__main__":
    pesado = KartPesado("Bowser Kart")
    medio = KartMedio("Mario Kart")
    ligero = KartLigero("Toad Kart")

    print("=== KARTS ESPECIALIZADOS ===")
    print(pesado)
    print(medio)
    print(ligero)

    print("\n=== PRUEBA DE ACELERACIÓN ===")
    print("Acelerar 50 km/h para cada uno:")

    pesado.acelerar(50)
    print(f"  Pesado: {pesado.velocidad:.1f} km/h (50 × 1.2 = 60)")
    assert pesado.velocidad == 60

    medio.acelerar(50)
    print(f"  Medio:  {medio.velocidad:.1f} km/h (50 × 1.0 = 50)")
    assert medio.velocidad == 50

    ligero.acelerar(50)
    print(f"  Ligero: {ligero.velocidad:.1f} km/h (50 × 0.8 = 40)")
    assert ligero.velocidad == 40

    print("\n=== VALIDAR LÍMITES ===")
    pesado.velocidad = 140
    pesado.acelerar(50)  # 140 + 60 = 200, pero max es 150
    assert pesado.velocidad == 150
    print(f"  Pesado no supera max (150): {pesado.velocidad}")

    print("\n✅ ¡Herencia y polimorfismo funcionan correctamente!")
