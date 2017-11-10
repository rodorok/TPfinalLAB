#include "usuarios.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>

void CrearUsuario(char archiuser[]){
    FILE * archi = fopen(archiuser,"wb");
    char user[5] = {"admin"};
    char pass[5] = {"admin"};
    usuario aux;
    strcpy(aux.usuario,user);
    strcpy(aux.passE,pass);
    fwrite(&aux,sizeof(usuario),1,archi);
    fclose(archi);
}

void Login(char archiuser[])
{
    FILE * usua;
    usuario aux;
    char usuario[20];
    char password[10];
    char passF[10];
    int A[2][5];
    int flag = 0;

    usua = fopen(archiuser, "rb");

    if (usua == NULL){
        printf("ARCHIVO IMPOSIBLE DE ABRIR, PRIMERO CREAR USUARIOS");

    }
    else{
        printf("\nNOMBRE DE USUARIO: ");
        fflush(stdin);
        gets(usuario);

        while(fread(&aux,sizeof(usuario),1,usua) > 0 && flag == 0)
        {
            if(strcmp(usuario,aux.usuario) == 0)
            {

                printf("\nPASSWORD: ");
                fflush(stdin);
                gets(passF);

                fDecrypting(password, aux.passE);

                if (strcmp(passF,password) == 0)
                {
                    printf("Bienvenido");
                    flag = 1;
                }
                else
                {
                    printf("\nPASSWORD INCORRECTA!\n\n");
                    flag = 1;
                }

            }
            else if (feof(usua))
            {
                printf("USUARIO INEXISTENTE.");
            }
        }
    }

    fclose(usua);
}
