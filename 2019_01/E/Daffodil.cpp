#include <iostream>
#include <cmath>

int main()
{
    // int n1, n2;
    // while(std::cin >> n1 >> n2)
    // {
    //     bool has = false;
    //     for(int i = n1; i <= n2; ++i)
    //     {
    //         int d1 = i / 100;
    //         int d2 = i / 10 % 10;
    //         int d3 = i % 10;
    //         if(std::pow(d1, 3) + std::pow(d2, 3) + std::pow(d3, 3) == i)
    //         {
    //             if(!has)
    //             {
    //                 has = true;
    //                 std::cout << i ;
    //             }
    //             else
    //             {
    //                 std::cout << ' ' << i ;
    //             }
    //         }
    //     }
    //     if(!has)
    //     {
    //         std::cout << "no" << std::endl;
    //     }
    //     else
    //     {
    //         std::cout << std::endl;
    //     } 
    // }
    
    int n1, n2;
    int nums[4] = {153, 370, 371, 407};
    while(std::cin >> n1 >> n2)
    {
        bool has = false;
        for(int i = 0; i != 4; ++i)
        {
            if(nums[i] >= n1 && nums[i] <= n2)
            {
                if(!has)
                {
                    has = true;
                    std::cout << nums[i] ;
                }
                else
                {
                    std::cout << ' ' << nums[i] ;
                }
            }
        }
        if(!has)
        {
            std::cout << "no" ;
        }
        std::cout << std::endl;
    }
    return 0;
}