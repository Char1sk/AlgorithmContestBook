#include <iostream>

inline int square(int x)
{
    return x*x;
}

int main()
{
    int cnt, x, y;
    std::cin >> cnt >> x >> y;
    int minThree[4] = {10000000, 10000000, 10000000, 10000000};
    int minIndex[4] = {0, 0, 0, 0};
    for (int c = 0; c < cnt; ++c)
    {
        int nowx, nowy;
        std::cin >> nowx >> nowy;
        int dist = square(nowx-x) + square(nowy-y);
        for (int i = 0; i < 3; ++i)
        {
            if (dist < minThree[i])
            {
                for (int j = 3; j > i; --j)
                {
                    std::swap(minThree[j-1], minThree[j]);
                    std::swap(minIndex[j-1], minIndex[j]);
                }
                minThree[i] = dist;
                minIndex[i] = c+1;
                break;
            }
        }
    }
    for (int i = 0; i < 3; ++i)
    {
        std::cout << minIndex[i] << std::endl;
    }
    
    return 0;
}