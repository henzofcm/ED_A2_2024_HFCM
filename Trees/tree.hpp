#ifndef TREES
#define TREES

#include <iostream>
#include <experimental/random>
#include <chrono>
#include "../Linked Lists/linkedlists.hpp"

/*  ---- IMPORTAÇÕES DE IOSTREAM ----  */
using std::cout;
using std::endl;
using std::cerr;

/*  ---- IMPORTAÇÕES DE RANDOM ----  */
using std::experimental::randint;

/*  ---- IMPORTAÇÕES DE CHRONO ----  */
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::microseconds;


/*  ---- FUNÇÕES BASE DE ÁRVORES ----  */
namespace Tree
{
    typedef struct Node
    {
        int iValue;

        Node* ptrLeft;
        Node* ptrRight;
    } Node;

    Node* ptrCreateNode(int iValue);

    void vInsertNode(Node*& ptrRoot, int iValue);

    void vPrintTree(Node* ptrRoot, int iSpace);

    void vDeleteTree(Node*& ptrRoot);

    Node* ptrSearchNodeDFS(Node* ptrRoot, int iValue);

    Node* ptrSearchNodeBFS(Node* ptrRoot, int iValue);
}

/*  ---- FUNÇÕES EXTRAS PARA TESTES ----  */
namespace RandomTrees
{
    Tree::Node* ptrGenerateRandomTree(int iSize);

    void vRandomTests(int iAmount, int iSize, Tree::Node* (*fSearch)(Tree::Node* ptrRoot, int iValue));

    void vRandomTreesTime(int iAmount, int iSize);
}

#endif
