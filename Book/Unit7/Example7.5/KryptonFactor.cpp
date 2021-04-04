#include <iostream>
#include <string>

std::string ans;

void getHardString(std::string &s, const int len, int &nowCount, const int totalCount)
{
    if (nowCount == totalCount)
    {
        ans = s;
    }
    else if (nowCount < totalCount)
    {
        for (int i = 0; i < len; ++i)
        {
            s.push_back('A'+i);
            int sz = s.size();
            bool isHard = true;
            for (int l = 1; l <= sz/2; ++l)
            {
                // compare [size-l, size) and [size-2*l, size-l);
                if (s.substr(sz-2*l, l) == s.substr(sz-l, l))
                {
                    isHard = false;
                    break;
                }
            }
            if (isHard)
            {
                ++nowCount;
                getHardString(s, len, nowCount, totalCount);
            }
            if (nowCount >= totalCount)
            {
                return ;
            }
            s.pop_back();
        }
    }
}

int main()
{
    int leng, count;
    while (std::cin >> count >> leng && leng && count)
    {
        ans.clear();
        std::string s;
        int start = 0;
        getHardString(s, leng, start, count);
        
        for (int i = 0; i < ans.size(); ++i)
        {
            printf("%c", ans[i]);
            if ((i+1)%4 == 0 && i != ans.size()-1)
            {
                printf("%c", ((i+1)%64 == 0 ? '\n' : ' '));
            }
        }
        printf("\n%d\n", ans.size());
    }
    return 0;
}