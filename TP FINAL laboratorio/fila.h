#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
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

typedef struct {
        int id;
        char apellido[30];
        int tipoCliente; 		/// Prioridad 1:embarazada, 2:jubilado y 3:persiente común
        int medioPago;		    /// 1:efectivo, 2:crédito y 3:todos
        int cantArticulos;		/// es el tiempo de ejecución
        int tiempoEspera;		/// es el tiempo de respuesta
        int tiempoProcesado;	/// es el tiempo que ya fue procesado en la línea de caja
        int eliminado;
} persona;

void inicReferencia(Fila* fila);
nodo2* crearNodo(persona a);
void mostrarFila(Fila* fila);
void agregaPpio(Fila* fila, nodo2* nuevo);
void extraer(Fila* fila);
void leerFila(Fila* fila);
int primero(Fila* fila);
int filaVacia(Fila* fila);
void agregaFinal(Fila* fila, nodo2* nuevo);



#endif // FILA_H_INCLUDED
