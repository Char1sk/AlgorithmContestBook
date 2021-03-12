#include <iostream>
#include <map>

void read(std::map<int, int> &colVal, int pos)
{
    int lv;
    std::cin >> lv;
    if (lv != -1)
    {
        colVal[pos-1] += lv;
        read(colVal, pos-1);
    }
    
    int rv;
    std::cin >> rv;
    if (rv != -1)
    {
        colVal[pos+1] += rv;
        read(colVal, pos+1);
    }
}

int main()
{
    int cases = 0;
    int rootVal;
    while (std::cin >> rootVal && rootVal != -1)
    {
        const int originPos = 0;
        std::map<int, int> columnValues;
        columnValues[originPos] = rootVal;
        
        read(columnValues, originPos);
        
        bool first = true;
        printf("Case %d:\n", ++cases);
        for (auto &p : columnValues)
        {
            if (first)
            {
                first = false;
            }
            else
            {
                std::cout << ' ' ;
            }
            std::cout << p.second;
        }
        std::cout << std::endl << std::endl;
    }
    return 0;
}