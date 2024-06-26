#include "linkedlists.hpp"

template <typename T>
void vSelectSort(LinkedList::Node<T>*& ptrList)
{
    // Caso for vazia, não há nada a fazer
    if (ptrList == nullptr)
        return;

    // Ponteiros que percorrerão a lista
    LinkedList::Node<T>* ptrUnsortedList = ptrList;
    LinkedList::Node<T>* ptrFoo = ptrList;

    // Holder para o menor elemento encontrado em cada loop
    LinkedList::Node<T>* ptrHolder = ptrList;

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
        LinkedList::vSwapElements(ptrUnsortedList, ptrHolder);

        // Por fim, fazem-nos começar numa nova lista menor
        ptrUnsortedList = ptrUnsortedList->ptrNext;
        ptrFoo = ptrUnsortedList;
        ptrHolder = ptrFoo;
    }
}

int main(void)
{
    // Faz 100 ordenações com listas de tamanho 10000
    RandomLists::vRandomTests<int>(100, 10000, vSelectSort);

    return 0;
}
