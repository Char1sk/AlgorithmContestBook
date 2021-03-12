#include <iostream>
#include <vector>
#include <set>

struct Student
{
    int now;
    int wakePeriod;
    int sleepPeriod;
    
    Student() : now(0), wakePeriod(0), sleepPeriod(0) {}
    Student(int n, int w, int s) : now(n), wakePeriod(w), sleepPeriod(s) {}
    bool isAwake()
    {
        return now <= wakePeriod;
    }
    void go(int wakeCount, int sleepCount)
    {
        if (now == wakePeriod)
        {
            if (wakeCount < sleepCount)
            {
                ++now;
            }
            else
            {
                now = 1;
            }
        }
        else if(now == wakePeriod+sleepPeriod)
        {
            now = 1;
        }
        else
        {
            ++now;
        }
        
    }
};

int main()
{
    // std::set<std::vector<int>> statuses;
    // std::vector<int> status1{1, 2, 3};
    // std::vector<int> status2{1, 2, 3};
    // std::vector<int> status3{3, 2, 1};
    // statuses.insert(status1);
    // std::cout << (statuses.find(status1) == statuses.end()) << std::endl
    //           << (statuses.find(status2) == statuses.end()) << std::endl
    //           << (statuses.find(status3) == statuses.end()) << std::endl;
    
    int cases = 0;
    int num;
    while ((std::cin >> num) && num)
    {
        Student students[12];
        std::set<std::vector<int>> statuses;
        for (int i = 0; i < num; ++i)
        {
            std::cin >> students[i].wakePeriod >> students[i].sleepPeriod >> students[i].now;
        }
        
        int tm = 1;
        while (true)
        {
            int wakeCount = 0;
            int sleepCount = 0;
            for (int i = 0; i < num; ++i)
            {
                if (students[i].isAwake())
                {
                    ++wakeCount;
                }
                else
                {
                    ++sleepCount;
                }
            }
            if (sleepCount == 0)
            {
                break;
            }
            
            std::vector<int> status;
            for (int i = 0; i < num; ++i)
            {
                status.push_back(students[i].now);
                // std::cout << students[i].now << ' ';////
            }
            // std::cout << std::endl;////
            if (statuses.find(status) == statuses.end())
            {
                statuses.insert(status);
            }
            else
            {
                tm = -1;
                break;
            }
            
            for (int i = 0; i < num; ++i)
            {
                students[i].go(wakeCount, sleepCount);
            }
            ++tm;
        }
        
        printf("Case %d: %d\n", ++cases, tm);
    }
    
    return 0;
}