#include <stdio.h>
#include "ordenamiento.h"

void ordenarBurbuja(contenedores *Contenedor, int cantidad, int ascendente) {
    int i, j;
    contenedores auxiliar;

    for (i = 0; i < cantidad - 1; i++) {
        for (j = 0; j < cantidad - 1 - i; j++) {
            if (ascendente == 1) {
                if (Contenedor[j].peso > Contenedor[j + 1].peso) {
                    auxiliar = Contenedor[j];
                    Contenedor[j] = Contenedor[j + 1];
                    Contenedor[j + 1] = auxiliar;
                }
            } else {
                if (Contenedor[j].peso < Contenedor[j + 1].peso) {
                    auxiliar = Contenedor[j];
                    Contenedor[j] = Contenedor[j + 1];
                    Contenedor[j + 1] = auxiliar;
                }
            }
        }
    }
}


void ordenarSeleccion(contenedores *Contenedor, int cantidad, int ascendente) {
    int i, j, posicion;
    contenedores auxiliar;

    for (i = 0; i < cantidad - 1; i++) {
        posicion = i;

        for (j = i + 1; j < cantidad; j++) {
            if (ascendente == 1) {
                if (Contenedor[j].peso < Contenedor[posicion].peso) {
                    posicion = j;
                }
            } else {
                if (Contenedor[j].peso > Contenedor[posicion].peso) {
                    posicion = j;
                }
            }
        }

        if (posicion != i) {
            auxiliar = Contenedor[i];
            Contenedor[i] = Contenedor[posicion];
            Contenedor[posicion] = auxiliar;
        }
    }
}
 

void ordenarInsercion(contenedores *Contenedor, int cantidad, int ascendente) {
    int i, j;
    contenedores auxiliar;

    for (i = 1; i < cantidad; i++) {
        auxiliar = Contenedor[i];
        j = i - 1;

        if (ascendente == 1) {
            while (j >= 0 && Contenedor[j].peso > auxiliar.peso) {
                Contenedor[j + 1] = Contenedor[j];
                j--;
            }
        } else {
            while (j >= 0 && Contenedor[j].peso < auxiliar.peso) {
                Contenedor[j + 1] = Contenedor[j];
                j--;
            }
        }

        Contenedor[j + 1] = auxiliar;
    }
}

