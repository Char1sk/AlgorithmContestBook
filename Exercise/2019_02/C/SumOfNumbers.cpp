#include <iostream>
#include <cstdio>
#include <cmath>

int main()
{
    double n;
    int m;
    while(std::cin >> n >> m)
    {
        double sum = 0.0;
        while(m--)
        {
            sum += n;
            n = std::sqrt(n);
        }
        printf("%.2lf\n", sum);
    }
    return 0;
}