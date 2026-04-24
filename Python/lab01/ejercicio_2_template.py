"""
ejercicio_2_template.py
Ejercicio 2: Implementar la clase Estudiante

Requisitos:
- Atributos: nombre (str), carrera (str), _calificaciones (list)
- Métodos: __init__, agregar_calificacion, promedio, aprobo, __str__, __eq__
- Validaciones: calificaciones entre 1.0 y 7.0
"""


class Estudiante:
    """Representa un estudiante con calificaciones."""

    def __init__(self, nombre, carrera):
        """Constructor de la clase Estudiante.

        Args:
            nombre (str): Nombre del estudiante
            carrera (str): Carrera del estudiante
        """
        # TODO: Asignar self.nombre y self.carrera
        # TODO: Inicializar self._calificaciones como lista vacía
        pass

    def agregar_calificacion(self, nota):
        """Añade una calificación a la lista.

        Args:
            nota (float): Calificación a agregar (debe estar entre 1.0 y 7.0)

        Raises:
            ValueError: Si nota < 1.0 o nota > 7.0
        """
        # TODO: Validar que 1.0 <= nota <= 7.0
        # TODO: Agregar nota a self._calificaciones
        pass

    def promedio(self):
        """Calcula el promedio de calificaciones.

        Returns:
            float: Promedio (o 0 si no hay calificaciones)
        """
        # TODO: Si no hay calificaciones, retornar 0
        # TODO: Calcular y retornar el promedio
        pass

    def aprobo(self):
        """Indica si el estudiante aprobó (promedio >= 4.0).

        Returns:
            bool: True si promedio >= 4.0, False en caso contrario
        """
        # TODO: Retornar True si promedio >= 4.0, False si no
        pass

    def __str__(self):
        """Representación en string del estudiante.

        Returns:
            str: Formato "[nombre] ([carrera]) - Promedio: [promedio formateado a 2 decimales]"
        """
        # TODO: Retornar string con formato
        # Nota: Usa f"{self.promedio():.2f}" para formatear a 2 decimales
        pass

    def __eq__(self, otro):
        """Compara dos estudiantes por nombre y carrera.

        Args:
            otro (Estudiante): Otro estudiante a comparar

        Returns:
            bool: True si tienen igual nombre y carrera
        """
        # TODO: Validar que otro sea instancia de Estudiante
        # TODO: Comparar nombre y carrera
        pass


# ============================================================================
# PRUEBAS (descomenta para verificar tu implementación)
# ============================================================================

if __name__ == "__main__":
    print("=== Pruebas Ejercicio 2: Clase Estudiante ===\n")

    # Prueba 1: Crear estudiante y agregar calificaciones
    print("Prueba 1: Crear estudiante")
    est = Estudiante("Maria", "Ingeniería en Computación")
    est.agregar_calificacion(6.5)
    est.agregar_calificacion(7.0)
    est.agregar_calificacion(5.5)
    print(f"Promedio: {est.promedio():.2f}")  # 6.33
    print(est)  # Maria (Ingeniería en Computación) - Promedio: 6.33
    print()

    # Prueba 2: Verificar aprobación
    print("Prueba 2: Verificar aprobación")
    print(f"¿Aprobó? {est.aprobo()}")  # True
    print()

    # Prueba 3: Estudiante que no aprueba
    print("Prueba 3: Estudiante con bajo promedio")
    est2 = Estudiante("Carlos", "Ingeniería Comercial")
    est2.agregar_calificacion(3.0)
    est2.agregar_calificacion(3.5)
    print(f"Promedio: {est2.promedio():.2f}")  # 3.25
    print(f"¿Aprobó? {est2.aprobo()}")  # False
    print()

    # Prueba 4: Comparación
    print("Prueba 4: Comparación")
    est3 = Estudiante("Maria", "Ingeniería en Computación")
    print(f"¿est == est3? {est == est3}")  # True (mismo nombre y carrera)
    print(f"¿est == est2? {est == est2}")  # False (diferente)
    print()

    # Prueba 5: Validaciones
    print("Prueba 5: Validaciones")
    try:
        est.agregar_calificacion(8.0)  # Error: nota > 7.0
    except ValueError as e:
        print(f"Error esperado: {e}")

    try:
        est.agregar_calificacion(0.5)  # Error: nota < 1.0
    except ValueError as e:
        print(f"Error esperado: {e}")
