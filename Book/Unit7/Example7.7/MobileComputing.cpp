#include <iostream>
#include <vector>

struct Node
{
    int weight;
    double leftLen;
    double rightLen;
    Node *left;
    Node *right;
    Node(int w = 0) : weight(w), leftLen(0), rightLen(0), left(nullptr), right(nullptr) {}
    int calWeight()
    {
        if (this)
        {
            if (weight == 0)
            {
                weight = left->calWeight() + right->calWeight();
            }
            return weight;
        }
        return 0;
    }
};

Node *rt = nullptr;

void *buildTree(Node *root, std::vector<int> &leafs, int &leafCount, int maxCount)
{
    if (leafs.size() == 1)
    {
        root = new Node(leafs[0]);
        ++leafCount;
        if (leafCount == maxCount)
        {
            rt->calWeight();
            std::cout << rt->weight << std::endl;////
        }
    }
    else
    {
        for (int s = 1; s < (1<<leafs.size()); ++s)
        {
            int temp = leafCount;
            std::vector<int> lv, rv;
            for (int b = 0; b < leafs.size(); ++b)
            {
                if (1&(s>>b))
                {
                    lv.push_back(leafs[b]);
                }
                else
                {
                    rv.push_back(leafs[b]);
                }
            }
            root = new Node();
            buildTree(root->left, lv, leafCount, maxCount);
            buildTree(root->right, rv, leafCount, maxCount);
            
            // delete root;
            leafCount = temp;
        }
    }
}

void clearTree(Node *t)
{
    if (t)
    {
        clearTree(t->left);
        clearTree(t->right);
        delete t;
    }
}

int main()
{
    int cases;
    std::cin >> cases;
    while (cases--)
    {
        double totalWid;
        int stoneCount;
        std::vector<int> stones(stoneCount);
        std::cin >> totalWid >> stoneCount;
        for (int i = 0; i < stoneCount; ++i)
        {
            std::cin >> stones[i];
        }
        
        rt = nullptr;
        int cnt = 0;
        buildTree(rt, stones, cnt, stoneCount);
        clearTree(rt);
    }
    return 0;
}