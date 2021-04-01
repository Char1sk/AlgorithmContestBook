#include <iostream>
#include <vector>
#include <map>

void getBranch(std::vector<int> &graph, const std::vector<std::vector<int>> &edges, int &branch, int from, bool isStart)
{
    if (graph[from] == 0)
    {
        if (isStart)
        {
            graph[from] = ++branch;
        }
        else
        {
            graph[from] = branch;
        }
        for (int to : edges[from])
        {
            getBranch(graph, edges, branch, to, false);
        }
    }
}

int main()
{
    // freopen("./in.txt", "r", stdin);
    // freopen("./out.txt", "w", stdout);
    
    int cases = 0;
    int verCount, edgeCount, timeUse;
    while (std::cin >> verCount >> edgeCount >> timeUse && (verCount || edgeCount || timeUse))
    {
        std::vector<int> graph(verCount, 0);
        std::vector<std::vector<int>> edges(verCount);
        for (int i = 0; i < edgeCount; ++i)
        {
            int v1, v2;
            std::cin >> v1 >> v2;
            edges[v1-1].push_back(v2-1);
            edges[v2-1].push_back(v1-1);
        }
        // get branch count
        // get odd degree count
        int branchCount = 0;
        int oddCount = 0;
        for (int i = 0; i < verCount; ++i)
        {
            if (!edges[i].empty())
            {
                getBranch(graph, edges, branchCount, i, true);
                if (edges[i].size() % 2 == 1)
                {
                    ++oddCount;
                }
            }
        }
        // calculate paths
        int pathCount = 0;
        pathCount += edgeCount;
        if (branchCount > 1)
        {
            pathCount += branchCount - 1;
        }
        oddCount -= 2 + 2*(branchCount-1);
        if (oddCount > 0)
        {
            pathCount += oddCount/2;
        }
        // print
        printf("Case %d: %d\n", ++cases, timeUse*pathCount);
    }
    return 0;
}