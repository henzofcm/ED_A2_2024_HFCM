#include "linkedlists.h"

void vBubbleSort(Node*& ptrList)
{
    // Caso seja vazia, não há nada a fazer
    if (ptrList == nullptr)
        return;

    // Ponteiros que percorrerão a lista
    Node* ptrSortedList = nullptr;
    Node* ptrFoo = ptrList;

    // Enquanto a lista não estiver toda organizada
    while (ptrSortedList != ptrList)
    {
        bool bSwapped  = false;

        // Percorre-a ordenando assim que possível
        while(ptrFoo->ptrNext != ptrSortedList)
        {
            // Troca-os de lugar se estiverem fora de ordem
            if (ptrFoo->iValue > ptrFoo->ptrNext->iValue)
            {
                bSwapped = true;
                LinkedList::vSwapElements(ptrFoo->ptrNext, ptrFoo);
            }

            ptrFoo = ptrFoo->ptrNext;
        }

        // Caso já esteja em ordem (não houve trocas), retorna
        if (bSwapped == false)
            return;

        // Por fim, ptrFoo retorna ao começo e ptrSortedList aumenta
        ptrSortedList = ptrFoo;
        ptrFoo = ptrList;
    }

}

int main(void)
{
    // Faz 100 ordenações com listas de tamanho 10000
    RandomTests::vRandomTests(100, 10000, vBubbleSort);

    return 0;
}
