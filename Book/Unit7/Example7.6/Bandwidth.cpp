#include <iostream>
#include <sstream>
#include <string>
#include <cstring>

std::string ans;

void getMinWidth(std::string arrange, bool graph[26][26], bool canVisit[26], int maxWid[26],
                 int &minWid, int nowWid, int nowN, int maxN)
{
    if (nowN == maxN)
    {
        ans = arrange;
        minWid = nowWid;
    }
    else
    {
        for (int i = 0; i < 26; ++i)
        {
            if (canVisit[i])
            {
                int tempMaxWid[26];
                memcpy(tempMaxWid, maxWid, sizeof(int)*26);
                
                int maxW = 0;
                int newW = 0;
                for (int j = 0; j < arrange.size(); ++j)
                {
                    if (graph[i][arrange[j]-'A'])
                    {
                        int delta = arrange.size()-j;
                        if (delta > maxWid[j])
                        {
                            maxWid[j] = delta;
                        }
                        if (delta > newW)
                        {
                            newW = delta;
                        }
                    }
                    if (maxWid[j] > maxW)
                    {
                        maxW = maxWid[j];
                    }
                }
                if (newW > maxW)
                {
                    maxW = newW;
                }
                
                if (maxW < minWid)
                {
                    arrange.push_back(i+'A');
                    canVisit[i] = false;
                    getMinWidth(arrange, graph, canVisit, maxWid, minWid, maxW, nowN+1, maxN);
                    arrange.pop_back();
                    canVisit[i] = true;
                }
                
                memcpy(maxWid, tempMaxWid, sizeof(int)*26);
            }
        }
    }
    
}

int main()
{
    std::string line;
    while (std::getline(std::cin, line) && line != "#")
    {
        ans.clear();
        
        for (char &c : line)
        {
            if (c == ':' || c == ';')
            {
                c = ' ';
            }
        }
        std::istringstream iss(line);
        
        bool chara[26];
        memset(chara, 0, sizeof(chara));
        bool graph[26][26];
        memset(graph, 0, sizeof(graph));
        int maxWid[26];
        memset(maxWid, 0, sizeof(maxWid));
        int maxN = 0;
        
        char key;
        std::string val;
        while (iss >> key >> val)
        {
            int k = key-'A';
            if (!chara[k])
            {
                ++maxN;
            }
            chara[k] = true;
            
            for (char c : val)
            {
                int ck = c-'A';
                graph[k][ck] = true;
                graph[ck][k] = true;
                if (!chara[ck])
                {
                    ++maxN;
                }
                chara[ck] = true;
            }
        }
        
        int minWid = 30;
        getMinWidth("", graph, chara, maxWid, minWid, 0, 0, maxN);
        
        for (char c : ans)
        {
            printf("%c ", c);
        }
        printf("-> %d\n", minWid);
        // std::cout << ans << ' ' << minWid << std::endl;////
    }
    return 0;
}