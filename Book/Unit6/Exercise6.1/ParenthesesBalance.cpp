#include <iostream>
#include <string>
#include <stack>

int main()
{
    // freopen("./in.txt", "r", stdin);
    // freopen("./out.txt", "w", stdout);
    
    int cases;
    std::cin >> cases;
    getchar();
    while (cases--)
    {
        std::string line;
        std::getline(std::cin, line);
        std::stack<char> parentheses;
        bool isLegal = true;
        for (char c : line)
        {
            switch (c)
            {
            case '(':
            case '[':
                parentheses.push(c);
                break;
            case ')':
                if (parentheses.empty())
                {
                    isLegal = false;
                }
                else
                {
                    char t = parentheses.top();
                    parentheses.pop();
                    if (t != '(')
                    {
                        isLegal = false;
                    }
                }
                break;
            case ']':
                if (parentheses.empty())
                {
                    isLegal = false;
                }
                else
                {
                    char t = parentheses.top();
                    parentheses.pop();
                    if (t != '[')
                    {
                        isLegal = false;
                    }
                }
                break;
            default:
                break;
            }
            
            if (!isLegal)
            {
                break;
            }
        }
        if (!parentheses.empty())
        {
            isLegal = false;
        }
        std::cout << (isLegal ? "Yes" : "No") << std::endl;
    }
    return 0;
}