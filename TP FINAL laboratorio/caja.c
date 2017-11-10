#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "caja.h"
#include "arbol.h"

///Funciones Cajas

caja abrirOcerrarCaja(caja c){ ///Funcion que resive y devuelve, la cierra si esta abierta y visebersa
    if(c.abiertaOcerrada == 1){
        c.abiertaOcerrada = 0;
    }
    else{
        c.abiertaOcerrada= 1;
    }
    return c;
}

caja buscarCaja(caja c[], int buscar){ ///buscamos una caja y la retornamos
    int i=0;
    if((c[i].nro_de_caja != buscar) && (buscar <= 8)){
        while (c[i].nro_de_caja != buscar){
            i++;
        }
    }
    return c[i];
}

///Funciones VOID

void agregarCajas(caja c[], int val, char archivoCaja[]){
    int i = 0;
    char option = 's';
    while(option == 's' && i < val){
        system("cls");
        puts("\n---------------------------------------");
        c[i].nro_de_caja = i+1;
        printf("\nCaja Numero: [%i]",c[i].nro_de_caja);
        printf("\nIngrese Nombre del cajero: ");
        fflush(stdin);
        gets(c[i].nombreCajero);
        printf("\nIngrese tipo de pago (1 Efectivo, 2 Credito, 3 Todos): ");
        fflush(stdin);
        scanf("%d",&c[i].tipo_pago);
        printf("\n (1 Abierta, 2 Cerrada): ");
        fflush(stdin);
        scanf("%d",&c[i].abiertaOcerrada);
        printf("\nAlgoritmo de Planificacion: ");
        fflush(stdin);
        gets(c[i].algoritmoPlanificacion);
        i++;
        printf("\nDesea seguir agregando Cajas? (S/N): ");
        fflush(stdin);
        scanf("%c",&option);
    }
<<<<<<< HEAD
}

void datosCajas(caja c[], int val){
    c[val].nro_de_caja = val+1;
    printf("\nCaja Numero: [%d]",c[val].nro_de_caja);
    printf("\nIngrese Nombre del cajero): ");
    fflush(stdin);
    scanf("%s",&c[val].nombreCajero);
    printf("\nIngrese tipo de pago (1 Efectivo, 2 Credito, 3 Todos): ");
    fflush(stdin);
    scanf("%d",&c[val].tipo_pago);
    printf("\n (1 Abierta, 2 Cerrada): ");
    fflush(stdin);
    scanf("%d",&c[val].abiertaOcerrada);
    printf("\nAlgoritmo de Planificacion: ");
    fflush(stdin);
    scanf("%s",&c[val].algoritmoPlanificacion);

=======
    arrayAarchi(c,val,archivoCaja);
>>>>>>> 50837f2d75ef06b4576a85e6fb455ebf283f8cac
}

void arrayAarchi(caja c[], int val,char archivoCaja[]){
    FILE * archi = fopen(archivoCaja, "wb");
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
            puts("\n------------------------------------------");
            mostrarCaja(aux);
        }
    }
    else{
        printf("\nERROR, archivo no encontrado");
    }
    fclose(archi);
}

void mostrarCaja(caja c){
    puts("\n-------------------------");
    printf("\nNumero de caja: %i",c.nro_de_caja);
    printf("\nNombre del cajero: %s",c.nombreCajero);
    printf("\nTipo de pago: %d",c.tipo_pago);
    if(c.abiertaOcerrada == 1){
        printf("\nEstado de la caja: Abierta");
    }else{
        printf("\nEstado de la cada; Cerrada");
    }
}

///Funciones int

int ArchivoACajas(char archivoCajas[], caja c[]){
    FILE * archi = fopen(archivoCajas,"rb");
    int i = 0;
    caja aux;
    if (archi != NULL){
        while (fread(&aux,sizeof(caja),1,archi) > 0){
            c[i] = aux;
            inicReferencia(&c[i].filita);
            i++;
        }
    }
    fclose(archi);
    return i;
}

int contarClientesCaja(caja c){
    int cant = 0;
    Fila seg = c.filita;
    nodo2 * aux;
    if (filaVacia(&seg) == 1){
        aux = seg.cabecera;
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
    if(opcion == 1){
//        cantidadclientes = agregarClientePreorden(raiz,c,cantidadclientes);
    }
    else{
        if (opcion == 2){
//            cantidadclientes = agregarClienteInorden(raiz,c,cantidadclientes);
        }
        else{
//            cantidadclientes = agregarClientePostorden(raiz,c,cantidadclientes);
        }
    }
    return cantidadclientes;
}

