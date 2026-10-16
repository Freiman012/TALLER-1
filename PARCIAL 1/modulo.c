
#include <stdio.h>
#include "contenedores.h"
#include "ordenamiento.h"

#define CAPACIDAD 5
contenedores Contenedor[CAPACIDAD];
int main() {

    int cantidad = 0;
    int opcion;
    int ascendente;
    int i;
    int algoritmo;



    do {
        printf("\n===== PATIO DE CONTENEDORES =====\n");
        printf("1. Registrar contenedor\n");
        printf("2. Mostrar contenedores\n");
        printf("3. Ordenar contenedores por peso\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                if (cantidad < CAPACIDAD) {
                    registrarContenedor(&Contenedor[cantidad]);
                    cantidad++;
                    printf("Contenedor registrado correctamente.\n");
                } else {
                    printf("La zona esta llena. Solo se permiten 5 contenedores.\n");
                }
                break;

            case 2:
                if (cantidad == 0) {
                    printf("No hay contenedores registrados.\n");
                } else {
                    for (i = 0; i < cantidad; i++) {
                        printf("\nContenedor numero %d\n", i + 1);
                        mostrarContenedor(&Contenedor[i]);
                    }
                }
                break;

            case 3:
                if (cantidad < 2) {
                    printf("Registre al menos 2 contenedores para ordenarlos.\n");
                } else {
                    printf("\nSeleccione el algoritmo:\n");
                    printf("1. Bubble Sort\n");
                    printf("2. Selection Sort\n");
                    printf("3. Insertion Sort\n");
                    printf("Opcion: ");
                    scanf("%d", &algoritmo);

                    printf("\nOrden deseado:\n");
                    printf("1. Menor a mayor\n");
                    printf("0. Mayor a menor\n");
                    printf("Opcion: ");
                    scanf("%d", &ascendente);

                    if (ascendente != 0 && ascendente != 1) {
                        printf("Opcion de orden no valida.\n");
                        break;
                    }

                    switch (algoritmo) {
                        case 1:
                           ordenarBurbuja(Contenedor, cantidad, ascendente);
                            break;

                        case 2:
                           ordenarSeleccion(Contenedor, cantidad, ascendente);
                            break;

                        case 3:
                            ordenarInsercion(Contenedor, cantidad, ascendente);
                            break;

                        default:
                            printf("Algoritmo no valido.\n");
                            break;
                    }

                    if (algoritmo >= 1 && algoritmo <= 3) {
                        printf("\nContenedores ordenados:\n");
                        for (i = 0; i < cantidad; i++) {
                            mostrarContenedor(&Contenedor[i]);
                        }
                    }
                }
                break;

            case 4:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opcion no valida. Intente de nuevo.\n");
        }

    } while (opcion != 4);

    return 0;
}
