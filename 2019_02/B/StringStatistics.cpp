#include <iostream>
#include <string>

int main()
{
    int n = 0;
    std::cin >> n;
    while(n--)
    {
        std::string s;
        std::cin >> s;
        int cnt = 0;
        for(auto c : s)
            if(isdigit(c))
                ++cnt;
        std::cout << cnt << std::endl;
    }
    return 0;
}