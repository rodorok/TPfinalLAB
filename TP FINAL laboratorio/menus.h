#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED
#include "arbol.h"
<<<<<<< HEAD
#include "fila.h"
=======
#include "caja.h"
>>>>>>> d8e8f49a180fa75a22c4f36ac35cdb3d116554f8

int menucaja();
int menuabrircajas();
int menucerrarcajas();
int menuprocesos(char archivitopers [],nodoArbol * arbol,Fila * filatotal);
int menumostrararbol(nodoArbol * arbol);
int menucargafilatotal(nodoArbol * arbol,Fila ** filatotal);

#endif // MENUS_H_INCLUDED
