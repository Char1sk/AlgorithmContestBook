#include <iostream>
#include <vector>
#include <set>
#include <cmath>

int main()
{
    int cases;
    std::cin >> cases;
    while (cases--)
    {
        int len;
        std::cin >> len;
        std::vector<int> zeros(len, 0);
        // std::cout << zeros.size() << zeros[0] << std::endl;////
        
        std::vector<int> tuple;
        for (int i = 0; i < len; ++i)
        {
            int itemp;
            std::cin >> itemp;
            tuple.push_back(itemp);
        }
        
        std::set<std::vector<int>> tuples;
        bool isLoop = false;
        for (int i = 0; i < 1005; ++i)
        {
            if (tuple == zeros)
            {
                break;
            }
            
            if (tuples.find(tuple) == tuples.end())
            {
                tuples.insert(tuple);
            }
            else
            {
                isLoop = true;
                break;
            }
            
            int head = tuple[0];
            for (int j = 0; j < len; ++j)
            {
                if (j != len-1)
                {
                    tuple[j] = std::abs(tuple[j]-tuple[j+1]);
                }
                else
                {
                    tuple[j] = std::abs(tuple[j]-head);
                }
                // std::cout << tuple[j] << ' ';////
            }
            // std::cout << std::endl;////
            
        }
        
        std::cout << (isLoop ? "LOOP" : "ZERO") << std::endl;
    }
    return 0;
}