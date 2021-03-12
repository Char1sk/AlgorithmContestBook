#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <queue>

int main()
{
    int n;
    while (std::cin >> n && n)
    {
        getchar();
        std::string line;
        while (std::getline(std::cin, line) && line != "0")
        {
            std::queue<int> input;
            std::queue<int> pattn;
            std::stack<int> trans;
            std::istringstream iss(line);
            for (int i = 1; i <= n; ++i)
            {
                int itemp;
                iss >> itemp;
                input.push(i);
                pattn.push(itemp);
            }
            
            // bool isOk = true;
            while (!pattn.empty() && !input.empty())
            {
                while (!input.empty() && (trans.empty() || trans.top() != pattn.front()))
                {
                    trans.push(input.front());
                    input.pop();
                }
                while (!trans.empty() && trans.top() == pattn.front())
                {
                    trans.pop();
                    pattn.pop();
                }
            }
            std::cout << (pattn.empty() ? "Yes" : "No") << std::endl;
        }
        std::cout << std::endl;
    }
    return 0;
}