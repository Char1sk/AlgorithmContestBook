#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

const int maxN = 50+5;
bool adjMat[maxN][maxN];

struct Node
{
    int cliqueSize;
    int level;
    // int maxLevel;
    int upperBound;
    std::vector<int> nodes;
    
    Node(int sz, int lvl, int ub) : 
            cliqueSize(sz), level(lvl), upperBound(ub) {}
    Node(const Node &n, int idx, int ub) : 
            cliqueSize(n.cliqueSize), level(n.level+1), upperBound(ub), nodes(n.nodes)
    {
        if (idx != -1)
        {
            ++cliqueSize;
            nodes.push_back(idx);
        }
    }
    bool operator<(const Node &n) const
    {
        return upperBound < n.upperBound;
    }
};


int main()
{
    int vcnt = 0;
    while (std::cin >> vcnt && vcnt)
    {
        memset(adjMat, 0, sizeof(adjMat));
        for (int i = 0; i < vcnt; ++i)
        {
            for (int j = 0; j < vcnt; ++j)
            {
                std::cin >> adjMat[i][j];
            }
        }
        
        int maxCnt = 0;
        std::priority_queue<Node>pq;
        pq.emplace(0, -1, 0);
        // for (int vidx = 0; vidx < vcnt; ++vidx)
        while (!pq.empty())
        {
            Node now = pq.top();
            pq.pop();
            if (now.level >= vcnt)
                break;
            // if choose
            bool choose = true;
            for (int idx : now.nodes)
            {
                if (!adjMat[idx][now.level+1])
                {
                    choose = false;
                    break;
                }
            }
            if (choose)
            {
                if (now.cliqueSize+1 > maxCnt)
                    maxCnt = now.cliqueSize+1;
                pq.emplace(now, now.level+1, vcnt-now.level+now.cliqueSize);
            }
            // if not choose
            if (vcnt-now.level+now.cliqueSize-1 > maxCnt)
            {
                pq.emplace(now, -1, vcnt-now.level+now.cliqueSize-1);
            }
        }
        
        std::cout << maxCnt << std::endl;
    }
    return 0;
}