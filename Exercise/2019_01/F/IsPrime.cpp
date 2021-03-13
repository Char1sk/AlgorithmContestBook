#include <iostream>
#include <cmath>

bool is_prime(int p)
{
    for(int i = 2; i <= std::sqrt(p); ++i)
        if(p % i == 0)
            return false;
    return true;
}

int main()
{
    // for(int i = -39; i <= 50; ++i)
    // {
    //     if(!is_prime(i*i + i + 41))
    //         std::cout << i << std::endl;
    // }
    int nums[4] = {40, 41, 44, 49};
    int x, y;
    while(std::cin >> x >> y)
    {
        if(x == 0 && y == 0)
            break;
        bool ok = true;
        for(int i = 0; i != 4; ++i)
        {
            if(nums[i] >= x && nums[i] <= y)
            {
                ok = false;
                break;
            }
        }
        if(ok)
            std::cout << "OK" << std::endl;
        else
            std::cout << "Sorry" << std::endl;
    }
    return 0;
}