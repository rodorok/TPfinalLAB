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
    Fila * filita ;
}caja;

///Funciones caja

caja abrirOcerrarCaja (caja c);
caja buscarCaja(caja c[], int buscar);
void agregarCajas(caja c[], int val, char archivoCaja[]);
void arrayAarchi(caja c[], int val,char archivoCaja[]);
void mostrarArchivoCaja (char archivoCaja[]);
void mostrarCaja(caja c);
int ArchivoACajas(char archivoCajas[], caja c[]);
int contarClientesCaja(caja c);
int contarClientesCaja(caja c);
int cajasMenorClientela (caja  c[], int tipoPago);




#endif // CAJA_H_INCLUDED

