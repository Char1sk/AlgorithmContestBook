#include <iostream>
#include <string>

int main()
{
    // freopen("./in.txt", "r", stdin);
    // freopen("./out.txt", "w", stdout);
    
    int cases;
    std::cin >> cases;
    while (cases--)
    {
        std::string line;
        std::cin >> line;
        int len = line.length();
        int period = 1;
        for (period = 1; period < len; ++period)
        {
            if (len % period == 0)
            {
                bool isOk = true;
                std::string word(line, 0, period);
                for (int i = 0; i < len; i += period)
                {
                    // std::cout << word << ' ' << line.substr(i, period) << std::endl;
                    if (word != line.substr(i, period))
                    {
                        isOk = false;
                        break;
                    }
                }
                if (isOk)
                {
                    break;
                }
            }
        }
        std::cout << period << std::endl;
        if (cases)
        {
            std::cout/*  << cases */ << std::endl;
        }
    }
    return 0;
}