#include <iostream>
#include <queue>
#include <cmath>

// Time Limit Exceeded
void my_solve()
{
    int cases;
    std::cin >> cases;
    while (cases--)
    {
        int depth, ballNum;
        std::cin >> depth >> ballNum;
        
        int ans = std::pow(2, depth-1);
        const int max = 2 * ans;
        std::queue<int> nodes;
        nodes.push(ans);
        nodes.push(max);
        for (int i = 1; i < ballNum; ++i)
        {
            if (nodes.front() == max)
            {
                nodes.pop();
                nodes.push(max);
            }
            int a = nodes.front();
            nodes.pop();
            int b = nodes.front();
            ans = (a+b)/2;
            nodes.push(a);
            nodes.push(ans);
        }
        
        std::cout << ans << std::endl;
    }
    std::cin >> cases;
}

// Accepted 100ms
void nb_solve()
{
    int cases;
    std::cin >> cases;
    while (cases--)
    {
        int depth, ballNum;
        std::cin >> depth >> ballNum;
        
        int ans = 1;
        for (int i = 0; i < depth-1; ++i)
        {
            // odd means left
            if (ballNum % 2 == 1)
            {
                ans *= 2;
                ballNum = ballNum / 2 + 1;
            }
            // even means right
            else
            {
                ans = 2 * ans + 1;
                ballNum /= 2;
            }
        }
        std::cout << ans << std::endl;
    }
    
    std::cin >> cases;
}

int main()
{
    nb_solve();
    return 0;
}