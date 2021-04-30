#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>

const int INF = 0x3f3f3f3f;

struct Edge
{
    int pointA;
    int pointB;
    int weight;
    Edge() : pointA(0), pointB(0), weight(INF) {}
    Edge(int a, int b, int w) : pointA(a), pointB(b), weight(w) {}
    bool operator< (const Edge &e) const
    {
        return weight < e.weight;
    }
};

const int maxPoint = 10000+5;
int pointID[maxPoint];

int main()
{
    int pointCnt, edgeCnt;
    while (std::cin >> pointCnt >> edgeCnt)
    {
        std::map<std::pair<int,int>, int>graph;
        std::vector<Edge> edges;
        for (int p = 0; p < pointCnt; ++p)
        {
            pointID[p] = p;
        }

        for (int e = 0; e < edgeCnt; ++e)
        {
            int a, b, weight;
            scanf("%d %d %d", &a, &b, &weight);
            --a;    --b;
            if (a != b)
            {
                if (a > b)
                {
                    std::swap(a, b);
                }
                if (graph.find({a,b}) == graph.end())
                {
                    graph[{a,b}] = edges.size();
                    edges.emplace_back(a, b, weight);
                }
                else if (edges[graph[{a,b}]].weight > weight)
                {
                    edges[graph[{a,b}]].weight = weight;
                }
            }
        }
        std::sort(edges.begin(), edges.end());
        
        int cost = 0;
        int step = 0;
        for (Edge &e : edges)
        {
            if (pointID[e.pointA] != pointID[e.pointB])
            {
                int newID = pointID[e.pointA];
                int oldID = pointID[e.pointB];
                for (int p = 0; p < pointCnt; ++p)
                {
                    if (pointID[p] == oldID)
                    {
                        pointID[p] = newID;
                    }
                }
                cost += e.weight;
                ++step;
            }
            if (step == pointCnt-1)
                break;
        }
        std::cout << (step==pointCnt-1 ? cost : -1) << std::endl;
    }
    return 0;
}