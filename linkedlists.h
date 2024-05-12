#ifndef LINKEDLISTS
#define LINKEDLISTS

#include <random>
#include <chrono>
#include <iostream>

/*  ---- IMPORTAÇÕES DE RANDOM ----  */
using std::rand;

/*  ---- IMPORTAÇÕES DE CHRONO ----  */
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::microseconds;

/*  ---- IMPORTAÇÕES DE IOSTREAM ----  */
using std::cout;
using std::endl;


typedef struct Node
{
    int iValue;
    Node* ptrNext;
    Node* ptrLast;
} Node;


/*  ---- FUNÇÕES BASE DE LISTA DUPLAMENTE ENCADEADA ----  */
Node* ptrCreateList(void);
Node* ptrCreateNode(int iValue);
void vAddElemFront(Node*& ptrList, int iValue);
void vAddElemEnd(Node*& ptrList, int iValue);
void vPrintList(Node* ptrList);
void vDeleteList(Node*& ptrList);
void vSwapElements(Node* ptrNode1, Node* ptrNode2);

/*  ---- FUNÇÕES EXTRAS PARA TESTES ----  */
Node* ptrGenerateRandomList(int iSize);
void vRandomTests(int iAmount, int iSize, void (*fSort)(Node*& ptrList));

#endif
