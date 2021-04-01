#include <iostream>

int main()
{
    int cases = 0;
    int count;
    while (std::cin >> count)
    {
        int seq[20];
        for (int i = 0; i < count; ++i)
        {
            std::cin >> seq[i];
        }
        long long maxProduct = 0;
        for (int from = 0; from < count; ++from)
        {
            long long pro = 1;
            for (int to = from; to < count; ++to)
            {
                pro *= seq[to];
                if (pro > maxProduct)
                {
                    maxProduct = pro;
                }
            }
        }
        printf("Case #%d: The maximum product is %lld.\n\n", ++cases, maxProduct);
    }
    return 0;
}