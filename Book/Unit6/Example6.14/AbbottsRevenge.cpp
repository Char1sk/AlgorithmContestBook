#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>

struct Triple
{
    int x;
    int y;
    char direction;
    std::vector<std::pair<int, int>> path;
    Triple() : x(0), y(0), direction(0) {}
    Triple(int i, int j, char c) : x(i), y(j), direction(c)
    {
        path.push_back({i, j});
    }
    Triple(int i, int j, char c, std::vector<std::pair<int, int>> vp) : x(i), y(j), direction(c), path(vp)
    {
        path.push_back({i, j});
    }
    bool operator< (const Triple &t) const
    {
        return x < t.x || (x == t.x && y < t.y) || (x == t.x && y == t.y && direction < t.direction);
    }
    bool operator== (const Triple &t) const
    {
        return x == t.x && y == t.y && direction == t.direction;
    }
};

const std::map<char, std::pair<int, int>> directions = {
    {'N', {-1, 0}}, {'S', {1, 0}}, {'W', {0, -1}}, {'E', {0, 1}}
};

char changeDirection(char origin, char change)
{
    if (change == 'F')
    {
        return origin;
    }
    else if (change == 'R')
    {
        switch (origin)
        {
        case 'N':
            return 'E';
        case 'E':
            return 'S';
        case 'S':
            return 'W';
        case 'W':
            return 'N';
        default:
            break;
        }
    }
    else if (change == 'L')
    {
        switch (origin)
        {
        case 'N':
            return 'W';
        case 'E':
            return 'N';
        case 'S':
            return 'E';
        case 'W':
            return 'S';
        default:
            break;
        }
    }
    return '*';
}

int main()
{
    // std::set<Triple> s;
    // Triple t1(1, 1, 'W');
    // s.insert(t1);
    // Triple t2(1, 1, 'E');
    // std::cout << (s.find(t2) == s.end()) << std::endl;
    // std::cout << (t1 == t2) << std::endl;
    // s.insert(t2);
    // std::cout << s.size() << std::endl;
    
    
    std::string name;
    while (std::cin >> name && name != "END")
    {
        std::map<char, std::string> maze[10][10];
        int fromx, fromy, tox, toy;
        char startDirect;
        std::cin >> fromx >> fromy >> startDirect >> tox >> toy;
        
        maze[fromx][fromy][startDirect].push_back(startDirect);
        int x, y;
        while (std::cin >> x && x)
        {
            std::cin >> y;
            std::string sign;
            while (std::cin >> sign && sign != "*")
            {
                char c = sign[0];
                for (int i = 1; i < sign.size(); ++i)
                {
                    maze[x][y][c].push_back(changeDirection(c, sign[i]));
                }
            }
        }
        
        std::set<Triple> nodes;
        std::queue<Triple> nodeQueue;
        // std::vector<Triple> nodePath;
        
        auto &pp = directions.at(startDirect);
        Triple firstStep(fromx, fromy, startDirect);
        // Triple secondStep(fromx+pp.first, fromy+pp.second, startDirect, firstStep.path);
        // firstStep.path.push_back({firstStep.x, firstStep.y});
        nodes.insert(firstStep);
        nodeQueue.push(firstStep);
        // nodePath.push_back(firstStep);
        
        bool isFound = false;
        std::vector<std::pair<int, int>> ans;
        while (!nodeQueue.empty())
        {
            Triple last(nodeQueue.front());
            nodeQueue.pop();
            
            std::string ds = maze[last.x][last.y][last.direction];
            for(char d : ds)
            {
                int xx = last.x + directions.at(d).first;
                int yy = last.y + directions.at(d).second;
                Triple toPush(xx, yy, d, last.path);
                if (xx == tox && yy == toy)
                {
                    isFound = true;
                    ans = toPush.path;
                    goto End;
                }
                if (nodes.find(toPush) == nodes.end())
                {
                    nodes.insert(toPush);
                    nodeQueue.push(toPush);
                    // nodePath.push_back(toPush);
                }
            }
        }
        End: ;
        std::cout << name;
        if (isFound)
        {
            for (int i = 0; i < ans.size(); ++i)
            {
                printf("%s(%d,%d)", (i%10 == 0 ? "\n  " : " "), ans[i].first, ans[i].second);
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