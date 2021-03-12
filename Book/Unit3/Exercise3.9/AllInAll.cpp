#include <iostream>
#include <string>

int main()
{
    std::string sub, sup;
    while (std::cin >> sub >> sup)
    {
        bool isFound = true;
        long long index = 0;
        for (int i = 0; i < sub.length(); ++i)
        {
            index = sup.find(sub[i], index);
            if (index == std::string::npos)
            {
                isFound = false;
                break;
            }
            ++index;
            // std::cout << sup[index] << std::endl;
        }
        std::cout << ( isFound ? "Yes" : "No") << std::endl;
    }
    return 0;
}