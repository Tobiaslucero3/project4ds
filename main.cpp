#include <iostream>

using namespace std;

template <class DT>
class Tree{
    protected:
        int* _parentArray[];
        int root;
    public:
        Tree();
        Tree(int numNodes);
        Tree(Tree tree);
        ~Tree();
        void LCA(int node, int otherNode);
        int& Parent(int i);
        int[] Children(int i);
        int[] Siblings(int i);
        void setRoot(int& rootNode);
        void setParent(int node, int parent);
        int nodesAtLevel(int i);
        int Level(int i);
        int height();
        void Preorder();


};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
