#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

const int maxN = 20;
const int directions[5][2] = {
    {0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}
};

struct Grid
{
    int x;
    int y;
    Grid() : x(0), y(0) {}
    Grid(int a, int b) : x(a), y(b) {}
    // bool operator< (const Grid &g) const
    // {
    //     return (x < g.x) || (x == g.x && y < g.y);
    // }
    bool operator== (const Grid &g) const
    {
        return (x == g.x) && (y == g.y);
    }
};

struct Status
{
    Grid ghosts[3];
    int step;
    // int adist;
    // bool operator< (const Status &s) const
    // {
    //     if (/* adist <  s.adist ||  */
    //         /* adist == s.adist &&  */step <  s.step ||
    //         /* adist == s.adist &&  */step == s.step && ghosts[0] <  ghosts[0] ||
    //         /* adist == s.adist &&  */step == s.step && ghosts[0] == ghosts[0] && ghosts[1] <  ghosts[1] ||
    //         /* adist == s.adist &&  */step == s.step && ghosts[0] == ghosts[0] && ghosts[1] == ghosts[1] && ghosts[2] <  ghosts[2])
    //     {
    //         return false; ///
    //     }
    //     return true; ///
    // }
    bool operator== (const Status &s) const
    {
        return ghosts[0] == s.ghosts[0] && ghosts[1] == s.ghosts[1] && ghosts[2] == s.ghosts[2];
    }
};

int main()
{
    int row, col, gcnt;
    while (std::cin >> col >> row >> gcnt && row && col && gcnt)
    {
        // input and initialize
        getchar();
        bool board[maxN][maxN];
        memset(board, 1, sizeof(board));
        Status start;
        Status end;
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                char c = getchar();
                if (c == '#')
                {
                    board[i][j] = false;
                }
                else if (islower(c))
                {
                    start.ghosts[c-'a'].x = i;
                    start.ghosts[c-'a'].y = j;
                }
                else if (isupper(c))
                {
                    end.ghosts[c-'A'].x = i;
                    end.ghosts[c-'A'].y = j;
                }
            }
            getchar();
        }
        // build graph
        std::vector<Grid> graph[maxN][maxN];
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (board[i][j])
                {
                    for (auto d : directions)
                    {
                        int nx = i+d[0];
                        int ny = j+d[1];
                        if (0 <= nx && nx < row && 0 <= ny && ny < col && board[nx][ny])
                        {
                            graph[i][j].emplace_back(nx, ny);
                        }
                    }
                }
            }
        }
        // single BFS
        std::queue<Status> q;
        q.push(start);
        while (!q.empty())
        {
            Status now = q.front();
            q.pop();
            if (now == end)
            {
                
                break;
            }
            // for (int g = 0; g < )
        }
    }
    return 0;
}