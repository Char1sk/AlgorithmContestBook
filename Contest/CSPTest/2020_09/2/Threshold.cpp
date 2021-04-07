#include <iostream>
#include <vector>

int main()
{
    int cnt;
    std::cin >> cnt;
    std::vector<int> safety(cnt);
    std::vector<int> passed(cnt);
    for (int i = 0; i < cnt; ++i)
    {
        std::cin >> safety[i] >> passed[i];
    }
    
    int maxPrecision = 0;
    int maxThreshold = 0;
    for (int i = 0; i < cnt; ++i)
    {
        int nowPrecision = 0;
        int nowThreshold = safety[i];
        for (int j = 0; j < cnt; ++j)
        {
            if (safety[j] >= nowThreshold && passed[j] || 
                safety[j] < nowThreshold && !passed[j])
            {
                ++nowPrecision;
            }
        }
        if (nowPrecision > maxPrecision || 
            nowPrecision == maxPrecision && nowThreshold > maxThreshold)
        {
            maxPrecision = nowPrecision;
            maxThreshold = nowThreshold;
        }
    }
    std::cout << maxThreshold << std::endl;
    return 0;
}