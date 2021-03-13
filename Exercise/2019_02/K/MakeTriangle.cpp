#include <iostream>

int main()
{
    int a, b, c;
    std::cin >> a >> b >> c;
    int sum = a + b + c;
    int max;
    max = (a > b) ? a : b ;
    max = (max > c) ? max : c ;
    int delta = 2 * max - sum + 1;
    std::cout << (delta > 0 ? delta : 0) << std::endl;
    return 0;
}