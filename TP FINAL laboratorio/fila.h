#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

typedef struct{
    int nro_de_caja;
    char nombreCajero[40];
    int tipo_pago;                 //  1 efectivo, 2 crédito o débito, 3 todos
    int abiertaOcerrada;
    char algoritmoPlanificacion[30];  // debe informar que tipo de alg. de planificación utiliza la caja
    Fila filita ;
}caja;

typedef struct nodo{
    caja datos_caja;
    struct cajero * siguiente;
    struct cajero * anterior;
} cajero;

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
