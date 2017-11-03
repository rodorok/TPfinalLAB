#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "caja.h"

///Funciones Cajas

caja abrirOcerrarCaja (caja c){ ///Funcion que resibe y devuelve, la cierra si esta abierta y visebersa
    if (c.abiertaOcerrada == 1){
        c.abiertaOcerrada = 0;
    }
    else{
        c.abiertaOcerrada= 1;
    }
    return c;
}

caja buscarCaja(caja A[], int buscar){ ///buscamos una caja y la retornamos
    int i=0;
    if((A[i].nro_de_caja!=buscar) && (buscar<=8)){
        while (A[i].nro_de_caja!=buscar){
            i++;
        }
    }
    return A[i];
}

///Funciones VOID

void agregarCajas(caja c[], int val){
    int i = 0;
    while(i < val){
        puts("\n---------------------------------------");
        datosCajas(c,i);
        i++;
    }
}

void datosCajas(caja c[], int val){
    c[val].nro_de_caja = val+1;
    printf("\nIngrese Nombre del cajero");
    fflush(stdin);
    scanf("%s",&c[val].nombreCajero);
    printf("\nIngrese tipo de pago (1 Efectivo, 2 Credito, 3 Todos");
    fflush(stdin);
    scanf("%d",&c[val].tipo_pago);
    printf("\n (1 Abierta, 2 Cerrada");
    fflush(stdin);
    scanf("%d",&c[val].abiertaOcerrada);
    printf("\nAlgoritmo de Planificacion");
    fflush(stdin);
    scanf("%c",&c[val].algoritmoPlanificacion);
    c[val].filita = NULL;
}

void arrayAarchi(caja c[], int val,char archivoCaja[]){
    FILE * archi = fopen(archivoCaja, "wb");
    caja * aux;
    int i = 0;
    while(i < val){
        fwrite(&c[i],sizeof(caja),1,archi);
        i++;
    }
    fclose(archi);
}

void mostrarArchivoCaja (char archivoCaja[]){
    FILE * archi = fopen(archivoCaja, "rb");
    caja aux;
    if (archi != NULL){
        while(fread(&aux,sizeof(caja),1,archi) > 0){
            inicFila(&(aux.filita));
            puts("\n------------------------------------------");
            mostrarCaja(aux);
        }
    }
    else{
        printf("\nERROR, archivo no encontrado");
    }
    fclose(archi);
}
/*
///Funciones int

int ArchivoACajas (char archivoCajas[], caja c[]){
    FILE * archi = fopen(archivoCajas,"rb");
    int i=0;
    caja aux;
    if (archi != NULL){
        while (fread(&aux,sizeof(caja),1,archi) > 0){
            c[i] = aux;
            inicFila(&(c[i].filita));
            i++;
        }
    }
    fclose(archi);
    return i;
}

int contarClientesCaja (caja c){
    int cant = 0;
    Fila seg = c.filita;
    nodo * aux;
    if (filaVacia(&seg) == 1){
        aux = seg.primero;
        while(aux->siguiente != NULL){
            aux = aux->siguiente;
            cant++;
        }
    }
    return cant;
}

int cajasMenorClientela (caja  c[], int tipoPago){ ///Funcion para Buscar caja con menos clientes, dependiendo el tipo de pago.
    int i=0;
    int flag=0;
    int menor=0;
    int posmenor=-1;

    while(flag == 0 && i<8){
        if ((c[i].tipo_pago == tipoPago) && (c[i].abiertaOcerrada == 1)){
            flag = 1;
            posmenor = i;
            menor = contarClientesCaja(c[posmenor]);
        }
        i++;
    }
    while (i<8){
        if((c[i].tipo_pago == tipoPago) && (c[i].abiertaOcerrada==1)){
            if(menor > contarClientesCaja(c[i])){
                menor = contarClientesCaja(c[i]);
                posmenor=i;
            }
        }
        i++;
    }
    return posmenor;
}

int agregarClienteACaja (caja c[], nodoArbol * raiz){
    int opcion;
    int cantidadclientes = 0;
    printf("En que orden desea recorrer el arbol");
    printf("\n[1] Preorden");
    printf("\n[2] Inorden");
    printf("\n[3] Postorden");
    printf("\nIngrese un numero: ");
    scanf("%d", &opcion);
    while (opcion > 3 || opcion < 1){
        printf("\nERROR, algoritmo no existente, ingrese nuevamente: ");
        scanf("%d", &opcion);
    }
    if(recorrido == 1){
        cantidadclientes = agregarClientePreorden(raiz,c,cantidadclientes);
    }
    else{
        if (recorrido == 2){
            cantidadclientes = agregarClienteInorden(raiz,c,cantidadclientes);
        }
        else{
            cantidadclientes = agregarClientePostorden(raiz,c,cantidadclientes);
        }
    }
    return cantidadclientes;
}
*/
