#include <iostream>
#include <queue>

int main()
{
    int len;
    while ((std::cin >> len) && len)
    {
        std::queue<int> cards;
        for (int i = 1; i < len+1; ++i)
        {
            cards.push(i);
        }
        
        std::cout << "Discarded cards:" ;
        for (int i = 0; i < len-1; ++i)
        {
            if (i != 0)
            {
                std::cout << ',' ;
            }
            std::cout << ' ';
            std::cout << cards.front();
            cards.pop();
            int head = cards.front();
            cards.pop();
            cards.push(head);
        }
        printf("\nRemaining card: %d\n", cards.front());
    }
    return 0;
}