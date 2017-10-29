#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menus.h"

int menucaja(){
char opcion;


    do
    {   system("cls");
        printf("\t\t\t<<< Menu Cajas >>>");
        printf("\n1- Abrir Cajas");
        printf("\n2- Cerrar Cajas");
        printf("\n3- Cargar cajas");
        printf("\n4- ");
        printf("\n\n\n ESC para volver atras.");
        opcion=getch();
        switch ( opcion )
        {
            case 49:system("cls");
                    menuabrircajas();
                    printf("\n\n\n");

                system("cls");
                    break;
            case 50:
                    system("cls");
                    menucerrarcajas();
                    printf("\n\n\n");

                    system("cls");
                    break;
            case 51:
                system("cls");
                    printf("Abre");
                    printf("\n\n\n");
                    system("pause");
                    system("cls");
                    break;
            case 52:
                system("cls");
                    printf("Abre");
                    printf("\n\n\n");
                    system("pause");
                    system("cls");

                    break;
        } ///switch principal
    }while ( opcion != 27 );  ///FIN DEL DO-WHILE
}

int menuprocesos(){
char opcion;


    do
    {   system("cls");
        printf("\t\t\t <<< Menu Procesos >>>");
        printf("\n\n1- Cargar Arbol");
        printf("\n2- Cargar Filas");
        printf("\n3- Diagrama de Flujo");
        printf("\n\n\n ESC para volver atras.");
        opcion=getch();
        switch ( opcion )
        {
            case 49:system("cls");
                    printf("Abre");
                    printf("\n\n\n");
                    system("pause");
                system("cls");
                    break;
            case 50:
                    system("cls");
                    printf("Abre");
                    printf("\n\n\n");
                    system("pause");
                    system("cls");
                    break;
            case 51:
                system("cls");
                    printf("Abre");
                    printf("\n\n\n");
                    system("pause");
                    system("cls");
                    break;
            case 52:
                system("cls");
                    printf("Abre");
                    printf("\n\n\n");
                    system("pause");
                    system("cls");

                    break;
        } ///switch principal
    }while ( opcion != 27 );  ///FIN DEL DO-WHILE

}
int menuabrircajas(){
char opcion;


    do
    {   system("cls");
        printf("\n1-Abrir todas las cajas");
        printf("\n2-Abrir de una caja");
        printf("\n\n\n ESC para volver atras.");
        opcion=getch();
        switch ( opcion )
        {
            case 49:system("cls");
                    printf("Abre");
                    printf("\n\n\n");
                    system("pause");
                system("cls");
                    break;
            case 50:
                    system("cls");
                    printf("Abre");
                    printf("\n\n\n");
                    system("pause");
                    system("cls");
                    break;


                    break;
        } ///switch principal
    }while ( opcion != 27 );  ///FIN DEL DO-WHILE
}
int menucerrarcajas(){
char opcion;


    do
    {   system("cls");
        printf("\n1-Cerrar todas las cajas");
        printf("\n2-Cerrar de una caja");
        printf("\n\n\n ESC para volver atras.");
        opcion=getch();
        switch ( opcion )
        {
            case 49:system("cls");
                    printf("Cierra");
                    printf("\n\n\n");
                    system("pause");
                system("cls");
                    break;
            case 50:
                    system("cls");
                    printf("Cierra");
                    printf("\n\n\n");
                    system("pause");
                    system("cls");
                    break;


                    break;
        } ///switch principal
    }while ( opcion != 27 );  ///FIN DEL DO-WHILE
}
