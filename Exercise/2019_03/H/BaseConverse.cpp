#include <iostream>
#include <string>
#include <algorithm>

using std::string;

char nums[16] {'0', '1', '2', '3', '4', '5', '6', 
    '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

int main()
{
    int base, num;
    while (std::cin >> num >> base)
    {
        bool isNeg = num < 0;
        if (isNeg)
        {
            num *= -1;
        }
        
        string newNum;
        while (num)
        {
            int rem = num % base;
            num /= base;
            newNum += nums[rem];
        }
        if (newNum.empty())
        {
            std::cout << 0 << std::endl;
        }
        else
        {
            if (isNeg)
            {
                std::cout << '-' ;
            }
            std::reverse(newNum.begin(), newNum.end());
            std::cout << newNum << std::endl;
            
        }
        
        
    }
    
    return 0;
}