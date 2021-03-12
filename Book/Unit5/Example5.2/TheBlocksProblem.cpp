#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
    freopen("./in.txt", "r", stdin);
    freopen("./out.txt", "w", stdout);
    
    int len;
    std::cin >> len; 
    std::vector<int> stacks[30];
    for (int i = 0; i < len; ++i)
    {
        stacks[i].push_back(i);
    }
    
    std::string command1;
    
    while ((std::cin >> command1) && (command1 != "quit"))
    {
        std::string command2;
        int num1, num2, index1, index2;
        std::cin >> num1 >> command2 >> num2;
        auto it1 = stacks[0].begin();
        auto it2 = stacks[0].begin();
        for (int i = 0; i < len; ++i)
        {
            if (std::find(stacks[i].begin(), stacks[i].end(), num1) != stacks[i].end())
            {
                it1 = std::find(stacks[i].begin(), stacks[i].end(), num1);
                index1 = i;
            }
            if (std::find(stacks[i].begin(), stacks[i].end(), num2) != stacks[i].end())
            {
                it2 = std::find(stacks[i].begin(), stacks[i].end(), num2);
                index2 = i;
            }
        }
        // std::cout << *it1 << *it2 << std::endl;///
        
        if (index1 == index2)
        {
            continue;
        }
        
        if (command1 == "move")
        {
            while (stacks[index1].back() != num1)
            {
                stacks[stacks[index1].back()].push_back(stacks[index1].back());
                stacks[index1].pop_back();
            }
        }
        // std::cout << stacks[index1].back() << std::endl;////
        if (command2 == "onto")
        {
            while (stacks[index2].back() != num2)
            {
                stacks[stacks[index2].back()].push_back(stacks[index2].back());
                stacks[index2].pop_back();
            }
        }
        // std::cout << stacks[index2].back() << std::endl;////
        for (auto i1 = it1; i1 != stacks[index1].end(); ++i1)
        {
            stacks[index2].push_back(*i1);
        }
        
        if (command1 == "pile")
        {
            while (stacks[index1].back() != num1)
            {
                stacks[index1].pop_back();
            }
        }
        stacks[index1].pop_back();
    }
    
    for (int i = 0; i < len; ++i)
    {
        printf("%d:", i);
        for (auto i1 = stacks[i].begin(); i1 != stacks[i].end(); ++i1)
        {
            printf(" %d", *i1);
        }
        std::cout << std::endl;
    }
    
    return 0;
}
// 0  0
// 1  1 9 2 4
// 2  
// 3  3
// 4  
// 5  5 8 7 6
// 6  
// 7  
// 8  
// 9  

