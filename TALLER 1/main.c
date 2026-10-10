#include <stdio.h>
#include "patio.h"

int main() {
    patio patio;
    Contenedor contenedor;
    char codigo[5];
    int opcion;
    int posicion;

    inicializarPatio(&patio);

    do {
        printf("\n===== PATIO DE CONTENEDORES =====\n");
        printf("1. Ingresar contenedor\n");
        printf("2. Mostrar contenedores\n");
        printf("3. Buscar contenedor\n");
        printf("4. Retirar contenedor\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                if (patioLleno(&patio)) {
                    printf("El patio esta lleno. Capacidad maxima: 5.\n");
                    break;
                }

                printf("Ingrese el codigo (4 letras o numeros): ");
                scanf("%4s", contenedor.codigo);

                if (!validarCodigo(contenedor.codigo)) {
                    printf("Codigo invalido. Debe tener 4 caracteres alfanumericos.\n");
                    break;
                }

                if (buscarContenedor(&patio, contenedor.codigo) != -1) {
                    printf("Ya existe un contenedor con ese codigo.\n");
                    break;
                }

                printf("Ingrese el peso en toneladas: ");
                scanf("%f", &contenedor.peso);

                if (contenedor.peso <= 0) {
                    printf("El peso debe ser mayor que cero.\n");
                    break;
                }

                printf("Ingrese el tipo de carga (sin espacios): ");
                scanf("%49s", contenedor.tipo);

                if (ingresarContenedor(&patio, contenedor)) {
                    printf("Contenedor ingresado correctamente.\n");
                } else {
                    printf("No se pudo ingresar el contenedor.\n");
                }
                break;

            case 2:
                mostrarPatio(&patio);
                break;

            case 3:
                printf("Ingrese el codigo que desea buscar: ");
                scanf("%4s", codigo);

                posicion = buscarContenedor(&patio, codigo);

                if (posicion != -1) {
                    printf("Contenedor encontrado:\n");
                    mostrarContenedor(patio.contenedores[posicion]);
                } else {
                    printf("No se encontro el contenedor.\n");
                }
                break;

            case 4:
                if (retirarContenedor(&patio)) {
                    printf("Se retiro el ultimo contenedor ingresado.\n");
                } else {
                    printf("El patio esta vacio. No hay contenedores para retirar.\n");
                }
                break;

            case 5:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opcion invalida. Intente de nuevo.\n");
        }

    } while (opcion != 5);

    return 0;
}