#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>

struct Order
{
    // bool isActive;
    bool isSell;
    int count;
    int price;
    int index;
    
    Order() {}
    Order(bool sl, int c, int p, int i) : isSell(sl), count(c), price(p), index(i) {}
};

struct BuyOrderCompare
{
    bool operator() (const Order &o1, const Order &o2)
    {
        return (o1.price < o2.price || o1.price == o2.price && o1.index > o2.index);
    }
};

struct SellOrderCompare
{
    bool operator() (const Order &o1, const Order &o2)
    {
        return (o1.price > o2.price || o1.price == o2.price && o1.index > o2.index);
    }
};

int main()
{   
    // freopen("./in.txt", "r", stdin);
    // freopen("./out.txt", "w", stdout);
    
    bool isFirst = true;
    int len;
    while (std::cin >> len)
    {
        if (isFirst)
        {
            isFirst = false;
        }
        else
        {
            std::cout << std::endl;
        }
        
        std::vector<Order> orders;
        std::priority_queue<Order, std::vector<Order>, BuyOrderCompare> buys;
        std::priority_queue<Order, std::vector<Order>, SellOrderCompare> sells;
        std::map<int, int> buyPriceToCount;
        std::map<int, int> sellPriceToCount;
        
        for (int i = 0; i < len; ++i)
        {
            std::string cmd;
            std::cin >> cmd;
            if (cmd == "BUY")
            {
                int count, price;
                std::cin >> count >> price;
                while (count && !sells.empty() && sells.top().price <= price)
                {
                    int idx = sells.top().index;
                    if (count > sells.top().count)
                    {
                        printf("TRADE %d %d\n", sells.top().count, sells.top().price);
                        sellPriceToCount[sells.top().price] -= sells.top().count;
                        count -= sells.top().count;
                        orders[idx].count = 0;
                        sells.pop();
                        // sells.push(orders[idx]);
                    }
                    else
                    {
                        printf("TRADE %d %d\n", count, sells.top().price);
                        sellPriceToCount[sells.top().price] -= count;
                        orders[idx].count -= count;
                        sells.pop();
                        sells.push(orders[idx]);
                        count = 0;
                    }
                    while (!sells.empty() && orders[sells.top().index].count == 0)
                    {
                        sells.pop();
                    }
                }
                orders.emplace_back(false, count, price, i);
                if (count)
                {
                    buys.push(orders[i]);
                    buyPriceToCount[price] += count;
                }
            }
            if (cmd == "SELL")
            {
                int count, price;
                std::cin >> count >> price;
                while (count && !buys.empty() && buys.top().price >= price)
                {
                    int idx = buys.top().index;
                    if (count > buys.top().count)
                    {
                        printf("TRADE %d %d\n", buys.top().count, buys.top().price);
                        buyPriceToCount[buys.top().price] -= buys.top().count;
                        count -= buys.top().count;
                        orders[idx].count = 0;
                        buys.pop();
                        // buys.push(orders[idx]);
                    }
                    else
                    {
                        printf("TRADE %d %d\n", count, buys.top().price);
                        buyPriceToCount[buys.top().price] -= count;
                        orders[idx].count -= count;
                        buys.pop();
                        buys.push(orders[idx]);
                        count = 0;
                    }
                    while (!buys.empty() && orders[buys.top().index].count == 0)
                    {
                        buys.pop();
                    }
                }
                orders.emplace_back(true, count, price, i);
                if (count)
                {
                    sells.push(orders[i]);
                    sellPriceToCount[price] += count;
                }
            }
            if (cmd == "CANCEL")
            {
                int index;
                std::cin >> index;
                orders.emplace_back();
                if (!orders[index-1].isSell)
                {
                    buyPriceToCount[orders[index-1].price] -= orders[index-1].count;
                    orders[index-1].count = 0;
                    while (!buys.empty() && orders[buys.top().index].count == 0)
                    {
                        buys.pop();
                    }
                }
                else
                {
                    sellPriceToCount[orders[index-1].price] -= orders[index-1].count;
                    orders[index-1].count = 0;
                    while (!sells.empty() && orders[sells.top().index].count == 0)
                    {
                        sells.pop();
                    }
                }
                
            }
            
            printf("QUOTE %d %d - %d %d\n", 
                    (buys.empty() ? 0 : buyPriceToCount[buys.top().price]),
                    (buys.empty() ? 0 : buys.top().price),
                    (sells.empty() ? 0 : sellPriceToCount[sells.top().price]),
                    (sells.empty() ? 99999 : sells.top().price));
        }
    }
    return 0;
}