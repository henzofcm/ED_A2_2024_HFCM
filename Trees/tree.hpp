#ifndef TREES
#define TREES

#include <iostream>

/*  ---- IMPORTAÇÕES DE IOSTREAM ----  */
using std::cout;
using std::endl;
using std::cerr;


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


#endif
