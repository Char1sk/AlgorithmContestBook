#include <iostream>
#include <string>
#include <list>
#include <stack>

int main()
{
    // freopen("./in.txt", "r", stdin);
    // freopen("./out.txt", "w", stdout);
    
    std::string stemp;
    while (std::cin >> stemp && stemp != "#")
    {
        std::list<std::stack<std::string>> piles(52);
        for (auto it = piles.begin(); it != piles.end(); ++it)
        {
            if (it != piles.begin())
            {
                std::cin >> stemp;
            }
            it->push(stemp);
        }
        
        while (true)
        {
            int i = 0;
            bool changed = false;
            for (auto it = piles.begin(); it != piles.end(); ++it, ++i)
            {
                std::string now = it->top();
                if (i >= 3)
                {
                    --it; --it; --it;
                    bool canDo = false;
                    std::string prev = it->top();
                    if (prev[0] == now[0] || prev[1] == now[1])
                    {
                        changed = true;
                        canDo = true;
                        it->push(now);
                    }
                    ++it; ++it; ++it;
                    if (canDo)
                    {
                        it->pop();
                        if (it->empty())
                        {
                            piles.erase(it);
                        }
                        break;
                    }
                }
                if (i >= 1)
                {
                    --it;
                    bool canDo = false;
                    std::string prev = it->top();
                    if (prev[0] == now[0] || prev[1] == now[1])
                    {
                        changed = true;
                        canDo = true;
                        it->push(now);
                    }
                    ++it;
                    if (canDo)
                    {
                        it->pop();
                        if (it->empty())
                        {
                            piles.erase(it);
                        }
                        break;
                    }
                }
            }
            if (!changed)
            {
                break;
            }
        }
        printf("%d %s remaining:", piles.size(), (piles.size() == 1 ? "pile" : "piles"));
        for (auto &s : piles)
        {
            printf(" %d", s.size());
        }
        std::cout << std::endl;
    }
    return 0;
}