#include <iostream>
template<class T>
class Node<T>{
    private:
        nodo;
        izq;
        der;
};

void preOrder(Node<T> *nodo)
{
    if(nodo == NULL)
        return;
    std::cout <<  *nodo << " ";
    preOrder(nodo->izq);
    preOrder(nodo->der);
};

void inOrder(Node<T> *nodo)
{
    if(nodo==NULL)
        return;
    inOrder(nodo->izq);
    std::cout << *nodo << " ";
    inOrder(nodo->der);
}

void postOrder(Node<T> *nodo)
{
    if(nodo==NULL)
        return;
    postOrder(nodo->izq);
    postOrder(nodo->der);
    std::cout << *nodo << " ";
}