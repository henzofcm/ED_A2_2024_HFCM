#include "tree.hpp"
#include <fstream>

void vRecordData(std::string strName, int iAmount, int iSize, void (*fFunc)(int iAmount, int iSize))
{
    // Redireciona cout para um arquivo
    std::ofstream ofFile(strName);
    std::cout.rdbuf(ofFile.rdbuf());

    // Mede o tempo de fFunc de iAmount objetos com iSize elementos
    fFunc(iAmount, iSize);
    ofFile.close();
}

int main(void)
{
    // Mede o tempo de criação de 100 árvores com 1000 elementos
    vRecordData("treeTime.txt", 100, 10000, RandomTrees::vRandomTreesTime);

    // Mede o tempo de criação de 100 listas com 1000 elementos
    vRecordData("listTime.txt", 100, 10000, RandomLists::vRandomListsTime<int>);


    // Redireciona cout
    std::ofstream ofFile1("treeDFS.txt");
    std::cout.rdbuf(ofFile1.rdbuf());

    // Mede o tempo de busca em árvores por DFS
    RandomTrees::vRandomTests(100, 10000, Tree::ptrSearchNodeDFS);
    ofFile1.close();


    // Redireciona cout
    std::ofstream ofFile2("treeBFS.txt");
    std::cout.rdbuf(ofFile2.rdbuf());

    // Mede o tempo de busca em árvores por BFS
    RandomTrees::vRandomTests(100, 10000, Tree::ptrSearchNodeBFS);
    ofFile2.close();
}
