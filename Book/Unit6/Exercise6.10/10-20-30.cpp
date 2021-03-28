#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <set>

const int maxN = 52;

struct Status
{
    int index;
    std::queue<int> deck;
    std::vector<std::list<int>> piles;
    Status() {}
    Status(int i, const std::queue<int> d, const std::vector<std::list<int>> &p) :
            index(i), deck(d), piles(p) {}
    bool operator< (const Status &s) const
    {
        if (index < s.index)
        {
            return true;
        }
        else
        {
            if (index == s.index && deck < s.deck)
            {
                return true;
            }
            else
            {
                if (index == s.index && deck == s.deck && piles < s.piles)
                {
                    return true;
                }
            }
            
        }
        return false;
    }
};

int main()
{
    int itemp;
    while (std::cin >> itemp && itemp)
    {
        std::set<Status> statuses;
        
        std::queue<int> deck;
        deck.push(itemp);
        for (int i = 1; i < maxN; ++i)
        {
            std::cin >> itemp;
            deck.push(itemp);
        }
        
        int restCount = 7;
        int index = 0;
        int total = 0;
        std::vector<std::list<int>> piles(restCount);
        std::vector<bool> exist(restCount, true);
        while (restCount && !deck.empty())
        {
            int now = deck.front();
            deck.pop();
            piles[index].push_back(now);
            while (piles[index].size() >= 3)
            {
                auto &pile = piles[index];
                auto bit = pile.begin();
                int b = *bit;
                auto bbit = pile.begin();       ++bbit;
                int bb = *bbit;
                auto rit = pile.end();          --rit;
                int r = *rit;
                auto rrit = pile.end();         --rrit;     --rrit;
                int rr = *rrit;
                auto rrrit = pile.end();        --rrrit;    --rrrit;    --rrrit;
                int rrr = *rrrit;
                
                bool nochange = true;
                if ((b+bb+r) % 10 == 0)
                {
                    deck.push(b);
                    deck.push(bb);
                    deck.push(r);
                    pile.erase(bit);
                    pile.erase(bbit);
                    pile.erase(rit);
                    nochange = false;
                }
                else if ((b+rr+r) % 10 == 0)
                {
                    deck.push(b);
                    deck.push(rr);
                    deck.push(r);
                    pile.erase(bit);
                    pile.erase(rrit);
                    pile.erase(rit);
                    nochange = false;
                }
                else if ((rrr+rr+r) % 10 == 0)
                {
                    deck.push(rrr);
                    deck.push(rr);
                    deck.push(r);
                    pile.erase(rrrit);
                    pile.erase(rrit);
                    pile.erase(rit);
                    nochange = false;
                }
                
                
                if (nochange)
                {
                    break;
                }
                
            }
            if (piles[index].empty())
            {
                exist[index] = false;
                --restCount;
            }
            
            ++total;
            
            Status next(index, deck, piles);
            if (statuses.find(next) != statuses.end())
            {
                break;
            }
            else
            {
                statuses.insert(next);
            }
            
            do
            {
                ++index;
                if (index == 7)
                {
                    index = 0;
                }
            } while (!exist[index] && restCount);
        }
        
        if (restCount == 0)
        {
            printf("Win : %d\n", total);
        }
        else if (deck.empty())
        {
            printf("Loss: %d\n", total);
        }
        else
        {
            printf("Draw: %d\n", total);
        }
        
    }
    return 0;
}