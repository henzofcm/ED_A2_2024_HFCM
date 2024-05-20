#include "linkedlists.h"


Node* ptrCreateList(void)
{
    // Retorna, apropriadamente, uma lista vazia
    return nullptr;
}

Node* ptrCreateNode(int iValue)
{
    // Aloca memória para o Node
    Node* ptrList = (Node*) malloc(sizeof(Node));

    // Atribui valores aos atributos
    ptrList->iValue = iValue;
    ptrList->ptrNext = nullptr;
    ptrList->ptrLast = nullptr;

    return ptrList;
}

void vAddElemFront(Node*& ptrList, int iValue)
{
    // Cria o novo node
    Node* ptrNewElem = ptrCreateNode(iValue);

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

void vAddElemEnd(Node*& ptrList, int iValue)
{
    // Cria o novo node
    Node* ptrNewElem = ptrCreateNode(iValue);

    // Caso a lista esteja vazia, ela será o novo elemento
    if (ptrList == nullptr)
    {
        ptrList = ptrNewElem;
        return;
    }

    // Percorre toda a lista com um ponteiro indicador
    Node* ptrFoo = ptrList;

    while (ptrFoo->ptrNext != nullptr)
    {
        ptrFoo = ptrFoo->ptrNext;
    }

    // E adiciona-o no fim da mesma
    ptrNewElem->ptrLast = ptrList;
    ptrList->ptrNext = ptrNewElem;
}

void vPrintList(Node* ptrList)
{
    // Foo para atravessar a lista
    Node* ptrFoo = ptrList;

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

void vDeleteList(Node*& ptrList)
{
    Node* ptrFoo = ptrList;

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
}

void vSwapElements(Node* ptrNode1, Node* ptrNode2)
{
    // Cria uma variável temporária
    int iTempValue = ptrNode1->iValue;

    // E troca os elementos
    ptrNode1->iValue = ptrNode2->iValue;
    ptrNode2->iValue = iTempValue;
}

int iFindElement(Node* ptrList, int iPosition)
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
    Node* ptrFoo = ptrList;

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

Node* ptrConvertArrayList(int arriSorted[], int iSize)
{
    // Itera sobre o array em ordem reversa para adicionar mais rápido
    Node* ptrList = ptrCreateList();

    for (int i = iSize - 1; i > -1; i--)
    {
        vAddElemFront(ptrList, arriSorted[i]);
    }

    return ptrList;
}



Node* ptrGenerateRandomList(int iSize)
{
    // Cria uma lista com elementos aleatórios de tamanho iSize
    Node* ptrNewList = ptrCreateList();

    for (int i = 0; i < iSize; i++)
    {
        vAddElemFront(ptrNewList, randint<int>(1, 100));
    }

    return ptrNewList;
}

void vRandomTests(int iAmount, int iSize, void (*fSort)(Node*& ptrList))
{   
    for (int i = 0; i < iAmount; i++)
    {
        // Gera uma lista
        Node* ptrList = ptrGenerateRandomList(iSize);

        // Mede o tempo
        auto aTimeStart = high_resolution_clock::now();
        fSort(ptrList);
        auto aTimeEnd = high_resolution_clock::now();

        // E adiciona ao tempo total
        auto aDuration = duration_cast<microseconds> (aTimeEnd - aTimeStart);
        cout << aDuration.count() << endl;

        // Limpa da memória
        vDeleteList(ptrList);
    }

    return;
}

