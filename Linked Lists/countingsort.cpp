#include "linkedlists.h"

template <typename T>
void vCountingSort(Node<T>*& ptrList)
{
    Node<T>* ptrFoo = ptrList;
    int iSize = 0;
    int iMaxElem = 0;

    // Acha o maior valor de ptrList e seu tamanho
    for (; ptrFoo != nullptr; iSize++)
    {
        // Caso for maior, atualiza
        if (ptrFoo->iValue > iMaxElem)
            iMaxElem = ptrFoo->iValue;

        // Avança
        ptrFoo = ptrFoo->ptrNext;
    }

    // Cria um array zerado para contar cada elemento da lista
    // (Para que haja acesso imediato)
    int arriCounter[iMaxElem + 1] = {};

    // Conta todos elementos de ptrList
    for (int i = 0; i < iSize; i++)
    {
        // Acha o elemento naquela posição
        int iElemValue = LinkedList::iFindElement<T>(ptrList, i);

        // E conta sua frequência
        arriCounter[iElemValue] += 1;
    }

    // Cria uma nova lista e insere os elementos já em ordem
    Node<T>* ptrSortedList = LinkedList::ptrCreateList<T>();

    for (int k = iMaxElem; k != -1; k--)
    {
        // Adiciona-o todas vezes que foram contadas
        for (int i = arriCounter[k]; i > 0; i--)
        {
            LinkedList::vAddElemFront<T>(ptrSortedList, k);
        }
    }

    // Apaga a anterior e aponta para a nova
    LinkedList::vDeleteList<T>(ptrList);
    ptrList = ptrSortedList;
}

template <typename T>
void vShowCountingSort(Node<T>*& ptrList)
{
    // Apresenta a lista desordenada
    cout << "A lista original: ";
    LinkedList::vPrintList(ptrList);

    Node<T>* ptrFoo = ptrList;
    int iSize = 0;
    int iMaxElem = 0;

    // Acha o maior valor de ptrList e seu tamanho
    for (; ptrFoo != nullptr; iSize++)
    {
        // Caso for maior, atualiza
        if (ptrFoo->iValue > iMaxElem)
            iMaxElem = ptrFoo->iValue;

        // Avança
        ptrFoo = ptrFoo->ptrNext;
    }

    // Mostra o maior elemento
    cout << "O maior elemento: " << iMaxElem << endl;

    // Cria um array zerado para contar cada elemento da lista
    // (Para que haja acesso imediato)
    int arriCounter[iMaxElem + 1] = {};

    // Conta todos elementos de ptrList
    for (int i = 0; i < iSize; i++)
    {
        // Acha o elemento naquela posição
        int iElemValue = LinkedList::iFindElement<T>(ptrList, i);

        // E conta sua frequência
        arriCounter[iElemValue] += 1;
    }

    // Mostra a contagem
    cout << "A contagem de cada elemento: ";
    
    for (int i = 0; i != iMaxElem + 1; i++)
        cout << arriCounter[i] << " ";

    cout << endl;

    // Cria uma nova lista e insere os elementos já em ordem
    Node<T>* ptrSortedList = LinkedList::ptrCreateList<T>();

    for (int k = iMaxElem; k != -1; k--)
    {
        // Adiciona-o todas vezes que foram contadas
        for (int i = arriCounter[k]; i > 0; i--)
        {
            LinkedList::vAddElemFront(ptrSortedList, k);
        }
    }

    // Apaga a anterior e aponta para a nova
    LinkedList::vDeleteList(ptrList);
    ptrList = ptrSortedList;

    // Mostra a nova lista
    cout << "Entao recriamos a lista em ordem: ";
    LinkedList::vPrintList(ptrList);
}


int main(void)
{
    Node<int>* ptrList = RandomTests::ptrGenerateRandomList<int>(5);

    // Faz o sort, mostrando cada etapa
    vShowCountingSort(ptrList);

    return 0;
}
