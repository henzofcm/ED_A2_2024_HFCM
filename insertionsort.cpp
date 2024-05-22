#include "linkedlists.h"

void vInsertionSort(Node*& ptrList)
{
    // Caso seja vazia, não há nada a fazer
    if (ptrList == nullptr)
        return;

    // Ponteiros que percorrerão a lista
    Node* ptrFoo = ptrList;
    Node* ptrElem = ptrFoo;

    // Enquanto a lista não for toda percorrida
    while(ptrFoo != nullptr)
    {
        ptrElem = ptrFoo;

        // Vai inserindo o novo elemento em sua posição na lista já parcialmente ordenada
        while(ptrElem->ptrLast != nullptr && ptrElem->ptrLast->iValue > ptrElem->iValue)
        {
            // Troca os elementos e move o ponteiro para trás
            LinkedList::vSwapElements(ptrElem, ptrElem->ptrLast);
            ptrElem = ptrElem->ptrLast;
        }

        // Avança somente quando todos até ptrFoo estiverem em ordem
        ptrFoo = ptrFoo->ptrNext;
    }

    return;
}

int main(void)
{
    // Faz 100 ordenações com listas de tamanho 10000
    RandomTests::vRandomTests(100, 10000, vInsertionSort);

    return 0;
}