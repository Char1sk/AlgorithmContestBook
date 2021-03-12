#include <iostream>
#include <utility>
#include <string>
#include <stack>

std::pair<int, int> mats[26];

int main()
{
    int num;
    std::cin >> num;
    while (num--)
    {
        char k;
        std::cin >> k;
        std::cin >> mats[k-'A'].first >> mats[k-'A'].second;
    }
    
    std::string expr;
    while (std::cin >> expr)
    {
        bool hasError = false;
        int times = 0;
        std::stack<std::pair<int, int>> ex;
        for (auto &c : expr)
        {
            if (c >= 'A' && c <= 'Z')
            {
                ex.push(mats[c-'A']);
            }
            else if (c == ')')
            {
                auto p2 = ex.top();
                ex.pop();
                auto p1 = ex.top();
                ex.pop();
                if (p1.second != p2.first)
                {
                    hasError = true;
                    break;
                }
                else
                {
                    times += p1.first * p1.second * p2.second;
                    ex.push({p1.first, p2.second});
                }
            }
        }
        if (hasError)
        {
            std::cout << "error" << std::endl;
        }
        else
        {
            std::cout << times << std::endl;
        }
    }
    
    return 0;
}