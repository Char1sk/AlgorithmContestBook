#include <iostream>
#include <vector>

struct Point
{
    int x;
    int y;
    bool t;
};

int main()
{
    int pointCnt, queryCnt;
    std::cin >> pointCnt >> queryCnt;
    std::vector<Point> points(pointCnt);
    int Acnt = 0, Bcnt = 0;
    for (int i = 0; i < pointCnt; ++i)
    {
        char c;
        std::cin >> points[i].x >> points[i].y >> c;
        points[i].t = c-'A';
        points[i].t ? ++Bcnt : ++Acnt;
    }
    for (int i = 0; i < queryCnt; ++i)
    {
        int t1, t2, t3;
        std::cin >> t1 >> t2 >> t3;
        int Aabove = 0, Babove = 0;
        for (int j = 0; j < pointCnt; ++j)
        {
            // 严格来说，这里限制的是 <= 0, > 1
            if (t1 + t2*points[j].x + t3*points[j].y > 0)
            {
                points[j].t ? ++Babove : ++Aabove;
            }
        }
        if (Aabove == 0 && Babove == Bcnt || 
            Babove == 0 && Aabove == Acnt)
        {
            std::cout << "Yes" << std::endl;
        }
        else
        {
            std::cout << "No" << std::endl;
        }
    }
    return 0;
}