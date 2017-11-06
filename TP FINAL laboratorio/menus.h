#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED
#include "arbol.h"
#include "fila.h"

int menucaja();
int menuabrircajas();
int menucerrarcajas();
int menuprocesos(char archivitopers [],nodoArbol * arbol,Fila * filatotal);
int menumostrararbol(nodoArbol * arbol);
int menucargafilatotal(nodoArbol * arbol,Fila ** filatotal);

#endif // MENUS_H_INCLUDED
