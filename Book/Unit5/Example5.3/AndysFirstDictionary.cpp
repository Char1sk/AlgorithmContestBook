#include <iostream>
#include <string>
#include <set>

bool getWord(std::string &word)
{
    bool ret;
    int ctemp;
    while (ctemp = getchar())
    {
        if (ctemp == EOF)
        {
            return false;
        }
        
        if (isalpha(ctemp))
        {
            word += tolower(ctemp);
        }
        else
        {
            return true;
        }
        
    }
}

int main()
{
    std::set<std::string> dict;
    std::string word;
    while (getWord(word))
    {
        if (!word.empty())
        {
            dict.insert(word);
        }
        word.clear();
    }
    for (auto &s : dict)
    {
        std::cout << s << std::endl;
    }
    return 0;
}