#include "tree.hpp"

int main(void)
{
    Tree::Node* ptrTree = Tree::ptrCreateNode(10);
    Tree::vInsertNode(ptrTree, 8);
    Tree::vInsertNode(ptrTree, 4);
    Tree::vInsertNode(ptrTree, 2);
    Tree::vInsertNode(ptrTree, 1);
    Tree::vInsertNode(ptrTree, 12);
    Tree::vInsertNode(ptrTree, 11);
    Tree::vInsertNode(ptrTree, 16);
    Tree::vInsertNode(ptrTree, 7);
    Tree::vInsertNode(ptrTree, 15);
    Tree::vInsertNode(ptrTree, 21);
    Tree::vInsertNode(ptrTree, 3);
    Tree::vInsertNode(ptrTree, 9);

    Tree::vPrintTree(ptrTree, 0);
    cout << endl << Tree::ptrSearchNodeBFS(ptrTree, 15)->iValue << endl;
    Tree::vDeleteTree(ptrTree);
}
