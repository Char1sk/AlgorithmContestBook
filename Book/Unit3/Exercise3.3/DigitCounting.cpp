#include <iostream>

int sin[10001][10] {0};
int sum[10001][10] {0};

int main()
{
    for (int i = 1; i <= 10000; ++i)
    {
        int temp = i;
        while (temp)
        {
            ++sin[i][temp%10];
            temp /= 10;
        }
    }
    for (int i = 1; i <= 10000; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            sum[i][j] = sum[i-1][j] + sin[i][j];
        }
    }
    int cases;
    std::cin >> cases;
    while (cases--)
    {
        int n;
        std::cin >> n;
        for (int i = 0; i < 10; ++i)
        {
            if (i != 0)
            {
                std::cout << ' ' ;
            }
            std::cout << sum[n][i] ;
        }
        std::cout << std::endl;
    }
    return 0;
}