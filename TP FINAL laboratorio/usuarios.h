#ifndef USUARIOS_H_INCLUDED
#define USUARIOS_H_INCLUDED
#include "matriz.h"

typedef struct
{
    char usuario[30];
    int passE [2][5];
}usuario;

void Login(char usuarios[])
{
    FILE*usua;
    usuario aux;
    char usuario[20];
    char password[10];
    char passF[10];
    int A[2][5];
    int flag = 0;

    usua = fopen(usuarios, "rb");

    if (usua == NULL)
    {
        printf("ARCHIVO IMPOSIBLE DE ABRIR, PRIMERO CREAR USUARIOS");

    }
    else
    {
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

                if (strcmp(passf,password) == 0)
                {
                    bienvenido();
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

#endif // USUARIOS_H_INCLUDED
