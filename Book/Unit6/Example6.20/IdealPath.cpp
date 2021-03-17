#include <iostream>
#include <map>
#include <queue>

// v1 to v2 with weight w
std::vector<std::map<int, int>> graph;
// minimum distance from i to n
std::vector<int> minDist;
// color on the minimum path
std::vector<int> minColor;

int main()
{
    int verCnt, edgCnt;
    while (std::cin >> verCnt >> edgCnt)
    {
        graph.clear();
        graph.resize(verCnt+1);
        while (edgCnt--)
        {
            int v1, v2, color;
            std::cin >> v1 >> v2 >> color;
            if (v1 != v2)
            {
                if (graph[v1][v2] == 0 || graph[v1][v2] > color)
                {
                    graph[v1][v2] = color;
                }
                if (graph[v2][v1] == 0 || graph[v2][v1] > color)
                {
                    graph[v2][v1] = color;
                }
            }
        }
        
        std::queue<int> bfsQ;
        
        minDist.clear();
        minDist.resize(verCnt+1);
        bfsQ.push(verCnt);
        while (!bfsQ.empty())
        {
            int now = bfsQ.front();
            bfsQ.pop();
            int nextDist = minDist[now] + 1;
            for (auto &p : graph[now])
            {
                int thisDist = minDist[p.first];
                if (p.first != verCnt && (thisDist == 0 || thisDist > nextDist))
                {
                    minDist[p.first] = nextDist;
                    bfsQ.push(p.first);
                }
            }
        }
        int minD = minDist[1];
        std::cout << minD << std::endl;
        
        minColor.clear();
        minColor.resize(minD+1);
        bfsQ.push(1);
        while (!bfsQ.empty())
        {
            int now = bfsQ.front();
            bfsQ.pop();
            int &nowColor = minColor[minDist[now]];
            for (auto &p : graph[now])
            {
                int thisColor = p.second;
                if (minDist[now] == minDist[p.first]+1 && (nowColor == 0 || nowColor > thisColor))
                {
                    nowColor = thisColor;
                }
            }
            for (auto &p : graph[now])
            {
                int thisColor = p.second;
                if (nowColor == thisColor)
                {
                    bfsQ.push(p.first);
                }
            }
        }
        
        for (int i = minD; i > 0; --i)
        {
            std::cout << minColor[i] << (i == 1 ? '\n' : ' ') ;
        }
    }
    return 0;
}