#include <iostream>
#include <vector>
#include <deque>

const int INF = 0x3f3f3f3f;
// const int INF = 0x7fffffff;

struct Info
{
    int dist;
    int cost;
    Info() : dist(INF), cost(INF) {}
    Info(int d, int c) : dist(d), cost(c) {}
    bool operator< (const Info &i) const
    {
        return (dist < i.dist) || (dist == i.dist && cost < i.cost);
    }
    Info operator+ (const Info &i) const
    {
        return Info(dist+i.dist, cost+i.cost);
    }
};

int main()
{
    int pointCnt, edgeCnt;
    while (scanf("%d %d", &pointCnt, &edgeCnt) && pointCnt && edgeCnt)
    {
        std::vector<std::vector<Info>> graph(pointCnt, std::vector<Info>(pointCnt));
        while (edgeCnt--)
        {
            int p1, p2, dist, cost;
            // std::cin >> p1 >> p2 >> dist >> cost;
            scanf("%d %d %d %d", &p1, &p2, &dist, &cost);
            --p1;   --p2;
            Info tinfo(dist, cost);
            if (tinfo < graph[p1][p2])
            {
                graph[p1][p2] = tinfo;
            }
            if (tinfo < graph[p2][p1])
            {
                graph[p2][p1] = tinfo;
            }
            // graph[p1-1][p2-1].dist = dist;
            // graph[p1-1][p2-1].cost = cost;
            // graph[p2-1][p1-1].dist = dist;
            // graph[p2-1][p1-1].cost = cost;
        }
        
        int start, end;
        // std::cin >> start >> end;
        scanf("%d %d", &start, &end);
        --start;
        --end;
        std::vector<Info> dists(pointCnt);
        std::deque<bool> visited(pointCnt, false);
        dists[start].dist = 0;
        dists[start].cost = 0;
        for (int t = 0; t < pointCnt; ++t)
        {
            int minIndex = -1;
            for (int p = 0; p < pointCnt; ++p)
            {
                if (!visited[p] && (minIndex == -1 || dists[p] < dists[minIndex]))
                {
                    minIndex = p;
                }
            }
            if (minIndex == end)
            {
                break;
            }
            
            if (minIndex != -1)
            {
                visited[minIndex] = true;
                for (int p = 0; p < pointCnt; ++p)
                {
                    if (!visited[p] && dists[minIndex] + graph[minIndex][p] < dists[p])
                    {
                        dists[p] = dists[minIndex] + graph[minIndex][p];
                    }
                }
            }
        }
        // std::cout << dists[end].dist << ' ' << dists[end].cost << std::endl;
        printf("%d %d\n", dists[end].dist, dists[end].cost );
    }
    return 0;
}