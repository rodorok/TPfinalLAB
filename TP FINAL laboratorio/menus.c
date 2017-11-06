#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menus.h"
#include "cliente.h"
#include "arbol.h"


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

int menuprocesos(char archivitopers [],nodoArbol * arbol,Fila * filatotal){
char opcion;


    do
    {   system("cls");
        printf("\t\t\t <<< Menu Procesos >>>");
        printf("\n\n1- Cargar Arbol");
        printf("\n2- Mostrar Arbol");
        printf("\n3- Cargar Filas");
        printf("\n\n\n ESC para volver atras.");
        opcion=getch();
        switch ( opcion )
        {
            case 49:system("cls");
                     arbol=archivoarbol(archivitopers,arbol);
                     printf("\t\t ARBOL CARGADO EXITOSAMENTE");
                    printf("\n\n\n");
                    system("pause");
                system("cls");
                    break;
            case 50:
                    system("cls");
                   menumostrararbol(arbol);
                    printf("\n\n\n");
                    system("pause");
                    system("cls");
                    break;
            case 51:
                system("cls");
                    menucargafilatotal(arbol,&filatotal);
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
int menumostrararbol(nodoArbol * arbol){
char opcion;


    do
    {   system("cls");
        printf("\n1-Inorder");
        printf("\n2-Preorder");
        printf("\n3-Postorder");
        printf("\n\n\n ESC para volver atras.");
        opcion=getch();
        switch ( opcion )
        {
            case 49:system("cls");
                    inorder(arbol);
                    printf("\n\n\n");
                    system("pause");
                system("cls");
                    break;
            case 50:
                    system("cls");
                    preorder(arbol);
                    printf("\n\n\n");
                    system("pause");
                    system("cls");
                    break;
            case 51:
                    system("cls");
                    postorder(arbol);
                    printf("\n\n\n");
                    system("pause");
                    system("cls");
                    break;



        } ///switch principal
    }while ( opcion != 27 );  ///FIN DEL DO-WHILE
}
int menucargafilatotal(nodoArbol * arbol,Fila ** filatotal){
char opcion;


    do
    {   system("cls");
        printf("Como desea agregar?\n\n");
        printf("\n1-Inorder");
        printf("\n2-Preorder");
        printf("\n3-Postorder");
        printf("\n\n\n ESC para volver atras.");
        opcion=getch();
        switch ( opcion )
        {
            case 49:system("cls");
                    system("pause");
                    agregarinorder(arbol,*filatotal);
                    printf("\n\nFila cargada exitosamente.\n");
                    printf("\n\n\n");
                    system("pause");
                system("cls");
                    break;
            case 50:
                    system("cls");
                    agregarpreorder(arbol,*filatotal);
                    printf("\n\nFila cargada exitosamente.");
                    printf("\n\n\n");
                    system("pause");
                    system("cls");
                    break;
            case 51:
                    system("cls");
                    agregarpostorder(arbol,*filatotal);
                    printf("\n\nFila cargada exitosamente.");
                    printf("\n\n\n");
                    system("pause");
                    system("cls");
                    break;



        } ///switch principal
    }while ( opcion != 27 );  ///FIN DEL DO-WHILE
}
