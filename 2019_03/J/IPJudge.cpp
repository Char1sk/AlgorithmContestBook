#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string line;
    while (std::cin >> line)
    {
        line += '.';
        std::vector<std::string> svec;
        long long pointIndex;
        while ((pointIndex = line.find('.')) != std::string::npos)
        {
            // std::cout << line.substr(0, pointIndex) << '+' << line.substr(pointIndex+1, line.size()-pointIndex) << std::endl;///
            svec.push_back(line.substr(0, pointIndex));
            line = line.substr(pointIndex+1, line.size()-pointIndex);
        }
        // svec.push_back(line);
        
        bool isIP = true;
        if (svec.size() != 4)
        {
            isIP = false;
        }
        else
        {
            for (int i = 0; i < 4; i++)
            {
                try
                {
                    int a = std::stoi(svec[i]);
                    if (a > 255 || a < 0 || (a != 0 && svec[i][0] == '0'))
                    {
                        isIP = false;
                        break;
                    }
                }
                catch(const std::exception& e)
                {
                    isIP = false;
                    break;
                }
            }
        }
        std::cout << (isIP ? "YES" : "NO") << std::endl;
        // for(auto p : svec)
        //     std::cout << p << std::endl;
    }
    return 0;
}