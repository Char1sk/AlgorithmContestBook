#include <iostream>
#include <vector>
#include <map>

struct Edge
{
    std::map<int, int> inputCount;
    std::map<int, int> outputCount;
    Edge() {}
};


int main()
{
    int cases = 0;
    int vertCnt;
    while (std::cin >> vertCnt && vertCnt)
    {
        std::vector<int> vertTokenCount(vertCnt+1, 0);
        for (int i = 1; i < vertCnt+1; ++i)
        {
            std::cin >> vertTokenCount[i];
        }
        
        int edgeCnt;
        std::cin >> edgeCnt;
        std::vector<Edge> edges(edgeCnt);
        for (int i = 0; i < edgeCnt; ++i)
        {
            int itemp;
            while (std::cin >> itemp && itemp)
            {
                if (itemp < 0)
                {
                    ++edges[i].inputCount[-itemp];
                }
                if (itemp > 0)
                {
                    ++edges[i].outputCount[itemp];
                }
            }
        }
        
        int nowFireCount = 0;
        int maxFireCount;
        std::cin >> maxFireCount;
        while (nowFireCount < maxFireCount)
        {
            bool isAlive = false;
            for (auto &e : edges)
            {
                bool canTrans = true;
                for (auto &p : e.inputCount)
                {
                    if (vertTokenCount[p.first] < p.second)
                    {
                        canTrans = false;
                        break;
                    }
                }
                if (canTrans)
                {
                    for (auto &p : e.inputCount)
                    {
                        vertTokenCount[p.first] -= p.second;
                    }
                    for (auto &p : e.outputCount)
                    {
                        vertTokenCount[p.first] += p.second;
                    }
                    isAlive = true;
                    break;
                }
            }
            if (isAlive)
            {
                ++nowFireCount;
            }
            else
            {
                break;
            }
        }
        
        if (nowFireCount == maxFireCount)
        {
            printf("Case %d: still live after %d transitions\n", ++cases, nowFireCount);
        }
        else
        {
            printf("Case %d: dead after %d transitions\n", ++cases, nowFireCount);
        }
        printf("Places with tokens:");
        for (int i = 1; i < vertCnt+1; ++i)
        {
            if (vertTokenCount[i])
            {
                printf(" %d (%d)", i, vertTokenCount[i]);
            }
        }
        std::cout << std::endl << std::endl;
    }
    return 0;
}