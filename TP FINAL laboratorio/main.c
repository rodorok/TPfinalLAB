#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "menus.h"


int main()
{

    char opcion;
    do{
        printf("\t\t\t <<< Menu Principal >>>");
        printf("\n\n");
        printf("\n\t 1- Menu Clientes");
        printf("\n\t 2- Menu Cajas");
        printf("\n\t 2- Menu Procesos");
        printf("\n\n");
        printf("Escape para salir");
        printf("\n\n");
        opcion=getch();

       switch(opcion){
            case '1':
                system("cls");

                cargapersona();
                printf("\n\n\n");
                system("cls");
                break;


            case '2':
                system("cls");
                menucaja();
                ///
                printf("\n\n\n");
                system("cls");
                break;


            case '3':
                  system("cls");
                  menuprocesos();
                  ///
                  printf("\n\n\n");
                  system("cls");
                  break;

                     }
    }while(opcion!=27);

    return 0;
}
