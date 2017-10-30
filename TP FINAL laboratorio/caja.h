#ifndef CAJA_H_INCLUDED
#define CAJA_H_INCLUDED

///Estructura de caja

typedef struct{
    int nro_de_caja;
    char nombreCajero[40];
    int tipo_pago;                 //  1 efectivo, 2 cr�dito o d�bito, 3 todos
    int abiertaOcerrada;
    char algoritmoPlanificacion[30];  // debe informar que tipo de alg. de planificaci�n utiliza la caja
    Fila filita ;
}cajas;


#endif // CAJA_H_INCLUDED
