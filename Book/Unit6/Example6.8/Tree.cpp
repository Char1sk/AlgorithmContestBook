#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

struct TreeNode
{
    int value;
    int parent = -1;
    int minSum = 0;
    bool used = false;
    int minLeaf;
};

void makeTree(int i, const std::vector<int> &inOrder, const std::vector<int> &postOrder,
              std::vector<bool> &isRoot, std::vector<TreeNode> &nodes, std::map<int, int> &pos)
{
    int len = inOrder.size();
    // auto it = std::find(inOrder.begin(), inOrder.end(), postOrder[i]);
    int idx = pos[postOrder[i]];
    isRoot[idx] = true;
    nodes[i].used = true;
    nodes[i].value = postOrder[i];
    // find right children
    if (idx != len-1 && !isRoot[idx+1])
    {
        nodes[i-1].parent = i;
        makeTree(i-1, inOrder, postOrder, isRoot, nodes, pos);
    }
    // find left children
    if (idx != 0 && !isRoot[idx-1])
    {
        
        int j = i-1;
        while (j >= 0 && nodes[j].used)
        {
            --j;
        }
        if (j >= 0)
        {
            nodes[j].parent = i;
            makeTree(j, inOrder, postOrder, isRoot, nodes, pos);
        }
    }
}

int main()
{
    std::string line1, line2;
    while (std::getline(std::cin, line1) && std::getline(std::cin, line2))
    {
        std::istringstream iss1(line1);
        std::istringstream iss2(line2);
        std::vector<int> inOrder;
        std::vector<int> postOrder;
        std::map<int, int> inOrderPos;
        int len = 0;
        int itemp;
        while (iss1 >> itemp)
        {
            inOrder.push_back(itemp);
            inOrderPos[itemp] = len++;
            iss2 >> itemp;
            postOrder.push_back(itemp);
        }
        // int len = inOrder.size();
        std::vector<TreeNode> nodes(len);
        std::vector<bool> isRoot(len, false);
        // std::vector<int> myRoot(len, 0);
        
        makeTree(len-1, inOrder, postOrder, isRoot, nodes, inOrderPos);
        
        for (int i = 0; i < len; ++i)
        {
            auto &self = nodes[i];
            if (self.minSum == 0)
            {
                self.minSum = self.value;
                self.minLeaf = self.value;
            }
            if (self.parent != -1)
            {
                auto &prnt = nodes[self.parent];
                if (prnt.minSum == 0 || prnt.minSum > prnt.value + self.minSum)
                {
                    prnt.minSum = prnt.value + self.minSum;
                    prnt.minLeaf = self.minLeaf;
                }
            }
        }
        
        std::cout << nodes.back().minLeaf << std::endl;
    }
    return 0;
}