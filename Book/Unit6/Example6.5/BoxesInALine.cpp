#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>   

int main()
{
    int cases = 0;
    int boxCount;
    int cmdCount;
    while (std::cin >> boxCount >> cmdCount)
    {
        bool isReversed = false;
        std::list<int> boxes(boxCount);
        std::vector<std::list<int>::iterator> indexes(boxCount+1);
        auto it = boxes.begin();
        for (int i = 1; i <= boxCount; ++i, ++it)
        {
            *it = i;
            indexes[i] = it;
        }
        
        while (cmdCount--)
        {
            int cmd;
            std::cin >> cmd;
            switch (cmd)
            {
            case 1:{
                int b1, b2;
                std::cin >> b1 >> b2;
                
                boxes.erase(indexes[b1]);
                auto it2 = indexes[b2];
                if (isReversed)
                    ++it2;
                indexes[b1] = boxes.insert(it2, b1);
                break;
                }
            case 2:{
                int b1, b2;
                std::cin >> b1 >> b2;
                
                boxes.erase(indexes[b1]);
                auto it2 = indexes[b2];
                if (!isReversed)
                    ++it2;
                indexes[b1] = boxes.insert(it2, b1);
                break;
                }
            case 3:{
                int b1, b2;
                std::cin >> b1 >> b2;
                auto it1 = indexes[b1];
                auto it2 = indexes[b2];
                *it1 = b2;
                *it2 = b1;
                indexes[b1] = it2;
                indexes[b2] = it1;
                break;
                }
            case 4:
                isReversed = !isReversed;
                break;
            default:
                break;
            }
        }
        
        unsigned long long sum = 0;
        if (isReversed)
        {
            // for (auto it = boxes.rbegin(); it != boxes.rend(); ++it)
            // {
            //     std::cout << *it << std::endl;////
            // }
            for (auto it = boxes.rbegin(); it != boxes.rend(); )
            {
                sum += *it;
                ++it;
                if (it != boxes.rend())
                    ++it;
            }
        }
        else
        {
            // for (auto it = boxes.begin(); it != boxes.end(); ++it)
            // {
            //     std::cout << *it << std::endl;////
            // }
            for (auto it = boxes.begin(); it != boxes.end(); )
            {
                sum += *it;
                ++it;
                if (it != boxes.end())
                    ++it;
            }
        }
        
        printf("Case %d: %llu\n", ++cases, sum);
    }
    return 0;
}

// 1 2 3 4 5 6
// 2 3 1 4 5 6
// 2 1 4 5 3 6
// 2 6 4 5 3 1
// 1 3 5 4 6 2