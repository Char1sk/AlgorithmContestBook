#include <iostream>

int main()
{
    int scr = 0;
    while(std::cin >> scr)
    {
        if(0 <= scr && scr < 60)
        {
            std::cout << "E" << std::endl;
        }
        else if(60 <= scr && scr < 70)
        {
            std::cout << "D" << std::endl;
        }
        else if(70 <= scr && scr < 80)
        {
            std::cout << "C" << std::endl;
        }
        else if(80 <= scr && scr < 90)
        {
            std::cout << "B" << std::endl;
        }
        else if(90  <= scr && scr <= 100)
        {
            std::cout << "A" << std::endl;
        }
        else
        {
            std::cout << "Score is error!" << std::endl;
        }
    }
    return 0;
}