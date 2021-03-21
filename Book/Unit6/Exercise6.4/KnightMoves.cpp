#include <iostream>
#include <string>
#include <queue>
#include <utility>

struct Node
{
    int x;
    int y;
    int step;
    Node(int i1, int i2, int s = 0) : x(i1), y(i2), step(s) {}
};


const int directions[8][2] = {
    {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}
};

int main()
{
    std::string p1, p2;
    while (std::cin >> p1 >> p2)
    {
        int fromx = p1[0]-'a', fromy = p1[1]-'1';
        int tox = p2[0]-'a', toy = p2[1]-'1';
        
        bool board[8][8] = {0};
        board[fromx][fromy] = true;
        std::queue<Node> bfsQ;
        bfsQ.emplace(fromx, fromy);
        while (!bfsQ.empty())
        {
            const Node &now = bfsQ.front();
            bfsQ.pop();
            if (now.x == tox && now.y == toy)
            {
                printf("To get from %s to %s takes %d knight moves.\n", p1.c_str(), p2.c_str(), now.step);
                break;
            }
            for (auto d : directions)
            {
                int newx = now.x + d[0];
                int newy = now.y + d[1];
                if (0 <= newx && newx < 8 && 0 <= newy && newy < 8 && !board[newx][newy])
                {
                    board[newx][newy] = true;
                    bfsQ.emplace(newx, newy, now.step+1);
                }
            }
        }
    }
    return 0;
}