#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>

const int directions[4][2] {
    {-1, 0}, {0, 1}, {1, 0}, {0, -1}
};

struct Triple
{
    int xpos;
    int ypos;
    int dindex;
    Triple() : xpos(0), ypos(0), dindex(0) {}
    Triple(int x, int y, int d) : xpos(x), ypos(y), dindex(d) {}
};

int getDirectionIndex(char c)
{
    std::string direction ("NESW");
    return direction.find(c);
}

int getTurnIndex(int ori, char turn)
{
    switch (turn)
    {
    case 'F': return ori;
    case 'R': return (ori+1)%4;
    case 'L': return (ori+3)%4;
    default:  return ori;
    }
}

int main()
{
    std::string name;
    while (std::cin >> name && name != "END")
    {
        int fromx, fromy, tox, toy;
        char startDirection;
        std::cin >> fromx >> fromy >> startDirection >> tox >> toy;
        int startIdx = getDirectionIndex(startDirection);
        
        bool canGo[10][10][4][4];
        memset(canGo, 0, sizeof(canGo));
        canGo[fromx][fromy][startIdx][startIdx] = true;
        int nx, ny;
        while (std::cin >> nx && nx)
        {
            std::cin >> ny;
            std::string ds;
            while (std::cin >> ds && ds != "*")
            {
                int idx = getDirectionIndex(ds[0]);
                for (int i = 1; i < ds.size(); ++i)
                {
                    int newIdx = getTurnIndex(idx, ds[i]);
                    canGo[nx][ny][idx][newIdx] = true;
                }
            }
        }
        
        Triple parent[10][10][4];
        int distance[10][10][4];
        memset(distance, -1, sizeof(distance));
        
        // Triple start(fromx + directions[startIdx][0], fromy + directions[startIdx][1], startIdx);
        Triple start(fromx, fromy, startIdx);
        Triple end;
        std::queue<Triple> qt;
        qt.push(start);
        
        bool isFound = false;
        while (!qt.empty())
        {
            Triple now = qt.front();
            qt.pop();
            // if (now.xpos == tox && now.ypos == toy)
            // {
            //     end = now;
            //     isFound = true;
            //     break;
            // }
            for (int d = 0; d < 4; ++d)
            {
                int newx = now.xpos+directions[d][0];
                int newy = now.ypos+directions[d][1];
                Triple next(newx, newy, d);
                if (canGo[now.xpos][now.ypos][now.dindex][d] && distance[next.xpos][next.ypos][next.dindex] == -1)////
                {
                    parent[newx][newy][d] = now;
                    distance[newx][newy][d] = distance[now.xpos][now.ypos][now.dindex]+1;
                    if (newx == tox && newy == toy)
                    {
                        end = next;
                        isFound = true;
                        goto End;
                    }
                    qt.push(next);
                }
            }
        }
        
        End: ;
        std::cout << name;
        if (isFound)
        {
            std::vector<Triple> path;
            
            path.push_back(end);
            while (distance[end.xpos][end.ypos][end.dindex] > 0)
            {
                path.push_back(parent[end.xpos][end.ypos][end.dindex]);
                end = path.back();
            }
            path.push_back(start);
            
            int i = 0;
            for (auto it = path.rbegin(); it != path.rend(); ++it, ++i)
            {
                printf("%s(%d,%d)", (i%10 == 0 ? "\n  " : " "), it->xpos, it->ypos);
            }
            std::cout << std::endl;
        }
        else
        {
            std::cout << "\n  No Solution Possible" << std::endl;
        }
        
    }
    return 0;
}