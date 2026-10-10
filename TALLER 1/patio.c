
#include <stdio.h>
#include "patio.h"

void inicializarPatio(patio *patio) {
    patio->cantidad = 0;
}

int patioLleno(patio *patio) {
    return patio->cantidad == CAPACIDAD;
}

int patioVacio(patio *patio) {
    return patio->cantidad == 0;
}

int ingresarContenedor(patio *patio, Contenedor contenedor) {
    if (patioLleno(patio)) {
        return 0;
    }

    patio->contenedores[patio->cantidad] = contenedor;
    patio->cantidad++;

    return 1;
}

void mostrarPatio(patio *patio) {
    int i;

    if (patioVacio(patio)) {
        printf("El patio esta vacio.\n");
        return;
    }

    for (i = patio->cantidad - 1; i >= 0; i--) {
        printf("\n--- Contenedor ---\n");
        mostrarContenedor(patio->contenedores[i]);
    }
}

int buscarContenedor(patio *patio, const char *codigo) {
    int i;
    int j;
    int iguales;

    for (i = 0; i < patio->cantidad; i++) {
        iguales = 1;

        for (j = 0; j < 4; j++) {
            if (patio->contenedores[i].codigo[j] != codigo[j]) {
                iguales = 0;
                break;
            }
        }

        if (iguales == 1) {
            return i;
        }
    }

    return -1;
}

int retirarContenedor(patio *patio) {
    if (patioVacio(patio)) {
        return 0;
    }

    patio->cantidad--;

    return 1;
}
