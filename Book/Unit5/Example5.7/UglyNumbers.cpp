#include <iostream>
#include <vector>
#include <queue>
#include <set>

int factors[] {2, 3, 5};

int main()
{
    std::priority_queue<unsigned long long, std::vector<unsigned long long>, std::greater<unsigned long long>> uglys;
    std::set<unsigned long long> outs;
    uglys.push(1);
    unsigned long long ans;
    for (int i = 0; i < 1500; ++i)
    {
        ans = uglys.top();
        uglys.pop();
        for (int j = 0; j < 3; ++j)
        {
            unsigned long long toPush = ans * factors[j];
            if (outs.find(toPush) == outs.end())
            {
                outs.insert(toPush);
                uglys.push(toPush);
            }
        }
    }
    std::cout << "The 1500'th ugly number is " << ans << "." << std::endl;
    return 0;
}