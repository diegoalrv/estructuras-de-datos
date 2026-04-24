"""
ejercicio_4_template.py
Ejercicio 4: Implementar la clase Fecha

Requisitos:
- Atributos: dia, mes, anno (todos validados)
- Métodos: __init__, es_bisiesto, dias_en_mes, es_valida, __str__, __eq__, __lt__
- Validaciones: día válido para mes/año, año >= 1
"""


class Fecha:
    """Representa una fecha completa con validación."""

    def __init__(self, dia, mes, anno):
        """Constructor de la clase Fecha.

        Args:
            dia (int): Día de la fecha (1-31)
            mes (int): Mes de la fecha (1-12)
            anno (int): Año de la fecha (>= 1)

        Raises:
            ValueError: Si la fecha no es válida
        """
        # TODO: Validar usando el método es_valida()
        # TODO: Si es válida, asignar self.dia, self.mes, self.anno
        # TODO: Si no es válida, lanzar ValueError("Fecha inválida")
        pass

    def es_bisiesto(self):
        """Determina si el año es bisiesto.

        Un año es bisiesto si:
        - Es divisible por 4 Y
        - No es divisible por 100 O es divisible por 400

        Returns:
            bool: True si el año es bisiesto
        """
        # TODO: Implementar lógica de año bisiesto
        # Regla: (anno % 4 == 0 and anno % 100 != 0) or (anno % 400 == 0)
        pass

    def dias_en_mes(self):
        """Retorna cuántos días tiene el mes.

        Returns:
            int: Número de días (28, 29, 30 o 31)
        """
        # TODO: Casos especiales:
        #   - Febrero: 29 si es bisiesto, 28 si no
        #   - Meses con 31 días: 1, 3, 5, 7, 8, 10, 12
        #   - Meses con 30 días: 4, 6, 9, 11
        pass

    def es_valida(self):
        """Valida que la fecha sea correcta.

        Returns:
            bool: True si la fecha es válida
        """
        # TODO: Validar:
        #   - anno >= 1
        #   - mes entre 1 y 12
        #   - dia entre 1 y dias_en_mes() para ese mes/año
        pass

    def __str__(self):
        """Representación en string de la fecha.

        Returns:
            str: Formato "DD/MM/AAAA"
        """
        # TODO: Retornar string formateado
        # Nota: Usa f"{self.dia:02d}/{self.mes:02d}/{self.anno:04d}"
        # para asegurar formato con ceros a la izquierda
        pass

    def __eq__(self, otra):
        """Compara si dos fechas son iguales.

        Args:
            otra (Fecha): Otra fecha a comparar

        Returns:
            bool: True si tienen el mismo día, mes y año
        """
        # TODO: Validar que otra sea instancia de Fecha
        # TODO: Comparar día, mes y año
        pass

    def __lt__(self, otra):
        """Compara si esta fecha es anterior a otra.

        Args:
            otra (Fecha): Otra fecha a comparar

        Returns:
            bool: True si esta fecha es anterior a otra
        """
        # TODO: Validar que otra sea instancia de Fecha
        # TODO: Comparar: primero año, luego mes, luego día
        pass


# ============================================================================
# FUNCIONES AUXILIARES ÚTILES (opcionales)
# ============================================================================

def dias_entre(fecha1, fecha2):
    """Calcula días entre dos fechas (solo como ejemplo).

    Nota: Esta es una simplificación. Para algo más preciso,
    considera usar la librería datetime estándar.
    """
    pass


# ============================================================================
# PRUEBAS (descomenta para verificar tu implementación)
# ============================================================================

if __name__ == "__main__":
    print("=== Pruebas Ejercicio 4: Clase Fecha ===\n")

    # Prueba 1: Crear fechas válidas
    print("Prueba 1: Crear fechas válidas")
    f1 = Fecha(15, 3, 2024)
    f2 = Fecha(20, 3, 2024)
    f3 = Fecha(29, 2, 2024)  # 2024 es bisiesto
    print(f"Fecha 1: {f1}")  # 15/03/2024
    print(f"Fecha 2: {f2}")  # 20/03/2024
    print(f"Fecha 3: {f3}")  # 29/02/2024
    print()

    # Prueba 2: Años bisiestos
    print("Prueba 2: Años bisiestos")
    print(f"¿2024 es bisiesto? {f1.es_bisiesto()}")  # True
    print(f"¿2023 es bisiesto? {Fecha(1, 1, 2023).es_bisiesto()}")  # False
    print(f"¿2000 es bisiesto? {Fecha(1, 1, 2000).es_bisiesto()}")  # True
    print(f"¿1900 es bisiesto? {Fecha(1, 1, 1900).es_bisiesto()}")  # False
    print()

    # Prueba 3: Días en mes
    print("Prueba 3: Días en mes")
    print(f"Febrero 2024 (bisiesto): {Fecha(1, 2, 2024).dias_en_mes()} días")  # 29
    print(f"Febrero 2023 (no bisiesto): {Fecha(1, 2, 2023).dias_en_mes()} días")  # 28
    print(f"Marzo: {Fecha(1, 3, 2024).dias_en_mes()} días")  # 31
    print()

    # Prueba 4: Comparaciones
    print("Prueba 4: Comparaciones")
    print(f"¿{f1} == {f2}? {f1 == f2}")  # False
    f4 = Fecha(15, 3, 2024)
    print(f"¿{f1} == {f4}? {f1 == f4}")  # True
    print(f"¿{f1} < {f2}? {f1 < f2}")  # True
    print(f"¿{f2} < {f1}? {f2 < f1}")  # False
    print()

    # Prueba 5: Fechas inválidas
    print("Prueba 5: Fechas inválidas")
    try:
        f_invalida = Fecha(30, 2, 2024)  # Febrero no tiene 30 días
    except ValueError as e:
        print(f"Error esperado: {e}")

    try:
        f_invalida = Fecha(31, 4, 2024)  # Abril solo tiene 30 días
    except ValueError as e:
        print(f"Error esperado: {e}")

    try:
        f_invalida = Fecha(0, 1, 2024)  # Día 0 no existe
    except ValueError as e:
        print(f"Error esperado: {e}")

    try:
        f_invalida = Fecha(15, 13, 2024)  # Mes 13 no existe
    except ValueError as e:
        print(f"Error esperado: {e}")

    try:
        f_invalida = Fecha(15, 3, 0)  # Año 0 no válido
    except ValueError as e:
        print(f"Error esperado: {e}")
    print()

    # Prueba 6: Casos especiales
    print("Prueba 6: Casos especiales")
    inicio_año = Fecha(1, 1, 2024)
    fin_año = Fecha(31, 12, 2024)
    print(f"Inicio de año: {inicio_año}")
    print(f"Fin de año: {fin_año}")
    print(f"¿{inicio_año} < {fin_año}? {inicio_año < fin_año}")  # True
