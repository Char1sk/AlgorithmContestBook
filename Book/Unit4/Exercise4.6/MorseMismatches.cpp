#include <iostream>
#include <string>
#include <map>

// char getKey()
// {
//     char ret = getchar();
//     while (ret == ' ' || ret == '\n')
//         ret = getchar();
//     return ret;
// }

int main()
{
    // freopen("./in.txt", "r", stdin);
    // freopen("./out.txt", "w", stdout);
    
    std::map<char, std::string> dict;
    std::map<std::string, std::string> context;
    
    char ky;
    while ((std::cin >> ky) && (ky != '*'))
    {
        std::cin >> dict[ky];
        // std::cout << ky << ' ' << dict[ky] << std::endl;////
    }
    // for (auto &p : dict)
    // {
    //     printf("%c\t%s\n", p.first, p.second.c_str());
    // }
    
    std::string word;
    while ((std::cin >> word) && (word != "*"))
    {
        std::string more;
        for (auto c : word)
        {
            more += dict[c];
        }
        context[word] = more;
    }
    // for (auto &p : context)
    // {
    //     printf("%s\t\t\t%s\n", p.first.c_str(), p.second.c_str());
    // }
    
    std::string morse;
    while ((std::cin >> morse) && (morse != "*"))
    {
        int matchCount = 0;
        std::string matchWord;
        for (auto &p : context)
        {
            if (p.second == morse)
            {
                if (!matchCount)
                {
                    matchWord = p.first;
                }
                ++matchCount;
            }
        }
        if (matchCount)
        {
            std::cout << matchWord ;
            if (matchCount > 1)
            {
                std::cout << '!' ;
            }
            std::cout << std::endl;
        }
        else
        {
            for (int l = 1; ; ++l)
            {
                for (auto &p : context)
                {
                    std::string toMatch = p.second;
                    if ( ( morse.substr(0, morse.length()-l) == toMatch ) )
                    {
                        std::cout << p.first << '?' << std::endl;
                        goto End;
                    }
                }
                for (auto &p : context)
                {
                    std::string toMatch = p.second;
                    if ( ( morse == toMatch.substr(0, toMatch.length()-l) ) )
                    {
                        std::cout << p.first << '?' << std::endl;
                        goto End;
                    }
                }
            }
            End: ;
        }
        
    }
    
    return 0;
}