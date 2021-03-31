#include <iostream>
#include <vector>
#include <stack>

int main()
{
    int length;
    while (std::cin >> length)
    {
        std::vector<std::vector<int>> tree(length+1);
        // record bfs indexes
        std::vector<int> dist(length+1);
        for (int i = 0; i < length; ++i)
        {
            int itemp;
            std::cin >> itemp;
            dist[itemp] = i;
        }
        // tree node stack
        int root;
        std::cin >> root;
        std::stack<int> nodes;
        nodes.push(root);
        for (int i = 1; i < length; ++i)
        {
            int now;
            std::cin >> now;
            while (true)
            {
                int tp = nodes.top();
                // means now is tp's child
                // if dist[tp]+1 == dist[now]:
                //     means now is tp's sibling
                if (tp == root || dist[tp]+1 < dist[now])
                {
                    tree[tp].push_back(now);
                    nodes.push(now);
                    break;
                }
                else
                {
                    nodes.pop();
                }
            }
        }
        // print
        for (int i = 1; i <= length; ++i)
        {
            printf("%d:", i);
            for (int val : tree[i])
            {
                printf(" %d", val);
            }
            printf("\n");
        }
    }
    return 0;
}