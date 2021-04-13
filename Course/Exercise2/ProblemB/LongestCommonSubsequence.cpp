#include <iostream>
#include <string>
#include <vector>

inline int maxOne(int a, int b)
{
    return (a > b ? a : b);
}

int main()
{
    std::string s1, s2;
    std::cin >> s1 >> s2;
    int len1 = s1.size(), len2 = s2.size();
    std::vector<std::vector<int>> maxLen(len1+1, std::vector<int>(len2+1));
    for (int r = 0; r < len1+1; ++r)
    {
        for (int c = 0; c < len2+1; ++c)
        {
            if (r == 0 || c == 0)
            {
                maxLen[r][c] = 0;
            }
            else
            {
                if (s1[r-1] == s2[c-1])
                {
                    maxLen[r][c] = 1 + maxLen[r-1][c-1];
                }
                else
                {
                    maxLen[r][c] = maxOne(maxLen[r-1][c], maxLen[r][c-1]);
                }
            }
        }
    }
    std::vector<int> revSubsequenceIndex;
    for (int r = len1, c = len2; maxLen[r][c]; )
    {
        if (s1[r-1] == s2[c-1])
        {
            revSubsequenceIndex.push_back(r-1);
            --r;
            --c;
        }
        else
        {
            if (maxLen[r-1][c] == maxLen[r][c])
            {
                --r;
            }
            else if (maxLen[r][c-1] == maxLen[r][c])
            {
                --c;
            }
            else
            {
                break;///?
            }
        }
    }
    for (auto reg = revSubsequenceIndex.rbegin(); reg != revSubsequenceIndex.rend(); ++reg)
    {
        std::cout << s1[*reg];
    }
    std::cout << std::endl;
    return 0;
}