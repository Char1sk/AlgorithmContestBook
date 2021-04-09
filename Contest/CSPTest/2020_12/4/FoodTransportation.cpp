#include <iostream>
#include <vector>
#include <queue>

const int BOUND = 2147483647;

inline int maxOne(int x, int y)
{
    return (x > y ? x : y);
}

inline int minOne(int x, int y)
{
    return (x < y ? x : y);
}

int main()
{
    // initalize
    int pointCnt, startCnt, kindCnt;
    std::cin >> pointCnt >> startCnt >> kindCnt;
    std::vector<std::vector<int>> kindPointIndexes(kindCnt);
    std::vector<std::vector<int>> graph(pointCnt);
    std::vector<std::vector<int>> weights(pointCnt, std::vector<int>(pointCnt, 0));
    for (int p = 0; p < pointCnt; ++p)
    {
        for (int k = 0; k < kindCnt; ++k)
        {
            bool isIn;
            std::cin >> isIn;
            if (isIn)
            {
                kindPointIndexes[k].push_back(p);
            }
        }
    }
    for (int p = 0; p < pointCnt-1; ++p)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);
        weights[u-1][v-1] = w;
        weights[v-1][u-1] = w;
    }
    // calculate all path weights
    for (int p = 0; p < pointCnt; ++p)
    {
        std::vector<int> length(pointCnt, -1);
        length[p] = 0;
        std::queue<int> bfs;
        bfs.push(p);
        while (!bfs.empty())
        {
            int now = bfs.front();
            bfs.pop();
            for (int idx : graph[now])
            {
                if (length[idx] == -1)
                {
                    length[idx] = length[now] + weights[idx][now];
                    weights[p][idx] = length[idx];
                    bfs.push(idx);
                }
            }
        }
    }
    
    if (startCnt == kindCnt)
    {
        int maxDist = 0;
        for (int k = 0; k < kindCnt; ++k)
        {
            const auto &v = kindPointIndexes[k];
            int ret = 0;
            std::vector<int> distToTree(pointCnt, BOUND);
            std::vector<bool> visited(pointCnt, false);
            for (int i = 0; i < v.size(); ++i)
            {
                int minIdx = -1;
                for (int pidx : v)
                {
                    if (!visited[pidx] && (minIdx == -1 || distToTree[pidx] < distToTree[minIdx]))
                    {
                        minIdx = pidx;
                    }
                }
                visited[minIdx] = true;
                if (i != 0)
                {
                    ret += distToTree[minIdx];
                }
                for (int pidx : v)
                {
                    if (!visited[pidx])
                    {
                        distToTree[pidx] = minOne(distToTree[pidx], weights[minIdx][pidx]);
                    }
                }
            }
            maxDist = maxOne(maxDist, ret);
        }
        std::cout << maxDist << std::endl;
    }
    return 0;
}

// 思路：
// 作为树，所有点之间的路径仅有一条
// 直接进行小Floyd，算出所有边的权重，并成为完全图 <O(n**3)=1e6
// 然后对每个点，加入到特定点的集合中，计算最小生成树 Prim O(n*k * k**2)=1e5
// 直接取最大值就行了 <O(n**2)=1e4
