#include <iostream>
#include <string>
#include <set>

int main()
{
    freopen(".././in.txt", "r", stdin);
    freopen(".././out.txt", "w", stdout);
    
    int typeCnt;
    while (std::cin >> typeCnt)
    {
        std::set<std::set<int>> types;
        for (int i = 0; i < typeCnt; ++i)
        {
            std::string block;
            std::cin >> block;
            std::set<int> type;
            for (int j = 0; j < 8; ++j)
            {
                char c1 = block[j];
                char c2 = block[++j];
                if (c1 != '0')
                {
                    int n = c1 - 'A' + 1;
                    if (c2 == '-')
                    {
                        n *= -1;
                    }
                    type.insert(n);
                }
            }
            if (!type.empty())
            {
                types.insert(type);
            }
        }
        
        std::set<std::set<int>> usedTypes;
        bool canSolve = false;
        for (auto &start : types)
        {
            if (usedTypes.find(start) != usedTypes.end())
            {
                continue;
            }
            usedTypes.insert(start);
            
            std::set<std::set<int>> status;
            std::set<int> now(start);
            bool cantSolve = false;
            while (!now.empty() && status.find(now) == status.end())
            {
                status.insert(now);
                std::set<int> next(now);
                bool canChange = false;
                for (auto i : now)
                {
                    bool canDel = false;
                    bool canAdd = false;
                    for (auto &s : types)
                    {
                        if (s.find(-i) != s.end())
                        {
                            canChange = true;
                            canDel = true;
                            if (s.find(i) != s.end())
                            {
                                canAdd = true;
                            }
                            for (auto j : s)
                            {
                                if (j != -i)
                                {
                                    next.insert(j);
                                }
                            }
                        }
                    }
                    if (canDel && !canAdd)
                    {
                        next.erase(i);
                    }
                }
                
                if (!canChange)
                {
                    cantSolve = true;
                    break;
                }
                now = next;
            }
            if (now.empty())
            {
                cantSolve = true;
            }
            if (!cantSolve)
            {
                canSolve = true;
                break;
            }
        }
        std::cout << (canSolve ? "unbounded" : "bounded") << std::endl;
    }
    return 0;
}