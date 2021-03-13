#include <iostream>

int main()
{
    int day;
    while(std::cin >> day)
    {
        long long num = 1;
        while(--day)
        {
            num = (num+1)<<1;
        }
        std::cout << num << std::endl;
    }
    return 0;
}