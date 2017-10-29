#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
typedef struct
{
    int dato;
    struct nodo2* siguiente;
    struct nodo2* anterior;
} nodo2;

typedef struct
{
    struct nodo2* cabecera;
    struct nodo2* cola;
} Referencia;

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
