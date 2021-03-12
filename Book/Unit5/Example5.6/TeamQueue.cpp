#include <iostream>
#include <string>
#include <queue>
#include <map>

int main()
{
    freopen("./in.txt", "r", stdin);
    freopen("./out.txt", "w", stdout);
    
    int cases = 0;
    int teamCount;
    while ((std::cin >> teamCount) && teamCount != 0)
    {
        std::map<int, int> numToTeam;
        int teamNum = 0;
        while (teamCount--)
        {
            int mateCount;
            std::cin >> mateCount;
            while (mateCount--)
            {
                int num;
                std::cin >> num;
                numToTeam.insert({num, teamNum});
            }
            ++teamNum;
        }
        
        std::queue<int> teamNumQueue;
        std::queue<int> teamQueues[1005];
        int teamMemCounts[1005] {0};
        
        printf("Scenario #%d\n", ++cases);
        std::string cmd;
        while ((std::cin >> cmd) && cmd != "STOP")
        {
            if (cmd == "ENQUEUE")
            {
                int num;
                std::cin >> num;
                int teamID = numToTeam[num];
                if (teamMemCounts[teamID] == 0)
                {
                    teamNumQueue.push(teamID);
                }
                ++teamMemCounts[teamID];
                teamQueues[teamID].push(num);
                
            }
            if (cmd == "DEQUEUE")
            {
                int teamID = teamNumQueue.front();
                std::cout << teamQueues[teamID].front() << std::endl;
                --teamMemCounts[teamID];
                teamQueues[teamID].pop();
                if (teamMemCounts[teamID] == 0)
                {
                    teamNumQueue.pop();
                }
            }
        }
        std::cout << std::endl;
    }
    return 0;
}