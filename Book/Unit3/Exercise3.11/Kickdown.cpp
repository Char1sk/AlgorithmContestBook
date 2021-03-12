#include <iostream>
#include <string>
#include <cmath>

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
} 

int main()
{
    std::string s1, s2;
    while (std::cin >> s1 >> s2)
    {
        int len1 = s1.length();
        int len2 = s2.length();
        int minLen = len1 + len2;
        for (int i = 0; i < len1; ++i)
        {
            bool canFit = true;
            for (int j = i; j < len1 && j < i + len2; ++j)
            {
                if ( (s1[j]-'0') + (s2[j-i]-'0') == 4 )
                {
                    canFit = false;
                    break;
                }
            }
            if (canFit && minLen > max(len1, i+len2))
            {
                minLen = max(len1, i+len2);
            }
        }
        for (int i = 0; i < len2; ++i)
        {
            bool canFit = true;
            for (int j = i; j < len2 && j < i + len1; ++j)
            {
                if ( (s1[j-i]-'0') + (s2[j]-'0') == 4 )
                {
                    canFit = false;
                    break;
                }
            }
            if (canFit && minLen > max(len2, i+len1))
            {
                minLen = max(len2, i+len1);
            }
        }
        std::cout << minLen << std::endl;
    }
    return 0;
}
// 2112112112
//  2212112