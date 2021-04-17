#include <iostream>

int main()
{
    int start = 10000;
    int tm = 0;
    while (start > 0)
    {
        if (tm % 2 == 0)
        {
            start -= 600;
        }
        else
        {
            start += 300;
        }
        ++tm;
    }
    std::cout << tm << std::endl;
    return 0;
}