#include <iostream>
#include <queue>

int main()
{
    int cases;
    std::cin >> cases;
    while (cases--)
    {
        int len;
        int myPos;
        std::cin >> len >> myPos;
        
        std::queue<int> printer;
        std::priority_queue<int> jobPrio;
        for (int i = 0; i < len; ++i)
        {
            int itemp;
            std::cin >> itemp;
            printer.push(itemp);
            jobPrio.push(itemp);
        }
        
        int minutes = 0;
        while (true)
        {
            if (printer.front() == jobPrio.top())
            {
                ++minutes;
                printer.pop();
                jobPrio.pop();
                if (myPos == 0)
                {
                    break;
                }
                else
                {
                    --myPos;
                    --len;
                }
            }
            else
            {
                printer.push(printer.front());
                printer.pop();
                if (myPos == 0)
                {
                    myPos = len-1;
                }
                else
                {
                    --myPos;
                }
            }
        }
        
        std::cout << minutes << std::endl;
    }
    return 0;
}