#include <iostream>
#include <vector>
#include <deque>
#include <cstring>

const int INF = 0x3f3f3f3f;
const int maxPoint = 1000;
int graph[maxPoint][maxPoint];

int main()
{
    int pointCnt, edgeCnt;
    while (std::cin >> pointCnt >> edgeCnt)
    {
        memset(graph, 0, sizeof(graph));
        for (int e = 0; e < edgeCnt; ++e)
        {
            int p1, p2, w;
            std::cin >> p1 >> p2 >> w;
            --p1;   --p2;
            if (p1 != p2 && (graph[p1][p2] == 0 || graph[p1][p2] > w))
            {
                graph[p1][p2] = w;
                graph[p2][p1] = w;
            }
        }
        std::vector<int> dists(pointCnt, INF);
        std::deque<bool> visit(pointCnt, false);
        dists[0] = 0;
        bool canDone = true;
        int total = 0;
        for (int p = 0; p < pointCnt; ++p)
        {
            int minIndex = -1;
            for (int pp = 0; pp < pointCnt; ++pp)
            {
                if (!visit[pp] && (minIndex==-1 || dists[minIndex] > dists[pp]))
                {
                    minIndex = pp;
                }
            }
            if (minIndex == -1)
            {
                canDone = false;
                break;
            }
            visit[minIndex] = true;
            for (int pp = 0; pp < pointCnt; ++pp)
            {
                if (!visit[pp] && graph[minIndex][pp] != 0 && dists[pp] > graph[minIndex][pp])
                {
                    dists[pp] = graph[minIndex][pp];
                }
            }
            total += dists[minIndex];
        }
        std::cout << (canDone ? total : -1) << std::endl;
    }
    return 0;
}