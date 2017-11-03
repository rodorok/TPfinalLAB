#ifndef CAJA_H_INCLUDED
#define CAJA_H_INCLUDED
#include "fila.h"
///Estructura de caja

typedef struct{
    int nro_de_caja;
    char nombreCajero[40];
    int tipo_pago;                 //  1 efectivo, 2 crédito o débito, 3 todos
    int abiertaOcerrada;
    char algoritmoPlanificacion[30];  // debe informar que tipo de alg. de planificación utiliza la caja
    Fila filita ;
}caja;

///Funciones caja

caja abrirOcerrarCaja (caja c);
caja buscarCaja(caja A[], int buscar);
void agregarCajas(caja c[], int val);
void datosCajas(caja c[], int val);
void arrayAarchi(caja c[], int val,char archivoCaja[]);
void mostrarArchivoCaja (char archivoCaja[]);



#endif // CAJA_H_INCLUDED

