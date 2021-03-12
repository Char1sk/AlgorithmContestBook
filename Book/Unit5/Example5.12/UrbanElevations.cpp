#include <iostream>
#include <algorithm>

struct Building
{
    int num;
    double x;
    double y;
    double width;
    double depth;
    double height;
    
    Building() : num(0), x(0), y(0), width(0), depth(0), height(0) {}
};

std::istream &operator>>(std::istream &is, Building &b)
{
    is >> b.x >> b.y >> b.width >> b.depth >> b.height;
    return is;
}

bool operator<(const Building &b1, const Building &b2)
{
    return (b1.x < b2.x) || (b1.x == b2.x && b1.y < b2.y);
}

int main()
{
    int cases;
    int len;
    while ((std::cin >> len) && len)
    {
        Building buildings[105];
        for (int i = 0; i < len; ++i)
        {
            buildings[i].num = i+1;
            std::cin >> buildings[i];
        }
        std::sort(buildings, buildings+len);
        
        if (cases != 0)
        {
            std::cout << std::endl;
        }
        printf("For map #%d, the visible buildings are numbered as follows:\n", ++cases);
        bool firstBuild = true;
        for (int i = 0; i < len; ++i)
        {
            auto &now = buildings[i];
            int left = now.x;
            
            bool isVisible = true;
            for (int j = 0; j < len; ++j)
            {
                auto &each = buildings[j];
                if (each.y+each.depth <= now.y && each.height >= now.height
                         && each.x <= left && each.x+each.width > left)
                {
                    left = each.x + each.width;
                    if (left >= now.x + now.width)
                    {
                        isVisible = false;
                        break;
                    }
                }
            }
            if (isVisible)
            {
                if (firstBuild)
                {
                    firstBuild = false;
                }
                else
                {
                    std::cout << ' ';
                }
                std::cout << now.num ;
            }
        }
        std::cout << std::endl;
    }
    return 0;
}