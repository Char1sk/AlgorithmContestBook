#include <iostream>
#include <queue>
#include <map>

const int directions[4][2] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}
};

int toInteger(int board[3][3])
{
    int ret = 0;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            ret *= 10;
            ret += board[i][j];
        }
    }
    return ret;
}

int main()
{
    int board[3][3];
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            std::cin >> board[i][j];
        }
    }
    int start = toInteger(board);
    
    int dest[3][3];
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            std::cin >> dest[i][j];
        }
    }
    int ans = toInteger(dest);
    
    std::map<int, int> history;
    history[start] = 0;
    std::queue<int> bfs;
    bfs.push(start);
    
    // bool canFind = false;
    int steps = -1;
    while (!bfs.empty())
    {
        int temp = bfs.front();
        int now = temp;
        bfs.pop();
        if (now == ans)
        {
            // canFind = true;
            steps = history[now];
            break;
        }
        
        int nowb[3][3];
        int zx, zy;
        for (int i = 2; i >= 0; --i)
        {
            for (int j = 2; j >= 0; --j)
            {
                nowb[i][j] = temp % 10;
                temp /= 10;
                if (nowb[i][j] == 0)
                {
                    zx = i;
                    zy = j;
                }
            }
        }
        
        for (auto d : directions)
        {
            int nextx = zx + d[0];
            int nexty = zy + d[1];
            if (0 <= nextx && nextx < 3 && 0 <= nexty && nexty < 3)
            {
                std::swap(nowb[zx][zy], nowb[nextx][nexty]);
                int nextv = toInteger(nowb);
                if (history.find(nextv) == history.end())
                {
                    history[nextv] = history[now]+1;
                    bfs.push(nextv);
                }
                std::swap(nowb[zx][zy], nowb[nextx][nexty]);
            }
        }
    }
    
    std::cout << steps << std::endl;
    return 0;
}