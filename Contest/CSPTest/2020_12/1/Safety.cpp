#include <iostream>

int main()
{
    int cnt;
    std::cin >> cnt;
    int safe = 0;
    while (cnt--)
    {
        int weight, score;
        std::cin >> weight >> score;
        safe += weight * score;
    }
    std::cout << (safe > 0 ? safe : 0) << std::endl;
    return 0;
}