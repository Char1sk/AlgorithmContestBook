#include <iostream>
#include <vector>
#include <queue>

void connect(std::vector<std::vector<int>> &g, char c1, char c2, char c3, char c4)
{
    if (c1 != '0' && c3 != '0')
    {
        int i = 2*(c1-'A') + (c2 == '-');
        int j = 2*(c3-'A') + (c4 == '-');
        g[i^1].push_back(j);
    }
}

bool bfsCheckCircle(std::vector<std::vector<int>> &g)
{
    int indegrees[52] = {0};
    int totaldeg = 0;
    for (auto &iv : g)
    {
        for (auto i : iv)
        {
            ++indegrees[i];
            ++totaldeg;
        }
    }
    
    std::queue<int> outQ;
    for (int i = 0; i < 52; ++i)
    {
        if (indegrees[i] == 0)
        {
            outQ.push(i);
        }
    }
    
    int outdeg = 0;
    while (!outQ.empty())
    {
        int frt = outQ.front();
        outQ.pop();
        for (auto i : g[frt])
        {
            --indegrees[i];
            ++outdeg;
            if (indegrees[i] == 0)
            {
                outQ.push(i);
            }
        }
    }
    
    return outdeg == totaldeg;
}

int main()
{
    int blockCnt;
    while (std::cin >> blockCnt)
    {
        std::vector<std::vector<int>> graph(52);
        while (blockCnt--)
        {
            std::string block;
            std::cin >> block;
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    if (i != j)
                    {
                        connect(graph, block[2*i], block[2*i+1], block[2*j], block[2*j+1]);
                    }
                }
            }
        }
        
        bool noCircle = bfsCheckCircle(graph);
        std::cout << (noCircle ? "bounded" : "unbounded") << std::endl;
    }
    return 0;
}