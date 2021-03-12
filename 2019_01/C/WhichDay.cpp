#include <iostream>
#include <sstream>
#include <string>

int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool leap(int year)
{
    if(year % 100 == 0)
        if(year % 400 == 0)
            return true;
        else
            return false;
    else if(year % 4 == 0)
        return true;
    else
        return false;
    
}

int main()
{
    int year = 0;
    int month = 0;
    int day = 0;
    std::string line;
    std::string temp;
    while(std::cin >> line)
    {
        std::istringstream iss(line);
        std::getline(iss, temp, '/');
        year = std::stoi(temp);
        std::getline(iss, temp, '/');
        month = std::stoi(temp);
        iss >> day ;
        int total = day;
        for(int m = 0; m != month-1; ++m)
        {
            total += days[m];
        }
        if(leap(year) && month > 2)
            ++total;
        std::cout << total << std::endl;
    }
    return 0;
}