#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

int main()
{
    std::string line;
    while(std::getline(std::cin, line))
    {
        std::sort(line.begin(), line.end());
        printf("%c %c %c\n", line[0], line[1], line[2]);
    }
    return 0;
}