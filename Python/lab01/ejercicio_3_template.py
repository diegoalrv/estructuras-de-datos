"""
ejercicio_3_template.py
Ejercicio 3: Implementar la clase Inventario

Requisitos:
- Atributos: _productos (dict con producto: cantidad)
- Métodos: __init__, agregar_producto, quitar_producto, obtener_cantidad,
           productos_disponibles, vaciar, __str__, __len__
- Validaciones: cantidad > 0, producto existe al quitar
"""


class Inventario:
    """Administra un inventario de productos."""

    def __init__(self):
        """Constructor de la clase Inventario.

        Inicializa un inventario vacío.
        """
        # TODO: Inicializar self._productos como diccionario vacío
        pass

    def agregar_producto(self, nombre, cantidad):
        """Añade o actualiza un producto en el inventario.

        Args:
            nombre (str): Nombre del producto
            cantidad (int): Cantidad a agregar (debe ser > 0)

        Raises:
            ValueError: Si cantidad <= 0
        """
        # TODO: Validar que cantidad > 0
        # TODO: Si el producto ya existe, sumar la cantidad
        # TODO: Si no existe, crear entrada nueva
        pass

    def quitar_producto(self, nombre, cantidad):
        """Reduce la cantidad de un producto.

        Args:
            nombre (str): Nombre del producto
            cantidad (int): Cantidad a quitar (debe ser > 0)

        Raises:
            ValueError: Si cantidad <= 0
            KeyError: Si el producto no existe
            ValueError: Si cantidad > cantidad disponible
        """
        # TODO: Validar que cantidad > 0
        # TODO: Validar que el producto existe (KeyError si no)
        # TODO: Validar que cantidad <= cantidad disponible
        # TODO: Si después de quitar la cantidad es 0, eliminar el producto
        # TODO: Si no es 0, actualizar la cantidad
        pass

    def obtener_cantidad(self, nombre):
        """Retorna la cantidad de un producto.

        Args:
            nombre (str): Nombre del producto

        Returns:
            int: Cantidad disponible (0 si no existe)
        """
        # TODO: Retornar la cantidad o 0 si no existe
        pass

    def productos_disponibles(self):
        """Retorna una lista de productos en stock.

        Returns:
            list: Lista de nombres de productos
        """
        # TODO: Retornar lista de claves del diccionario
        pass

    def vaciar(self):
        """Vacía completamente el inventario."""
        # TODO: Limpiar self._productos
        pass

    def __len__(self):
        """Retorna la cantidad total de unidades.

        Returns:
            int: Suma de todas las cantidades
        """
        # TODO: Sumar todas las cantidades en el diccionario
        pass

    def __str__(self):
        """Representación en string del inventario.

        Returns:
            str: Formato "Inventario: Producto1 (cant1), Producto2 (cant2), ..."
        """
        # TODO: Crear string con todos los productos y cantidades
        # Nota: Si está vacío, retornar "Inventario: vacío"
        pass


# ============================================================================
# PRUEBAS (descomenta para verificar tu implementación)
# ============================================================================

if __name__ == "__main__":
    print("=== Pruebas Ejercicio 3: Clase Inventario ===\n")

    # Prueba 1: Crear inventario y agregar productos
    print("Prueba 1: Agregar productos")
    inv = Inventario()
    inv.agregar_producto("Laptop", 5)
    inv.agregar_producto("Mouse", 20)
    inv.agregar_producto("Teclado", 15)
    print(inv)  # Inventario: Laptop (5), Mouse (20), Teclado (15)
    print(f"Total de unidades: {len(inv)}")  # 40
    print()

    # Prueba 2: Obtener cantidad
    print("Prueba 2: Obtener cantidades")
    print(f"Laptops disponibles: {inv.obtener_cantidad('Laptop')}")  # 5
    print(f"Monitores disponibles: {inv.obtener_cantidad('Monitor')}")  # 0 (no existe)
    print()

    # Prueba 3: Productos disponibles
    print("Prueba 3: Productos disponibles")
    print(f"Productos: {inv.productos_disponibles()}")
    print()

    # Prueba 4: Quitar productos
    print("Prueba 4: Quitar productos")
    inv.quitar_producto("Mouse", 3)
    print(f"Después de quitar 3 Mouse: {inv.obtener_cantidad('Mouse')}")  # 17
    print(f"Total de unidades: {len(inv)}")  # 37
    print(inv)
    print()

    # Prueba 5: Agregar más del mismo producto
    print("Prueba 5: Agregar más del mismo producto")
    inv.agregar_producto("Mouse", 10)
    print(f"Mouse después de agregar 10 más: {inv.obtener_cantidad('Mouse')}")  # 27
    print(f"Total de unidades: {len(inv)}")  # 47
    print()

    # Prueba 6: Vaciar inventario
    print("Prueba 6: Vaciar inventario")
    inv.vaciar()
    print(inv)  # Inventario: vacío
    print(f"Total de unidades: {len(inv)}")  # 0
    print()

    # Prueba 7: Validaciones
    print("Prueba 7: Validaciones")
    inv2 = Inventario()
    inv2.agregar_producto("Phone", 10)

    try:
        inv2.agregar_producto("Tablet", -5)  # Error: cantidad negativa
    except ValueError as e:
        print(f"Error esperado: {e}")

    try:
        inv2.quitar_producto("Phone", 20)  # Error: cantidad insuficiente
    except ValueError as e:
        print(f"Error esperado: {e}")

    try:
        inv2.quitar_producto("Camera", 5)  # Error: producto no existe
    except KeyError as e:
        print(f"Error esperado: Producto no existe")
