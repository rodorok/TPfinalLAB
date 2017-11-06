#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

void inicReferencia(Fila* fila)
{
    fila->cabecera=NULL;
    fila->cola=NULL;
}

nodo2* crearNodo(persona a)
{
    nodo2 * aux= (nodo2*)malloc(sizeof(nodo2));
    strcpy(aux->apellido,a.apellido);///asignamos los valores de p a aux
    aux->tipoCliente=a.tipoCliente;
    aux->medioPago=a.medioPago;
    aux->cantArticulos=a.cantArticulos;
    aux->tiempoEspera=0;
    aux->tiempoProcesado=0;
    aux->eliminado=a.eliminado;
    aux->anterior=NULL;
    aux->siguiente=NULL;
    return aux;
}

void mostrarFila(Fila* fila)
{
    nodo2* aux=fila->cabecera;
    printf("\n\nPrincipio...\n");
    while(aux!=NULL)
    {
        printf("\n\nApellido:%s \nMedio de Pago: %d \nCantidad de Articulos: %d ", aux->apellido,aux->medioPago,aux->cantArticulos);

        aux=aux->siguiente;
    }
    printf("\n\nFINAL...");
    printf("\n");
}
// sin uso!
void agregaPpio(Fila* fila, nodo2* nuevo)
{
    if(fila->cabecera==NULL)
    {
        fila->cabecera=nuevo;
        fila->cola=nuevo;
    }
    else
    {
        nodo2* seg=fila->cabecera;
        nuevo->siguiente=seg;
        seg->anterior=nuevo;
        fila->cabecera=nuevo;
    }
}

void agregaFinalF(Fila* fila, nodo2* nuevo)
{
    if(fila->cabecera==NULL)
    {
        fila->cabecera=nuevo;
        fila->cola=nuevo;
    }
    else
    {
        nodo2* cola=fila->cola;
        cola->siguiente =  nuevo;
        nuevo->anterior=cola;
        fila->cola=nuevo;
    }
}

void extraer(Fila* fila)
{
    int resp;
    if(fila->cabecera!=NULL)
    {
        nodo2* aux=fila->cabecera;
        nodo2* sig=aux->siguiente;
        if(fila->cabecera!=fila->cola)
        {
            sig->anterior=NULL;
        }
        else
        {
            fila->cabecera=NULL;
        }
        fila->cabecera=sig;

        free(aux);
    }

}

void leerFila(Fila* fila)
{
    persona aux1;
    printf("Ingrese apellido:");
    scanf("%s", &aux1.apellido);
    printf("\ningrese cant Articulos:");
    scanf("%d", &aux1.cantArticulos);
    printf("\nIngrese medio de pago");
    scanf("%d",&aux1.medioPago);
    nodo2 * aux = crearNodo(aux1);
    agregaFinalF(fila,aux);
}



int filaVacia(Fila* fila)
{
    int resp=0;
    if(fila->cabecera==NULL)
        resp=1;
    return resp;
}
