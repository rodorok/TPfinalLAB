#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "menus.h"
<<<<<<< HEAD
#include "caja.h"

int main()
{
    cajas * cajas[8] = {0};

=======
#include "arbol.h"



int main()
{
    nodoArbol * arbol = inicArbol();
    char archivitopers[] = {"datos_persona"};
>>>>>>> 1ab0cd4f2394bcec4047504b19bc7f04abfa1e5d
    char opcion;
    do{
        printf("\t\t\t <<< Menu Principal >>>");
        printf("\n\n");
        printf("\n\t 1- Menu Clientes");
        printf("\n\t 2- Menu Cajas");
        printf("\n\t 3- Menu Procesos");
        printf("\n\n");
        printf("Escape para salir");
        printf("\n\n");
        opcion=getch();

       switch(opcion){
            case '1':
                system("cls");
                cargapersona(archivitopers);
                printf("\n\n\n");
                system("cls");
                break;


            case '2':
                system("cls");
                menucaja();
                printf("\n\n\n");
                system("cls");
                break;


            case '3':
                  system("cls");
                  menuprocesos(archivitopers,arbol);
                  printf("\n\n\n");
                  system("cls");
                  break;

                     }
    }while(opcion!=27);

    return 0;
}
