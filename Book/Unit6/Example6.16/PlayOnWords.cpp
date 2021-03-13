#include <iostream>
#include <string>
#include <cstring>
// #include <set>

void dfs(bool graph[26][26], bool canReach[26], int from)
{
    for (int i = 0; i < 26; ++i)
    {
        if (graph[from][i] && !canReach[i])
        {
            canReach[i] = true;
            dfs(graph, canReach, i);
        }
    }
}

int main()
{
    int cases;
    std::cin >> cases;
    while (cases--)
    {
        bool graph[26][26];
        memset(graph, 0, sizeof(graph));
        bool haveAlpha[26];
        memset(haveAlpha, 0, sizeof(haveAlpha));
        int wordDegrees[26];
        memset(wordDegrees, 0, sizeof(wordDegrees));
        
        int wordCount;
        std::cin >> wordCount;
        while (wordCount--)
        {
            std::string word;
            std::cin >> word;
            int from = word.front() - 'a';
            int to   = word.back()  - 'a';
            graph[from][to] = true;
            haveAlpha[from] = true;
            haveAlpha[ to ] = true;
            ++wordDegrees[from];
            --wordDegrees[ to ];
        }
        
        bool haveEuler = true;
        int startIdx = -1;
        int endIdx = -1;
        for (int i = 0; i < 26; ++i)
        {
            int d = wordDegrees[i];
            if (d == 1)
            {
                if (startIdx == -1)
                {
                    startIdx = i;
                }
                else
                {
                    haveEuler = false;
                    // goto End;
                    break;
                }
            }
            else if (d == -1)
            {
                if (endIdx == -1)
                {
                    endIdx = true;
                }
                else
                {
                    haveEuler = false;
                    // goto End;
                    break;
                }
            }
            else if(d != 0)
            {
                haveEuler = false;
                // goto End;
                break;
            }
        }
        
        bool canReach[26];
        memset(canReach, 0, sizeof(canReach));
        if (startIdx == -1)
        {
            for (int i = 0; i < 26; ++i)
            {
                if (haveAlpha[i])
                {
                    startIdx = i;
                    break;
                }
            }
        }
        canReach[startIdx] = true;
        dfs(graph, canReach, startIdx);
        
        bool isConnective = true;
        for (int i = 0; i < 26; ++i)
        {
            if (haveAlpha[i] != canReach[i])
            {
                isConnective = false;
                break;
            }
        }
        
        // End: ;
        std::cout << (haveEuler && isConnective ? "Ordering is possible." : "The door cannot be opened.") << std::endl;
    }
    return 0;
}