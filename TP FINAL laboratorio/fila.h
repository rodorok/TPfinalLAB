#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include "cliente.h"
#include "lista.h"
typedef struct{
    persona filita;
    struct cajero * siguiente;
    struct cajero * anterior;
}fila_caja;

typedef struct{
    struct caja * cabecera;
    struct caja * cola;
}fila;

void inicReferencia(fila* fila);
nodo* crearNodo(int dato);
void mostrarFila(fila* fila);
void agregaPpio(fila* fila, nodo* nuevo);
int extraer(fila* fila);
void leerFila(fila* fila);
int primero(fila* fila);
int filaVacia(fila* fila);
int capicuaRecursivo(nodo * cabeza, nodo * cola);


#endif // FILA_H_INCLUDED
