
#include <stdio.h>
#include <string.h>
#include "ordenamiento.h"


void registrarContenedor(contenedores *Contenedor) {
    printf("Ingrese el codigo del contenedor (4 caracteres): ");
    scanf("%4s", Contenedor->codigo);

    printf("Ingrese el peso en toneladas: ");
    scanf("%f", &Contenedor->peso);

    printf("Ingrese el tipo de mercancia: ");
    scanf(" %49[^\n]", Contenedor->tipo);

    printf("Ingrese la bahia asignada: ");
    scanf(" %9s", Contenedor->bahia);
}

void mostrarContenedor(contenedores *Contenedor) {
    printf("Codigo: %s\n", Contenedor->codigo);
    printf("Peso: %.2f toneladas\n", Contenedor->peso);
    printf("Tipo de mercancia: %s\n", Contenedor->tipo);
    printf("Bahia: %s\n", Contenedor->bahia);
}
