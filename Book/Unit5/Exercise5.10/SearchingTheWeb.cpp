#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

void normalize(std::string &s)
{
    for (char &c : s)
    {
        if (!isalpha(c))
        {
            c = ' ';
        }
        if (isupper(c))
        {
            c = tolower(c);
        }
    }
}

int main()
{
    // freopen("./in.txt", "r", stdin);
    // freopen("./out.txt", "w", stdout);
    
    std::map<std::string, std::map<int, std::set<int>>> wordToPassageLines;
    std::vector<std::vector<std::string>> passages;
    
    int passageCount;
    std::cin >> passageCount;
    getchar();
    const std::string stars(10, '*');
    for (int passageNumber = 0; passageNumber < passageCount; ++passageNumber)
    {
        std::vector<std::string> passage;
        std::string line;
        for (int lineNumber = 0; std::getline(std::cin, line) && (line.size() != 10 || line != stars); ++lineNumber)
        {
            passage.push_back(line);
            normalize(line);
            std::istringstream iss(line);
            std::string word;
            while (iss >> word)
            {
                wordToPassageLines[word][passageNumber].insert(lineNumber);
            }
        }
        passages.push_back(passage);
    }
    
    int queryCount;
    std::cin >> queryCount;
    getchar();
    while (queryCount--)
    {
        std::string line;
        std::getline(std::cin, line);
        
        std::map<int, std::set<int>> answers;
        switch (std::count(line.begin(), line.end(), ' '))
        {
        case 0:
        {
            answers = wordToPassageLines[line];
            break;
        }
        case 2:
        {
            std::istringstream iss(line);
            std::string word1, cmd, word2;
            iss >> word1 >> cmd >> word2;
            auto &mp1 = wordToPassageLines[word1];
            auto &mp2 = wordToPassageLines[word2];
            if (cmd == "AND")
            {
                for (auto &pr1 : mp1)
                {
                    for (auto &pr2 : mp2)
                    {
                        if (pr1.first == pr2.first)
                        {
                            for (int i : pr1.second)
                            {
                                answers[pr1.first].insert(i);
                            }
                            for (int i : pr2.second)
                            {
                                answers[pr2.first].insert(i);
                            }
                        }
                    }
                }
            }
            else if (cmd == "OR")
            {
                for (auto &pr1 : mp1)
                {
                    for (int i : pr1.second)
                    {
                        answers[pr1.first].insert(i);
                    }
                }
                for (auto &pr2 : mp2)
                {
                    for (int i : pr2.second)
                    {
                        answers[pr2.first].insert(i);
                    }
                }
            }
            break;
        }
        case 1:
        {
            std::set<int> ex;
            std::istringstream iss(line);
            std::string word, cmd;
            iss >> cmd >> word;
            auto &mp = wordToPassageLines[word];
            for (auto &pr : mp)
            {
                ex.insert(pr.first);
            }
            for (int i = 0; i < passageCount; ++i)
            {
                if (ex.find(i) == ex.end())
                {
                    for (int j = 0; j < passages[i].size(); ++j)
                    {
                        answers[i].insert(j);
                    }
                }
            }
            break;
        }
        default:
            break;
        }
        
        bool firstPassage = true;
        for (auto &pr : answers)
        {
            if (!firstPassage)
            {
                std::cout << std::string(10, '-') << std::endl;
            }
            for (auto i : pr.second)
            {
                firstPassage = false;
                // std::cout << pr.first << ' ' << i << ' ' << std::endl;////
                std::cout << passages[pr.first][i] << std::endl;
            }
        }
        if (answers.empty())
        {
            std::cout << "Sorry, I found nothing." << std::endl;
        }
        std::cout << std::string(10, '=') << std::endl;
    }
    
    return 0;
}