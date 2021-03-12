#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

struct Task
{
    int tid;
    int totalCount;
    int nextTime;
    int useTime;
    int comeTime;
    Task() {}
    Task(int i1, int i2, int i3, int i4, int i5) : 
            tid(i1), totalCount(i2), nextTime(i3), useTime(i4), comeTime(i5) {}
};

struct Person
{
    int pid;
    std::vector<int> priority;
    int lastTime;
    int needTime;
    Person() {}
    Person(int i, const std::vector<int> &vi) : 
            pid(i), priority(vi), lastTime(0), needTime(0) {}
};

// bool operator< (const Person &p1, const Person &p2)
// {
//     return (p1.lastTime > p2.lastTime) || (p1.lastTime == p2.lastTime && p1.pid > p2.pid);
// }

struct SB
{
    int a;
    SB() : a(0) {}
    SB(int i) : a(i) {}
};


int main()
{
    int cases;
    int topicCount;
    while (std::cin >> topicCount && topicCount)
    {
        int count = 0;
        std::map<int, Task> tidToTasks;
        while (topicCount--)
        {
            int td, tc, bt, ut, ct;
            std::cin >> td >> tc >> bt >> ut >> ct;
            tidToTasks[td] = Task(td, tc, bt, ut, ct);
            count += tc;
        }
        
        int peopleCount;
        std::cin >> peopleCount;
        std::vector<Person> people;
        while (peopleCount--)
        {
            int pd, pc;
            std::cin >> pd >> pc;
            std::vector<int> temp;
            while (pc--)
            {
                int tp;
                std::cin >> tp;
                temp.push_back(tp);
            }
            people.emplace_back(pd, temp);
        }
        
        int minute = 0;
        std::map<int, int> tidToCount;
        while (true)
        {
            for (auto &prt : tidToTasks)
            {
                if (prt.second.totalCount && minute == prt.second.nextTime)
                {
                    prt.second.nextTime += prt.second.comeTime;
                    ++tidToCount[prt.second.tid];
                    --prt.second.totalCount;
                }
            }
            
            for (auto &p : people)
            {
                if (p.needTime)
                {
                    if (--p.needTime == 0)
                    {
                        --count;
                    }
                }
            }
            
            while (true)
            {
                std::map<int, std::vector<Person*>> tidToPersons;
                for (auto &p : people)
                {
                    if (!p.needTime)
                    {
                        for (auto i : p.priority)
                        {
                            if (tidToCount[i])
                            {
                                tidToPersons[i].push_back(&p);
                                break;
                            }
                        }
                    }
                }
                if (tidToPersons.empty())
                {
                    break;
                }
                for (auto &pr : tidToPersons)
                {
                    if (tidToCount[pr.first] >= pr.second.size())
                    {
                        tidToCount[pr.first] -= pr.second.size();
                        for (auto &p : pr.second)
                        {
                            p->lastTime = minute;
                            p->needTime = tidToTasks[pr.first].useTime;
                            pr.second.clear();
                        }
                    }
                    else
                    {
                        std::sort(pr.second.begin(), pr.second.end(), [](Person *p1, Person *p2)
                            {return (p1->lastTime > p2->lastTime) || (p1->lastTime == p2->lastTime && p1->pid > p2->pid);});
                        for (int i = 0; i < tidToCount[pr.first]; ++i)
                        {
                            auto &p = pr.second.back();
                            p->lastTime = minute;
                            p->needTime = tidToTasks[pr.first].useTime;
                            pr.second.pop_back();
                        }
                        tidToCount[pr.first] = 0;
                    }
                }
            }
            if (!count)
            {
                break;
            }
            ++minute;
            // std::cout << people[0].needTime << ' ' << people[1].needTime << std::endl;////
        }
        
        printf("Scenario %d: All requests are serviced within %d minutes.\n", ++cases, minute);
    }
    return 0;
}

// 0 1 2 3 4 5 6 7 8 9 10
// *   *   *   *   *
//   +   +   +   +   +