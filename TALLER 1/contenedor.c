#include <stdio.h>
#include "contenedor.h"

void inicializarContenedor(Contenedor *contenedor) {
 contenedor->codigo[0] = '\0';
 contenedor->peso = 0;
 contenedor->tipo[0] = '\0';
}

int validarCodigo(const char *codigo) {
    int i;

    for (i = 0; i < 4; i++) {
        if (codigo[i] == '\0') {
            return 0;
        }
    }

      if (codigo[4] != '\0') {
        return 0;
    }

    return 1;
}

 void mostrarContenedor(Contenedor contenedor) {
    printf("Codigo: %s\n", contenedor.codigo);
    printf("Peso: %.2f toneladas\n", contenedor.peso);
    printf("Tipo de carga:%s\n", contenedor.tipo);

}

 




