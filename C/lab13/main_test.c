/*
 * Estructuras de Datos - EIN423-B
 * Laboratorio 13: Hashing con Sondeo Abierto - PRUEBAS
 *
 * Pruebas unitarias para validar implementación.
 * El estudiante debe implementar las funciones en hash_abierto.c
 * hasta que todas las pruebas pasen.
 */

#include "hash_abierto.h"
#include <assert.h>

#define VERDE  "\x1b[32m"
#define ROJO   "\x1b[31m"
#define RESET  "\x1b[0m"

void test_crear_e_insertar() {
    printf("\n=== TEST 1: Crear e Insertar ===\n");

    TablaHashAbierta *tha = tha_crear(11);
    assert(tha != NULL);
    assert(tha->m == 11);
    assert(tha->n == 0);

    // Insertar elementos: 10, 22, 31, 4, 15, 28, 17, 88, 59
    int claves[] = {10, 22, 31, 4, 15, 28, 17, 88, 59};
    for (int i = 0; i < 9; i++) {
        int intentos = tha_insertar(tha, claves[i], claves[i] * 10);
        printf("Insertar %d requirió %d sondeos\n", claves[i], intentos);
        assert(intentos > 0);
    }

    printf("Tabla después de inserciones:\n");
    tha_imprimir(tha);

    printf(VERDE "✓ TEST 1 PASÓ\n" RESET);
    tha_destruir(tha);
}

void test_buscar() {
    printf("\n=== TEST 2: Buscar ===\n");

    TablaHashAbierta *tha = tha_crear(11);
    int claves[] = {10, 22, 31, 4, 15};

    for (int i = 0; i < 5; i++) {
        tha_insertar(tha, claves[i], claves[i] * 10);
    }

    // Buscar clave existente
    int valor;
    int encontrado = tha_buscar(tha, 22, &valor);
    assert(encontrado == 1);
    assert(valor == 220);
    printf("✓ tha_buscar(22) encontrado, valor=%d\n", valor);

    // Buscar clave inexistente
    encontrado = tha_buscar(tha, 100, &valor);
    assert(encontrado == 0);
    printf("✓ tha_buscar(100) no encontrado\n");

    printf(VERDE "✓ TEST 2 PASÓ\n" RESET);
    tha_destruir(tha);
}

void test_eliminar() {
    printf("\n=== TEST 3: Eliminar ===\n");

    TablaHashAbierta *tha = tha_crear(11);
    int claves[] = {10, 22, 31, 4, 15};

    for (int i = 0; i < 5; i++) {
        tha_insertar(tha, claves[i], claves[i] * 10);
    }

    int n_inicial = tha->n;

    // Eliminar elemento existente
    int resultado = tha_eliminar(tha, 22);
    assert(resultado == 1);
    assert(tha->n == n_inicial - 1);
    printf("✓ tha_eliminar(22) exitoso\n");

    // Verificar que ya no existe
    int valor;
    int encontrado = tha_buscar(tha, 22, &valor);
    assert(encontrado == 0);
    printf("✓ tha_buscar(22) después de eliminar retorna 0\n");

    // Intentar eliminar nuevamente
    resultado = tha_eliminar(tha, 22);
    assert(resultado == 0);
    printf("✓ tha_eliminar(22) nuevamente retorna 0\n");

    printf(VERDE "✓ TEST 3 PASÓ\n" RESET);
    tha_destruir(tha);
}

void test_sondeo_con_eliminado() {
    printf("\n=== TEST 4: Sondeo con Celda ELIMINADO ===\n");

    TablaHashAbierta *tha = tha_crear(11);

    // Insertar 22 en posición 0 (22 % 11 = 0)
    tha_insertar(tha, 22, 220);
    int valor;
    int encontrado = tha_buscar(tha, 22, &valor);
    assert(encontrado == 1);
    printf("✓ Insertar 22 exitoso\n");

    // Eliminar 22
    tha_eliminar(tha, 22);
    printf("✓ Eliminar 22 exitoso\n");

    // Insertar 33 (33 % 11 = 0, también hash en 0)
    // Debe usar la celda ELIMINADO sin interrumpir búsquedas futuras
    int intentos = tha_insertar(tha, 33, 330);
    printf("Insertar 33 requirió %d sondeos (ahora en posición 0 o próxima disponible)\n", intentos);

    // Verificar que 33 se encuentra
    encontrado = tha_buscar(tha, 33, &valor);
    assert(encontrado == 1);
    assert(valor == 330);
    printf("✓ tha_buscar(33) encontrado después de insertar en celda ELIMINADO\n");

    tha_imprimir(tha);

    printf(VERDE "✓ TEST 4 PASÓ\n" RESET);
    tha_destruir(tha);
}

void test_comparar_sondeos() {
    printf("\n=== TEST 5: Comparación de Métodos de Sondeo ===\n");

    printf("\nSondeo Lineal:\n");
    TablaHashAbierta *tha_lineal = tha_crear(11);
    int claves[] = {10, 22, 31, 4, 15, 28, 17, 88, 59};
    for (int i = 0; i < 9; i++) {
        int intentos = tha_insertar(tha_lineal, claves[i], claves[i] * 10);
        printf("  %d → %d sondeos\n", claves[i], intentos);
    }

    printf("\nTabla con Sondeo Lineal:\n");
    tha_imprimir(tha_lineal);

    printf(VERDE "✓ TEST 5 COMPLETADO\n" RESET);
    tha_destruir(tha_lineal);
}

int main() {
    printf("╔════════════════════════════════════════════════════════╗\n");
    printf("║  Estructuras de Datos - Lab 13: Hashing Sondeo Abierto ║\n");
    printf("║  EIN423-B - UTFSM                                       ║\n");
    printf("╚════════════════════════════════════════════════════════╝\n");

    test_crear_e_insertar();
    test_buscar();
    test_eliminar();
    test_sondeo_con_eliminado();
    test_comparar_sondeos();

    printf("\n╔════════════════════════════════════════════════════════╗\n");
    printf("║" VERDE "              TODOS LOS TESTS PASARON ✓              " RESET "║\n");
    printf("╚════════════════════════════════════════════════════════╝\n\n");

    return 0;
}
