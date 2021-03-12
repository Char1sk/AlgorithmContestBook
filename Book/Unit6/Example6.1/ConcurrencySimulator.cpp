#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <map>

int main()
{
    // freopen("./in.txt", "r", stdin);
    // freopen("./out.txt", "w", stdout);
    
    int cases;
    std::cin >> cases;
    while (cases--)
    {
        int proCount;
        std::cin >> proCount;
        int insTime[5];
        for (int i = 0; i < 5; ++i)
        {
            std::cin >> insTime[i];
        }
        int maxTime;
        std::cin >> maxTime;
        getchar();
        
        std::vector<std::vector<std::string>> programs;
        for (int i = 0; i < proCount; ++i)
        {
            std::vector<std::string> program;
            std::string line;
            while (std::getline(std::cin, line) && line != "end")
            {
                program.push_back(line);
            }
            program.push_back("end");
            programs.push_back(program);
        }
        std::vector<int> counters(proCount, 0);
        
        bool isLocked = false;
        int nowIdx = 0;
        std::map<char, int> variables;
        std::deque<int> waitQ;
        std::queue<int> blockQ;
        for (int i = 0; i < proCount; ++i)
        {
            waitQ.push_back(i);
        }
        
        int needTime = maxTime;
        while (!waitQ.empty() || !blockQ.empty() || counters[nowIdx] < programs[nowIdx].size())
        {
            if (needTime >= maxTime)
            {
                needTime = 0;
                if (!waitQ.empty())
                {
                    nowIdx = waitQ.front();
                    waitQ.pop_front();
                }
            }
            
            std::istringstream iss(programs[nowIdx][counters[nowIdx]]);
            std::string cmd;
            iss >> cmd;
            if (cmd.size() == 1)
            {
                needTime += insTime[0];
                char k = cmd[0];
                int v;
                iss >> cmd >> v;
                variables[k] = v;
            }
            if (cmd == "print")
            {
                needTime += insTime[1];
                iss >> cmd;
                printf("%d: %d\n", nowIdx+1, variables[cmd[0]]);
            }
            if (cmd == "lock")
            {
                needTime += insTime[2];
                if (!isLocked)
                {
                    isLocked = true;
                }
                else
                {
                    blockQ.push(nowIdx);
                    needTime = maxTime;
                    continue;
                }
                
            }
            if (cmd == "unlock")
            {
                isLocked = false;
                needTime += insTime[3];
                if (!blockQ.empty())
                {
                    waitQ.push_front(blockQ.front());
                    blockQ.pop();
                }
            }
            
            if (needTime >= maxTime)
            {
                waitQ.push_back(nowIdx);
            }
            
            if (cmd == "end")
            {
                needTime = maxTime;
            }
            ++counters[nowIdx];
        }
        
        if (cases)
        {
            std::cout << std::endl;
        }
    }
    return 0;
}