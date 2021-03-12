#include <iostream>
#include <sstream>
#include <string>
#include <map>

int main()
{
    std::map<std::string, int> word_cnts;
    std::string line;
    int max = 0;
    while(std::getline(std::cin, line))
    {
        if(line[0] == '#')
            break;
        std::istringstream iss(line);
        std::string word;
        while(iss >> word)
        {
            word[0] = tolower(word[0]);
            if(max < ++word_cnts[word])
                max = word_cnts[word];
        }
    }
    for(auto &p : word_cnts)
    {
        if(p.second == max)
            std::cout << p.first << std::endl;
    }
    return 0;
}