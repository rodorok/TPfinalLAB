#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

nodo * inicLista ()
{
    return NULL;
}

nodo * crearNodoLista (persona cliente)
{
    nodo * nuevo=(nodo*)malloc(sizeof(nodo));

    strcpy(nuevo->cliente.apellido, cliente.apellido);
    nuevo->cliente.tipoCliente = cliente.tipoCliente;
    nuevo->cliente.medioPago = cliente.medioPago;
    nuevo->cliente.cantArticulos = cliente.cantArticulos;
    nuevo->cliente.tiempoEspera = 0;
    nuevo->cliente.tiempoProcesado = 0;
    nuevo->cliente.eliminado = cliente.eliminado;

    ///asignamos los datos pedidos
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;

    return nuevo;
}

nodo * agregarAlPrincipio (nodo * lista, nodo * nuevo)
{
    nuevo->siguiente=lista;
    if(lista!=NULL)
    {
        lista->anterior=nuevo;
    }
    return nuevo;
}

nodo * buscarUltimo (nodo * lista)
{
    nodo * seg=lista;
    while (seg->siguiente!=NULL){
        seg=seg->siguiente;
    }
    return seg;
}

nodo * agregarAlFinal (nodo * lista, nodo * nuevo)
{
    nodo * seg;
    if (lista==NULL)
    {
        lista=nuevo;
    }
    else
    {
        seg = buscarUltimo(lista);
        seg->siguiente = nuevo;
        nuevo->anterior = seg;
    }
    return lista;
}

nodo * agregarEnOrdenTipoCliente (nodo * lista, nodo * nuevo)
{
    if (lista==NULL)
    {
        lista=nuevo;
    }
    else if(nuevo->cliente.tipoCliente <= lista->cliente.tipoCliente)
    {
        lista=agregarAlPrincipio(lista,nuevo);
    }
    else
    {
        nodo * ante=lista;
        nodo * seg=lista->siguiente;
        while(seg!=NULL && seg->cliente.tipoCliente <= nuevo->cliente.tipoCliente)
        {
            ante=seg;
            seg=seg->siguiente;
        }

        ante->siguiente=nuevo;
        nuevo->anterior=ante;
        nuevo->siguiente=seg;

        if(seg!=NULL)
        {
            seg->anterior=nuevo;
        }
    }
    return lista;
}

nodo * agregarEnOrdenPorCant (nodo * lista, nodo * nuevo)
{
    if (lista==NULL)
    {
        lista=nuevo;
    }
    else if(nuevo->cliente.cantArticulos <= lista->cliente.cantArticulos)
    {
        lista=agregarAlPrincipio(lista,nuevo);
    }
    else
    {
        nodo * ante=lista;
        nodo * seg=lista->siguiente;
        while(seg!=NULL && seg->cliente.cantArticulos <= nuevo->cliente.cantArticulos)
        {
            ante=seg;
            seg=seg->siguiente;
        }

        ante->siguiente=nuevo;
        nuevo->anterior=ante;
        nuevo->siguiente=seg;

        if(seg!=NULL)
        {
            seg->anterior=nuevo;
        }
    }
    return lista;
}

/*void mostrarLista(nodo * aux)
{
    while (aux!=NULL)///mientras tenga datos
    {
        mostrarPersona(aux->cliente);///mostraremos los clientes de la lista
        aux=aux->siguiente;///avanzamos en la lista
    }
}*/

nodo * borrarPrimero (nodo * lista)
{
    nodo * seg=lista;
    if (lista->siguiente)
    {
        lista=lista->siguiente;///encontramos el primer nodo y creamos una copia de la lista pero sin el primer nodo
    }///esto si es que la lista tiene mas de un nodo
    lista->anterior=NULL;
    free(seg);///borramos el primer nodo

    return lista;///devolvemos la lista
}

nodo * borrarNodo(nodo * lista, nodo * buscado)
{
    nodo * aBorrar=NULL;
    nodo * seg=NULL;

    if(lista!=NULL)///si la lista existe
    {
        if(lista->cliente.apellido==buscado->cliente.apellido)///si los datos coinciden
        {
            aBorrar=lista;

            lista=lista->siguiente;///creamos una copia sin el datoa aborrar
            if(lista!=NULL)///si existe lista (ya que al hacer la copia puede pasar que lista->siguiente fuese NULL)
            {
                lista->anterior=NULL;///el anterior (que seria el nodo a borrar) lo volvemos NULL ya que sera eliminado
            }

            free(aBorrar);///eliminamos el nodo
        }///todo esto en caso de que fuese el primer nodo el que se queria borrar
        else
        {
            seg=lista->siguiente;///creamos una seguidora
            while(seg!=NULL && seg->cliente.apellido!=buscado->cliente.apellido)///y mientras existan mas clientes y no se encuentre al buscado
            {
                seg=seg->siguiente;///avanzamos en la lista
            }
            if(seg!= NULL)///si seg no quedo "vacio" despues del while (es decir que se encontro el nodo buscado)
            {
                nodo * ant=seg->anterior;
                ant->siguiente=seg->siguiente;///guardamos lo anterior y lo siguiente sin guardar el nodo a borrar

                if(seg->siguiente!=NULL)
                {
                    nodo * aux = seg->siguiente;
                    aux->anterior=ant;
                }
                free(seg);///borramos el nodo buscado
            }

        }
    }
    return lista;///retornamos la nueva lista sin ese nodo
}
