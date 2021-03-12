#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main()
{
    int cases;
    std::cin >> cases;
    while (cases--)
    {
        std::map<int, std::vector<int>> dots;
        int len;
        std::cin >> len;
        while (len--)
        {
            int x, y;
            std::cin >> x >> y;
            dots[x].push_back(y);
        }
        
        bool isSymmetric = true;
        auto head = dots.begin();
        auto tail = dots.end();
        --tail;
        int sym = head->first;
        for (int i = 0; i < dots.size()/2; ++i, ++head, --tail)
        {
            std::sort(head->second.begin(), head->second.end());
            std::sort(tail->second.begin(), tail->second.end());
            if (head->second != tail->second)
            {
                isSymmetric = false;
                break;
            }
            
            if (i == 0)
            {
                sym = (head->first + tail->first)/2;
            }
            else if (sym != (head->first + tail->first)/2)
            {
                isSymmetric = false;
                break;
            }
        }
        
        if (head == tail && head->first != sym)
        {
            isSymmetric = false;
        }
        
        std::cout << (isSymmetric ? "YES" : "NO") << std::endl;
    }
    
    return 0;
}