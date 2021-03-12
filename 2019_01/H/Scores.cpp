#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

int main()
{
    int n;
    while(std::cin >> n)
    {
        std::vector<int> vec;
        int itemp;
        for(int i = 0; i != n; ++i)
        {
            std::cin >> itemp;
            vec.push_back(itemp);
        }
        int sum = 0;
        int min = 100, max = 0;
        for(auto i : vec)
        {
            if(min > i)
                min = i;
            if(max < i)
                max = i;
            sum += i;
        }
        sum -= min;
        sum -= max;
        printf("%.2lf\n", 1.0*sum/(n-2));
    }
    return 0;
}