#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include "cliente.h"

typedef struct
{
    char apellido[10];
    int tipoCliente;
    int medioPago;
    int cantArticulos;
    int tiempoEspera;
    int tiempoProcesado;
    int eliminado;
    struct nodo2* siguiente;
    struct nodo2* anterior;
} nodo2;

typedef struct
{
    struct nodo2* cabecera;
    struct nodo2* cola;
} Fila;

void inicFila(Fila* fila);
nodo2* crearNodo(persona a);
void mostrarFila(Fila* fila);
void agregaPpio(Fila* fila, nodo2* nuevo);
void extraer(Fila* fila);
void leerFila(Fila* fila);
int primero(Fila* fila);
int filaVacia(Fila* fila);
void agregaFinalF(Fila* fila, nodo2* nuevo);



#endif // FILA_H_INCLUDED
