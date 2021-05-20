#include <iostream>
#include <algorithm>

struct Item
{
    int weight;
    int value;
    bool operator< (const Item &it) const
    {
        if (1.0 * value / weight > 1.0 * it.value / it.weight)
        {
            return true;
        }
        else if (weight < it.weight)
        {
            return true;
        }
        return false;
    }
};

const int maxN = 100+5;
int N = 0;
int W = 0;
Item items[maxN];

double getUpperBound(int idx, int nowValue, int restWeight)
{
    double ret = nowValue;
    int rweight = restWeight;
    for (int i = idx; i < N; ++i)
    {
        if (items[i].weight <= rweight)
        {
            ret += items[i].value;
            rweight -= items[i].weight;
        }
        else
        {
            ret += 1.0 * items[i].value * rweight / items[i].weight;
            rweight = 0;
            break;
        }
    }
    return ret;
}

double maxValue = 0.0;
void chooseItem(int idx, int nowValue, int restWeight)
{
    if (idx >= N)
    {
        maxValue = nowValue;
        // if (nowValue > maxValue)
        // {
        //     maxValue = nowValue;
        // }
        return;
    }
    // chooseItem(idx+1, nowValue, restWeight);
    // choose 1
    if (items[idx].weight <= restWeight)
    {
        chooseItem(idx+1, nowValue+items[idx].value, restWeight-items[idx].weight);
    }
    // not choose 0
    // double d1 = getUpperBound(idx, nowValue, restWeight);
    double d2 = getUpperBound(idx+1, nowValue, restWeight);
    if (maxValue < d2)
    {
        chooseItem(idx+1, nowValue, restWeight);
    }
}

int main()
{
    std::cin >> N >> W;
    for (int n = 0; n < N; ++n)
    {
        std::cin >> items[n].weight >> items[n].value;
    }
    std::sort(items, items+N);
    chooseItem(0, 0, W);
    std::cout << maxValue << std::endl;
    return 0;
}