#ifndef USUARIOS_H_INCLUDED
#define USUARIOS_H_INCLUDED
#include "matriz.h"

typedef struct
{
    char usuario[30];
    int passE [2][5];
}usuario;

void Login(char archiuser[]);
void CrearUsuario(char archiuser[]);

#endif // USUARIOS_H_INCLUDED
