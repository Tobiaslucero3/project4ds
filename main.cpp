#include <iostream>

using namespace std;

template <class DT>
class Tree{
    protected:
        int _parentArray;
        int* root;
        int size;
    public:
        Tree();
        Tree(int numNodes);
        Tree(Tree<DT>& tree);
        ~Tree();
        int& LCA(int node, int otherNode);
        int& Parent(int i);
        int Children(int i);
        int Siblings(int i);
        void setRoot(int& rootNode);
        void setParent(int node, int parent);
        int nodesAtLevel(int i);
        int Level(int i);
        int height();
        void Preorder();
};

template <class DT>
Tree<DT>::Tree()
{
    _parentArray = new int[0];
    size = 0;
}

template <class DT>
Tree<DT>::Tree(int numNodes)
{
    _parentArray = new int[numNodes];
    size = numNodes;
}

template <class DT>
Tree<DT>::Tree(Tree<DT>& tree)
{
    _parentArray = new int[tree.size];
    for(int i = 0; i < tree.size; ++i)
    {
        _parentArray[i] = tree._parentArray[i];
    }
}

template <class DT>
Tree<DT>::~Tree()
{

}

int main()
{
    Tree<int> tree;
    return 0;
}
