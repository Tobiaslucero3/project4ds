#include <iostream>

using namespace std;

class Tree{
    protected:
        int* _parentArray;
        int* root;
        int size;
    public:
        Tree();
        Tree(int numNodes);
        Tree(Tree& tree);
        ~Tree();
        int& LCA(int node, int otherNode);
        int Parent(int i);
        int* Children(int node);
        int* Siblings(int node);
        void setRoot(int& rootNode);
        void setParent(int node, int parent);
        int nodesAtLevel(int i);
        int Level(int i);
        int height();
        void Preorder();
};

Tree::Tree()
{
    _parentArray = new int[0];
    size = 0;
}

Tree::Tree(int numNodes)
{
    _parentArray = new int[numNodes];
    size = numNodes;
}

Tree::Tree(Tree& tree)
{
    _parentArray = new int[tree.size];
    for(int i = 0; i < tree.size; ++i)
    {
        _parentArray[i] = tree._parentArray[i];
    }
}

Tree::~Tree()
{

}

int& Tree::LCA(int node, int otherNode)
{

}

int Tree::Parent(int i)
{
    if(i>size)
    {
        return -1;
    }
    return (_parentArray[i]);
}

int* Tree::Children(int node)
{
    int* children = new int;
    int count = 0;
    for(int i = 0; i < size; ++i)
    {
        if(((_parentArray[i])==node)&&(i!=node))
        {
            children[count] = i;
            count++;
        }
    }
    if(count==0)
    {
        children[0] = -1;
    }
    return children;
}

int* Tree::Siblings(int node)
{
    if(node > size)
    {
        return new int(-1);
    }
    int parent = _parentArray[node];
    int* siblings = new int;
    int count = 0;
    for(int i = 0; i < size; ++i)
    {
        //cout << parent << endl;
        //cout << (_parentArray[i]==parent) << endl;
        if((_parentArray[i]==parent)&&(i!=node))
        {
            cout << "LOL" << endl;
            siblings[count] = i;
            count++;
        }
    }
    if (count==0)
    {
        siblings[0] = -1;
    }
    return siblings;
}

int main()
{
    Tree  tree;
    Tree  tree1(3);
    tree.LCA(0, 0);
    cout << *tree.Children(0) << endl;
    cout << tree1.Parent(2) << endl;
    cout << *tree1.Siblings(2);
    return 0;
}
