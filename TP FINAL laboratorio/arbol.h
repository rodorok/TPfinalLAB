#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED
#include"cliente.h"
typedef struct {
    persona p;
    struct nodoArbol *izq;
    struct nodoArbol *der;
}nodoArbol;

///Funciones
nodoArbol * inicArbol();
nodoArbol * crearNodoArbol(persona a);
nodoArbol * insertar(nodoArbol * arbol, persona a);
void preorder(nodoArbol * arbol);
void inorder(nodoArbol * arbol);
void postorder(nodoArbol * arbol);
nodoArbol * buscar(nodoArbol * arbol, char nombre[10]);
#endif // ARBOL_H_INCLUDED
