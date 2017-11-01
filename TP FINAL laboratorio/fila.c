#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

void inicFila(fila * filita){
    filita->cabecera=NULL;
    filita->cola=NULL;
}

/*caja* crearNodo(caja * cajero)
{
    caja * aux=(caja*)malloc(sizeof(caja));

    aux->nro_de_caja = cajero.datos_caja.nro_de_caja;
    strcpy(aux->nombreCajero, cajero)

    aux->anterior = NULL;
    aux->siguiente = NULL;
    return aux;
}*/

void mostrarFila(fila* fila)
{
    nodo* aux=fila->cabecera;
    printf("\n");
    printf("Principio.......................................Final\n");
    while(aux!=NULL)
    {
        printf("[%d] ", aux->dato);
        aux=aux->siguiente;
    }
    printf("\nPrincipio.......................................Final\n");
}

// sin uso!
void agregaPpio(fila* fila, nodo* nuevo)
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

void agregaFinal(fila* fila, nodo* nuevo)
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

int extraer(fila* fila)
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
        resp=aux->dato;
        free(aux);
    }
    return resp;
}

void leerFila(fila* fila)
{
    int a;
    printf("Ingrese un valor:");
    scanf("%d", &a);
    nodo2 * aux = crearNodo(a);
    agregaFinal(fila,aux );
}

int primero(fila* fila)
{
    int resp;
    if(fila->cabecera!=NULL)
    {
        nodo2* aux=fila->cabecera;
        resp=aux->dato;
    }
    return resp;
}

int filaVacia(fila* fila)
{
    int resp=0;
    if(fila->cabecera==NULL)
        resp=1;
    return resp;
}

int capicuaRecursivo(nodo * cabeza, nodo * cola)
{
    int capicua =0;

    if(cabeza!=NULL && cola!=NULL)
    {
        if (cabeza==cola||cabeza->anterior==cola) // si llegue al centro de la fila.. par o impar
        {
            capicua=1;
        }
        else
        {
            if(cabeza->dato==cola->dato)
            {
                capicua = capicuaRecursivo(cabeza->siguiente, cola->anterior);
            }
            else
            {
                capicua=0;
            }
        }
    }
    return capicua;

}
