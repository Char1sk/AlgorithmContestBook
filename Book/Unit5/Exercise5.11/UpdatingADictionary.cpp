#include <iostream>
#include <sstream>
#include <string>
#include <map>

int main()
{
    int cases;
    std::cin >> cases;
    getchar();
    while (cases--)
    {
        std::map<std::string, std::string> dicts[2];
        for (int i = 0; i < 2; ++i)
        {
            std::string line;
            std::getline(std::cin, line);
            for (auto &c : line)
            {
                if (!isalnum(c))
                {
                    c = ' ';
                }
            }
            std::istringstream iss(line);
            std::string key, val;
            while (iss >> key >> val)
            {
                dicts[i][key] = val;
            }
        }
        
        if (dicts[0] == dicts[1])
        {
            std::cout << "No changes" << std::endl;
        }
        else
        {
            bool hasNew = false;
            for (auto &p1 : dicts[1])
            {
                if (dicts[0].find(p1.first) == dicts[0].end())
                {
                    std::cout << (hasNew ? ',' : '+');
                    hasNew = true;
                    std::cout << p1.first;
                }
            }
            if (hasNew)
            {
                std::cout << std::endl;
            }
            
            bool hasDel = false;
            for (auto &p0 : dicts[0])
            {
                if (dicts[1].find(p0.first) == dicts[1].end())
                {
                    std::cout << (hasDel ? ',' : '-');
                    hasDel = true;
                    std::cout << p0.first;
                }
            }
            if (hasDel)
            {
                std::cout << std::endl;
            }
            
            bool hasEdit = false;
            for (auto &p1 : dicts[1])
            {
                if (dicts[0].find(p1.first) != dicts[0].end() && dicts[0][p1.first] != dicts[1][p1.first])
                {
                    std::cout << (hasEdit ? ',' : '*');
                    hasEdit = true;
                    std::cout << p1.first;
                }
            }
            if (hasEdit)
            {
                std::cout << std::endl;
            }
        }
        
        std::cout << std::endl;
    }
    return 0;
}