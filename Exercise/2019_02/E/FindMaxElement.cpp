#include <iostream>
#include <string>

int main()
{
    std::string s;
    while(std::cin >> s)
    {
        char maxc = 0;
        for(auto c : s)
            if(maxc < c)
                maxc = c;
        int length = s.length();
        for(int i = 0; i != length; ++i)
            if(s[i] == maxc)
            {
                s.insert(i+1, "(max)");
                i += 5;
                length += 5;
            }
        std::cout << s << std::endl;
    }
    return 0;
}