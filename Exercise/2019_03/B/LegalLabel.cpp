#include <iostream>
#include <string>

int main()
{
    int n;
    std::cin >> n;
    getchar();
    while(n--)
    {
        bool is_ok = true;
        std::string line;
        std::getline(std::cin, line);
        
        if(line.size() <= 0)
            is_ok = false;
        else if(!(isalpha(line[0]) || line[0] == '_'))
            is_ok = false;
        else
            for(int i = 1; i < line.size(); ++i)
            {
                if(!(isalpha(line[i]) || isdigit(line[i]) || line[i] == '_'))
                {
                    is_ok = false;
                    break;
                }
            }
        
        std::cout << (is_ok ? "yes" : "no") << std::endl;
    }
    return 0;
}