#include "linkedlists.hpp"

namespace LinkedList
{

template <typename T>
Node<T>* ptrCreateList(void)
{
    // Retorna, apropriadamente, uma lista vazia
    return nullptr;
}

template <typename T>
Node<T>* ptrCreateNode(T iValue)
{
    // Aloca memória para o Node
    Node<T>* ptrList = (Node<T>*) malloc(sizeof(Node<T>));

    // Atribui valores aos atributos
    ptrList->iValue = iValue;
    ptrList->ptrNext = nullptr;
    ptrList->ptrLast = nullptr;

    return ptrList;
}

template <typename T>
void vAddElemFront(Node<T>*& ptrList, T iValue)
{
    // Cria o novo node
    Node<T>* ptrNewElem = ptrCreateNode(iValue);

    // Caso a lista esteja vazia, ela será o novo elemento
    if (ptrList == nullptr)
    {
        ptrList = ptrNewElem;
        return;
    }

    // E adiciona-o no inicio da lista
    ptrNewElem->ptrNext = ptrList;
    ptrList->ptrLast = ptrNewElem;
    ptrList = ptrNewElem;
}

template <typename T>
void vAddElemEnd(Node<T>*& ptrList, T iValue)
{
    // Cria o novo node
    Node<T>* ptrNewElem = ptrCreateNode(iValue);

    // Caso a lista esteja vazia, ela será o novo elemento
    if (ptrList == nullptr)
    {
        ptrList = ptrNewElem;
        return;
    }

    // Percorre toda a lista com um ponteiro indicador
    Node<T>* ptrFoo = ptrList;

    while (ptrFoo->ptrNext != nullptr)
    {
        ptrFoo = ptrFoo->ptrNext;
    }

    // E adiciona-o no fim da mesma
    ptrNewElem->ptrLast = ptrFoo;
    ptrFoo->ptrNext = ptrNewElem;
}

template <typename T>
void vRmvElemFront(Node<T>*& ptrList)
{
    // Salva o próximo na lista
    Node<T>* ptrFoo = ptrList->ptrNext;

    // Apaga o primeiro elemento
    free(ptrList);

    // Atualiza o começo da lista
    ptrFoo->ptrLast = nullptr;
    ptrList = ptrFoo;
}

template <typename T>
void vPrintList(Node<T>* ptrList)
{
    // Foo para atravessar a lista
    Node<T>* ptrFoo = ptrList;

    // Anda elemento a elemento, printando cada um
    // (Se estiver vazia, não printa nada)
    while(ptrFoo != nullptr)
    {
        cout << ptrFoo->iValue << " ";
        ptrFoo = ptrFoo->ptrNext;
    }

    // E termina a linha
    cout << endl;
}

template <typename T>
void vDeleteList(Node<T>*& ptrList)
{
    Node<T>* ptrFoo = ptrList;

    // Itera sobre toda a lista
    while (ptrFoo != nullptr)
    {
        // Avança a lista
        ptrList = ptrList->ptrNext;

        // Libera o Foo (antecessor ao ptrList)
        free(ptrFoo);

        // Avança o Foo
        ptrFoo = ptrList;
    }
    
    ptrList = nullptr;
}

template <typename T>
void vSwapElements(Node<T>* ptrNode1, Node<T>* ptrNode2)
{
    // Cria uma variável temporária
    int iTempValue = ptrNode1->iValue;

    // E troca os elementos
    ptrNode1->iValue = ptrNode2->iValue;
    ptrNode2->iValue = iTempValue;
}

template <typename T>
T iFindElement(Node<T>* ptrList, int iPosition)
{
    // Tratamento de erros
    if (iPosition < 0)
    {
        cout << "Posição inexistente! \n";
        return -1;
    }

    if (ptrList == nullptr)
    {
        cout << "Lista vazia! \n";
        return -1;
    }

    // Acha o elemento naquela posição
    Node<T>* ptrFoo = ptrList;

    for (int i = 0; i < iPosition; i++)
    {
        ptrFoo = ptrFoo->ptrNext;

        // Caso termine a lista antes da hora
        if (ptrFoo == nullptr)
        {
            cout << "Posição inexistente! \n";
            return -1;
        }
    }

    return ptrFoo->iValue;
}

template <typename T>
Node<T>* ptrConvertArrayList(T arriSorted[], int iSize)
{
    // Itera sobre o array em ordem reversa para adicionar mais rápido
    Node<T>* ptrList = ptrCreateList<T>();

    for (int i = iSize - 1; i > -1; i--)
    {
        vAddElemFront(ptrList, arriSorted[i]);
    }

    return ptrList;
}

}

namespace RandomLists
{

template <typename T>
LinkedList::Node<T>* ptrGenerateRandomList(int iSize)
{
    // Cria uma lista com elementos aleatórios de tamanho iSize
    LinkedList::Node<T>* ptrNewList = LinkedList::ptrCreateList<T>();

    for (int i = 0; i < iSize; i++)
    {
        LinkedList::vAddElemFront(ptrNewList, randint<T>(1, 100));
    }

    return ptrNewList;
}

template <typename T>
void vRandomTests(int iAmount, int iSize, void (*fSort)(LinkedList::Node<T>*& ptrList))
{   
    for (int i = 0; i < iAmount; i++)
    {
        // Gera uma lista
        LinkedList::Node<T>* ptrList = ptrGenerateRandomList<T>(iSize);

        // Mede o tempo
        auto aTimeStart = high_resolution_clock::now();
        fSort(ptrList);
        auto aTimeEnd = high_resolution_clock::now();

        // E adiciona ao tempo total
        auto aDuration = duration_cast<microseconds> (aTimeEnd - aTimeStart);
        cout << aDuration.count() << endl;

        // Limpa da memória
        LinkedList::vDeleteList<T>(ptrList);
    }

    return;
}

template <typename T>
void vRandomListsTime(int iAmount, int iSize)
    {
        for (int i = 0; i < iAmount; i++)
        {
            LinkedList::Node<T>* ptrList = nullptr;

            // Mede o tempo de geração de uma árvore
            auto aTimeStart = high_resolution_clock::now();
            ptrList = ptrGenerateRandomList<T>(iSize);
            auto aTimeEnd = high_resolution_clock::now();

            // E move para cout
            auto aDuration = duration_cast<microseconds> (aTimeEnd - aTimeStart);
            cout << aDuration.count() << endl;

            // Limpa da memória
            LinkedList::vDeleteList<T>(ptrList);
        }
    }

}
