#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main()
{
    std::vector<std::vector<std::string>> text;
    std::string line;
    int maxWid = 0;
    while (std::getline(std::cin, line))
    {
        std::istringstream iss(line);
        std::vector<std::string> textLine;
        std::string word;
        while (iss >> word)
        {
            textLine.push_back(word);
        }
        text.push_back(textLine);
        if (textLine.size() > maxWid)
        {
            maxWid = textLine.size();
        }
    }
    
    std::vector<int> maxLens;
    for (int j = 0; j < maxWid; ++j)
    {
        int maxLen = 0;
        for (int i = 0; i < text.size(); ++i)
        {
            if (j < text[i].size() && maxLen < text[i][j].size())
            {
                maxLen = text[i][j].size();
            }
        }
        maxLens.push_back(maxLen);
    }
    
    for (int i = 0; i < text.size(); ++i)
    {
        for (int j = 0; j < text[i].size(); ++j)
        {
            std::cout << text[i][j] ;
            if (j != text[i].size()-1)
            {
                for (int k = text[i][j].size(); k < maxLens[j]+1; ++k)
                {
                    std::cout << ' ' ;
                }
            }
        }
        std::cout << std::endl;
    }
    return 0;
}

//   start:  integer;    // begins here
// stop: integer; //  ends here
//  s:  string;
// c:   char; // temp