#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    // freopen("./in.txt", "r", stdin);
    // freopen("./out.txt", "w", stdout);
    

    int son, mon;
    while (std::cin >> son >> mon)
    {    
        printf("%d/%d = ", son, mon);
        // if (son == 0)
        // {
        //     std::cout << "0.(0)" << std::endl;
        //     std::cout << "   1 = number of digits in repeating cycle" << std::endl << std::endl;
        //     continue;
        // }
        
        int integer = son / mon;
        son -= integer * mon;
        std::vector<int> quos;
        std::vector<int> rems;
        while (std::find(rems.begin(), rems.end(), son) == rems.end())
        {
            rems.push_back(son);
            quos.push_back(10*son / mon);
            son = 10*son % mon;
        }
        auto head = std::find(rems.begin(), rems.end(), son);
        
        // do
        // {
        //     son *= 10;
        //     quos.push_back(son / mon);
        //     son = son % mon;
        //     rems.push_back(son);
        // } while (std::find(rems.begin(), rems.end(), rems.back()) == rems.end()-1);
        
        // auto head = std::find(rems.begin(), rems.end(), rems.back());
        // auto tail = rems.end()-1;
        // if (rems.back() == *(rems.end()-2))
        // {
        //     ++head;
        //     ++tail;
        // }
        
        std::cout << integer << '.';
        int index = 0;
        for (auto qit = quos.begin(), rit = rems.begin(); index < 50; ++qit, ++rit, ++index)
        {
            if (rit == head)
            {
                std::cout << "(" ;
            }
            if (rit == rems.end())
            {
                std::cout << ")" << std::endl;
                break;
            }
            std::cout << *qit ;
        }
        if (index == 50)
        {
            std::cout << "...)" << std::endl;
        }
        std::cout << "   " << rems.end() - head << " = number of digits in repeating cycle" << std::endl << std::endl;
    }
    return 0;
}