#include <iostream>
#include <vector>
#include <map>

inline int maxOne(int a, int b)
{
    return (a > b ? a : b);
}

inline int minOne(int a, int b)
{
    return (a < b ? a : b);
}

int main()
{
    int thingCnt, totalWeight;
    std::cin >> thingCnt >> totalWeight;
    
    std::vector<int> thingWeights(thingCnt);
    std::vector<int> thingValues(thingCnt);
    
    for (int i = 0; i < thingCnt; ++i)
    {
        std::cin >> thingWeights[i] >> thingValues[i];
    }
    
    // maxValue[i][j] means max total value of [i, n-1] with weight j
    std::vector<std::vector<int>> maxValues(thingCnt, std::vector<int>(totalWeight+1));
    
    for (int t = thingCnt-1; t >= 0; --t)
    {
        int nowWeight = thingWeights[t];
        int nowValue = thingValues[t];
        int maxw = minOne(totalWeight, nowWeight-1);
        for (int w = 0; w <= maxw; ++w)
        {
            // for cases of weights[t] > weight
            if (t == thingCnt-1)
            {
                maxValues[t][w] = 0;
            }
            else
            {
                maxValues[t][w] = maxValues[t+1][w];
            }
        }
        for (int w = maxw+1; w <= totalWeight; ++w)
        {
            // for cases of weights[t] <= weight
            if (t == thingCnt-1)
            {
                maxValues[t][w] = nowValue;
            }
            else
            {
                int m1 = maxValues[t+1][w];
                int m2 = nowValue + maxValues[t+1][w-nowWeight];
                maxValues[t][w] = maxOne(m1, m2);
            }
        }
    }
    
    std::cout << maxValues[0][totalWeight] << std::endl;
    
    return 0;
}