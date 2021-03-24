#include <iostream>

const int maxN = 10000+5;
bool isExsistent[maxN] = {0};

int main()
{
    int count, rank;
    std::cin >> count >> rank;
    
    // range constraint to optimize
    int min = 0, max = maxN;
    
    for (int i = 0; i < count; ++i)
    {
        int itemp;
        std::cin >> itemp;
        isExsistent[itemp] = true;
        if (itemp < min)
        {
            min = itemp;
        }
        if (itemp > max)
        {
            max = itemp;
        }
    }
    int r = 0;
    for (int i = min; i < max; ++i)
    {
        if (isExsistent[i])
        {
            ++r;
            if (r == rank)
            {
                std::cout <<i  << std::endl;
                break;
            }
        }
    }
    if (r != rank)
    {
        std::cout << "NO RESULT" << std::endl;
    }
    return 0;
}