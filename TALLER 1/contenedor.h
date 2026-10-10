#ifndef CONTENEDORES_H
#define CONTENEDORES_H
#define CODIGO 5
#define TIPO 50

typedef struct {

char codigo [CODIGO];
char tipo [TIPO];
float peso;
}Contenedor;

void inicializarContenedor(Contenedor *contenedor);
void mostrarContenedor(Contenedor contenedor);
int validarCodigo(const char *codigo);

#endif









