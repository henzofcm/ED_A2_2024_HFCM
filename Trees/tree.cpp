#include "tree.hpp"

namespace Tree
{
    Node* ptrCreateNode(int iValue)
    {
        // Cria o nó
        Node* ptrNode = (Node*) malloc(sizeof(Node));

        // Caso ocorra algum erro
        if (ptrNode == nullptr)
        {
            cerr << "Erro em ptrCreateNode: malloc" << endl;
            std::exit(1);
        }

        // Atribui seus elementos
        ptrNode->iValue = iValue;
        ptrNode->ptrLeft = nullptr;
        ptrNode->ptrRight = nullptr;

        return ptrNode;
    }

    void vInsertNode(Node*& ptrRoot, int iValue)
    {
        // Caso a raiz passada seja NULL, cria uma nova
        if (ptrRoot == nullptr)
        {
            ptrRoot = ptrCreateNode(iValue);
            return;
        }

        // Insere recursivamente, com menores na esquerda
        if (iValue < ptrRoot->iValue)
        {
            vInsertNode(ptrRoot->ptrLeft, iValue);
        }
        else
        {
            vInsertNode(ptrRoot->ptrRight, iValue);
        }

        return;
    }

    void vPrintTree(Node* ptrRoot, int iSpace)
    {
        // Caso base
        if (ptrRoot == nullptr)
            return;
 
        // Aumenta o espaçamento
        iSpace += 6;
 
        // Começa pela direita
        vPrintTree(ptrRoot->ptrRight, iSpace);
 
        // Printa o valor após o espaçamento adequado
        cout << endl;
        for (int i = 6; i < iSpace; i++)
            cout << " ";
        
        cout << ptrRoot->iValue;
 
        // Vai para a esquerda
        vPrintTree(ptrRoot->ptrLeft, iSpace);
    }

    void vDeleteTree(Node*& ptrRoot)
    {
        // Deleta recursivamente por Depth-First em pós-ordem
        if (ptrRoot != nullptr)
        {
            vDeleteTree(ptrRoot->ptrLeft);
            vDeleteTree(ptrRoot->ptrRight);

            // Libera da memória e muda o ponteiro
            free(ptrRoot);
            ptrRoot = nullptr;
        }

        return;
    }

    Node* ptrSearchNodeDFS(Node* ptrRoot, int iValue)
    {
        // Caso a raiz seja nula
        if (ptrRoot == nullptr)
            return nullptr;

        // Se a raiz atual for o valor, retorna-o
        if (ptrRoot->iValue == iValue)
        {
            return ptrRoot;
        }
        else
        {
            // Caso contrário, pesquisa pela esquerda
            Node* ptrTemp = ptrSearchNodeDFS(ptrRoot->ptrLeft, iValue);

            if (ptrTemp != nullptr)
                return ptrTemp;

            // E depois pela direita
            ptrTemp = ptrSearchNodeDFS(ptrRoot->ptrRight, iValue);

            return ptrTemp;
        }
    }

    Node* ptrSearchNodeBFS(Node* ptrRoot, int iValue)
    {
        // Caso a árvore esteja vazia, não há o que achar
        if (ptrRoot == nullptr)
            return nullptr;

        // Cria uma lista encadeada que suporta elementos Tree::Node*
        // Onde será salvo toda camada a ser visitada (esquerda -> direita)
        LinkedList::Node<Node*>* ptrList = LinkedList::ptrCreateList<Node*>();

        // Adiciona ptrRoot nela
        LinkedList::vAddElemEnd(ptrList, ptrRoot);

        // Percorre a lista enquanto ela não estiver vazia
        while(ptrList != nullptr)
        {
            Node* ptrNode = ptrList->iValue;

            // Se achar o valor, apaga a lista encadeada e retorna
            if (ptrNode->iValue == iValue)
            {
                LinkedList::vDeleteList(ptrList);
                return ptrNode;
            }

            // Adiciona o nó da esquerda da raíz atual
            if (ptrNode->ptrLeft != nullptr)
                LinkedList::vAddElemEnd(ptrList, ptrNode->ptrLeft);

            // Adiciona o nó da direita
            if (ptrNode->ptrRight != nullptr)
                LinkedList::vAddElemEnd(ptrList, ptrNode->ptrRight);

            // Remove a folha visitada da lista encadeada
            LinkedList::vRmvElemFront(ptrList);
        }

        // Se não achar nada, o elemento não existe
        free(ptrList);
        return nullptr;
    }

}

namespace RandomTrees
{
    Tree::Node* ptrGenerateRandomTree(int iSize)
    {
        // Cria uma árvore vazia
        Tree::Node* ptrTree = nullptr;

        // Adiciona iSize elementos aleátorios nela
        for (int i = 0; i < iSize; i++)
        {
            Tree::vInsertNode(ptrTree, randint<int>(1, 100));
        }

        return ptrTree;
    }

    void vRandomTests(int iAmount, int iSize, Tree::Node* (*fSearch)(Tree::Node* ptrRoot, int iValue))
    {
        for (int i = 0; i < iAmount; i++)
        {
            // Gera uma árvore
            Tree::Node* ptrTree = ptrGenerateRandomTree(iSize);

            // Mede o tempo de uma busca
            auto aTimeStart = high_resolution_clock::now();
            fSearch(ptrTree, randint<int>(1, 100));
            auto aTimeEnd = high_resolution_clock::now();

            // E move para cout
            auto aDuration = duration_cast<microseconds> (aTimeEnd - aTimeStart);
            cout << aDuration.count() << endl;

            // Limpa da memória
            Tree::vDeleteTree(ptrTree);
        }
    }

    void vRandomTreesTime(int iAmount, int iSize)
    {
        for (int i = 0; i < iAmount; i++)
        {
            Tree::Node* ptrTree = nullptr;

            // Mede o tempo de geração de uma árvore
            auto aTimeStart = high_resolution_clock::now();
            ptrTree = ptrGenerateRandomTree(iSize);
            auto aTimeEnd = high_resolution_clock::now();

            // E move para cout
            auto aDuration = duration_cast<microseconds> (aTimeEnd - aTimeStart);
            cout << aDuration.count() << endl;

            // Limpa da memória
            Tree::vDeleteTree(ptrTree);
        }
    }


}
