#ifndef LINKEDLISTS
#define LINKEDLISTS

#include <experimental/random>
#include <chrono>
#include <iostream>

/*  ---- IMPORTAÇÕES DE RANDOM ----  */
using std::experimental::randint;

/*  ---- IMPORTAÇÕES DE CHRONO ----  */
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::microseconds;

/*  ---- IMPORTAÇÕES DE IOSTREAM ----  */
using std::cout;
using std::endl;

template <typename T>
struct Node
{
    T iValue;
    Node* ptrNext;
    Node* ptrLast;
};


/*  ---- FUNÇÕES BASE DE LISTA DUPLAMENTE ENCADEADA ----  */
namespace LinkedList
{
    template <typename T>
    Node<T>* ptrCreateList(void);

    template <typename T>
    Node<T>* ptrCreateNode(T iValue);

    template <typename T>
    void vAddElemFront(Node<T>*& ptrList, T iValue);

    template <typename T>
    void vAddElemEnd(Node<T>*& ptrList, T iValue);
    
    template <typename T>
    void vPrintList(Node<T>* ptrList);

    template <typename T>
    void vDeleteList(Node<T>*& ptrList);
    
    template <typename T>
    void vSwapElements(Node<T>* ptrNode1, Node<T>* ptrNode2);
    
    template <typename T>
    T iFindElement(Node<T>* ptrList, int iPosition);
    
    template <typename T>
    Node<T>* ptrConvertArrayList(int arriSorted[], int iSize);
}

/*  ---- FUNÇÕES EXTRAS PARA TESTES ----  */
namespace RandomTests
{
    template <typename T>
    Node<T>* ptrGenerateRandomList(int iSize);

    template <typename T>
    void vRandomTests(int iAmount, int iSize, void (*fSort)(Node<T>*& ptrList));
}

#include "linkedlists.tpp"

#endif
