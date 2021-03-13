#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

bool abs_greater(int a, int b)
{
    return std::abs(a) > std::abs(b);
}

int main()
{
    int n;
    while(std::cin >> n)
    {
        if(n == 0)
            break;
        std::vector<int> ivec;
        while(n--)
        {
            int itemp;
            std::cin >> itemp;
            ivec.push_back(itemp);
        }
        std::sort(ivec.begin(), ivec.end(), abs_greater);
        bool first = true;
        for(auto i : ivec)
        {
            if(first)
                first = false;
            else
                std::cout << ' ' ;
            std::cout << i ;
        }
        std::cout << std::endl;
    }
    return 0;
}