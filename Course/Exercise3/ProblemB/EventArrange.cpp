#include <iostream>
#include <algorithm>

struct Event
{
    int beg;
    int end;
    Event() : beg(0), end(0) {}
};

const int maxN = 1000+5;
Event events[maxN];

int main()
{
    int count;
    std::cin >> count;
    for (int e = 0; e < count; ++e)
    {
        std::cin >> events[e].beg >> events[e].end;
    }
    std::sort(events, events+count, [count](const Event &e1, const Event &e2){return e1.end < e2.end;});
    
    int nextTime = 0;
    int ans = 0;
    for (int e = 0; e < count; ++e)
    {
        if (events[e].beg >= nextTime)
        {
            nextTime = events[e].end;
            ++ans;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}