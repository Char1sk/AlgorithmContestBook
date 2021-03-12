#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

std::map<std::string, int> arraySize;
std::map<std::string, std::set<int>> arrayUsed;
std::map<std::string, std::map<int, int>> arrayValue;

void checkRange(const std::string &name, int index);
std::pair<std::string, int> getNameIndex(const std::string &exp);
int getValue(const std::string &exp);

void checkRange(const std::string &name, int index)
{
    if (index < 0 || index >= arraySize[name])
    {
        throw std::exception();
    }
}

std::pair<std::string, int> getNameIndex(const std::string &exp)
{
    int left = exp.find('[');
    int right = exp.find(']');
    std::string name(exp, 0, left);
    int index = getValue(exp.substr(left+1, right-left-1));
    return std::make_pair(name, index);
}

int getValue(const std::string &exp)
{
    if(exp.find('[') == std::string::npos)
    {
        return std::stoi(exp);
    }
    else
    {
        auto p = getNameIndex(exp);
        checkRange(p.first, p.second);
        if (arrayUsed[p.first].find(p.second) == arrayUsed[p.first].end())
        {
            throw std::exception();
        }
        return arrayValue[p.first][p.second];
    }
    
}

int main()
{
    // freopen("./in.txt")
    
    std::string line;
    while ((std::cin >> line) && line != ".")
    {
        arraySize.clear();
        arrayUsed.clear();
        arrayValue.clear();
        bool hasException = false;
        int lineNumber = 1;
        do
        {
            try
            {
                if (line.find('=') == std::string::npos)
                {
                    auto p = getNameIndex(line);
                    arraySize[p.first] = p.second;
                }
                else
                {
                    int sep = line.find('=');
                    std::string leftExp(line, 0, sep);
                    std::string rightExp(line, sep+1);
                    auto p = getNameIndex(leftExp);
                    checkRange(p.first, p.second);
                    int val = getValue(rightExp);
                    arrayUsed[p.first].insert(p.second);
                    arrayValue[p.first][p.second] = val;
                }
            }
            catch(const std::exception& e)
            {
                hasException = true;
            }
            if (!hasException)
            {
                ++lineNumber;
            }
        } while ((std::cin >> line) && line != ".");
        
        std::cout << (hasException ? lineNumber : 0) << std::endl;
    }
    return 0;
}