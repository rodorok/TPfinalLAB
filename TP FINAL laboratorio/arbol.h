#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

typedef struct {
    int dato;
    struct nodoArbol *izq;
    struct nodoArbol *der;
}nodoArbol;

///Funciones
nodoArbol * inicArbol();
nodoArbol * crearNodoArbol(int dato);
nodoArbol * insertar(nodoArbol * arbol, int dato);
void preorder(nodoArbol * arbol);
void inorder(nodoArbol * arbol);
void postorder(nodoArbol * arbol);
nodoArbol * buscar(nodoArbol * arbol, int dato);


#endif // ARBOL_H_INCLUDED
