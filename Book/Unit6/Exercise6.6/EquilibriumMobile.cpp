#include <iostream>
#include <string>
#include <queue>
#include <map>

void countWeightedWeight(std::map<long long, int> &wwCount, const std::string &input, std::queue<int> sepList[20],
              int left, int right, int layer, int &total)
{
    if (input[left] == '[')
    {
        ++layer;
        int sep = sepList[layer].front();
        sepList[layer].pop();
        
        countWeightedWeight(wwCount, input, sepList, left+1 , sep, layer, total);
        countWeightedWeight(wwCount, input, sepList, sep+1, right, layer, total);
    }
    else
    {
        long long val = std::stoll(input.substr(left, right-left));
        ++wwCount[ ((long long)1 << layer) * val];
        ++total;
    }
}

int main()
{
    int cases;
    std::cin >> cases;
    while (cases--)
    {
        std::string input;
        std::cin >> input;
        
        std::queue<int> sepList[20];
        for (int i = 0, layer = 0; i < input.size(); ++i)
        {
            char c = input[i];
            if (c == '[')
            {
                ++layer;
            }
            if (c == ']')
            {
                --layer;
            }
            if (c == ',')
            {
                sepList[layer].push(i);
            }
        }
        
        int totalCount = 0;
        std::map<long long, int> weightedWeightCount;
        countWeightedWeight(weightedWeightCount, input, sepList, 0, input.size(), 0, totalCount);
        
        int maxCount = 0;
        for (auto &p : weightedWeightCount)
        {
            if (maxCount < p.second)
            {
                maxCount = p.second;
            }
        }
        std::cout << totalCount - maxCount << std::endl;
    }
    return 0;
}