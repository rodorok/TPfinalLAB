/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "caja.h"


void agregar_caja(cajas c[],int val){
    int i = 0;
    char option = 's';
    while( option == 's' && i < val ){
        if( c[i] != 0 ){
            i++;
        }
        else{
            datos_caja(c[i]);
            i++;
            printf("Desea seguir agregando cajas? (S/N) : ");
            fflush(stdin);
            scanf("%c",&option);
        }
    }
}

void datos_caja(cajas c[]){
            printf("Numero de caja: [%d] \n", i+1);
            c.nro_de_caja = i;
            printf("Ingrese nombre del cajero: ");
            fflush(stdin);
            scanf("%s",&c.nombreCajero);
            printf("\n");
            printf("Tipo de pago(1 efectivo, 2 crédito o débito, 3 todos): ");
            fflush(stdin);
            scanf("%d",&c.tipo_pago);
            printf("\n");
            printf("Estado de caja (1 abierta) (2 cerrada): ");
            fflush(stdin);
            scanf("%d",&c.abiertaOcerrada);
            printf("\n");
            printf("Ingrese tipo de Planificacion: ");
            fflush(stdin);
            scanf("%c",&c.algoritmoPlanificacion);
            printf("\n");
            c.filita = NULL;
*/
