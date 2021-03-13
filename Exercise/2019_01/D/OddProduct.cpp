#include <iostream>

int main()
{
    int n = 0;
    while(std::cin >> n)
    {
        int product = 1;
        while(n--)
        {
            int temp;
            std::cin >> temp;
            if(temp % 2)
                product *= temp;
        }
        std::cout << product << std::endl;
    }
    return 0;
}