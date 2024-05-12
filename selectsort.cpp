#include "linkedlists.h"

void vSelectSort(Node*& ptrList)
{
    // Caso for vazia, não há nada a fazer
    if (ptrList == nullptr)
        return;

    // Ponteiros que percorrerão a lista
    Node* ptrUnsortedList = ptrList;
    Node* ptrFoo = ptrList;

    // Holder para o menor elemento encontrado em cada loop
    Node* ptrHolder = ptrList;

    while (ptrUnsortedList->ptrNext != nullptr)
    {
        while(ptrFoo != nullptr)
        {
            // Caso, nesta iteração, ptrFoo seja menor, salva-o
            if (ptrFoo->iValue < ptrHolder->iValue)
            {
                ptrHolder = ptrFoo;
            }

            ptrFoo = ptrFoo->ptrNext;
        }

        // Troca-os de lugar
        vSwapElements(ptrUnsortedList, ptrHolder);

        // Por fim, fazem-nos começar numa nova lista menor
        ptrUnsortedList = ptrUnsortedList->ptrNext;
        ptrFoo = ptrUnsortedList;
        ptrHolder = ptrFoo;
    }
}

int main(void)
{
    return 0;
}
