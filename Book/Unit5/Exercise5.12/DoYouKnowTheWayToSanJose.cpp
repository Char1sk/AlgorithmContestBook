#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

struct Map
{
    std::string name;
    double x1;
    double y1;
    double x2;
    double y2;
    double cx;
    double cy;
    double len;
    double wid;
    double sqr;
    
    Map() : sqr(-1) {}
    Map(const std::string &s, double i1, double i2, double i3, double i4) : 
            name(s), x1(i1), y1(i2), x2(i3), y2(i4), cx((i1+i3)/2), cy((i2+i4)/2), 
            len(i3-i1), wid(i4-i2), sqr((x2-x1)*(y2-y1)) {}
};

bool operator< (const Map &m1, const Map &m2)
{
    return m1.sqr > m2.sqr;
}

bool isGreater(const Map &m1, const Map &m2, double x, double y)
{
    if (m2.sqr == -1)
    {
        return true;
    }
    else
    {
        double dis1 = (m1.cx-x)*(m1.cx-x) + (m1.cy-y)*(m1.cy-y);
        double dis2 = (m2.cx-x)*(m2.cx-x) + (m2.cy-y)*(m2.cy-y);
        if (dis1 < dis2)
        {
            return true;
        }
        else if (std::abs(dis1-dis2)<1e-4)
        {
            double rat1 = std::abs(m1.wid/m1.len-0.75);
            double rat2 = std::abs(m2.wid/m2.len-0.75);
            if (rat1 < rat2)
            {
                return true;
            }
            else if (std::abs(rat1-rat2)<1e-4)
            {
                dis1 = (m1.x2-x)*(m1.x2-x) + (m1.y1-y)*(m1.y1-y);
                dis2 = (m2.x2-x)*(m2.x2-x) + (m2.y1-y)*(m2.y1-y);
                if (dis1 > dis2)
                {
                    return true;
                }
                else if (std::abs(dis1-dis2)<1e-4)
                {
                    if (m1.x1 < m2.x1)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
    }
    return false;
}

int main()
{
    std::string stemp;
    std::cin >> stemp;
    
    std::set<Map> maps;
    while (std::cin >> stemp && stemp != "LOCATIONS")
    {
        double x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2)
        {
            std::swap(x1, x2);
        }
        if (y1 > y2)
        {
            std::swap(y1, y2);
        }
        maps.emplace(stemp, x1, y1, x2, y2);
    }
    
    std::map<std::string, std::pair<double, double>> cities;
    while (std::cin >> stemp && stemp != "REQUESTS")
    {
        double x, y;
        std::cin >> x >> y;
        cities[stemp] = {x, y};
    }
    
    while (std::cin >> stemp && stemp != "END")
    {
        int errorCode = 0;
        
        int level;
        std::cin >> level;
        
        std::set<Map> contains;
        double x, y;
        
        int nowLvl = 0;
        Map maxMap;
        
        if (cities.find(stemp) == cities.end())
        {
            errorCode = 1;
            goto End;
        }
        x = cities[stemp].first;
        y = cities[stemp].second;
        
        // std::cout << "!!!!!!citi: " << cities.find(stemp)->first << std::endl;;
        
        for (auto &m : maps)
        {
            if (m.x1 < x && x < m.x2 && m.y1 < y && y < m.y2)
            {
                contains.insert(m);
            }
        }
        if (contains.empty())
        {
            errorCode = 2;
            goto End;
        }
        
        for (auto &m : contains)
        {
            if (maxMap.sqr == -1 || maxMap.sqr > m.sqr)
            {
                ++nowLvl;
                maxMap = m;
                // std::cout << nowLvl << m.name << std::endl;////
            }
            else if(nowLvl == level)
            {
                if (isGreater(m, maxMap, x, y))
                {
                    // std::cout << m.name << std::endl;////
                    maxMap = m;
                }
            }
            
            if (nowLvl >= level)
            {
                break;
            }
        }
        if (nowLvl < level)
        {
            errorCode = 3;
            goto End;
        }
        
        End:;
        switch (errorCode)
        {
        case 0:
            printf("%s at detail level %d using %s\n", stemp.c_str(), level, maxMap.name.c_str());
            break;
        
        case 1:
            printf("%s at detail level %d unknown location\n", stemp.c_str(), level);
            break;
        
        case 2:
            printf("%s at detail level %d no map contains that location\n", stemp.c_str(), level);
            break;
        
        case 3:
            printf("%s at detail level %d no map at that detail level; using %s\n", stemp.c_str(), level, maxMap.name.c_str());
            break;
        
        default:
            break;
        }
    }
    return 0;
}