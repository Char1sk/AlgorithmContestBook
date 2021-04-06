#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

const int maxN = 6;
const int directions[4][2] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}
};

struct Status
{
    int x;
    int y;
    int step;
    int adist;
    // int father;
    Status() : x(0), y(0), step(0), adist(0) {}
    Status(int i, int j, int s, int a) : x(i), y(j), step(s), adist(a) {}
    bool operator< (const Status &s) const
    {
        if (adist <  s.adist || 
            adist == s.adist && step <  s.step ||
            adist == s.adist && step == s.step && x <  s.x ||
            adist == s.adist && step == s.step && x == s.x && y <  s.y)
        {
            // return true;
            return false;
        }
        // return false;
        return true;
    }
};

void AStar(bool board[maxN][maxN])
{
    int steps[maxN][maxN];
    memset(steps, 127, sizeof(steps));
    steps[0][0] = 0;
    
    int dist[maxN][maxN];
    memset(dist, 127, sizeof(dist));
    dist[maxN-1][maxN-1] = 0;
    Status end(maxN-1, maxN-1, 0, 0);
    std::queue<Status> dq;
    dq.push(end);
    while (!dq.empty())
    {
        Status now = dq.front();
        dq.pop();
        for (auto d : directions)
        {
            Status next(now.x+d[0], now.y+d[1], now.step+1, 0);
            if (0 <= next.x && next.x < maxN && 0 <= next.y && next.y < maxN
                && board[next.x][next.y] && dist[next.x][next.y] > next.step)
            {
                dist[next.x][next.y] = next.step;
                dq.push(next);
            }
        }
    }
    
    // Status start(0, 0, 0);
    Status start(0, 0, 0, maxN << 1);
    std::priority_queue<Status> aq;
    aq.push(start);
    int loopCount = 0;
    int ans = -1;
    while (!aq.empty())
    {
        ++loopCount;
        Status now = aq.top();
        aq.pop();
        std::cout<< loopCount << ':' << now.x << ',' << now.y << std::endl;////
        if (now.x == maxN-1 && now.y == maxN-1)
        {
            ans = now.step;
            break;
        }
        for (auto d : directions)
        {
            // int nx = now.x + d[0];
            // int ny = now.y + d[1];
            // int ns = now.step;
            // Status next(now.x+d[0], now.y+d[1], now.step+1, dist[]+(maxN-now.x-d[0])+(maxN-now.y-d[1]));
            Status next;
            next.x = now.x + d[0];
            next.y = now.y + d[1];
            next.step = now.step + 1;
            next.adist = dist[next.x][next.y] + (maxN - next.x) + (maxN - next.y);
            if (0 <= next.x && next.x < maxN && 0 <= next.y && next.y < maxN
                && board[next.x][next.y] && steps[next.x][next.y] > next.step)
            {
                steps[next.x][next.y] = next.step;
                aq.push(next);
            }
        }
    }
    printf("%d: %d\n", loopCount, ans);
    // std::cout << ans << std::endl;
}

int main()
{
    bool board[maxN][maxN] = {
        {1, 0, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0, 1},
        {1, 0, 1, 0, 1, 1},
        {1, 0, 0, 0, 1, 0},
        {1, 1, 1, 1, 1, 1}
    };
    // bool board[maxN][maxN] = {
    //     {1, 1, 1, 1, 1, 1},
    //     {1, 1, 1, 1, 1, 1},
    //     {1, 1, 1, 1, 1, 1},
    //     {1, 1, 1, 1, 1, 1},
    //     {1, 1, 1, 1, 0, 0},
    //     {1, 1, 1, 1, 1, 1}
    // };
    AStar(board);
    // std::priority_queue<int> qq;
    // qq.push(1);
    // qq.push(2);
    // std::cout << qq.top() << std::endl;
    return 0;
}