#include <iostream>
#include <algorithm>

class Pallet
{
public:
    int len;
    int wid;
};

std::istream &operator>> (std::istream &is, Pallet &p)
{
    std::cin >> p.len >> p.wid;
    if (p.len < p.wid)
    {
        std::swap(p.len, p.wid);
    }
    return is;
}

bool operator< (const Pallet &p1, const Pallet &p2)
{
    return (p1.len < p2.len) || (p1.len == p2.len && p1.wid < p2.wid);
}

bool operator== (const Pallet &p1, const Pallet &p2)
{
    return (p1.len == p2.len) && (p1.wid == p2.wid);
}

int main()
{
    Pallet pallets[6];
    while (std::cin >> pallets[0])
    {
        // ba ba ca ca cb cb
        for (int i = 1; i < 6; ++i)
        {
            std::cin >> pallets[i];
        }
        std::sort(pallets, pallets+6);
        
        if (pallets[0] == pallets[1] && pallets[2] == pallets[3] && pallets[4] == pallets[5] && 
                pallets[0].len == pallets[4].wid && pallets[0].wid == pallets[2].wid && pallets[2].len == pallets[4].len)
            std::cout << "POSSIBLE" << std::endl;
        else
            std::cout << "IMPOSSIBLE" << std::endl;
    }
    return 0;
}