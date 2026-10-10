#ifndef PATIO_H
#define PATIO_H
#include "contenedor.h"
#define CAPACIDAD 5

 typedef struct {
 Contenedor contenedores[CAPACIDAD];
 int cantidad;
 } patio;

 void inicializar_patio(patio *patio);
 int patioLleno(patio *patio);
 int patioVacio(patio *patio);
 int ingresarContenedor(patio *patio, Contenedor contenedor);
 void mostrarPatio(patio *patio);
 int buscarContenedor(patio *patio, const char *codigo);
 int retirarContenedor(patio *patio);

#endif