#ifndef CONTENEDORES_H
#define CONTENEDORES_H
#define CODIGO 5
#define TIPO 50
#define BAHIA 10

typedef struct {
    char codigo[CODIGO];
    char tipo[TIPO];
    float peso;
    char bahia[BAHIA]; 
} contenedores;

int validarCodigo(char codigo[]);
void registrarContenedor(contenedores *Contenedor);
void mostrarContenedor(contenedores *Contenedor);
#endif
