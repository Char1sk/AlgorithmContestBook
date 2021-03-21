#include <iostream>
#include <queue>
#include <cstring>

const int directions[4][2] = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}
};

struct Node
{
    int x;
    int y;
    int step;
    int passed;
    Node(int i, int j, int s, int p) : x(i), y(j), step(s), passed(p) {}
};


int main()
{
    int cases;
    std::cin >> cases;
    while (cases--)
    {
        int row, col, maxp;
        std::cin >> row >> col >> maxp;
        
        int used[25][25];
        memset(used, -1, sizeof(used));
        bool board[25][25];
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                std::cin >> board[i][j];
            }
        }
        
        int minStep = -1;
        std::queue<Node> bfsQ;
        bfsQ.emplace(0, 0, 0, 0);
        used[0][0] = 0;
        while (!bfsQ.empty())
        {
            Node &now = bfsQ.front();
            bfsQ.pop();
            if (now.x == row-1 && now.y == col-1)
            {
                minStep = now.step;
                break;
            }
            for (auto d : directions)
            {
                int newx = now.x + d[0];
                int newy = now.y + d[1];
                if (0 <= newx && newx < row && 0 <= newy && newy < col)
                {
                    if (board[newx][newy])
                    {
                        if (now.passed < maxp && (used[newx][newy] == -1 || now.passed+1 < used[newx][newy]))
                        {
                            used[newx][newy] = now.passed+1;
                            bfsQ.emplace(newx, newy, now.step+1, now.passed+1);
                        }
                    }
                    else
                    {
                        if (used[newx][newy] == -1 || 0 < used[newx][newy])
                        {
                            used[newx][newy] = 0;
                            bfsQ.emplace(newx, newy, now.step+1, 0);
                        }
                    }
                }
            }
        }
        std::cout << minStep << std::endl;
    }
    return 0;
}