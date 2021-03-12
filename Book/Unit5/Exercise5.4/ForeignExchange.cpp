#include <iostream>
#include <map>
#include <algorithm>

int main()
{
    int len;
    while ((std::cin >> len) && len)
    {
        std::map<int, int> counts;
        for (int i = 0; i < len; ++i)
        {
            int i1, i2;
            std::cin >> i1 >> i2;
            --counts[i1];
            ++counts[i2];
        }
        
        bool isOk = true;
        for (auto &p : counts)
        {
            if (p.second)
            {
                isOk = false;
                break;
            }
        }
        
        std::cout << (isOk ? "YES" : "NO") << std::endl;
    }
}