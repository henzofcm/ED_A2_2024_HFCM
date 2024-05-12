#include <random>
#include <chrono>
#include <iostream>

/*  ---- IMPORTAÇÕES DE RANDOM ----  */
using std::rand;

/*  ---- IMPORTAÇÕES DE CHRONO ----  */
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;

/*  ---- IMPORTAÇÕES DE IOSTREAM ----  */
using std::cout;
using std::endl;


typedef struct Node
{
    int iValue;
    Node* ptrNext;
    Node* ptrLast;
} Node;


/*  ---- FUNÇÕES BASE DE LISTA DUPLAMENTE ENCADEADA ----  */
Node* ptrCreateList(void);
Node* ptrCreateNode(int iValue);
void vAddElemFront(Node*& ptrList, int iValue);
void vAddElemEnd(Node*& ptrList, int iValue);
void vPrintList(Node* ptrList);
void vDeleteList(Node*& ptrList);
void vSwapElements(Node* ptrNode1, Node* ptrNode2);

/*  ---- FUNÇÕES EXTRAS PARA TESTES ----  */
Node* ptrGenerateRandomList(int iSize);
int64_t iRandomTests(int iAmount, int iSize, void (*fSort)(Node*& ptrList));

int main()
{
    return 0;
}

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


Node* ptrGenerateRandomList(int iSize)
{
    // Cria uma lista com elementos aleatórios de tamanho iSize
    Node* ptrNewList = ptrCreateList();

    for (int i = 0; i < iSize; i++)
    {
        vAddElemFront(ptrNewList, rand());
    }

    return ptrNewList;
}

int64_t iRandomTests(int iAmount, int iSize, void (*fSort)(Node*& ptrList))
{
    // Salvará o tempo total gasto em todas iterações
    int64_t iTotalTime = 0;
    
    for (int i = 0; i < iAmount; i++)
    {
        // Gera uma lista
        Node* ptrList = ptrGenerateRandomList(iSize);

        // Mede o tempo
        auto aTimeStart = high_resolution_clock::now();
        fSort(ptrList);
        auto aTimeEnd = high_resolution_clock::now();

        // E adiciona ao tempo total
        auto aDuration = duration_cast<nanoseconds> (aTimeEnd - aTimeStart);
        iTotalTime += aDuration.count();

        // Limpa da memória
        vDeleteList(ptrList);
    }

    return iTotalTime;
}
