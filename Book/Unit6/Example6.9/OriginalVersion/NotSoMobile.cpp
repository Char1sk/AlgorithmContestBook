#include <iostream>
#include <vector>

struct Node
{
    int weight = 0;
    int leftLen = 0;
    int rightLen = 0;
    int leftIndex = 0;
    int rightIndex = 0;
    Node(int w) : weight(w) {}
    Node(int ll, int rl) : leftLen(ll), rightLen(rl) {}
};

int read(std::vector<Node> &nodes, bool &b)
{
    // static int times = 0;
    
    int lw, ll, rw, rl;
    std::cin >> lw >> ll >> rw >> rl;
    int ret = nodes.size();
    nodes.emplace_back(ll, rl);
    // FOR NO REASON I HAVE TO USE A TEMP INT!!!
    // OPERATOR '=' DONT CALCULATE RIGHT TO LEFT BUT UNDEFINED!!!
    if (lw == 0)
    {
        int i = read(nodes, b);
        nodes[ret].leftIndex = i;
        // std::cout << "leftindex" << i << nodes[ret].leftIndex << std::endl;////
    }
    else
    {
        nodes[ret].leftIndex = nodes.size();
        nodes.emplace_back(lw);
    }
    
    if (rw == 0)
    {
        int i = read(nodes, b);
        nodes[ret].rightIndex = i;
        // std::cout << "rightindex" << i << nodes[ret].rightIndex << std::endl;////
    }
    else
    {
        nodes[ret].rightIndex = nodes.size();
        nodes.emplace_back(rw);
    }
    
    int w1 = nodes[nodes[ret].leftIndex].weight;
    int w2 = nodes[nodes[ret].rightIndex].weight;
    nodes[ret].weight = w1 + w2;
    
    if (w1 * nodes[ret].leftLen != w2 * nodes[ret].rightLen)
    {
        b = false;
    }
    
    return ret;
}

int main()
{
    int cases;
    std::cin >> cases;
    while (cases--)
    {
        bool isBalanced = true;
        std::vector<Node> nodes;
        read(nodes, isBalanced);
        std::cout << (isBalanced ? "YES" : "NO") << std::endl;
        if (cases)
            std::cout << std::endl;
    }
    
    return 0;
}
// 1
// 0 1 0 2
// 2 1 2 1
// 1 2 1 2
// 