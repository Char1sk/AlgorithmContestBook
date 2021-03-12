#include <iostream>
#include <string>

int main()
{
    std::string word1, word2;
    while (std::cin >> word1 >> word2)
    {
        int len = word1.length();
        int wordCount1[30] {0};
        int wordCount2[30] {0};
        for (int i = 0; i < len; ++i)
        {
            ++wordCount1[word1[i]-'A'];
            ++wordCount2[word2[i]-'A'];
        }
        int useCount1[110] {0};
        int useCount2[110] {0};
        for (int i = 0; i < 30; ++i)
        {
            ++useCount1[wordCount1[i]];
            ++useCount2[wordCount2[i]];
        }
        bool isSame = true;
        for (int i = 0; i < 110; ++i)
        {
            if (useCount1[i] != useCount2[i])
            {
                isSame = false;
                break;
            }
        }
        std::cout << (isSame ? "YES" : "NO") << std::endl;
    }
    return 0;
}