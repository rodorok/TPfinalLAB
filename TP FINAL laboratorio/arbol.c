#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbol.h"
#include "fila.h"
#include "cliente.h"

nodoArbol * inicArbol(){
    return NULL;
}

nodoArbol * crearNodoArbol(persona a){
    nodoArbol * aux = (nodoArbol *) malloc(sizeof(nodoArbol));

   strcpy(aux->p.apellido,a.apellido);///asignamos los valores de p a aux
    aux->p.tipoCliente=a.tipoCliente;
    aux->p.medioPago=a.medioPago;
    aux->p.cantArticulos=a.cantArticulos;
    aux->p.tiempoEspera=0;
    aux->p.tiempoProcesado=0;
    aux->p.eliminado=a.eliminado;

    aux->izq=NULL;
    aux->der=NULL;

    return aux;
}

nodoArbol * insertar(nodoArbol * arbol, persona a){
    if(arbol==NULL){
        arbol = crearNodoArbol(a);
    }
    else{
        if(a.id > arbol->p.id)
            {
            arbol->der = insertar(arbol->der, a);
            }
        else{
            arbol->izq = insertar(arbol->izq, a);
            }
        }

    return arbol;
}

void preorder(nodoArbol * arbol){
    if(arbol != NULL){
        printf("\n%s ", arbol->p.apellido);

        preorder(arbol->izq);
        preorder(arbol->der);
    }
}
void agregarpreorder(nodoArbol * arbol, Fila* filita){
    if(arbol != NULL){
        persona aux=arbol->p;
        nodo2*auxlista=crearNodo(aux);
        agregaFinalF(filita,auxlista);
        agregarpreorder(arbol->izq,filita);
        agregarpreorder(arbol->der,filita);
    }
}

void inorder(nodoArbol * arbol){
    if(arbol != NULL){

        inorder(arbol->izq);
        printf("\n%s ", arbol->p.apellido);
        inorder(arbol->der);

    }
}
void agregarinorder(nodoArbol * arbol,Fila * filita){

    if(arbol != NULL){

        persona aux=arbol->p;
        nodo2*auxlista=crearNodo(aux);
        agregarinorder(arbol->izq,filita);
        agregaFinalF(filita,auxlista);
        agregarinorder(arbol->der,filita);

    }
}

void postorder(nodoArbol * arbol){
    if(arbol != NULL){
        postorder(arbol->izq);
        postorder(arbol->der);
        printf("\n%s ", arbol->p.apellido);

    }
}
void agregarpostorder(nodoArbol * arbol,Fila * filita){
    if(arbol != NULL){
        agregarpostorder(arbol->izq,filita);
        agregarpostorder(arbol->der,filita);
         persona aux=arbol->p;
        nodo2*auxlista=crearNodo(aux);
        agregaFinalF(filita,auxlista);

    }
}

nodoArbol * buscar(nodoArbol * arbol, char nombre[10])
{
    nodoArbol * rta=NULL;
    if(arbol!=NULL)
    {
        if(strcmp(nombre,arbol->p.apellido) == 0)
        {
            rta = arbol;
        }
        else
        {
            if(nombre >arbol->p.apellido)
            {
                rta = buscar(arbol->der, nombre);
            }
            else
            {
                rta = buscar(arbol->izq, nombre);
            }
        }
    }
    return rta;
}

nodoArbol * archivoarbol(char nombre[],nodoArbol * arbol)
{
    persona aux;
    FILE * archi=fopen(nombre,"rb");
    if (archi==NULL)
    {
        printf("No se encontro el archivo\n");
    }
    else
    {
        while (!feof(archi))
        {
            fread(&aux,sizeof(persona),1,archi);
            if (!feof(archi))
            {
                arbol=insertar(arbol,aux);

            }
        }
    }
    fclose(archi);

    return arbol;
}

