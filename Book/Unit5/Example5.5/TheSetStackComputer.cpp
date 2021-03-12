#include <iostream>
#include <set>
#include <map>
#include <stack>

std::map<std::set<int>, int> setToID;
int id = 0;

void addSet(const std::set<int> &st)
{
    if (setToID[st] == 0)
    {
        setToID[st] = ++id;
    }
}

int main()
{
    int cases;
    std::cin >> cases;
    while (cases--)
    {
        std::stack<std::set<int>> setStack;
        
        int opCount;
        std::cin >> opCount;
        while (opCount--)
        {
            std::string cmd;
            std::cin >> cmd;
            
            if (cmd == "PUSH")
            {
                std::set<int> newSet;
                addSet(newSet);
                setStack.push(newSet);
            }
            if (cmd == "DUP")
            {
                std::set<int> newSet(setStack.top());
                setStack.push(newSet);
            }
            if (cmd == "UNION")
            {
                std::set<int> newSet1(setStack.top());
                setStack.pop();
                std::set<int> newSet2(setStack.top());
                setStack.pop();
                for (auto i : newSet2)
                {
                    newSet1.insert(i);
                }
                addSet(newSet1);
                setStack.push(newSet1);
            }
            if (cmd == "INTERSECT")
            {
                std::set<int> newSet1(setStack.top());
                setStack.pop();
                std::set<int> newSet2(setStack.top());
                setStack.pop();
                std::set<int> newSet;
                for (auto i : newSet1)
                {
                    if (newSet2.find(i) != newSet2.end())
                    {
                        newSet.insert(i);
                    }
                }
                addSet(newSet);
                setStack.push(newSet);
            }
            if (cmd == "ADD")
            {
                std::set<int> newSet1(setStack.top());
                setStack.pop();
                std::set<int> newSet2(setStack.top());
                setStack.pop();
                newSet2.insert(setToID[newSet1]);
                addSet(newSet2);
                setStack.push(newSet2);
            }
            
            std::cout << setStack.top().size() << std::endl;
        }
        
        // for (auto &p : setToID)
        // {
        //     std::cout << "{" ;
        //     for (auto i : p.first)
        //     {
        //         std::cout << i << ',';
        //     }
        //     std::cout << "}" << p.second << std::endl; ;
        // }
        
        std::cout << "***" << std::endl;
    }
    return 0;
}