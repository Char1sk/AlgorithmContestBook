#include <iostream>
#include <set>

struct Node
{
    // int value;
    int degree = 0;
    std::set<int> children;
};

int main()
{
    int task, cnt;
    while (std::cin >> task >> cnt && task)
    {
        Node nodes[105];
        while (cnt--)
        {
            int from, to;
            std::cin >> from >> to;
            ++nodes[to].degree;
            nodes[from].children.insert(to);
        }
        for (int i = 1; i <= task; ++i)
        {
            for (int j = 1; j <= task; ++j)
            {
                if (nodes[j].degree == 0)
                {
                    nodes[j].degree = -1;
                    for (int k : nodes[j].children)
                    {
                        --nodes[k].degree;
                    }
                    std::cout << j << (i == task ? '\n' : ' ') ;
                    break;
                }
            }
        }
    }
    return 0;
}