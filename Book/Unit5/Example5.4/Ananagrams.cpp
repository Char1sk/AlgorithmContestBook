#include <iostream>
#include <string>
#include <map>
#include <algorithm>

std::string getStandardString(std::string s)
{
    for (auto &c : s)
    {
        c = tolower(c);
    }
    std::sort(s.begin(), s.end());
    return s;
}

int main()
{
    std::map<std::string, std::string> dict;
    std::map<std::string, int> stdCount;
    std::string word;
    while ((std::cin >> word) && word != "#")
    {
        std::string stds(getStandardString(word));
        dict.insert({word, stds});
        ++stdCount[stds];
    }
    for (auto &p : dict)
    {
        if (stdCount[p.second] == 1)
        {
            std::cout << p.first << std::endl;
        }
    }
    return 0;
}