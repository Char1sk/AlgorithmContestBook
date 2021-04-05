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
int maxW = -1;

void buildTree(Node *root, std::vector<int> &leafs, int &leafCount, int maxCount, int maxWid)
{
    if (leafs.size() == 1)
    {
        // root = new Node(leafs[0]);
        ++leafCount;
        if (leafCount == maxCount)
        {
            double ll = 0.0, rl = 0.0;
            for (Node *p = rt; p != nullptr; p = p->left)
            {
                ll += p->leftLen;
            }
            for (Node *p = rt; p != nullptr; p = p->right)
            {
                rl += p->rightLen;
            }
            if (maxW < ll + rl && ll + rl < maxWid)
            {
                maxW = ll + rl;
            }
            // rt->calWeight();
            // std::cout << rt->weight << std::endl;////
        }
    }
    else
    {
        for (int s = 1; s < (1<<leafs.size()); ++s)
        {
            int temp = leafCount;
            std::vector<int> lv, rv;
            int lw = 0, rw = 0;
            for (int b = 0; b < leafs.size(); ++b)
            {
                if (1&(s>>b))
                {
                    lv.push_back(leafs[b]);
                    lw += leafs[b];
                }
                else
                {
                    rv.push_back(leafs[b]);
                    rw += leafs[b];
                }
            }
            
            root = new Node(lw + rw);
            root->leftLen = 1.0 * rw / (lw + rw);
            root->rightLen = 1.0 * lw / (lw + rw);
            
            buildTree(root->left, lv, leafCount, maxCount, maxWid);
            buildTree(root->right, rv, leafCount, maxCount, maxWid);
            
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
        std::cin >> totalWid >> stoneCount;
        std::vector<int> stones(stoneCount, 0);
        for (int i = 0; i < stoneCount; ++i)
        {
            // std::cout << stones.size() << std::endl;////
            std::cin >> stones[i];
        }
        
        maxW = -1;
        rt = nullptr;
        int cnt = 0;
        buildTree(rt, stones, cnt, stoneCount, totalWid);
        std::cout << maxW << std::endl;
        clearTree(rt);
    }
    return 0;
}