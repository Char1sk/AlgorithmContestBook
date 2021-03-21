#include <iostream>
#include <string>
#include <vector>
#include <queue>

struct Node
{
    long long weight;
    int leftIndex;
    int rightIndex;
    Node(long long w = 0, int li = -1, int ri = -1) : weight(w), leftIndex(li), rightIndex(ri) {}
};

int buildTree(std::vector<Node> &v, const std::string &s, std::queue<int> sepList[20],
              int left, int right, long long &weight, int layer)
{
    int selfIndex = v.size();
    v.emplace_back();
    if (s[left] == '[')
    {
        ++layer;
        int sep = sepList[layer].front();
        sepList[layer].pop();
        
        long long lw = 0, rw = 0;
        int li = buildTree(v, s, sepList, left+1, sep, lw, layer);
        int ri = buildTree(v, s, sepList, sep+1, right, rw, layer);
        weight = lw + rw;
        v[selfIndex].weight = lw + rw;
        v[selfIndex].leftIndex = li;
        v[selfIndex].rightIndex = ri;
    }
    else
    {
        long long val = std::stoll(s.substr(left, right-left));
        weight = val;
        v[selfIndex].weight = val;
    }
    return selfIndex;
}

int main()
{
    int cases;
    std::cin >> cases;
    while (cases--)
    {
        std::string input;
        std::cin >> input;
        std::vector<Node> tree;
        long long useless = 0;
        
        std::queue<int> sepList[20];
        for (int i = 0, layer = 0; i < input.size(); ++i)
        {
            char c = input[i];
            if (c == '[')
            {
                ++layer;
            }
            if (c == ']')
            {
                --layer;
            }
            if (c == ',')
            {
                sepList[layer].push(i);
            }
        }
        
        buildTree(tree, input, sepList, 0, input.size(), useless, 0);
        std::cout << "sb" << std::endl;////
    }
    return 0;
}