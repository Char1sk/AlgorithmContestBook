#include <iostream>
#include <vector>
#include <algorithm>

int digitSum(int num)
{
    int ret = 0;
    while(num)
    {
        ret += num % 10;
        num /= 10;
    }
    return ret;
}

int main()
{
    // std::vector<int> table;
    // for (int i = 1; i <= 100000; ++i)
    // {
    //     int a = i + digitSum(i);
    //     table.push_back(a);
    // }
    
    int table[100001] {0};
    for (int i = 1; i <= 100000; ++i)
    {
        int sum = i + digitSum(i);
        if (sum <= 100000 && table[sum] == 0)
        {
            table[sum] = i;
        }
    }
    
    int cases;
    std::cin >> cases;
    while (cases--)
    {
        int num;
        std::cin >> num;
        std::cout << table[num] << std::endl;
        // auto it = std::find_if(table.begin(), table.end(),
        //         [num](int gen){ return gen == num; });
        // if ( it != table.end() )
        // {
        //     std::cout << it-table.begin()+1 << std::endl;
        // }
        // else
        // {
        //     std::cout << 0 << std::endl;
        // }
        
    }
    return 0;
}