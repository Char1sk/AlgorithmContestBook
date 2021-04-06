#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cstring>

inline int min(int a, int b)
{
    return a < b ? a : b;
}

struct Status
{
    int total;
    int liter[3];
    Status() : total(0)
    {
        memset(liter, 0, sizeof(liter));
    }
    Status(int i, int j, int k, int t) : total(t)
    {
        liter[0] = i;
        liter[1] = j;
        liter[2] = k;
    }
    bool operator< (const Status &s) const
    {
        if (/* total <  s.total ||  */
            /* total == s.total &&  */liter[0] <  s.liter[0] ||
            /* total == s.total &&  */liter[0] == s.liter[0] && liter[1] <  s.liter[1] ||
            /* total == s.total &&  */liter[0] == s.liter[0] && liter[1] == s.liter[1] && liter[2] < s.liter[2])
        {
            return true;
        }
        return false;
    }
};

struct StatusCmp
{
    bool operator()(const Status &lhs, const Status &rhs)
    {
        if (lhs.total >  rhs.total || 
            lhs.total == rhs.total && lhs.liter[0] >  rhs.liter[0] ||
            lhs.total == rhs.total && lhs.liter[0] == rhs.liter[0] && lhs.liter[1] >  rhs.liter[1] ||
            lhs.total == rhs.total && lhs.liter[0] == rhs.liter[0] && lhs.liter[1] == rhs.liter[1] && lhs.liter[2] > rhs.liter[2])
        {
            return true;
        }
        return false;
    }
};

int main()
{
    // freopen("./in.txt", "r", stdin);
    // freopen("./out.txt", "w", stdout);
    
    int cases;
    std::cin >> cases;
    while (cases--)
    {
        int maxL[3];
        int target;
        std::cin >> maxL[0] >> maxL[1] >> maxL[2] >> target;
        Status start(0, 0, maxL[2], 0);
        
        std::priority_queue<Status, std::vector<Status>, StatusCmp> bfs;
        bfs.push(start);
        // std::set<Status> history;
        // history.insert(start);
        std::map<Status, int> minWat;
        minWat[start] = 0;
        std::map<int, int> closeToMinWater;
        
        int closest = 0;
        // int minWater = 250;
        if (maxL[2] > target)
        {
            while (!bfs.empty())
            {
                Status now = bfs.top();
                bfs.pop();
                
                // bool canQuit = false;
                // for (int l : now.liter)
                // {
                //     if (l == target)
                //     {
                //         // if (minWater > now.total)
                //         // {
                //         //     minWater = now.total;
                //         // }
                //         canQuit = true;
                //         break;
                //     }
                // }
                // if (canQuit)
                // {
                //     break;
                // }
                
                for (int i = 0; i < 3; ++i)
                {
                    for (int j = 0; j < 3; ++j)
                    {
                        if (i != j)
                        {
                            int delta = min(now.liter[i], maxL[j]-now.liter[j]);
                            if (delta)
                            {
                                Status nexts(now);
                                nexts.liter[i] -= delta;
                                nexts.liter[j] += delta;
                                nexts.total += delta;
                                if (minWat.find(nexts) == minWat.end() || minWat[nexts] > nexts.total)
                                {
                                    minWat[nexts] = nexts.total;
                                    bfs.push(nexts);
                                    
                                    for (int k = 0; k < 3; ++k)
                                    {
                                        int lk = nexts.liter[k];
                                        if (lk && closest <= lk && lk <= target)
                                        {
                                            closest = lk;
                                            int &val = closeToMinWater[closest];
                                            if (val == 0 || val > nexts.total)
                                            {
                                                val = nexts.total;
                                            }
                                            // if (minWater > nexts.total)
                                            // {
                                                // minWater = nexts.total;
                                            // }
                                        }
                                        // if (closest == nexts.liter[k] && minWater > nexts.total)
                                        // {
                                        //     minWater = nexts.total;
                                        // }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        else
        {
            // minWater = 0;
            closest = maxL[2];
            closeToMinWater[closest] = 0;
        }
        
        std::cout << closeToMinWater[closest] << ' ' << closest << std::endl;
    }
    return 0;
}