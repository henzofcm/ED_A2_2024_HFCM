#include "linkedlists.h"

void vCountingSort(Node*& ptrList)
{
    Node* ptrFoo = ptrList;
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
        int iElemValue = iFindElement(ptrList, i);

        // E conta sua frequência
        arriCounter[iElemValue] += 1;
    }

    // Torna arriCounter acumulado
    for (int j = 1; j < iMaxElem + 1; j++)
        arriCounter[j] += arriCounter[j-1];

    // Cria um novo array, dessa vez ordenado
    int arriSorted[iSize] = {};

    for (int k = iSize - 1; k > -1; k--)
    {
        // Acha o elemento naquela posição
        int iElemValue = iFindElement(ptrList, k);

        // Adiciona ordenado e subtrai de arriCounter
        arriCounter[iElemValue] -= 1;
        arriSorted[arriCounter[iElemValue]] = iElemValue;
    }

    // Converte para listas encadeadas :)
    Node* ptrSorted = ptrConvertArrayList(arriSorted, iSize);

    vDeleteList(ptrList);
    ptrList = ptrSorted;
}

int main(void)
{
    Node* ptrList = ptrGenerateRandomList(5);
    cout << "A lista original: ";
    vPrintList(ptrList);

    cout << "A lista ordenada: ";
    vCountingSort(ptrList);
    vPrintList(ptrList);


    return 0;
}