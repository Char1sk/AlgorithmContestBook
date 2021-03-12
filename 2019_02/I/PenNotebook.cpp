#include <iostream>

int main()
{
    int num, pen, note;
    std::cin >> num >> pen >> note;
    std::cout << ((pen >= num && note >= num)? "Yes" : "No" ) << std::endl;
    return 0;
}