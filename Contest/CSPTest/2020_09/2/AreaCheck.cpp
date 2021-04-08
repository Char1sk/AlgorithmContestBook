#include <iostream>

int main()
{
    int pcnt, needTime, tcnt, x1, y1, x2, y2;
    std::cin >> pcnt >> needTime >> tcnt >> x1 >> y1 >> x2 >> y2;
    int passCnt = 0, stayCnt = 0;
    for (int p = 0; p < pcnt; ++p)
    {
        bool isPass = false;
        bool isStay = false;
        int nowTime = 0;
        for (int t = 0; t < tcnt; ++t)
        {
            int x, y;
            std::cin >> x >> y;
            if (x1 <= x && x <= x2 && y1 <= y && y <= y2)
            {
                ++nowTime;
                isPass = true;
                if (nowTime == needTime)
                {
                    isStay = true;
                }
            }
            else
            {
                nowTime = 0;
            }
        }
        passCnt += isPass;
        stayCnt += isStay;
    }
    std::cout << passCnt << std::endl;
    std::cout << stayCnt << std::endl;
    return 0;
}