#include <iostream>
#include <vector>

int main()
{
    int n;
    while(std::cin >> n)
    {
        if(n == 0)
            break;
        std::vector<int> ivec;
        int min = 2147483647;
        int min_pos = 0;
        for(int i = 0; i != n; ++i)
        {
            int itemp;
            std::cin >> itemp;
            ivec.push_back(itemp);
            if(min > itemp)
            {
                min = itemp;
                min_pos = i;
            }
        }
        std::swap(ivec[0], ivec[min_pos]);
        
        bool first = 1;
        for(auto i : ivec)
        {
            if(first)
                first = 0;
            else
                std::cout << ' ';
            std::cout << i;
        }
        std::cout << std::endl;
    }
    return 0;
}