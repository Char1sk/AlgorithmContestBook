#include <iostream>
#include <cstdlib>
#include <ctime>

const int maxN = 30;
const int maxValue = 10000;

int main()
{
    freopen("./input2.txt", "w", stdout);
    srand((unsigned)time(NULL));
    std::cout << maxN << std::endl;
    for (int r = 0; r < maxN; ++r)
    {
        for (int c = 0; c <= r; ++c)
        {
            std::cout << rand() % maxValue << ' ';
        }
        std::cout << std::endl;
    }
    return 0;
}