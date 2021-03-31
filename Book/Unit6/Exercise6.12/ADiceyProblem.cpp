#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <utility>
// #include <cstring>

// ESWN
const int directions[4][2]{
    {0, 1}, {1, 0}, {0, -1}, {-1, 0}
};

struct Dice
{
    int top;
    int bot;
    int south;
    int north;
    int west;
    int east;
    Dice() {}
    Dice(int t, int s) : top(t), bot(7-t), south(s), north(7-s)
    {
        if      ((t == 1 && s == 2) || (t == 2 && s == 6) || (t == 6 && s == 5) || (t == 5 && s == 1))
        {
            west = 4;
            east = 3;
        }
        else if ((t == 2 && s == 1) || (t == 6 && s == 2) || (t == 5 && s == 6) || (t == 1 && s == 5))
        {
            west = 3;
            east = 4;
        }
        else if ((t == 2 && s == 4) || (t == 4 && s == 5) || (t == 5 && s == 3) || (t == 3 && s == 2))
        {
            west = 1;
            east = 6;
        }
        else if ((t == 4 && s == 2) || (t == 5 && s == 4) || (t == 3 && s == 5) || (t == 2 && s == 3))
        {
            west = 6;
            east = 1;
        }
        else if ((t == 6 && s == 4) || (t == 4 && s == 1) || (t == 1 && s == 3) || (t == 3 && s == 6))
        {
            west = 2;
            east = 5;
        }
        else if ((t == 4 && s == 6) || (t == 1 && s == 4) || (t == 3 && s == 1) || (t == 6 && s == 3))
        {
            west = 5;
            east = 2;
        }
    }
    void roll(int dire)
    {
        int temp;
        switch (dire)
        {
        case 0:
            temp = east;
            east = top;
            top = west;
            west = bot;
            bot = temp;
            break;
        case 1:
            temp = south;
            south = top;
            top = north;
            north = bot;
            bot = temp;
            break;
        case 2:
            temp = west;
            west = top;
            top = east;
            east = bot;
            bot = temp;
            break;
        case 3:
            temp = north;
            north = top;
            top = south;
            south = bot;
            bot = temp;
            break;
        default:
            break;
        }
    }
    std::string toString() const
    {
        std::string ret;
        ret += top + '0';
        ret += bot + '0';
        ret += south + '0';
        ret += north + '0';
        ret += east + '0';
        ret += west + '0';
        return ret;
    }
    bool operator< (const Dice &d) const
    {
        return toString() < d.toString();
    }
};

struct Grid
{
    int value;              // the value
    std::set<Dice> dices;   // visited dices
    Grid() : value(0), dices() {}
};

struct Status
{
    int nowx;
    int nowy;
    Dice nowd;
    std::vector<std::pair<int, int>> path;
    Status() : nowx(0), nowy(0), nowd() {}
    Status(int x, int y, int dtop, int dsouth, const std::vector<std::pair<int, int>> vpii)
             : nowx(x), nowy(y), nowd(dtop, dsouth), path(vpii)
    {
        path.push_back({x, y});
    }
};

int main()
{
    std::string name;
    while (std::cin >> name && name != "END")
    {
        // input and initialize
        int row, col, startx, starty, top, south;
        std::cin >> row >> col >> startx >> starty >> top >> south;
        --startx;       --starty;
        std::vector<std::vector<Grid>> board(row, std::vector<Grid>(col));
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                std::cin >> board[i][j].value;
            }
        }
        // let's BFS!
        std::queue<Status> bfsQ;
        bfsQ.emplace(startx, starty, top, south, std::vector<std::pair<int, int>>());
        bool isFirst = true;
        std::vector<std::pair<int, int>> answer;
        while (!bfsQ.empty())
        {
            Status tpStatus = bfsQ.front();
            bfsQ.pop();
            int topVal = tpStatus.nowd.top;
            
            if (isFirst)
            {
                isFirst = false;
            }
            else if (tpStatus.nowx == startx && tpStatus.nowy == starty)
            {
                answer = tpStatus.path;
                break;
            }
            
            for (int i = 0; i < 4; ++i)
            {
                int nextx = tpStatus.nowx + directions[i][0];
                int nexty = tpStatus.nowy + directions[i][1];
                if (0 <= nextx && nextx < row && 0 <= nexty && nexty < col && board[nextx][nexty].value)
                {
                    Grid &bd = board[nextx][nexty];
                    Dice nextd(tpStatus.nowd.top, tpStatus.nowd.south);
                    nextd.roll(i);
                    if ((bd.value == -1 || bd.value == topVal) && bd.dices.find(nextd) == bd.dices.end())
                    {
                        bd.dices.insert(nextd);
                        bfsQ.emplace(nextx, nexty, nextd.top, nextd.south, tpStatus.path);
                    }
                }
            }
        }
        std::cout << name;
        if (answer.empty())
        {
            std::cout << "\n  No Solution Possible" << std::endl;
        }
        else
        {
            for (int i = 0; i < answer.size(); ++i)
            {
                printf("%s(%d,%d)%c", (i%9==0 ? "\n  " : ""), 
                        answer[i].first+1, answer[i].second+1, (i==answer.size()-1 ? '\n' : ','));
            }
        }
    }
    return 0;
}