"""
ENCAPSULAMIENTO EN MARIO KART: Protegiendo el Estado del Kart
===============================================================

PROBLEMA SIN ENCAPSULAMIENTO:
Si exponemos los atributos del Kart directamente, alguien podría hacer trampa:

    kart = Kart("Mario", 200)
    kart.velocidad = 999  # ¡Hizo trampa! Velocidad imposible
    kart.combustible = -100  # ¡Negativo! No tiene sentido
    kart.velocidad_max = 10000  # ¡Cambió las reglas!

SOLUCION: ENCAPSULAMIENTO
Con atributos privados y @property, controlamos qué se puede hacer:

    kart = Kart("Mario", 200)
    kart.velocidad = 999  # ❌ ERROR: No permitido, velocidad_max es 200
    kart.combustible = -50  # ❌ ERROR: No puede ser negativo
    kart.acelerar(50)  # ✅ CORRECTO: Método controlado
"""

import math


class Kart:
    """Kart con encapsulamiento real: atributos privados + validación."""

    def __init__(self, piloto: str, velocidad_max: int, combustible_max: int = 100):
        self.piloto = piloto
        self._velocidad_max = velocidad_max
        self._combustible_max = combustible_max

        # ATRIBUTOS PRIVADOS: No se puede acceder directamente desde afuera
        self.__velocidad = 0.0  # Velocidad actual (0 a velocidad_max)
        self.__combustible = combustible_max  # Combustible actual (0 a max)
        self.__desgaste_neumaticos = 0  # Desgaste (0 a 100)
        self.__posicion_x = 0.0
        self.__posicion_y = 0.0
        self.__direccion = 0  # Ángulo 0-360

    # ============================================
    # VELOCIDAD: Con validación
    # ============================================
    @property
    def velocidad(self) -> float:
        """Lee la velocidad actual de forma segura."""
        return self.__velocidad

    @velocidad.setter
    def velocidad(self, valor: float) -> None:
        """Establece velocidad con validación.

        - No puede ser negativa
        - No puede superar velocidad_max
        - Consume combustible
        """
        if valor < 0:
            print(f"⚠️ {self.piloto}: Velocidad no puede ser negativa. Ajustando a 0.")
            self.__velocidad = 0.0
        elif valor > self._velocidad_max:
            print(f"⚠️ {self.piloto}: Velocidad supera el máximo ({self._velocidad_max} km/h). Limitando.")
            self.__velocidad = float(self._velocidad_max)
        else:
            self.__velocidad = float(valor)

    # ============================================
    # COMBUSTIBLE: Con validación y consumo
    # ============================================
    @property
    def combustible(self) -> float:
        """Lee el combustible actual de forma segura."""
        return self.__combustible

    @combustible.setter
    def combustible(self, valor: float) -> None:
        """Establece combustible con validación.

        - No puede ser negativo
        - No puede superar combustible_max
        """
        if valor < 0:
            print(f"⚠️ {self.piloto}: Combustible no puede ser negativo. Motor apagado.")
            self.__combustible = 0.0
            self.__velocidad = 0.0  # Si no hay combustible, no hay velocidad
        elif valor > self._combustible_max:
            print(f"⚠️ {self.piloto}: Combustible lleno ({self._combustible_max} L).")
            self.__combustible = float(self._combustible_max)
        else:
            self.__combustible = float(valor)

    # ============================================
    # DESGASTE: Aumenta solo por conducción
    # ============================================
    @property
    def desgaste_neumaticos(self) -> float:
        """Lee el desgaste de neumáticos (0-100)."""
        return self.__desgaste_neumaticos

    def _aumentar_desgaste(self, cantidad: float) -> None:
        """PRIVADO: Solo métodos internos pueden aumentar desgaste."""
        self.__desgaste_neumaticos = min(100, self.__desgaste_neumaticos + cantidad)
        if self.__desgaste_neumaticos >= 100:
            print(f"🔴 {self.piloto}: ¡NEUMÁTICOS DESTROZADOS! Velocidad reducida 50%")

    # ============================================
    # ACCIONES CONTROLADAS
    # ============================================
    def acelerar(self, incremento: float) -> None:
        """Acelera el Kart de forma segura.

        - Valida que haya combustible
        - Consume combustible
        - Aumenta desgaste
        - Respeta velocidad máxima
        """
        if self.__combustible <= 0:
            print(f"❌ {self.piloto}: ¡Sin combustible! No puedo acelerar.")
            self.__velocidad = 0.0
            return

        # Calcular desgaste por aceleración
        desgaste = incremento * 0.1  # Mayor aceleración = más desgaste
        self._aumentar_desgaste(desgaste)

        # Consumir combustible (más combustible con más aceleración)
        consumo = incremento * 0.05
        self.combustible -= consumo

        # Aplicar aceleración
        nueva_velocidad = self.__velocidad + incremento

        # Penalidad por desgaste: Si los neumáticos están muy gastados, acelera menos
        if self.__desgaste_neumaticos > 80:
            nueva_velocidad *= 0.5  # Solo 50% de la aceleración normal

        self.velocidad = nueva_velocidad
        print(f"⏫ {self.piloto} acelera a {self.__velocidad:.1f} km/h (Combustible: {self.__combustible:.1f}L)")

    def frenar(self, decremento: float) -> None:
        """Frena el Kart de forma segura.

        - Reduce velocidad gradualmente
        - Aumenta desgaste (menos que aceleración)
        - Recupera un poco de combustible (regenerativo)
        """
        desgaste = decremento * 0.05  # Frenar desgasta menos
        self._aumentar_desgaste(desgaste)

        # Frenado regenerativo: recupera 10% del combustible ahorrado
        energia_recuperada = decremento * 0.01
        self.combustible += energia_recuperada

        nueva_velocidad = self.__velocidad - decremento
        self.velocidad = nueva_velocidad
        print(f"⏬ {self.piloto} frena a {self.__velocidad:.1f} km/h (Recupera {energia_recuperada:.2f}L)")

    def girar(self, angulo: float) -> None:
        """Gira el Kart (normaliza ángulo 0-360).

        - Giros bruscos a alta velocidad aumentan desgaste
        """
        # Penalidad: Giros bruscos a alta velocidad
        penalidad_giro = abs(angulo) * (self.__velocidad / self._velocidad_max) * 0.1
        self._aumentar_desgaste(penalidad_giro)

        self.__direccion = (self.__direccion + angulo) % 360
        print(f"🔄 {self.piloto} gira a {self.__direccion}°")

    def actualizar_posicion(self) -> None:
        """Actualiza posición basada en velocidad y dirección."""
        if self.__desgaste_neumaticos > 80:
            velocidad_efectiva = self.__velocidad * 0.5
        else:
            velocidad_efectiva = self.__velocidad

        self.__posicion_x += velocidad_efectiva * math.cos(math.radians(self.__direccion))
        self.__posicion_y += velocidad_efectiva * math.sin(math.radians(self.__direccion))

    def repostar(self, cantidad: float) -> None:
        """Recarga combustible en un pit stop."""
        viejo = self.__combustible
        self.combustible += cantidad
        print(f"⛽ {self.piloto} repostó ({viejo:.1f}L → {self.__combustible:.1f}L)")

    def cambiar_neumaticos(self) -> None:
        """Cambia neumáticos en pit stop."""
        self.__desgaste_neumaticos = 0
        print(f"🛞 {self.piloto}: Neumáticos nuevos instalados")

    def obtener_posicion(self) -> tuple:
        """Obtiene posición actual (SEGURO: retorna copia)."""
        return (self.__posicion_x, self.__posicion_y)

    def obtener_estado(self) -> str:
        """Retorna el estado actual del Kart."""
        salud_neumaticos = "🟢 BUENOS" if self.__desgaste_neumaticos < 50 else "🟡 DESGASTADOS" if self.__desgaste_neumaticos < 80 else "🔴 CRÍTICOS"
        return f"""
🏎️  {self.piloto}
├─ Velocidad: {self.__velocidad:.1f}/{self._velocidad_max} km/h
├─ Combustible: {self.__combustible:.1f}/{self._combustible_max} L
├─ Neumáticos: {self.__desgaste_neumaticos:.0f}% desgaste ({salud_neumaticos})
├─ Dirección: {self.__direccion}°
└─ Posición: ({self.__posicion_x:.1f}, {self.__posicion_y:.1f})
        """

    def __str__(self) -> str:
        return f"🏎️ {self.piloto} | V: {self.__velocidad:.0f}/{self._velocidad_max} km/h | Combustible: {self.__combustible:.0f}L"


# ============================================================
# DEMOSTRACION: Por qué el encapsulamiento es importante
# ============================================================
if __name__ == "__main__":
    print("=" * 60)
    print("ENCAPSULAMIENTO EN MARIO KART")
    print("=" * 60)

    # Crear un Kart
    mario = Kart("Mario", velocidad_max=200, combustible_max=100)
    print(mario.obtener_estado())

    # ✅ FORMA CORRECTA: Usar métodos públicos
    print("\n✅ FORMA CORRECTA: Acelerar usando el método:")
    mario.acelerar(50)
    print(mario)

    # ❌ FORMA INCORRECTA (INTENTO): Acceder al atributo privado
    print("\n❌ INTENTO DE TRAMPA: Cambiar velocidad directamente:")
    try:
        mario._Kart__velocidad = 999  # "Name mangling" en Python
        print(f"⚠️ Se intentó establecer velocidad a 999, pero ahora es: {mario.velocidad} km/h")
    except:
        print("❌ Error: No se puede acceder al atributo privado")

    # ✅ FORMA SEGURA: Usar el setter del @property
    print("\n✅ Intento de establecer velocidad a 999 a través del setter:")
    mario.velocidad = 999  # El setter valida y limita
    print(f"Velocidad después del intento: {mario.velocidad} km/h (limitada a máximo)")

    # Más acciones
    print("\n--- Simulación de carrera ---")
    mario.girar(-15)
    mario.actualizar_posicion()
    mario.acelerar(30)
    mario.girar(10)
    mario.actualizar_posicion()

    print("\n--- Daño por conducción agresiva ---")
    for i in range(5):
        mario.acelerar(40)
        mario.girar(45)
        mario.actualizar_posicion()

    print(mario.obtener_estado())

    print("\n--- Pit Stop ---")
    mario.repostar(50)
    mario.cambiar_neumaticos()

    print(mario.obtener_estado())

    # ============================================================
    # COMPARACIÓN: SIN ENCAPSULAMIENTO
    # ============================================================
    print("\n" + "=" * 60)
    print("COMPARACIÓN: ¿QUÉ PASARÍA SIN ENCAPSULAMIENTO?")
    print("=" * 60)

    class KartSinEncapsulamiento:
        """Versión SIN protección (¡MALA PRÁCTICA!)"""
        def __init__(self, piloto: str, velocidad_max: int):
            self.piloto = piloto
            self.velocidad_max = velocidad_max
            self.velocidad = 0  # ❌ PÚBLICO: Cualquiera puede cambiarlo
            self.combustible = 100  # ❌ PÚBLICO: Puede ser negativo
            self.posicion_x = 0

    print("\nSin encapsulamiento, un tramposo hace esto:")
    luigi = KartSinEncapsulamiento("Luigi", 200)
    print(f"✅ Luigi creado: {luigi.velocidad} km/h")

    # ¡TRAMPA!
    luigi.velocidad = 9999
    luigi.combustible = -999
    luigi.velocidad_max = 10000
    print(f"❌ ¡TRAMPA! Luigi tiene: {luigi.velocidad} km/h (velocidad_max: {luigi.velocidad_max})")
    print(f"❌ ¡TRAMPA! Combustible: {luigi.combustible}L (¡NEGATIVO!)")
    print(f"\n❌ El juego está roto. Luigi es invencible e ilimitado.")

    print("\n" + "=" * 60)
    print("CONCLUSIÓN: El encapsulamiento protege la integridad del juego")
    print("=" * 60)
