#include <iostream>
#include <set>
#include <string>

std::set<std::string> dict;
std::set<std::string> words[26];

int main()
{
    std::string word;
    while (std::cin >> word)
    {
        dict.insert(word);
        words[word[0]-'a'].insert(word);
    }
    
    for (auto &s1 : dict)
    {
        int index = s1[0]-'a';
        for (auto &s2 : words[index])
        {
            int len = s2.size();
            if (s1.substr(0, len) == s2 && dict.find(s1.substr(len)) != dict.end())
            {
                std::cout << s1 << std::endl;
                break;
            }
        }
    }
    return 0;
}
// 100 -> 100*100
// 75 1..1 -> 75*75+25