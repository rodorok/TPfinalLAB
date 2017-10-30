#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

typedef struct{
    persona filita;
    struct cajero * siguiente;
    struct cajero * anterior;
}fila_caja;

typedef struct{
    struct caja * cabecera;
    struct caja * cola;
}fila;

void inicReferencia(Referencia* fila);
nodo2* crearNodo(int dato);
void mostrarFila(Referencia* fila);
void agregaPpio(Referencia* fila, nodo2* nuevo);
int extraer(Referencia* fila);
void leerFila(Referencia* fila);
int primero(Referencia* fila);
int filaVacia(Referencia* fila);
int capicuaRecursivo(nodo2 * cabeza, nodo2 * cola);


#endif // FILA_H_INCLUDED
