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
        int* nodesAtLevel(int level);
        int Level(int node);
        int height();
        void Preorder();
        void display();
};

void Tree::display()
{
    for(int i = 0; i < size; ++i)
    {
        cout << _parentArray[i] << " , ";
    }
    cout << endl;
}
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

void Tree::setRoot(int& rootNode)
{
    _parentArray[rootNode] = -1;
    root = &rootNode;
}

void Tree::setParent(int node, int parent)
{
    _parentArray[node] = parent;

}

int* Tree::nodesAtLevel(int level)
{
    if(level > height())
    {
        return new int(-1);
    }
    int* nodes = new int;
    int count = 0;
    for(int i = 0; i < size; ++i)
    {
        if(Level(i)==level)
        {
            nodes[count] = i;
            count++;
        }
    }
    return nodes;
}

int Tree::Level(int node)
{
    int parent = _parentArray[node];
    int level = 1;
    while(parent!=-1)
    {
        level++;
        parent = _parentArray[parent];
    }
    return level;
}

int Tree::height()
{
    int parent;
    int biggestHeight = 0, height = 1;
    for(int i = 0; i < size; ++i)
    {
        parent = _parentArray[i];
        while(parent!=-1)
        {
            height++;
            parent = _parentArray[parent];
        }
        if(height>biggestHeight)
        {
            biggestHeight = height;
        }
        height = 1;
    }
    return biggestHeight;
}

int main()
{
    Tree tree(7);
    int root = 3;
    tree.setRoot(root);
    tree.setParent(1, 3);
    tree.setParent(2, 3);
    tree.setParent(0, 1);
    tree.setParent(4, 1);
    tree.setParent(5, 2);
    tree.setParent(6, 5);
    tree.display();
    cout << tree.height() << endl;
    cout << tree.Level(0) << endl;
    cout << tree.Parent(4) << endl;
    int* starArray = tree.Children(5);
    cout << starArray[0];
    //cout << endl << starArray[1];
}
