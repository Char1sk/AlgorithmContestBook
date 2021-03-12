#include <iostream>
#include <string>
#include <map>
#include <set>

struct map_cmp
{
    bool operator() (const std::string &s1, const std::string &s2)
    {
        return (s1.size() < s2.size()) || (s1.size() == s2.size() && s1 < s2);
    }
};

int main()
{
    std::map<std::string, std::string, map_cmp> tree; // road to value
    std::set<std::string> nodes;
    std::string stemp;
    bool isLegal = true;
    while (std::cin >> stemp)
    {
        if (stemp == "()")
        {
            for (auto &p : tree)
            {
                if (p.first != "" && nodes.find(p.first.substr(0, p.first.size()-1)) == nodes.end())
                {
                    isLegal = false;
                    break;
                }
            }
            if (isLegal)
            {
                for (auto &p : tree)
                {
                    if (p.first != "")
                    {
                        std::cout << ' ' ;
                    }
                    std::cout << p.second ;
                }
                std::cout << std::endl;
            }
            else
            {
                std::cout << "not complete" << std::endl;
            }
            
            isLegal = true;
            tree.clear();
            nodes.clear();
            continue;
        }
        else if (isLegal)
        {
            stemp = stemp.substr(1, stemp.size()-2);
            int idx = stemp.find(',');
            std::string val(stemp, 0, idx);
            std::string rod(stemp, idx+1);
            if (tree.find(rod) != tree.end())
            {
                isLegal = false;
            }
            else
            {
                tree[rod] = val;
                nodes.insert(rod);
            }
            
        }
    }
    
    return 0;
}