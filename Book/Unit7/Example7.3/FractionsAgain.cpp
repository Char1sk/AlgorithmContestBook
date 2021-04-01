#include <iostream>
#include <vector>
#include <utility>

int main()
{
    int k;
    while (std::cin >> k)
    {
        int count = 0;
        std::vector<std::pair<int, int>> out;
        for (int y = k+1; y <= 2*k; ++y)
        {
            int x = k*y / (y-k);
            if ((y-k)*x == k*y)
            {
                ++count;
                out.emplace_back(x, y);
            }
        }
        printf("%d\n", count);
        for (auto &p : out)
        {
            printf("1/%d = 1/%d + 1/%d\n", k, p.first, p.second);
        }
    }
    return 0;
}